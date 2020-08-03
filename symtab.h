#ifndef SYMTAB_H_   /* Include guard */
#define SYMTAB_H_

#include <stdbool.h>
#include "info.h"

#define TABLE_SIZE 211

typedef struct loc { // location in text
    int line;
    int col;
    struct loc *next;
} loc;

typedef struct scope {
    int id;
    struct loc *start;
    struct loc *end;
    struct scope *father;
    struct scope *next;
} scope;

typedef struct entity { // -> func_val , variable , class
    char name[MAX_TOKEN_SIZE];
    int scope_id; // declaration is in which scope_id
    loc *locations; // locations of code lines
    int type; // type of statement is encoding by integer number
    int in_class_field_type; // if (is field of class) = class type else -1

    constant *const_val;
    primitive *prime_val;
    object *obj_val;
    array *arr_val;
    func *func_val;

    // pointer to next item in the hash table
    struct entity *next;
} entity;

typedef struct symbol_entry {
    int colno;
    struct entity *val;
    struct symbol_entry *next;
} symbol_entry;

typedef struct entity_entry {
    struct entity *val;
    struct entity_entry *prev;
} entity_entry;

typedef struct entity_stack { // for saving prev previous reference of entities
    entity_entry *root;
    entity_entry *pointer;
} entity_stack;

scope *curr_scope;
scope *scope_list;
int last_scope_id;
entity **hash_table;
entity *curr_entity;
entity_stack *entity_heap;
symbol_entry **symbol_table;
bool is_this;
int curr_class_scope;

void init_scope_list();

scope *create_scope(int id, loc *start, scope *parent);

bool is_father(int child_id, int father_id);

scope *find_scope_by_id(int id);

scope *find_scope_by_start_loc(int start_line, int start_col);

scope *find_scope_by_end_loc(int end_line, int end_col);

void move_out_from_scope(int line, int col); // hide the current scope_id

void move_in_new_scope(int line, int col); // go to next scope_id

void init_hash_table(); // initialize hash table

unsigned int hash(char *key); // hash func_val

entity *
create_entity(char *name, loc *location, int scope, char *type, int num_of_braces, char *owner_class, bool is_const,
              int ival, double dval, char *sval, bool bval);

void add_to_hash_table(entity *new_entity);

void insert_local_var(char *name, int line, int col, char *type, int num_of_braces);

void insert_field(char *name, int line, int col, char *type, int num_of_braces, char *owner_class);

void insert_param(char *name, int line, int col, char *type, int num_of_braces);

void reference(char *name, int line, int col);

loc *create_loc(int line, int col);

entity *lookup(char *name); // search for entry

void show_hash_table(FILE *file); // print table in file for debugging

void show_scopes(FILE *file);

void reset_current_entity_type();

void chain_reference_tracking_entity(char *field_name, int line, int col, bool is_method);

void adapt_symbol_table_to_tac(int last_line);

void add_to_symbol_table(entity *ent);

symbol_entry *create_symbol_entry(entity *ent, int colno);

entity *get_from_symbol_table(int line, int col);

void push_entity(entity *ent);

entity *pop_entity();

entity_entry *create_entity_entry(entity *ent);

void assign_down_casting(char *type);

int get_allocation_bytes(int line, int col);

void show_symbol_table(FILE *file, int last_line);

void reference_to_function(char *name, int line, int col, char *owner_class);

#endif
