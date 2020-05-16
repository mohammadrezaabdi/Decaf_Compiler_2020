%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  
  bool doesValidFlag = true;
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
COMMENT	(\/\*([^*]|\*+[^*\/])*\*+\/)|(\/\/(.*))

%%
{WS}		{/*ignore white spaces*/}
void|int|double|bool|string|class|interface|null|this|extends|implements|for|while|if|else|return|break|new|NewArray|Print|ReadInteger|ReadLine {printf("%s\n",yytext);}
"+"|"-"|"*"|"/"|"%"|"<"|"<="|">"|">="|"="|"=="|"!="|"&&"|"||"|"!"|";"|","|"."|"[]"|"["|"]"|"("|")"|"{"|"}" {printf("%s\n",yytext);} 
{BOOL}		{printf("T_BOOLEANLITERAL %s\n",yytext);}
{ID}		{printf("T_ID %s\n",yytext);}
{STRING}	{printf("T_STRINGLITERAL %s\n",yytext);}
{INTEGER}	{printf("T_INTLITERAL %s\n",yytext);}
{DOUBLE}	{printf("T_DOUBLELITERAL %s\n",yytext);}
{COMMENT}	{/*ignore comments*/}
. 			{/*undefined input*/
				printf("UNDEFIND_TOKEN\n");
				doesValidFlag = false;
				yyterminate();
			}		
%%
int yywrap(){}
int main(){
	
	while (1){
		if(!doesValidFlag){
		  yyterminate();
		  return 0; 
		}
		yylex();
	}
	return 0;
}

