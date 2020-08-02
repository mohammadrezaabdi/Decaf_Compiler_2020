#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "info.h"

void init_lists() {
    // initialize primitive types
    type_list = (char **) malloc(sizeof(char *) * MAX_TYPE_NUM);
    type_list[0] = (char *) "void";
    type_list[1] = (char *) "int";
    type_list[2] = (char *) "double";
    type_list[3] = (char *) "string";
    type_list[4] = (char *) "bool";
    type_list[5] = (char *) "array";
    type_list[6] = (char *) "function";
    num_of_types = 7;
    // initialize NULL constant
    const_list = (const_entry *) malloc(sizeof(const_entry));
    const_list->val = (constant *) malloc(sizeof(constant));
    strcpy(const_list->val->name, (char *) "NULL");
    const_list->val->type = VOID_TYPE;
    const_list->val->ival = 0;
    const_list->val->dval = 0.0;
    const_list->val->sval = NULL;
    const_list->val->bval = false;
    const_list->next = NULL;
    num_of_consts = 1;
    // initial function list
    func_list = (func_entry *) malloc(sizeof(func_entry));
    func_list->val = (func *) malloc(sizeof(func));
    strcpy(func_list->val->name, (char *) "length");
    func_list->val->inf_type = INT_TYPE;
    func_list->val->inf_num_of_pair_braces = 0;
    func_list->val->params = NULL;
    func_list->val->num_of_parms = 0;
    func_list->val->owner_class_type = 0;
    func_list->next = NULL;
    num_of_funcs = 1;
    func_decl = false;
    func_scope = false;
    // initial class list
    class_list = NULL;
    num_of_classes = 0;
}

bool is_primitive(int type) {
    return (type < ARR_TYPE && type != 0);
}

bool is_class_object(int type) {
    return (type > FUNC_TYPE);
}

int get_type_id(char *name) { // if can't find the type returns -1
    if (name != NULL) {
        for (int i = 0; i < num_of_types; i++) {
            if (strcmp(type_list[i], name) == 0) {
                return i;
            }
        }
    }
    return -1;
}

void add_to_type_list(char *name) {
    if (get_type_id(name) < 0) {
        type_list[num_of_types] = (char *) malloc(sizeof(char) * strlen(name));
        strncpy(type_list[num_of_types], name, strlen(name));
        num_of_types++;
    }
}

constant *find_const(int type, int ival, double dval, char *sval, bool bval) {
    const_entry *temp = const_list;
    constant *candidate = NULL;
    while ((temp != NULL)) {
        if ((temp->val->type == type) &&
            ((type == INT_TYPE && temp->val->ival == ival) ||
             (type == DBL_TYPE && temp->val->dval == dval) ||
             (type == STR_TYPE && strcmp(temp->val->sval, sval) == 0) ||
             (type == BOOL_TYPE && temp->val->bval == bval))) {
            candidate = temp->val;
        }
        temp = temp->next;
    }
    return candidate;
}

void add_to_const_list(int type, int ival, double dval, char *sval, bool bval) {
    if (find_const(type, ival, dval, sval, bval) == NULL) {
        const_entry *new_entry = (const_entry *) malloc(sizeof(const_entry));
        new_entry->val = create_const(type, ival, dval, sval, bval);
        new_entry->next = NULL;
        if (const_list == NULL) {
            const_list = new_entry;
        } else {
            const_entry *last = const_list;
            while ((last->next != NULL)) last = last->next;
            last->next = new_entry;
        }
        num_of_consts++;
    }
}

constant *create_const(int type, int ival, double dval, char *sval, bool bval) {
    constant *new_cons = (constant *) malloc(sizeof(constant));
    new_cons->type = type;
    new_cons->ival = 0;
    new_cons->dval = 0.0;
    new_cons->sval = NULL;
    new_cons->bval = false;
    char *label = (char *) malloc(sizeof(char) * 10);
    sprintf(label, "const_%d", num_of_consts);
    strncpy(new_cons->name, label, strlen(label));
    switch (type) {
        case INT_TYPE:
            new_cons->ival = ival;
            new_cons->mem_byte = INT_SIZE;
            break;
        case DBL_TYPE:
            new_cons->dval = dval;
            new_cons->mem_byte = DBL_SIZE;
            break;
        case STR_TYPE:
            new_cons->sval = (char *) malloc(sizeof(char) * strlen(sval));
            strncpy(new_cons->sval, sval, strlen(sval));
            new_cons->mem_byte = CHR_SIZE * strlen(sval);
            break;
        case BOOL_TYPE:
            new_cons->bval = bval;
            new_cons->mem_byte = BOOL_SIZE;
            break;
        default:
            break;
    }
    return new_cons;
}

func *find_func(char *name, int owner_class_type) {
    func_entry *temp = func_list;
    while ((temp != NULL) &&
           (strcmp(temp->val->name, name) != 0 ||
            temp->val->owner_class_type != owner_class_type)) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    } else {
        return temp->val;
    }
}

func *add_to_func_list(char *name, char *inf_type, char *owner_class, int inf_num_of_pair_braces) {
    if (find_func(name, get_type_id(owner_class)) == NULL) {
        func_entry *new_entry = (func_entry *) malloc(sizeof(const_entry));
        new_entry->val = create_func(name, inf_type, owner_class, inf_num_of_pair_braces);
        new_entry->next = NULL;
        if (func_list == NULL) {
            func_list = new_entry;
        } else {
            func_entry *last = func_list;
            while (last->next != NULL) last = last->next;
            last->next = new_entry;
        }
        num_of_funcs++;
        return new_entry->val;
    }
    return NULL;
}

func *create_func(char *name, char *inf_type, char *owner_class, int inf_num_of_pair_braces) {
    func *new_func = (func *) malloc(sizeof(func));
    strncpy(new_func->name, name, strlen(name));
    int inf_t = get_type_id(inf_type);
    new_func->inf_type = (inf_t > 0) ? inf_t : 0;
    new_func->inf_num_of_pair_braces = inf_num_of_pair_braces;
    new_func->params = NULL;
    new_func->num_of_parms = 0;
    int type_id = get_type_id(owner_class);
    new_func->owner_class_type = (owner_class != NULL && type_id > 0) ? type_id : 0;
    return new_func;
}

param *create_param(char *name, char *type, int num_of_pair_braces) {
    param *new_param = (param *) malloc(sizeof(param));
    strncpy(new_param->name, name, strlen(name));
    int type_id = get_type_id(type);
    new_param->num_of_pair_braces = num_of_pair_braces;
    new_param->type = type_id;
    new_param->passing = (is_primitive(type_id) && num_of_pair_braces == 0) ? CALL_BY_VALUE : CALL_BY_REFER;
    return new_param;
}

void add_param_to_func(char *name, char *type, int num_of_pair_braces) {
    param *new_param = create_param(name, type, num_of_pair_braces);
    if (curr_func->params == NULL) {
        curr_func->params = new_param;
    } else {
        param *temp = curr_func->params;
        while ((temp->next != NULL) && strcmp(temp->name, new_param->name) != 0) temp = temp->next;
        if (strcmp(temp->name, new_param->name) == 0) {
            curr_func->num_of_parms--;
        } else {
            temp->next = new_param;
        }
    }
    curr_func->num_of_parms++;
}

class *create_class(char *name) {
    class *new_class = (class *) malloc(sizeof(class));
    strncpy(new_class->name, name, strlen(name));
    new_class->type = get_type_id(name);
    new_class->father = 0;
    new_class->kids = NULL;
    new_class->num_of_kids = 0;
    new_class->fields = NULL;
    new_class->num_of_fields = 0;
    new_class->v_table = create_vtable();
    return new_class;
}

class *find_class(char *name) {
    class_entry *temp = class_list;
    while ((temp != NULL) && strcmp(temp->val->name, name) != 0) temp = temp->next;
    if (temp == NULL) {
        return NULL;
    } else {
        return temp->val;
    }
}

void add_to_class_list(char *name) {
    if (find_class(name) == NULL) {
        class_entry *new_entry = (class_entry *) malloc(sizeof(class_entry));
        new_entry->val = create_class(name);
        new_entry->next = NULL;
        if (class_list == NULL) {
            class_list = new_entry;
        } else {
            class_entry *last = class_list;
            while (last->next != NULL) last = last->next;
            last->next = new_entry;
        }
        num_of_classes++;
    }
}

void set_father(class *child, char *father) {
    class *father_class = find_class(father);
    child->father = get_type_id(father);
    kid *new_kid = create_kid(type_list[child->type]);
    if (father_class->kids == NULL) {
        father_class->kids = new_kid;
        father_class->num_of_kids++;
    } else if (find_kid(child->type, father_class->kids) == NULL) {
        kid *last = father_class->kids;
        while (last->next != NULL) last = last->next;
        last->next = new_kid;
        father_class->num_of_kids++;
    }
}

kid *find_kid(int type, kid *list) {
    kid *founded_kid = list;
    while ((founded_kid != NULL) && founded_kid->type != type) founded_kid = founded_kid->next;
    if (founded_kid == NULL) {
        return NULL;
    } else {
        return founded_kid;
    }
}

kid *create_kid(char *type) {
    kid *new_kid = (kid *) malloc(sizeof(kid));
    new_kid->next = NULL;
    new_kid->type = get_type_id(type);
    return new_kid;
}

field *create_field(char *name, char *type, int num_of_pair_braces) {
    field *new_field = (field *) malloc(sizeof(field));
    strncpy(new_field->name, name, strlen(name));
    new_field->type = get_type_id(type);
    new_field->next = NULL;
    new_field->num_of_pair_braces = num_of_pair_braces;
    return new_field;
}

void add_field_to_class(char *name, char *type, int num_of_pair_braces) {
    field *new_field = create_field(name, type, num_of_pair_braces);
    if (curr_class->fields == NULL) {
        curr_class->fields = new_field;
    } else {
        field *temp = curr_class->fields;
        while ((temp->next != NULL) && strcmp(temp->name, new_field->name) != 0) temp = temp->next;
        if (strcmp(temp->name, new_field->name) == 0) {
            curr_class->num_of_fields--;
        } else {
            temp->next = new_field;
        }
    }
    curr_class->num_of_fields++;
}

vtable *create_vtable() {
    vtable *new_vtabe = (vtable *) malloc(sizeof(vtable));
    new_vtabe->list = NULL;
    new_vtabe->size = 0;
    new_vtabe->delta = 0;
    return new_vtabe;
}

vtable_entry *create_vtable_entry(char *name, char *owner_class) {
    vtable_entry *new_vtable_entry = (vtable_entry *) malloc(sizeof(vtable_entry));
    strncpy(new_vtable_entry->name, name, strlen(name));
    new_vtable_entry->owner_class_type = get_type_id(owner_class);
    new_vtable_entry->next = NULL;
    return new_vtable_entry;
}

void add_to_vtable(char *func_name, char *owner_class) {
    vtable_entry *new_entry = create_vtable_entry(func_name, owner_class);
    if (curr_class->v_table->list == NULL) {
        curr_class->v_table->list = new_entry;
    } else {
        vtable_entry *temp = curr_class->v_table->list;
        while ((temp->next != NULL) &&
               (strcmp(temp->name, new_entry->name) != 0 ||
                temp->owner_class_type != new_entry->owner_class_type)) {
            temp = temp->next;
        }
        if (strcmp(temp->name, new_entry->name) == 0 &&
            temp->owner_class_type == new_entry->owner_class_type) {
            curr_class->v_table->size--;
        } else {
            temp->next = new_entry;
        }
    }
    curr_class->v_table->size++;
}

void finalize_fields_and_vtable_of_classes() {
    class_entry *list = class_list;
    while (list != NULL) {
        if (list->val->father != VOID_TYPE) {
            // link father fields
            if (list->val->fields == NULL) {
                list->val->fields = find_class(type_list[list->val->father])->fields;
            } else {
                field *last = list->val->fields;
                while (last->next != NULL) last = last->next;
                last->next = find_class(type_list[list->val->father])->fields;
            }
            // link father vtable
            if (list->val->v_table->list == NULL) {
                list->val->v_table->list = find_class(type_list[list->val->father])->v_table->list;
            } else {
                vtable_entry *last = list->val->v_table->list;
                while (last->next != NULL) last = last->next;
                last->next = find_class(type_list[list->val->father])->v_table->list;
            }
        }
        list = list->next;
    }
    // update numbers
    list = class_list;
    while (list != NULL) {
        if (list->val->father != VOID_TYPE) {
            // reset numbers
            list->val->num_of_fields = 0;
            list->val->v_table->size = 0;
            // counting again
            if (list->val->fields != NULL) {
                field *last = list->val->fields;
                while (last != NULL) {
                    list->val->num_of_fields++;
                    last = last->next;
                }
            }
            if (list->val->v_table->list != NULL) {
                vtable_entry *last = list->val->v_table->list;
                while (last != NULL) {
                    list->val->v_table->size++;
                    last = last->next;
                }
            }
        }
        list = list->next;
    }
}

int get_byte_size(int type) {
    if (type == VOID_TYPE) {
        return NULL_SIZE;
    }
    if (type == INT_TYPE) {
        return INT_SIZE;
    }
    if (type == DBL_TYPE) {
        return DBL_SIZE;
    }
    if (type == BOOL_TYPE) {
        return BOOL_SIZE;
    }
    if (type == ARR_TYPE || is_class_object(type)) {
        return POINTER_SIZE;
    }
    return 0;
}

primitive *create_primitive(char *name, char *type) {
    primitive *new_prim = (primitive *) malloc(sizeof(primitive));
    strncpy(new_prim->name, name, strlen(name));
    new_prim->type = get_type_id(type);
    new_prim->mem_byte = get_byte_size(new_prim->type);
    return new_prim;
}

array *create_array(char *name, char *each_type, int number_of_pair_braces) {
    array *new_arr = (array *) malloc(sizeof(array));
    strncpy(new_arr->name, name, strlen(name));
    new_arr->each_type = get_type_id(each_type);
    new_arr->num_of_pair_braces = number_of_pair_braces;
    new_arr->size = 0;
    new_arr->unit_mem_byte = get_byte_size(number_of_pair_braces > 1 ? ARR_TYPE : new_arr->each_type);
    return new_arr;
}

object *create_object(char *name, char *type) {
    object *new_obj = (object *) malloc(sizeof(object));
    class *owner_class = find_class(type);
    // initials
    strncpy(new_obj->name, name, strlen(name));
    new_obj->type = get_type_id(type);
    // setting vtable
    new_obj->v_table = owner_class->v_table;
    // setting instances
    new_obj->fields = owner_class->fields;
    field *f_mem = owner_class->fields;
    new_obj->mem_byte = POINTER_SIZE; // todo: for vtable ???
    while (f_mem != NULL) {
        new_obj->mem_byte += get_byte_size(f_mem->type);
        f_mem = f_mem->next;
    }
    return new_obj;
}

func *find_func_from_vtable(object *obj, char *func_name) {
    vtable *v_table = obj->v_table;
    vtable_entry *entry = v_table->list;
    int step = 0;
    while (entry != NULL && step < v_table->delta) { // for up casting
        entry = entry->next;
        step++;
    }
    while (entry != NULL && strcmp(entry->name, func_name) != 0) entry = entry->next;
    if (entry != NULL) {
        return find_func(entry->name, entry->owner_class_type);
    }
    return NULL;
}

field *track_fields(object *obj, char *field_name) {
    field *list = obj->fields;
    while (list != NULL && strcmp(list->name, field_name) != 0) list = list->next;
    return list;
}

primitive *find_prime(char *name, prime_entry *list) {
    prime_entry *temp = list;
    while ((temp != NULL) && strcmp(temp->val->name, name) != 0) temp = temp->next;
    if (temp != NULL) {
        return temp->val;
    } else {
        return NULL;
    }
}

array *find_array(char *name, arr_entry *list) {
    arr_entry *temp = list;
    while ((temp != NULL) && strcmp(temp->val->name, name) != 0) temp = temp->next;
    if (temp != NULL) {
        return temp->val;
    } else {
        return NULL;
    }
}

object *find_object(char *name, object_entry *list) {
    object_entry *temp = list;
    while ((temp != NULL) && strcmp(temp->val->name, name) != 0) temp = temp->next;
    if (temp != NULL) {
        return temp->val;
    } else {
        return NULL;
    }
}

void class_up_casting(object *from_class, char *to_class) { // both up-casting & down-casting
    vtable_entry *entry = from_class->v_table->list;
    from_class->v_table->delta = 0;
    int to_class_id = get_type_id(to_class);
    while ((entry != NULL) && entry->owner_class_type != to_class_id) {
        from_class->v_table->delta++;
        entry = entry->next;
    }
}

bool is_your_father (char * father_name, char * child_name){
    class * child = find_class(child_name);
    class * father = find_class(father_name);
    kid * temp = father->kids;
    for (int i = 0; i < father->num_of_kids; ++i) {
        if (temp->type == child->type){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void class_down_casting(object *father_obj, char *child_class_name) {
    if(is_your_father(type_list[father_obj->type], child_class_name)) {
        vtable *final_vtable = find_class(child_class_name)->v_table;
        father_obj->v_table = create_vtable();
        father_obj->v_table->list = final_vtable->list;
        father_obj->v_table->size = final_vtable->size;
    }
}

void show_types(FILE *file) {
    fprintf(file, "type list :\n");
    for (int i = 0; i < num_of_types; ++i) {
        fprintf(file, "%s : %d\n", type_list[i], i);
    }
    fprintf(file, "\n");
}

void show_constants(FILE *file) {
    fprintf(file, "const list (%d):\n", num_of_consts);
    const_entry *con = const_list;
    for (int i = 0; i < num_of_consts; ++i) {
        fprintf(file, " %s : %s : ", con->val->name, type_list[con->val->type]);
        switch (con->val->type) {
            case VOID_TYPE:
                fprintf(file, "null\n");
                break;
            case INT_TYPE:
                fprintf(file, "%d\n", con->val->ival);
                break;
            case DBL_TYPE:
                fprintf(file, "%lf\n", con->val->dval);
                break;
            case STR_TYPE:
                fprintf(file, "%s\n", con->val->sval);
                break;
            case BOOL_TYPE:
                fprintf(file, "%s\n", con->val->bval ? "true" : "false");
                break;
        }
        con = con->next;
    }
    fprintf(file, "\n");
}

void show_functions(FILE *file) {
    fprintf(file, "function list :\n");
    func_entry *fun = func_list;
    for (int i = 0; i < num_of_funcs; ++i) {
        fprintf(file, "%d)\n", i);
        fprintf(file, "  name : %s\n", fun->val->name);
        fprintf(file, "  return type: %s(%d)\n", type_list[fun->val->inf_type], fun->val->inf_num_of_pair_braces);
        fprintf(file, "  parameters (name, type (brace), passing) (%d): ", fun->val->num_of_parms);
        param *par = fun->val->params;
        while (par != NULL) {
            fprintf(file, "(%s, %s(%d), %s) ", par->name, type_list[par->type], par->num_of_pair_braces,
                    (par->passing == CALL_BY_VALUE) ? "by value" : "by reference");
            par = par->next;
        }
        fprintf(file, "\n  status : %s\n",
                (fun->val->owner_class_type == VOID_TYPE) ? "non-member" : type_list[fun->val->owner_class_type]);
        fun = fun->next;
    }
    fprintf(file, "\n");
}

void show_classes(FILE *file) {
    fprintf(file, "class list :\n");
    class_entry *cls = class_list;
    for (int i = 0; i < num_of_classes; ++i) {
        fprintf(file, "%d)\n", i + 1);
        fprintf(file, "  name : %s\n", cls->val->name);
        fprintf(file, "  type : %s\n", type_list[cls->val->type]);
        fprintf(file, "  father : %s\n", type_list[cls->val->father]);
        fprintf(file, "  children (%d) : ", cls->val->num_of_kids);
        kid *child = cls->val->kids;
        while (child != NULL) {
            fprintf(file, "%s ", type_list[child->type]);
            child = child->next;
        }
        fprintf(file, "\n  fields (name, type) (%d) : ", cls->val->num_of_fields);
        field *fil = cls->val->fields;
        while (fil != NULL) {
            fprintf(file, "(%s, %s(%d)) ", fil->name, type_list[fil->type], fil->num_of_pair_braces);
            fil = fil->next;
        }
        fprintf(file, "\n  Vtable (%d) delta (%d) : ", cls->val->v_table->size,
                cls->val->v_table->delta);
        vtable_entry *vtab = cls->val->v_table->list;
        while (vtab != NULL) {
            fprintf(file, "(%s, %s) ", vtab->name, type_list[vtab->owner_class_type]);
            vtab = vtab->next;
        }
        fprintf(file, "\n");
        cls = cls->next;
    }
    fprintf(file, "\n");
}