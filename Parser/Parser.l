%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include "Parser.tab.h"
  FILE *out;
%}

/*definitions*/
/* _PAT means "pattern" in order to distinguish regex patterns from token names mentioned in parser file. */
CHAR	[a-zA-Z]
DIGIT	[0-9]
WS		[ \r\n\t\r\v\f]+
ID_PAT		{CHAR}(_|{CHAR}|{DIGIT})*
INTEGER_PAT	(0[xX]({DIGIT}|[a-fA-F])+)|({DIGIT}+)
DOUBLE_PAT	[0-9]+\.[0-9]*([Ee]([+-])?[0-9]+)?
STRING_PAT	\"[^\n\"]*\"
BOOL_PAT	(true|false)
COMMENT	(\/\*([^*]|\*+[^*\/])*\*+\/)|(\/\/[^\n]*)

%%
{WS}		{/*ignore white spaces*/}
void        {return T_VOID;}
int         {return T_INT;}
double      {return T_DOUBLE;}
bool        {return T_BOOL;}
string      {return T_STRING;}
class       {return T_CLASS;}
interface   {return T_INTERFACE;}
null        {return T_NULL;}
this        {return T_THIS;}
extends     {return T_EXTENDS;}
implements  {return T_IMPLEMENTS;}
for         {return T_FOR;}
while       {return T_WHILE;}
if          {return T_IF;}
else        {return T_ELSE;}
return      {return T_RETURN;}
break       {return T_BREAK;}
new         {return T_NEW;}
NewArray    {return T_NEWARRAY;}
Print       {return T_PRINT;}
ReadInteger {return T_READINTEGER;}
ReadLine    {return T_READLINE;}
"+"|"-"|"*"|"/"|"%"|"<"|"<="|">"|">="|"="|"=="|"!="|"&&"|"||"|"!"|";"|","|"."|"[]"|"["|"]"|"("|")"|"{"|"}"  {
            if (strcmp(yytext, "<=") == 0)
                return T_LEQ;
            else if (strcmp(yytext, ">=") == 0)
                return T_BEQ;
            else if (strcmp(yytext, "==") == 0)
                return T_EQ;
            else if (strcmp(yytext, "!=") == 0)
                return T_NEQ;
            else if (strcmp(yytext, "&&") == 0)
                return T_AND;
            else if (strcmp(yytext, "||") == 0)
                return T_OR;
            else if (strcmp(yytext, "[]") == 0)
                return PAIREDBRACES;
            else
                return yytext[0]; /* Because in this case the matched pattern is a single character that will be directly returned as yylex output.*/
            }
{BOOL_PAT}		{return T_BOOLCONSTANT;}
{ID_PAT}	    {
                    if (yyleng > 31) {
                        yyterminate();
                    } else {
                        return T_ID;
                    }
			    }
{STRING_PAT}	{return T_STRINGCONSTANT;}
{INTEGER_PAT}	{return T_INTCONSTANT;}
{DOUBLE_PAT}	{return T_DOUBLECONSTANT;}
{COMMENT}	{/*ignore comments*/}
. 			{/*undefined input*/
				yyterminate();
			}		
%%

void yyerror(char const *s) {
    fprintf(out, "NO");
}

int yywrap(){}
int main(/*int argc, char *argv[]*/){

    /*#ifdef YYDEBUG
      yydebug = 1;
    #endif*/

    int parsingResult;

    /*if(argc < 3){
       printf("Arguments error\n");
       return 1;
    }
    yyin = fopen(argv[1],"r");
    out = fopen(argv[2],"w");
	//yylex();*/

    yyin = fopen("tests/t001-class1.in", "r");
    out = fopen("out.txt", "w");
	parsingResult = yyparse();
	if (parsingResult == 0) //TODO This part is based on page 78 of Bison doc; However, there is doubt about correctness and sufficiency of this part.
        fprintf(out, "YES");
    //else
        //printf("NO");

	fclose (out);
	//printf("Scanning completed successfully.\n");
	return 0;
}