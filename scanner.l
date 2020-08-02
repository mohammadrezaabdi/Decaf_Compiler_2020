%{
  #include "parser_m.tab.h"
  #include "info.h"
  #include "symtab.h"
  int lineno = 1;
  int colno = 1;
  int T_ID_lineo;
  int T_ID_colno;
  int pass = 1;
  #define PASS_NUM 3
  #define LEVEL_1 1
  #define LEVEL_2 2
  #define LEVEL_3 3
  #define LEVEL_4 4
  char * input_file_path;
%}

/*definitions*/
/* _PAT means "pattern" in order to distinguish regex patterns from token names mentioned in parser file. */
CHAR	[a-zA-Z]
DIGIT	[0-9]
WS		[ \r\t\r\v\f]+
ENTER \n
ID_PAT		{CHAR}(_|{CHAR}|{DIGIT})*
INTEGER_PAT	(0[xX]({DIGIT}|[a-fA-F])+)|({DIGIT}+)
DOUBLE_PAT	[0-9]+\.[0-9]*([Ee]([+-])?[0-9]+)?
STRING_PAT	\"[^\n\"]*\"
BOOL_PAT	(true|false)
COMMENT	(\/\*([^*]|\*+[^*\/])*\*+\/)|(\/\/[^\n]*)

%%
{ENTER}       {//printf("l %d - c %d\n", lineno, colno);
              lineno++; colno = 1;
              }
{WS}	       	{colno += yyleng; /*ignore white spaces*/}
void          {colno += yyleng; yylval.stringLiteral=yytext; return T_VOID;}
int           {colno += yyleng; yylval.stringLiteral=yytext; return T_INT;}
double        {colno += yyleng; yylval.stringLiteral=yytext; return T_DOUBLE;}
bool          {colno += yyleng; yylval.stringLiteral=yytext; return T_BOOL;}
string        {colno += yyleng; yylval.stringLiteral=yytext; return T_STRING;}
class         {colno += yyleng; return T_CLASS;}
interface     {colno += yyleng; return T_INTERFACE;}
null          {colno += yyleng; return T_NULL;}
this          {colno += yyleng; return T_THIS;}
extends       {colno += yyleng; return T_EXTENDS;}
implements    {colno += yyleng; return T_IMPLEMENTS;}
for           {colno += yyleng; return T_FOR;}
while         {colno += yyleng; return T_WHILE;}
if            {colno += yyleng; return T_IF;}
else          {colno += yyleng; return T_ELSE;}
return        {colno += yyleng; return T_RETURN;}
break         {colno += yyleng; return T_BREAK;}
new           {colno += yyleng; return T_NEW;}
NewArray      {colno += yyleng; return T_NEWARRAY;}
Print         {colno += yyleng; return T_PRINT;}
ReadInteger   {colno += yyleng; return T_READINTEGER;}
ReadLine      {colno += yyleng; return T_READLINE;}
"+"           {colno += yyleng; return yytext[0];}
"-"           {colno += yyleng; return yytext[0];}
"*"           {colno += yyleng; return yytext[0];}
"/"           {colno += yyleng; return yytext[0];}
"%"           {colno += yyleng; return yytext[0];}
"<"           {colno += yyleng; return yytext[0];}
"<="          {colno += yyleng; return T_LEQ;}
">"           {colno += yyleng; return yytext[0];}
">="          {colno += yyleng; return T_BEQ;}
"="           {colno += yyleng; return yytext[0];}
"=="          {colno += yyleng; return T_EQ;}
"!="          {colno += yyleng; return T_NEQ;}
"&&"          {colno += yyleng; return T_AND;}
"||"          {colno += yyleng; return T_OR;}
"!"           {colno += yyleng; return yytext[0];}
";"           {colno += yyleng; return yytext[0];}
","           {colno += yyleng; return yytext[0];}
"."           {colno += yyleng; return yytext[0];}
"[]"          {colno += yyleng; return PAIREDBRACES;}
"["           {colno += yyleng; return yytext[0];}
"]"           {colno += yyleng; return yytext[0];}
"("           {colno += yyleng; return yytext[0];}
")"           {colno += yyleng; return yytext[0];}
"{"           {colno += yyleng; make_scope(); return yytext[0];}
"}"           {colno += yyleng; hide_scope(); return yytext[0];}
{BOOL_PAT}    {T_ID_lineo = lineno; T_ID_colno = colno; colno += yyleng; yylval.booleanLiteral = (bool) (strcmp(yytext, (char *) "true") == 0); return T_BOOLCONSTANT;}
{ID_PAT}	    {
                if (yyleng > 31) {
                  printf("lexical error: identifier size over 31\n");
                  yyterminate();
                } else {
                  T_ID_lineo = lineno;
                  T_ID_colno = colno;
                  yylval.stringLiteral=yytext;
                  colno += yyleng;
                  return T_ID;
                }
			        }
{STRING_PAT}	{T_ID_lineo = lineno; T_ID_colno = colno; colno += yyleng; yylval.stringLiteral=yytext; return T_STRINGCONSTANT;}
{INTEGER_PAT}	{T_ID_lineo = lineno; T_ID_colno = colno; colno += yyleng; yylval.intLiteral=atoi(yytext); return T_INTCONSTANT;}
{DOUBLE_PAT}	{T_ID_lineo = lineno; T_ID_colno = colno; colno += yyleng; yylval.doubleLiteral=atof(yytext); return T_DOUBLECONSTANT;}
{COMMENT}   	{colno += yyleng; /*ignore comments*/}
. 			      {/*undefined input*/
                printf("lexical error: undefined input\n");
				        yyterminate();
			        }
<<EOF>>       {
                // multi-pass parsing levels:
                // level 1 : find out just types & constants & builting raw class
                // level 2 : making function list & setting classes hieracy
                // level 3 : making symbol table
                // level 4 : tac generation
                if(pass < PASS_NUM){
                  if(pass == LEVEL_2){
                    // setting hieracy of classes
                    finalize_fields_and_vtable_of_classes();
                    // starting hash_table
                    init_hash_table();
                  }
                  yyin = fopen( input_file_path, "r" );
                  yy_switch_to_buffer( yy_create_buffer( yyin, YY_BUF_SIZE ));
                  lineno = 1;
                  colno = 1;
                  pass++;
                }
                else{
                  yyterminate();
                }
              }
%%

int yywrap(void){return 1;}

char* get_element(char * string, int index, char *delims){
  char * token = strtok(string, delims);
   while( token != NULL && index > 0 ) {
      token = strtok(NULL, delims);
      index--;
   }
   return token;
}

int get_num_of_pair_braces(char * string){
  int count = 0;
  int len = strlen(string);
  for(int i=0;i<len-1;i++){
    if(string[i]=='[' && string[i+1]==']'){
      count++;
    }
  }
  return count;
}
