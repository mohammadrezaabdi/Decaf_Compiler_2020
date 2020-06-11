%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "lex.yy.c"
    void yyerror(char const *s);
    FILE *out;
    #define YYDEBUG 1
%}
    /* This part is related to semantic analysis: */
    %union {
        int intLiteral;
        double doubleLiteral;
        bool booleanLiteral;
        char *stringLiteral;
        //TODO Some datatype is needed for pointer to symbol table entries.
    }

    /* Operator tokens and ID: */
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
    %token  <symbolTablePtr> T_ID

    /* Keyword tokens: */
    %token  T_VOID T_INT T_DOUBLE T_BOOL T_STRING T_CLASS T_INTERFACE T_NULL T_THIS T_EXTENDS T_IMPLEMENTS
            T_FOR T_WHILE T_IF T_ELSE T_RETURN T_BREAK T_NEW T_NEWARRAY T_PRINT T_READINTEGER T_READLINE

    /* Constant tokens: */
    %token  <intLiteral> T_INTCONSTANT
    %token  <doubleLiteral> T_DOUBLECONSTANT
    %token  <stringLiteral> T_STRINGCONSTANT
    %token  <booleanLiteral> T_BOOLCONSTANT;
%%
    /* Note: "cs" prefix before name of a non-terminal means a comma separated group of that non-terminal.*/
    /* Note: "opt" prefix before name of a non-terminal means Opttional(zero or one times) existence of that non-terminal.*/
       program:     decl decls
        ;decls:     /*empty*/ | decl decls
         ;decl:     variableDecl | functionDecl | classDecl | interfaceDecl
;variableDecls:     /*empty*/ | variableDecls variableDecl
 ;variableDecl:     variable ';'
     ;variable:     type T_ID
         ;type:     T_INT | T_DOUBLE | T_BOOL | T_STRING | T_ID | type PAIREDBRACES
 ;functionDecl:     type T_ID '(' formals ')' stmtBlock | T_VOID T_ID '(' formals ')' stmtBlock
      ;formals:     /*empty*/ | variable csVariable
   ;csVariable:     /*empty*/ | csVariable ',' variable
    ;classDecl:     T_CLASS T_ID optExt optImp '{' fields '}'
       ;optExt:     /*empty*/ | T_EXTENDS T_ID
       ;optImp:     /*empty*/ | T_IMPLEMENTS T_ID csID
         ;csID:     /*empty*/ | csID ',' T_ID
       ;fields:     /*empty*/ | field fields
        ;field:     variableDecl | functionDecl
;interfaceDecl:     T_INTERFACE T_ID '{' prototypes '}'
   ;prototypes:     /*empty*/ | prototype prototypes
    ;prototype:     type T_ID '(' formals ')' ';' | T_VOID T_ID '(' formals ')' ';'
    ;stmtBlock:     '{' variableDecls stmts '}'
        ;stmts:     /*empty*/ | stmt stmts
         ;stmt:     optExpr ';' | ifStmt | whileStmt | forStmt | breakStmt
                    | returnStmt | printStmt | stmtBlock
      ;optExpr:     /*empty*/ | expr
       ;ifStmt:     T_IF '(' expr ')' stmt optElse
      ;optElse:     /*empty*/ | T_ELSE stmt
    ;whileStmt:     T_WHILE '(' expr ')' stmt
      ;forStmt:     T_FOR '(' optExpr ';' expr ';' optExpr ')' stmt
   ;returnStmt:     T_RETURN optExpr ';'
    ;breakStmt:     T_BREAK ';'
    ;printStmt:     T_PRINT '(' expr csExpr ')' ';'
       ;csExpr:     /*empty*/ | csExpr ',' expr
         ;expr:     lvalue '=' expr | constant | lvalue | T_THIS | call | '(' expr ')'
                    | expr '+' expr | expr '-' expr | expr '*' expr | expr '/' expr
                    | expr '%' expr | '-' expr %prec T_UNARYMINUS
                    | expr '<' expr | expr T_LEQ expr
                    | expr '>' expr | expr T_BEQ expr | expr T_EQ expr | expr T_NEQ expr
                    | expr T_AND expr | expr T_OR expr | '!' expr | T_READINTEGER '(' ')'
                    | T_READLINE '(' ')' | T_NEW T_ID | T_NEWARRAY '(' expr ',' type ')'
       ;lvalue:     T_ID | expr '.' T_ID | expr '[' expr ']'
         ;call:     T_ID '(' actuals ')' | expr '.' T_ID '(' actuals ')'
      ;actuals:     /*empty*/ | expr csExpr
     ;constant:     T_INTCONSTANT | T_DOUBLECONSTANT | T_BOOLCONSTANT | T_STRINGCONSTANT | T_NULL
%%
int main(int argc, char *argv[]){
    int parsingResult;
    if(argc < 3){
       printf("Arguments error\n");
       return 1;
    }
  //  yydebug = 1; // for debuging
    yyin = fopen(argv[1],"r");
    out = fopen(argv[2],"w");
  	parsingResult = yyparse();
  	if (parsingResult == 0) //TODO This part is based on page 78 of Bison doc; However, there is doubt about correctness and sufficiency of this part.
        fprintf(out, "YES");
    else{
        printf("NO");
        return 0;
      }

  	fclose (out);
	  printf("parsing completed successfully.\n");
  	return 0;
}

void yyerror(char const *s) {
    fprintf(out, "NO");
}
