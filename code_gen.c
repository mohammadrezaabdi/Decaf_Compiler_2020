#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code_gen.h"

char *get_directive(int type, bool is_const) {
    if (is_const && type == STR_TYPE) {
        return STR_DIR;
    } else if (type == DBL_TYPE) {
        return DBL_DIR;
    } else {
        return WORD_DIR;
    }
}

char *get_label(entity *ent) {
    char *name = (char *) malloc(sizeof(char) * MAX_TOKEN_SIZE * 2);
    strcpy(name, ent->name);
    if (ent->const_val == NULL) {
        strcat(name, (char *) "_");
        if (ent->type == FUNC_TYPE) {
            strcat(name, type_list[ent->func_val->owner_class_type]);
        } else if (ent->in_class_field_type > 0) {
            strcat(name, type_list[ent->in_class_field_type]);
        } else {
            char str_num[5];
            sprintf(str_num, "%d", ent->scope_id);
            strcat(name, str_num);
        }
    }
    return name;
}

char *get_var_value(entity *ent) {
    int max_digits = 24;
    char *value =(char *) malloc(sizeof(char) * max_digits);
    if (ent->const_val != NULL) {
        switch (ent->type) {
            case INT_TYPE:
                snprintf(value, sizeof(ent->const_val->ival), "%d", ent->const_val->ival);
                break;
            case DBL_TYPE:
                snprintf(value, sizeof(ent->const_val->dval), "%lf", ent->const_val->dval);
                break;
            case STR_TYPE:
                return ent->const_val->sval;
                break;
            case BOOL_TYPE:
                snprintf(value, sizeof(ent->const_val->bval), "%d", ent->const_val->bval);
                break;
        }
    } else {
        sprintf(value, "0");
    }
    return value;
}

void generate_data_part(FILE *file) {
    fprintf(file, DATA_DIR);
    for (int i = 0; i < TABLE_SIZE; ++i) {
        entity *ent = hash_table[i];
        while (ent != NULL) {
            if (ent->type != FUNC_TYPE) {
                fprintf(file, "\n%s: %s %s", get_label(ent), get_directive(ent->type, true), get_var_value(ent));
            }
            ent = ent->next;
        }
    }
    fprintf(file, "\n");
}
