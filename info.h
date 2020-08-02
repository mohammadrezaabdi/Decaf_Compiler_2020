#ifndef INFO_H_
#define INFO_H_

#include <stdbool.h>

#define TYPE_NUM 20
#define MAX_TOKEN_SIZE 40
#define MAX_TYPE_NUM 40

// defined_types
#define VOID_TYPE 0 // NULL , VOID
#define INT_TYPE 1
#define DBL_TYPE 2
#define STR_TYPE 3
#define BOOL_TYPE 4
#define ARR_TYPE 5
#define FUNC_TYPE 6

// primitive data types size (per byte)
#define NULL_SIZE 4
#define INT_SIZE 4
#define DBL_SIZE 8
#define CHR_SIZE 1
#define BOOL_SIZE 4
#define POINTER_SIZE 4

// how parameter is passed
#define CALL_BY_VALUE 1
#define CALL_BY_REFER 2

typedef struct constant {
    char name[MAX_TOKEN_SIZE];
    int type;
    int ival;
    double dval;
    char *sval;
    bool bval;
    int mem_byte;
} constant;

typedef struct primitive {
    char name[MAX_TOKEN_SIZE];
    int type;
    int mem_byte;
} primitive;

typedef struct object {
    char name[MAX_TOKEN_SIZE];
    int type;
    struct field *fields;
    int num_of_fields;
    struct vtable *v_table;
    int mem_byte;
} object;

typedef struct array {
    char name[MAX_TOKEN_SIZE];
    int each_type;
    int size;
    int num_of_pair_braces; // for 2D arrays types
    int unit_mem_byte;
} array;

typedef struct param {
    char name[MAX_TOKEN_SIZE];
    int type; // parameter type
    int num_of_pair_braces; // for array types
    int passing; // value or reference
    struct param *next;
} param;

typedef struct func {
    char name[MAX_TOKEN_SIZE];
    int inf_type; // return type
    int inf_num_of_pair_braces; // for array types
    param *params;
    int num_of_parms;
    int owner_class_type; // if member func_val -> = (owner type) else = 0
} func;

typedef struct vtable_entry {
    char name[MAX_TOKEN_SIZE];
    int owner_class_type;
    struct vtable_entry *next;
} vtable_entry;

typedef struct vtable {
    struct vtable_entry *list;
    int size;
    int delta; // for class casting
} vtable;

typedef struct field {
    char name[MAX_TOKEN_SIZE];
    int type;
    int num_of_pair_braces; // for array types
    struct field *next;
} field;

typedef struct kid {
    int type;
    struct kid *next;
} kid;

typedef struct class {
    char name[MAX_TOKEN_SIZE];
    int type;
    int father; // type of father
    struct kid *kids; // all types of kids
    int num_of_kids; // number of kids
    struct field *fields;
    int num_of_fields;
    struct vtable *v_table;
} class;

typedef struct class_entry {
    struct class *val;
    struct class_entry *next;
} class_entry;

typedef struct const_entry {
    struct constant *val;
    struct const_entry *next;
} const_entry;

typedef struct func_entry {
    struct func *val;
    struct func_entry *next;
} func_entry;

typedef struct object_entry {
    struct object *val;
    struct object_entry *next;
} object_entry;

typedef struct prime_entry {
    struct primitive *val;
    struct prime_entry *next;
} prime_entry;

typedef struct arr_entry {
    struct array *val;
    struct arr_entry *next;
} arr_entry;

char **type_list;
int num_of_types;
const_entry *const_list;
int num_of_consts;
func_entry *func_list;
int num_of_funcs;
class_entry *class_list;
int num_of_classes;
func *curr_func;
bool func_decl;
bool func_scope;
class *curr_class;
bool class_decl;

void init_lists();

bool is_primitive(int type);

bool is_class_object(int type);

constant *create_const(int type, int ival, double dval, char *sval, bool bval);

func *create_func(char *name, char *inf_type, char *owner_class, int inf_num_of_pair_braces);

param *create_param(char *name, char *type, int num_of_pair_braces);

class *create_class(char *name);

field *create_field(char *name, char *type, int num_of_pair_braces);

kid *create_kid(char *type);

vtable *create_vtable();

vtable_entry *create_vtable_entry(char *name, char *owner_class);

object *create_object(char *name, char *type);

primitive *create_primitive(char *name, char *type);

array *create_array(char *name, char *each_type, int number_of_pair_braces);

int get_type_id(char *name);

int get_byte_size(int type);

constant *find_const(int type, int ival, double dval, char *sval, bool bval);

func *find_func(char *name, int owner_class_type);

func *find_func_from_vtable(object *obj, char *func_name);

field *track_fields(object *obj, char *field_name);

class *find_class(char *name);

kid *find_kid(int type, kid *list);

primitive *find_prime(char *name, prime_entry *list);

array *find_array(char *name, arr_entry *list);

object *find_object(char *name, object_entry *list);

void add_to_type_list(char *name);

void add_to_const_list(int type, int ival, double dval, char *sval, bool bval);

func *add_to_func_list(char *name, char *inf_type, char *owner_class, int inf_num_of_pair_braces);

void add_param_to_func(char *name, char *type, int num_of_pair_braces);

void add_to_class_list(char *name);

void add_to_vtable(char *func_name, char *owner_class);

void add_field_to_class(char *name, char *type, int num_of_pair_braces);

void set_father(class *child, char *father);

void finalize_fields_and_vtable_of_classes();

void class_up_casting(object *from_class, char *to_class);

void class_down_casting(object *father_obj, char *child_class_name);

bool is_your_father(char *father_name, char *child_name);

void show_types(FILE *file);

void show_constants(FILE *file);

void show_functions(FILE *file);

void show_classes(FILE *file);

#endif
