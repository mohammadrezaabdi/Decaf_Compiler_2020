%{
  #include "Parser.tab.h"
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
                        printf("lexical error: identifier size over 31\n");
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
        printf("lexical error: undefined input\n");
				yyterminate();
			}
%%

int yywrap(void){return 1;}
