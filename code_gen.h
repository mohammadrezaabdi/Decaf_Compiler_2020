#ifndef CODE_GEN_H
#define CODE_GEN_H
#include "info.h"
#include "symtab.h"

#define DATA_DIR ".data\n"
#define WORD_DIR ".word"
#define DBL_DIR ".double"
#define STR_DIR ".asciiz"
#define ARR_DIR ".space"
#define TEXT_DIR ".text"

char *get_directive(int type, bool is_const);

char *get_label(entity *ent);

char *get_var_value(entity *ent);

void generate_data_part(FILE *file);

#endif
