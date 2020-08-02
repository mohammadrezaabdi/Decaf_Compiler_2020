#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "info.h"
#include "symtab.h"

void init_hash_table() {
    hash_table = (entity **) malloc(sizeof(entity *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // adding constatns
    const_entry *cEntry = const_list;
    for (int i = 0; i < num_of_consts; ++i) {
        add_to_table(create_entity(cEntry->val->name, NULL, 0, type_list[cEntry->val->type], 0, NULL, true,
                                   cEntry->val->ival,
                                   cEntry->val->dval, cEntry->val->sval, cEntry->val->bval));
        cEntry = cEntry->next;
    }
    // adding functions
    func_entry *fEntry = func_list;
    for (int i = 0; i < num_of_funcs; ++i) {
        add_to_table(
                create_entity(fEntry->val->name, NULL, (fEntry->val->owner_class_type > 0) ? 1 : 0, (char *) "function",
                              0,
                              (fEntry->val->owner_class_type > 0) ? type_list[fEntry->val->owner_class_type] : NULL,
                              false, 0, 0.0, NULL, false));
        fEntry = fEntry->next;
    }
    curr_scope = 0;
    curr_entity = NULL;
}

unsigned int hash(char *key) {
    unsigned int hash_val = 0;
    for (; *key != '\0'; key++) hash_val += *key;
    hash_val += key[0] % 11 + (key[0] << 3) - key[0];
    return hash_val % TABLE_SIZE;
}

loc *create_loc(int line, int col) {
    loc *location = (loc *) malloc(sizeof(loc));
    location->line = line;
    location->col = col;
    location->next = NULL;
    return location;
}

entity *
create_entity(char *name, loc *location, int scope, char *type, int num_of_braces, char *owner_class, bool is_const,
              int ival, double dval, char *sval, bool bval) {
    entity *new_entity = (entity *) malloc(sizeof(entity));
    strncpy(new_entity->name, name, strlen(name));
    new_entity->locations = location;
    new_entity->scope = scope;
    new_entity->next = NULL;
    new_entity->type = (num_of_braces > 0) ? ARR_TYPE : get_type_id(type);
    new_entity->in_class_field_type = -1;
    if (class_decl && new_entity->type != FUNC_TYPE && owner_class != NULL) {
        new_entity->in_class_field_type = get_type_id(owner_class);
    }
    if (is_const) {
        new_entity->const_val = find_const(new_entity->type, ival, dval, sval, bval);
    } else if (is_primitive(new_entity->type)) {
        new_entity->prime_val = create_primitive(name, type);
    } else if (new_entity->type == ARR_TYPE) {
        new_entity->arr_val = create_array(name, type, num_of_braces);
    } else if (new_entity->type == FUNC_TYPE) {
        new_entity->func_val = find_func(name, get_type_id(owner_class));
    } else {
        new_entity->obj_val = create_object(name, type);
    }
    return new_entity;
}

void add_to_table(entity *new_entity) {
    unsigned int hash_val = hash(new_entity->name);
    new_entity->next = hash_table[hash_val];
    hash_table[hash_val] = new_entity;
    // tracking current entity
    curr_entity = new_entity;
}

void insert_local_var(char *name, int line, int col, char *type, int num_of_braces) {
    entity * found = lookup(name);
    if (found == NULL || (found->type != get_type_id(type))) {
        add_to_table(
                create_entity(name, create_loc(line, col), curr_scope, type, num_of_braces, NULL, false, 0, 0.0, NULL,
                              false));
    } else {
        reference(name, line, col);
    }
}

void insert_field(char *name, int line, int col, char *type, int num_of_braces, char *owner_class) {
    add_to_table(create_entity(name, create_loc(line, col), curr_scope, type, num_of_braces, owner_class, false, 0, 0.0,
                               NULL, false));
}

void insert_param(char *name, int line, int col, char *type, int num_of_braces) {
    add_to_table(
            create_entity(name, create_loc(line, col), curr_scope + 1, type, num_of_braces, NULL, false, 0, 0.0, NULL,
                          false));
}

void reference(char *name, int line, int col) {
    entity *founded_entity = lookup(name);
    if (founded_entity != NULL) {
        if (founded_entity->locations == NULL) {
            founded_entity->locations = create_loc(line, col);
        } else {
            loc *temp = founded_entity->locations;
            while (temp->next != NULL) temp = temp->next;
            temp->next = create_loc(line, col);
        }
        // tracking current entity
        curr_entity = founded_entity;
    }
}

void reset_current_entity_type() {
    entity *new_entity = (entity *) malloc(sizeof(entity));
    strncpy(new_entity->name, curr_entity->name, strlen(curr_entity->name));
    new_entity->locations = curr_entity->locations;
    new_entity->scope = curr_entity->scope;
    new_entity->next = NULL;
    new_entity->type = 0;
//    curr_entity->in_class_field_type = -1;
    new_entity->const_val = NULL;
    new_entity->prime_val = NULL;
    new_entity->obj_val = NULL;
    new_entity->arr_val = NULL;
    new_entity->func_val = NULL;
    //todo: freeing current entity
    curr_entity = new_entity;
}

void reference_to_function(char *name, int line, int col, char *owner_class) {
    unsigned int hash_val = hash(name);
    entity *id = hash_table[hash_val];
    while ((id != NULL) &&
           (strcmp(name, id->name) != 0 || (owner_class!=NULL && id->func_val->owner_class_type != get_type_id(owner_class)))) {
        id = id->next;
    }
    if (id != NULL) {
        if (id->locations == NULL) {
            id->locations = create_loc(line, col);
        } else {
            loc *temp = id->locations;
            while (temp->next != NULL) temp = temp->next;
            temp->next = create_loc(line, col);
        }
        // tracking current entity
        curr_entity = id;
    }
}

void chain_reference_tracking_entity(char *field_name, int line, int col, bool is_method) {
    if (is_class_object(curr_entity->type)) {
        if (is_method) {
            func *function = find_func_from_vtable(curr_entity->obj_val, field_name);
            if (function != NULL) {
                reset_current_entity_type();
                curr_entity->type = FUNC_TYPE;
                curr_entity->func_val = function;
                reference_to_function(field_name, line, col, type_list[curr_entity->func_val->owner_class_type]);
            }
        } else {
            field *founded_field = track_fields(curr_entity->obj_val, field_name);
            if (is_primitive(founded_field->type) && founded_field->num_of_pair_braces == 0) {
                reset_current_entity_type();
                curr_entity->type = founded_field->type;
                curr_entity->prime_val = create_primitive(founded_field->name, type_list[founded_field->type]);
                if(class_decl && get_type_id(curr_class->name) == curr_entity->in_class_field_type) {
                    reference(founded_field->name, line, col);
                }
                return;
            }
            if (founded_field->type == ARR_TYPE || founded_field->num_of_pair_braces > 0) {
                reset_current_entity_type();
                curr_entity->type = ARR_TYPE;
                curr_entity->arr_val = create_array(founded_field->name, type_list[founded_field->type],
                                                    founded_field->num_of_pair_braces);
                if(class_decl && get_type_id(curr_class->name) == curr_entity->in_class_field_type) {
                    reference(founded_field->name, line, col);
                }
                return;
            }
            if (is_class_object(founded_field->type) || founded_field->num_of_pair_braces == 0) {
                reset_current_entity_type();
                curr_entity->type = founded_field->type;
                curr_entity->obj_val = create_object(founded_field->name, type_list[founded_field->type]);
                curr_entity->in_class_field_type = founded_field->type;
                if(class_decl && get_type_id(curr_class->name) == curr_entity->in_class_field_type) {
                    reference(founded_field->name, line, col);
                }
                return;
            }
        }
    }
}

entity *lookup(char *name) {
    unsigned int hash_val = hash(name);
    entity *id = hash_table[hash_val];
    while ((id != NULL) && (strcmp(name, id->name) != 0)) {
        id = id->next;
    }
    return id;
}

void show_symbol_table(FILE *file) { //todo: finishing
    fprintf(file, "SYMBOL TABLE [name, scope, type, is_field_type, locations * (line, col)]\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        entity *temp = hash_table[i];
        while (temp != NULL) {
            fprintf(file, "[%s, %d, %s, ", temp->name, temp->scope, type_list[temp->type]);
            if (temp->in_class_field_type > 0) {
                fprintf(file, "%s, ", type_list[temp->in_class_field_type]);
            }
            loc *location = temp->locations;
            while (location != NULL) {
                fprintf(file, "(%d, %d) ", location->line, location->col);
                location = location->next;
            }
            temp = temp->next;
            fprintf(file, "]\n");
        }
    }
}

void hide_scope() {
    // hiding variables
    // for (int i = 0; i < TABLE_SIZE; i++) {
    //         entity * temp = hash_table[i];
    //         while (temp != NULL && temp->scope == curr_scope) {
    //                 temp = temp->next;
    //         }
    //         hash_table[i] = temp;
    // }
    if (curr_scope > 0)
        curr_scope--;
}

void make_scope() {
    curr_scope++;
}
