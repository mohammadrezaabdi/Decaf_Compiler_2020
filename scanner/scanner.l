%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  FILE *out;
%}

/*defenitions*/
CHAR	[a-zA-Z]
DIGIT	[0-9]
WS		[ \r\n\t\r\v\f]+
ID		{CHAR}(_|{CHAR}|{DIGIT}){0,30}
INTEGER	(0[xX]({DIGIT}|[a-fA-F])+)|({DIGIT}+)
DOUBLE	(\.[0-9]+)|([0-9]+\.[0-9]*([Ee]([+-])?[0-9]+)?)
STRING	\"[^\n\"]*\"
BOOL	(true|false)
COMMENT	(\/\*([^*]|\*+[^*\/])*\*+\/)|(\/\/[^\n]*)

%%
{WS}		{/*ignore white spaces*/}
void|int|double|bool|string|class|interface|null|this|extends|implements|for|while|if|else|return|break|new|NewArray|Print|ReadInteger|ReadLine {fprintf(out,"%s\n",yytext);}
"+"|"-"|"*"|"/"|"%"|"<"|"<="|">"|">="|"="|"=="|"!="|"&&"|"||"|"!"|";"|","|"."|"[]"|"["|"]"|"("|")"|"{"|"}" {fprintf(out,"%s\n",yytext);}
{BOOL}		{fprintf(out,"T_BOOLEANLITERAL %s\n",yytext);}
{ID}		{fprintf(out,"T_ID %s\n",yytext);}
{STRING}	{fprintf(out,"T_STRINGLITERAL %s\n",yytext);}
{INTEGER}	{fprintf(out,"T_INTLITERAL %s\n",yytext);}
{DOUBLE}	{fprintf(out,"T_DOUBLELITERAL %s\n",yytext);}
{COMMENT}	{/*ignore comments*/}
. 			{/*undefined input*/
				fprintf(out,"UNDEFIND_TOKEN\n");
				yyterminate();
			}		
%%
int yywrap(){}
int main(int argc, char *argv[]){
    if(argc < 3){
       printf("args error\n");
       return 1;
    }
    yyin = fopen(argv[1],"r");
    out = fopen(argv[2],"w");
	yylex();
	fclose (out);
	printf("successfully scanned\n");
	return 0;
}

