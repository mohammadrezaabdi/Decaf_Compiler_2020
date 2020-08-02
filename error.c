#include "stdio.h"
#include "error.h"

void show_err(int yyparse_out){
        if (yyparse_out == 0) { //TODO This part is based on page 78 of Bison doc; However, there is doubt about correctness and sufficiency of this part.
        }else{
                printf("Parsing Error %d\n", yyparse_out);
                return;
        }
        printf("Parsing completed successfuly.\n");
}
