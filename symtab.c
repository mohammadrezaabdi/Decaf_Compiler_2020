#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "info.h"
#include "symtab.h"

void init_scope_list() {
    scope_list = create_scope(0, create_loc(1, 1), NULL);
    curr_scope = scope_list;
    last_scope_id = 0;
}

void init_hash_table() {
    hash_table = (entity **) malloc(sizeof(entity *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // adding constatns
    const_entry *cEntry = const_list;
    for (int i = 0; i < num_of_consts; ++i) {
        add_to_hash_table(create_entity(cEntry->val->name, NULL, 0, type_list[cEntry->val->type], 0, NULL, true,
                                        cEntry->val->ival,
                                        cEntry->val->dval, cEntry->val->sval, cEntry->val->bval));
        cEntry = cEntry->next;
    }
    // adding functions
    func_entry *fEntry = func_list;
    for (int i = 0; i < num_of_funcs; ++i) {
        add_to_hash_table(
                create_entity(fEntry->val->name, NULL, 0, (char *) "function",
                              0,
                              (fEntry->val->owner_class_type > 0) ? type_list[fEntry->val->owner_class_type] : NULL,
                              false, 0, 0.0, NULL, false));
        fEntry = fEntry->next;
    }
    is_this = false;
    curr_class_scope = 0;
    curr_entity = NULL;
    symbol_table = NULL;
    // stack initialization
    entity_heap = malloc(sizeof(entity_stack));
    entity_heap->root = NULL;
    entity_heap->pointer = NULL;
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
    new_entity->scope_id = scope;
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

void add_to_hash_table(entity *new_entity) {
    unsigned int hash_val = hash(new_entity->name);
    new_entity->next = hash_table[hash_val];
    hash_table[hash_val] = new_entity;
    // tracking current entity
    curr_entity = new_entity;
}

void insert_local_var(char *name, int line, int col, char *type, int num_of_braces) {
    entity *found = lookup(name);
    if (found == NULL || found->type != get_type_id(type)) {
        add_to_hash_table(
                create_entity(name, create_loc(line, col), curr_scope->id, type, num_of_braces, NULL, false, 0, 0.0,
                              NULL,
                              false));
    } else {
        reference(name, line, col);
    }
}

void insert_field(char *name, int line, int col, char *type, int num_of_braces, char *owner_class) {
    add_to_hash_table(
            create_entity(name, create_loc(line, col), curr_scope->id, type, num_of_braces, owner_class, false, 0, 0.0,
                          NULL, false));
}

void insert_param(char *name, int line, int col, char *type, int num_of_braces) {
    add_to_hash_table(
            create_entity(name, create_loc(line, col), curr_scope->id, type, num_of_braces, NULL, false, 0, 0.0, NULL,
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
        push_entity(curr_entity);
        curr_entity = founded_entity;
    }
}

entity *lookup(char *name) {
    unsigned int hash_val = hash(name);
    entity *id = hash_table[hash_val];
    while ((id != NULL) && !(strcmp(name, id->name) == 0 && ((is_this && curr_class_scope == id->scope_id) ||
                                                             (!is_this && (curr_scope->id == id->scope_id ||
                                                                           is_father(curr_scope->id,
                                                                                     id->scope_id)))))) {
        id = id->next;
    }
    return id;
}

void reset_current_entity_type() {
    entity *new_entity = (entity *) malloc(sizeof(entity));
    strncpy(new_entity->name, curr_entity->name, strlen(curr_entity->name));
    new_entity->locations = curr_entity->locations;
    new_entity->scope_id = curr_entity->scope_id;
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
    int typeId = get_type_id(owner_class);
    int owner_class_id = (typeId > 0) ? typeId : 0;
    while ((id != NULL) &&
           (strcmp(name, id->name) != 0 || id->func_val->owner_class_type != owner_class_id)) {
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
    if (curr_entity->type == ARR_TYPE && strcmp(field_name, (char *) "length") == 0) {
        reference_to_function("length", line, col, type_list[0]);
    }
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
            if (strcmp(curr_entity->name, (char *) "this") == 0) {
                is_this = true;
            }
            field *founded_field = track_fields(curr_entity->obj_val, field_name);
            if (is_primitive(founded_field->type) && founded_field->num_of_pair_braces == 0) {
                reset_current_entity_type();
                curr_entity->type = founded_field->type;
                curr_entity->prime_val = create_primitive(founded_field->name, type_list[founded_field->type]);
                //    if (class_decl && get_type_id(curr_class->name) == curr_entity->in_class_field_type) {
                reference(founded_field->name, line, col);
                //    }

            } else if (founded_field->type == ARR_TYPE || founded_field->num_of_pair_braces > 0) {
                reset_current_entity_type();
                curr_entity->type = ARR_TYPE;
                curr_entity->arr_val = create_array(founded_field->name, type_list[founded_field->type],
                                                    founded_field->num_of_pair_braces);
                //    if (class_decl && get_type_id(curr_class->name) == curr_entity->in_class_field_type) {
                reference(founded_field->name, line, col);
                //    }

            } else if (is_class_object(founded_field->type) || founded_field->num_of_pair_braces == 0) {
                reset_current_entity_type();
                curr_entity->type = founded_field->type;
                curr_entity->obj_val = create_object(founded_field->name, type_list[founded_field->type]);
                curr_entity->in_class_field_type = founded_field->type;
                //   if (class_decl && get_type_id(curr_class->name) == curr_entity->in_class_field_type) {
                reference(founded_field->name, line, col);
                //   }
            }
            is_this = false;
        }
    }
}

void show_hash_table(FILE *file) { //todo: finishing
    fprintf(file, "SYMBOL TABLE [name, scope_id, type, is_field_type, locations * (line, col)]\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        entity *temp = hash_table[i];
        while (temp != NULL) {
            fprintf(file, "[%s, %d, %s, ", temp->name, temp->scope_id, type_list[temp->type]);
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

bool is_father(int child_id, int father_id) {
    scope *child = find_scope_by_id(child_id);
    scope *father = child->father;
    while ((father != NULL) && (father->id != father_id)) father = father->father;
    return (father != NULL);
}

scope *find_scope_by_id(int id) {
    scope *list = scope_list;
    while ((list != NULL) && (list->id != id)) list = list->next;
    return list;
}

scope *find_scope_by_start_loc(int start_line, int start_col) {
    scope *list = scope_list;
    while ((list != NULL) && (list->start->line != start_line) && (list->start->col != start_col)) list = list->next;
    return list;
}

scope *find_scope_by_end_loc(int end_line, int end_col) {
    scope *list = scope_list;
    while ((list != NULL) && (list->end->line != end_line) && (list->end->col != end_col)) list = list->next;
    return list;
}

void move_out_from_scope(int line, int col) {
    curr_scope->end = create_loc(line, col);
    curr_scope = curr_scope->father;
}

void move_in_new_scope(int line, int col) {
    last_scope_id++;
    scope *new_scope = create_scope(last_scope_id, create_loc(line, col), curr_scope);
    scope *list = scope_list;
    while (list->next != NULL) list = list->next;
    list->next = new_scope;
    curr_scope = new_scope;
}

void show_scopes(FILE *file) {
    scope *list = scope_list;
    fprintf(file, "SCOPE [ID, start(l,c), end(l,c), parent] :\n");
    while (list != NULL) {
        fprintf(file, "[%d (%d, %d) (%d, %d) %d]\n", list->id, list->start->line, list->start->col, list->end->line,
                list->end->col, (list->father != NULL) ? list->father->id : 0);
        list = list->next;
    }
    fprintf(file, "\n");
}

scope *create_scope(int id, loc *start, scope *parent) {
    scope *new_scope = (scope *) malloc(sizeof(scope));
    new_scope->id = id;
    new_scope->start = start;
    new_scope->end = NULL;
    new_scope->father = parent;
    new_scope->next = NULL;
    return new_scope;
}

void adapt_symbol_table_to_tac(int last_line) {
    symbol_table = (symbol_entry **) malloc(sizeof(symbol_entry *) * last_line);
    for (int i = 0; i < last_line; ++i) {
        symbol_table[i] = NULL;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        entity *temp = hash_table[i];
        while (temp != NULL) {
            add_to_symbol_table(temp);
            temp = temp->next;
        }
    }
    //free(hash_table); todo: free in future
}

void add_to_symbol_table(entity *ent) {
    loc *l = ent->locations;
    while (l != NULL) {
        if (symbol_table[l->line] == NULL) {
            symbol_table[l->line] = create_symbol_entry(ent, l->col);
//            ent->next = NULL;
        } else {
            symbol_entry *last = symbol_table[l->line];
            while (last->next != NULL) last = last->next;
            last->next = create_symbol_entry(ent, l->col);
//            ent->next = NULL;
        }
        l = l->next;
    }
}

symbol_entry *create_symbol_entry(entity *ent, int colno) {
    symbol_entry *new_entry = (symbol_entry *) malloc(sizeof(symbol_entry));
    new_entry->val = ent;
    new_entry->colno = colno;
    new_entry->next = NULL;
    return new_entry;
}

entity *get_from_symbol_table(int line, int col) {
    symbol_entry *ent = symbol_table[line];
    while ((ent != NULL) && ent->colno != col) ent = ent->next;
    if (ent == NULL) {
        return NULL;
    } else {
        return ent->val;
    }
}

int get_allocation_bytes(int line, int col) {
    entity *ent = get_from_symbol_table(line, col);
    if (is_primitive(ent->type) && ent->prime_val != NULL) {
        return ent->prime_val->mem_byte;
    } else if (is_primitive(ent->type) && ent->const_val != NULL) {
        return ent->const_val->mem_byte;
    } else if (ent->type == ARR_TYPE && ent->arr_val != NULL) {
        return ent->arr_val->unit_mem_byte;
    } else if (is_class_object(ent->type) && ent->obj_val != NULL) {
        return ent->obj_val->mem_byte;
    }
    return 0;
}

void show_symbol_table(FILE *file, int last_line) {
    fprintf(file, "SYMBOL TABLE : \n\n");
    for (int i = 0; i < last_line; ++i) {
        symbol_entry *symbol_list = symbol_table[i];
        fprintf(file, "%d :\n", i);
        while (symbol_list != NULL) {
            fprintf(file, "  (%d)[%s, %d, %s, ", symbol_list->colno, symbol_list->val->name, symbol_list->val->scope_id,
                    type_list[symbol_list->val->type]);
            if (symbol_list->val->in_class_field_type > 0) {
                fprintf(file, "%s]\n", type_list[symbol_list->val->in_class_field_type]);
            } else if (symbol_list->val->type == FUNC_TYPE) {
                fprintf(file, "%s]\n", type_list[symbol_list->val->func_val->owner_class_type]);
            } else {
                fprintf(file, "]\n");
            }
            symbol_list = symbol_list->next;
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}

void push_entity(entity *ent) { // push
    if (entity_heap->root == NULL) {
        entity_heap->root = create_entity_entry(ent);
        entity_heap->pointer = entity_heap->root;
    } else {
        entity_entry *new_entry = create_entity_entry(ent);
        new_entry->prev = entity_heap->pointer;
        entity_heap->pointer = new_entry;
    }
}

entity *pop_entity() { // pop
    if (entity_heap->pointer != NULL) {
        entity_entry *temp = entity_heap->pointer;
        entity_heap->pointer = entity_heap->pointer->prev;
        free(temp->prev);
        return temp->val;
    }
    return NULL;
}

entity_entry *create_entity_entry(entity *ent) {
    entity_entry *new_entry = (entity_entry *) malloc(sizeof(entity_entry));
    new_entry->val = ent;
    new_entry->prev = NULL;
    return new_entry;
}

void down_casting(char * type){
    while (is_primitive(curr_entity->type) || curr_entity->type == FUNC_TYPE){
        curr_entity = pop_entity();
    }
    if(curr_entity->type == ARR_TYPE){
        curr_entity->obj_val =  create_object(curr_entity->name, type_list[curr_entity->arr_val->each_type]);
        curr_entity->type = curr_entity->arr_val->each_type;
    }
    class_down_casting(curr_entity->obj_val, type);
}