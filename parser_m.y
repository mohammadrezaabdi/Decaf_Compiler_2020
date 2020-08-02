//for mohammadreza: copy this file and modify the copied version

//TODO: TAC //start by amirabbas
//TODO: multi-pass parsing ?
//TODO: symbol table & scoping //mohammadreza -> spaghetti stack
//TODO: type casting //amirabbas 4 itod dtoi itob btoi
//TODO: type checking ?
//TODO: mips code generation ?
//TODO: register allocation
//TODO: inheritance (OP)

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "info.c"
    #include "symtab.c"
    #include "error.c"
    #include "lex.yy.c"
    void yyerror(char const *s);
    #define YYDEBUG 1
    char * delim = (char *) " []();+-*/%!<>.,;={}";
%}
    /* This part is related to semantic analysis: */
    %union {
        int intLiteral;
        double doubleLiteral;
        bool booleanLiteral;
        char *stringLiteral;

    }

    /* Operator tokens and entity: */
    %expect 1
    %left   '='
    %left   T_OR
    %left   T_AND
    %left   T_EQ T_NEQ
    %left   '<' '>' T_LEQ T_BEQ
    %left   '+' '-'
    %left   '*' '/' '%'
    %left   '!' T_UNARYMINUS
    %left   '[' '.'
    %token  PAIREDBRACES
    %left   '('
    %token  <stringLiteral> T_ID T_VOID

    /* Keyword tokens: */
    %token  T_CLASS T_INTERFACE T_EXTENDS T_IMPLEMENTS T_FOR T_WHILE T_IF T_ELSE T_RETURN T_BREAK T_NEW T_NEWARRAY T_PRINT T_READINTEGER T_READLINE

    /* Constant tokens: */
    %token  <intLiteral> T_INTCONSTANT
    %token  <doubleLiteral> T_DOUBLECONSTANT
    %token  <stringLiteral> T_STRINGCONSTANT T_INT T_DOUBLE T_BOOL T_STRING T_NULL T_THIS
    %token  <booleanLiteral> T_BOOLCONSTANT

    %type <stringLiteral> type

%%
    /* Note: "cs" prefix before name of a non-terminal means a comma separated group of that non-terminal.*/
    /* Note: "opt" prefix before name of a non-terminal means Opttional(zero or one passs) existence of that non-terminal.*/
program         :     decl decls
                ;
decls           :     /*empty*/
                |     decl decls
                ;
decl            :     variableDecl
                |     functionDecl
                |     classDecl
                |     interfaceDecl
                ;
variableDecls   :     /*empty*/
                |     variableDecls variableDecl
                ;
variableDecl    :     variable ';'
                ;
variable        :     type T_ID {
                                  switch(pass){
                                    case LEVEL_2:
                                      if(class_decl && !func_scope){
                                        add_field_to_class(get_element($2, 0, delim), get_element($1, 0, delim), get_num_of_pair_braces($1));
                                      }
                                      if(func_decl){
                                        add_param_to_func(get_element($2, 0, delim), get_element($1, 0, delim), get_num_of_pair_braces($1));
                                      }
                                      break;
                                    case LEVEL_3:
                                      if (class_decl && !func_scope && curr_scope == 1){
                                        insert_field(get_element($2, 0, delim), T_ID_lineo, T_ID_colno, get_element($1, 0, delim), get_num_of_pair_braces($1), curr_class->name);
                                      } else if (func_decl){
                                        insert_param(get_element($2, 0, delim), T_ID_lineo, T_ID_colno, get_element($1, 0, delim), get_num_of_pair_braces($1));
                                      } else {
                                        insert_local_var(get_element($2, 0, delim), T_ID_lineo, T_ID_colno, get_element($1, 0, delim), get_num_of_pair_braces($1));
                                      }
                                      break;
                                  }
                                }
                ;
type            :     T_INT               {$$ = $1;}
                |     T_DOUBLE            {$$ = $1;}
                |     T_BOOL              {$$ = $1;}
                |     T_STRING            {$$ = $1;}
                |     T_ID                {$$ = $1;}
                |     type PAIREDBRACES   {$$ = $1;}
                ;
functionDecl    :     type T_ID {
                                  func_decl = true;
                                  func_scope = true;
                                  switch(pass){
                                    case LEVEL_2:
                                      curr_func = add_to_func_list(get_element($2, 0, delim), get_element($1, 0, delim), (curr_class!=NULL) ? curr_class->name : NULL, get_num_of_pair_braces($1));
                                      if(class_decl){
                                        add_to_vtable(get_element($2, 0, delim), curr_class->name);
                                      }
                                      break;
                                    case LEVEL_3:
                                      curr_func = find_func(get_element($2, 0, delim), get_type_id(curr_class->name));
                                      break;
                                  }
                                }
                      '(' formals ')' {
                                        func_decl = false;
                                        switch(pass){
                                          case LEVEL_2:
                                            curr_func = NULL;
                                            break;
                                        }
                                      }
                      stmtBlock       {
                                        func_scope = false;
                                      }

                |     T_VOID T_ID {
                                    func_decl = true;
                                    func_scope = true;
                                    switch(pass){
                                      case LEVEL_2:
                                        curr_func = add_to_func_list(get_element($2, 0, delim), get_element($1, 0, delim), (curr_class!=NULL) ? curr_class->name : NULL, get_num_of_pair_braces($1));
                                        if(class_decl){
                                          add_to_vtable(get_element($2, 0, delim), curr_class->name);
                                        }
                                        break;
                                      case LEVEL_3:
                                        curr_func = find_func(get_element($2, 0, delim), get_type_id(curr_class->name));
                                        break;
                                    }
                                  }
                      '(' formals ')'{
                                        func_decl = false;
                                          switch(pass){
                                            case LEVEL_2:
                                            curr_func = NULL;
                                            break;
                                          }
                                        }
                       stmtBlock        {
                                          func_scope = false;
                                        }
                ;
formals         :     /*empty*/
                |     variable csVariable
                ;
csVariable      :     /*empty*/
                |     csVariable ',' variable
                ;
classDecl       :     T_CLASS T_ID  {
                                      class_decl = true;
                                      switch(pass){
                                        case LEVEL_1:
                                          add_to_type_list($2);
                                          add_to_class_list($2);
                                          break;
                                        case LEVEL_2:
                                          curr_class = find_class($2);
                                          break;
                                        case LEVEL_3:
                                          curr_class = find_class($2);
                                          break;
                                      }
                                    }
                      optExt optImp '{' fields '}' {
                                                      class_decl = false;
                                                      switch(pass){
                                                        case LEVEL_2:
                                                          curr_class = NULL;
                                                          break;
                                                        case LEVEL_3:
                                                          curr_class = NULL;
                                                          break;
                                                      }
                                                    }
                ;
optExt          :     /*empty*/
                |     T_EXTENDS T_ID  {
                                        switch(pass){
                                          case LEVEL_2:
                                            set_father(curr_class, $2);
                                            break;
                                        }
                                      }
                ;
optImp          :     /*empty*/
                |     T_IMPLEMENTS T_ID csID
                ;
csID            :     /*empty*/
                |     csID ',' T_ID
                ;
fields          :     /*empty*/
                |     field fields
                ;
field           :     variableDecl
                |     functionDecl
                ;
interfaceDecl   :     T_INTERFACE T_ID '{' prototypes '}'
                ;
prototypes      :     /*empty*/
                |     prototype prototypes
                ;
prototype       :     type T_ID '(' formals ')' ';'
                |     T_VOID T_ID '(' formals ')' ';'
                ;
stmtBlock       :     '{' variableDecls stmts '}'
                ;
stmts           :     /*empty*/
                |     stmt stmts
                ;
stmt            :     optExpr ';'
                |     ifStmt
                |     whileStmt
                |     forStmt
                |     breakStmt
                |     returnStmt
                |     printStmt
                |     stmtBlock
                ;
optExpr         :     /*empty*/
                |     expr
                ;
ifStmt          :     T_IF '(' expr ')' stmt optElse
                ;
optElse         :     /*empty*/
                |     T_ELSE stmt
                ;
whileStmt       :     T_WHILE '(' expr ')' stmt
                ;
forStmt         :     T_FOR '(' optExpr ';' expr ';' optExpr ')' stmt
                ;
returnStmt      :     T_RETURN optExpr ';'
                ;
breakStmt       :     T_BREAK ';'
                ;
printStmt       :     T_PRINT '(' expr csExpr ')' ';'
                ;
csExpr          :     /*empty*/
                |     csExpr ',' expr
                ;
expr            :     lvalue '=' expr
                |     constant
                |     lvalue
                |     T_THIS  {
                                switch(pass){
                                  case LEVEL_3:
                                    if (class_decl){
                                     curr_entity = create_entity((char * ) "_this", create_loc(T_ID_lineo, T_ID_colno), curr_scope, curr_class->name, 0, curr_class->name, false, 0, 0.0, NULL, false);
                                    }
                                    break;
                                }
                              }
                |     call
                |     '(' expr ')'
                |     expr '+' expr
                |     expr '-' expr
                |     expr '*' expr
                |     expr '/' expr
                |     expr '%' expr
                |     '-' expr %prec T_UNARYMINUS
                |     expr '<' expr
                |     expr T_LEQ expr
                |     expr '>' expr
                |     expr T_BEQ expr
                |     expr T_EQ expr
                |     expr T_NEQ expr
                |     expr T_AND expr
                |     expr T_OR expr
                |     '!' expr
                |     T_READINTEGER '(' ')'
                |     T_READLINE '(' ')'
                |     T_NEW T_ID  {
                                    switch(pass){
                                      case LEVEL_3: //TODO memory allocation handling in tac
                                        class_down_casting(curr_entity->obj_val, get_element($2, 0, delim));
                                    }
                                  }
                |     T_NEWARRAY  {
                                    //TODO memory allocation handling in tac
                                  }
                      '(' expr ',' type ')'
                ;
lvalue          :     T_ID                {
                                            switch(pass){
                                              case LEVEL_3:
                                                reference(get_element($1, 0, delim), T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          }
                |     expr '.' T_ID       {
                                            switch(pass){
                                              case LEVEL_3:
                                                chain_reference_tracking_entity(get_element($3, 0, delim), T_ID_lineo, T_ID_colno, false);
                                                break;
                                              }
                                          }
                |     expr '[' expr ']'
                ;
call            :     T_ID                {
                                            switch(pass){
                                              case LEVEL_3:
                                                reference_to_function(get_element($1, 0, delim), T_ID_lineo, T_ID_colno, (curr_class!=NULL) ? curr_class->name : NULL);
                                                break;
                                            }
                                          }
                      '(' actuals ')'
                |     expr '.' T_ID       {
                                            switch(pass){
                                              case LEVEL_3:
                                                chain_reference_tracking_entity(get_element($3, 0, delim), T_ID_lineo, T_ID_colno, true);
                                                break;
                                            }
                                          }
                      '(' actuals ')'
                ;
actuals         :     /*empty*/
                |     expr csExpr
                ;
constant        :     T_INTCONSTANT       {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(INT_TYPE, $1, 0.0, NULL, false);
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(INT_TYPE, $1, 0.0, NULL,false)->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          }
                |     T_DOUBLECONSTANT    {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(DBL_TYPE, 0, $1, NULL, false);
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(DBL_TYPE, 0, $1, NULL,false)->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          }
                |     T_BOOLCONSTANT      {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(BOOL_TYPE, 0, 0.0, NULL, $1);
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(BOOL_TYPE, 0, 0.0, NULL,$1)->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          }
                |     T_STRINGCONSTANT    {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(STR_TYPE, 0, 0.0, $1, false);
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(STR_TYPE, 0, 0.0, $1, false)->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          }
                |     T_NULL
                ;
%%
int main(int argc, char *argv[]){
    if(argc < 3){
       printf("Arguments error\n");
       return 1;
    }
    //yydebug = 1;
    init_lists();
    input_file_path = argv[1];
    FILE * info_file = fopen ("status.txt","w");
    FILE * sym_file = fopen ("symbol_table.txt","w");
    yyin = fopen(input_file_path, "r");
    show_err(yyparse());
    show_types(info_file);
    show_constants(info_file);
    show_functions(info_file);
    show_classes(info_file);
    show_symbol_table(sym_file);
    fclose(info_file);
    fclose(sym_file);
  	return 0;
}

void yyerror(char const *s) {
    //todo: error handling
}
