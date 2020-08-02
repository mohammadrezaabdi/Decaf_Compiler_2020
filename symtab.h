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

typedef struct entity { // -> func_val , variable , class
    char name[MAX_TOKEN_SIZE];
    int scope; // declaration is in which scope
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

entity **hash_table;
int curr_scope;
entity *curr_entity;

// Function Declarations
void init_hash_table(); // initialize hash table
unsigned int hash(char *key); // hash func_val
entity * create_entity(char *name, loc *location, int scope, char *type, int num_of_braces, char *owner_class, bool is_const,int ival,double dval, char *sval, bool bval);
void add_to_table(entity *new_entity);
void insert_local_var(char *name, int line, int col, char *type, int num_of_braces);
void insert_field(char *name, int line, int col, char *type, int num_of_braces, char *owner_class);
void insert_param(char *name, int line, int col, char *type, int num_of_braces);
void reference(char *name, int line, int col);
loc *create_loc(int line, int col);
entity *lookup(char *name) ; // search for entry
void show_symbol_table(FILE *file); // print table in file for debugging
void hide_scope(); // hide the current scope
void make_scope(); // go to next scope
void reset_current_entity_type();
void chain_reference_tracking_entity(char *field_name, int line, int col, bool is_method);
void adapt_symbol_table_to_tac(); // todo in future
int get_allocation_bytes(int line, int col); // todo in future

#endif
