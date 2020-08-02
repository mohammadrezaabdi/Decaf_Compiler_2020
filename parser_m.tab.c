
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 12 "parser_m.y"

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


/* Line 189 of yacc.c  */
#line 88 "parser_m.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_OR = 258,
     T_AND = 259,
     T_NEQ = 260,
     T_EQ = 261,
     T_BEQ = 262,
     T_LEQ = 263,
     T_UNARYMINUS = 264,
     PAIREDBRACES = 265,
     T_ID = 266,
     T_VOID = 267,
     T_CLASS = 268,
     T_INTERFACE = 269,
     T_EXTENDS = 270,
     T_IMPLEMENTS = 271,
     T_FOR = 272,
     T_WHILE = 273,
     T_IF = 274,
     T_ELSE = 275,
     T_RETURN = 276,
     T_BREAK = 277,
     T_NEW = 278,
     T_NEWARRAY = 279,
     T_PRINT = 280,
     T_READINTEGER = 281,
     T_READLINE = 282,
     T_INTCONSTANT = 283,
     T_DOUBLECONSTANT = 284,
     T_STRINGCONSTANT = 285,
     T_INT = 286,
     T_DOUBLE = 287,
     T_BOOL = 288,
     T_STRING = 289,
     T_NULL = 290,
     T_THIS = 291,
     T_BOOLCONSTANT = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "parser_m.y"

        int intLiteral;
        double doubleLiteral;
        bool booleanLiteral;
        char *stringLiteral;

    


/* Line 214 of yacc.c  */
#line 171 "parser_m.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 183 "parser_m.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   402

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,     2,     2,    16,     2,     2,
      22,    51,    14,    12,    52,    13,    20,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       8,     3,     9,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,    10,    11,    18,    21,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    12,    14,    16,    18,
      19,    22,    25,    28,    30,    32,    34,    36,    38,    41,
      42,    43,    52,    53,    54,    63,    64,    67,    68,    72,
      73,    82,    83,    86,    87,    91,    92,    96,    97,   100,
     102,   104,   105,   112,   113,   116,   123,   130,   131,   137,
     138,   141,   144,   146,   148,   150,   152,   154,   156,   158,
     159,   161,   168,   169,   172,   178,   188,   192,   195,   202,
     203,   207,   211,   213,   215,   217,   219,   223,   227,   231,
     235,   239,   243,   246,   250,   254,   258,   262,   266,   270,
     274,   278,   281,   285,   289,   292,   293,   301,   303,   307,
     312,   313,   319,   320,   328,   329,   332,   334,   336,   338,
     340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    59,    58,    -1,    -1,    59,    58,    -1,
      61,    -1,    64,    -1,    71,    -1,    78,    -1,    -1,    60,
      61,    -1,    62,    50,    -1,    63,    23,    -1,    43,    -1,
      44,    -1,    45,    -1,    46,    -1,    23,    -1,    63,    21,
      -1,    -1,    -1,    63,    23,    65,    22,    69,    51,    66,
      82,    -1,    -1,    -1,    24,    23,    67,    22,    69,    51,
      68,    82,    -1,    -1,    62,    70,    -1,    -1,    70,    52,
      62,    -1,    -1,    25,    23,    72,    73,    74,    53,    76,
      54,    -1,    -1,    27,    23,    -1,    -1,    28,    23,    75,
      -1,    -1,    75,    52,    23,    -1,    -1,    77,    76,    -1,
      61,    -1,    64,    -1,    -1,    26,    23,    53,    79,    80,
      54,    -1,    -1,    81,    80,    -1,    63,    23,    22,    69,
      51,    50,    -1,    24,    23,    22,    69,    51,    50,    -1,
      -1,    53,    83,    60,    84,    54,    -1,    -1,    85,    84,
      -1,    86,    50,    -1,    87,    -1,    89,    -1,    90,    -1,
      92,    -1,    91,    -1,    93,    -1,    82,    -1,    -1,    95,
      -1,    31,    22,    95,    51,    85,    88,    -1,    -1,    32,
      85,    -1,    30,    22,    95,    51,    85,    -1,    29,    22,
      86,    50,    95,    50,    86,    51,    85,    -1,    33,    86,
      50,    -1,    34,    50,    -1,    37,    22,    95,    94,    51,
      50,    -1,    -1,    94,    52,    95,    -1,    97,     3,    95,
      -1,   102,    -1,    97,    -1,    48,    -1,    98,    -1,    22,
      95,    51,    -1,    95,    12,    95,    -1,    95,    13,    95,
      -1,    95,    14,    95,    -1,    95,    15,    95,    -1,    95,
      16,    95,    -1,    13,    95,    -1,    95,     8,    95,    -1,
      95,    11,    95,    -1,    95,     9,    95,    -1,    95,    10,
      95,    -1,    95,     7,    95,    -1,    95,     6,    95,    -1,
      95,     5,    95,    -1,    95,     4,    95,    -1,    17,    95,
      -1,    38,    22,    51,    -1,    39,    22,    51,    -1,    35,
      23,    -1,    -1,    36,    96,    22,    95,    52,    63,    51,
      -1,    23,    -1,    95,    20,    23,    -1,    95,    19,    95,
      55,    -1,    -1,    23,    99,    22,   101,    51,    -1,    -1,
      95,    20,    23,   100,    22,   101,    51,    -1,    -1,    95,
      94,    -1,    40,    -1,    41,    -1,    49,    -1,    42,    -1,
      47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    65,    66,    68,    69,    70,    71,    73,
      74,    76,    78,   100,   101,   102,   103,   104,   105,   107,
     124,   107,   144,   161,   144,   181,   182,   184,   185,   187,
     187,   217,   218,   226,   227,   229,   230,   232,   233,   235,
     236,   239,   238,   255,   256,   258,   259,   261,   261,   277,
     278,   280,   281,   282,   283,   284,   285,   286,   287,   289,
     290,   292,   294,   295,   297,   299,   301,   303,   305,   307,
     308,   310,   311,   312,   313,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   348,   348,   353,   360,   367,
     369,   369,   377,   377,   386,   387,   389,   399,   409,   419,
     429
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "T_OR", "T_AND", "T_NEQ", "T_EQ",
  "'<'", "'>'", "T_BEQ", "T_LEQ", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "T_UNARYMINUS", "'['", "'.'", "PAIREDBRACES", "'('", "T_ID", "T_VOID",
  "T_CLASS", "T_INTERFACE", "T_EXTENDS", "T_IMPLEMENTS", "T_FOR",
  "T_WHILE", "T_IF", "T_ELSE", "T_RETURN", "T_BREAK", "T_NEW",
  "T_NEWARRAY", "T_PRINT", "T_READINTEGER", "T_READLINE", "T_INTCONSTANT",
  "T_DOUBLECONSTANT", "T_STRINGCONSTANT", "T_INT", "T_DOUBLE", "T_BOOL",
  "T_STRING", "T_NULL", "T_THIS", "T_BOOLCONSTANT", "';'", "')'", "','",
  "'{'", "'}'", "']'", "$accept", "program", "decls", "decl",
  "variableDecls", "variableDecl", "variable", "type", "functionDecl",
  "$@1", "$@2", "$@3", "$@4", "formals", "csVariable", "classDecl", "$@5",
  "optExt", "optImp", "csID", "fields", "field", "interfaceDecl", "$@6",
  "prototypes", "prototype", "stmtBlock", "$@7", "stmts", "stmt",
  "optExpr", "ifStmt", "optElse", "whileStmt", "forStmt", "returnStmt",
  "breakStmt", "printStmt", "csExpr", "expr", "$@8", "lvalue", "call",
  "$@9", "$@10", "actuals", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,   258,   259,   260,   261,    60,    62,
     262,   263,    43,    45,    42,    47,    37,    33,   264,    91,
      46,   265,    40,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
      59,    41,    44,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    61,    62,    63,    63,    63,    63,    63,    63,    65,
      66,    64,    67,    68,    64,    69,    69,    70,    70,    72,
      71,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    79,    78,    80,    80,    81,    81,    83,    82,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    88,    88,    89,    90,    91,    92,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    95,    97,    97,    97,
      99,    98,   100,    98,   101,   101,   102,   102,   102,   102,
     102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     0,
       2,     2,     2,     1,     1,     1,     1,     1,     2,     0,
       0,     8,     0,     0,     8,     0,     2,     0,     3,     0,
       8,     0,     2,     0,     3,     0,     3,     0,     2,     1,
       1,     0,     6,     0,     2,     6,     6,     0,     5,     0,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     6,     0,     2,     5,     9,     3,     2,     6,     0,
       3,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     0,     7,     1,     3,     4,
       0,     5,     0,     7,     0,     2,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,     0,     0,     0,    13,    14,    15,    16,     0,
       3,     5,     0,     0,     6,     7,     8,    22,    29,     0,
       1,     2,     3,    11,    18,    12,     0,    31,    41,     4,
       0,    25,     0,    33,    43,    25,    27,     0,     0,    32,
       0,     0,     0,     0,     0,    43,     0,    26,    12,    23,
      35,    37,     0,     0,    42,    44,    20,     0,     0,    34,
      39,    40,     0,    37,    25,    25,     0,    28,    47,    24,
       0,    30,    38,     0,     0,    21,     9,    36,     0,     0,
      49,    46,    45,     0,     0,     0,    97,     0,     0,     0,
      59,     0,     0,    95,     0,     0,     0,   106,   107,   109,
     110,    74,   108,    10,    58,     0,    49,     0,    52,    53,
      54,    56,    55,    57,    60,    73,    75,    72,    97,    82,
      91,     0,     0,    59,     0,     0,     0,    67,    94,     0,
       0,     0,     0,    48,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,   104,     0,     0,     0,    66,     0,    69,
      92,    93,    90,    89,    88,    87,    83,    85,    86,    84,
      77,    78,    79,    80,    81,     0,    98,    71,    69,     0,
       0,    59,    59,     0,     0,    99,     0,   105,   101,     0,
      64,    62,     0,     0,     0,   104,    59,    59,    61,     0,
      68,    70,     0,     0,    63,    96,   103,    59,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    21,    22,    80,    11,    12,    37,    14,    30,
      66,    26,    58,    38,    47,    15,    27,    33,    41,    59,
      62,    63,    16,    34,    44,    45,   104,    76,   105,   106,
     107,   108,   198,   109,   110,   111,   112,   113,   184,   114,
     129,   115,   116,   122,   186,   179,   117
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -181
static const yytype_int16 yypact[] =
{
     203,  -181,   -14,    -9,     6,  -181,  -181,  -181,  -181,    23,
     203,  -181,    50,     3,  -181,  -181,  -181,  -181,  -181,    48,
    -181,  -181,   203,  -181,  -181,    93,    94,    92,  -181,  -181,
      99,   280,    97,   109,    -4,   280,  -181,    57,   103,  -181,
     132,   118,   166,   253,   150,    -4,   170,   173,  -181,  -181,
    -181,    61,   208,   212,  -181,  -181,  -181,   280,   185,   191,
    -181,  -181,   196,    61,   280,   280,   185,  -181,  -181,  -181,
     255,  -181,  -181,   228,   229,  -181,  -181,  -181,   231,   234,
     222,  -181,  -181,     8,     8,     8,   219,   263,   264,   265,
       8,   238,   269,  -181,   282,   283,   284,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,   258,   260,   266,  -181,  -181,
    -181,  -181,  -181,  -181,   348,   311,  -181,  -181,   295,    40,
      40,   137,   296,     8,     8,     8,   272,  -181,  -181,   297,
       8,   279,   290,  -181,  -181,  -181,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
     319,     8,  -181,     8,   293,   154,   171,  -181,     8,   348,
    -181,  -181,   364,   187,   377,   377,    98,    98,    98,    98,
     217,   217,    40,    40,    40,    83,   322,   348,   348,   299,
       8,   298,   298,   120,    31,  -181,   326,   313,  -181,   204,
    -181,   317,   280,   316,     8,     8,     8,   298,  -181,   -16,
    -181,   348,   330,   331,  -181,  -181,  -181,   298,  -181
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,   372,   395,  -181,   -47,    -3,     0,   -45,  -181,
    -181,  -181,  -181,   -27,  -181,  -181,  -181,  -181,  -181,  -181,
     335,  -181,  -181,  -181,   354,  -181,   -51,  -181,   294,  -180,
     -87,  -181,  -181,  -181,  -181,  -181,  -181,  -181,   223,   -72,
    -181,  -181,  -181,  -181,  -181,   207,  -181
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -103
static const yytype_int16 yytable[] =
{
      13,   190,   191,   126,    60,    24,    61,    69,    46,    17,
      13,   119,   120,   121,    18,    75,    60,   204,    61,     1,
      42,    83,    13,    20,    24,    84,    25,   208,    36,    19,
      85,   118,    36,   103,    43,   205,   154,    73,    74,     5,
       6,     7,     8,    92,    93,    43,    95,    96,    97,    98,
      99,    13,   155,   156,    67,   100,   101,   102,   159,   149,
     150,    36,    36,    13,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    24,   177,
      48,   178,   193,   194,     1,     2,   183,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      23,    28,   149,   150,     5,     6,     7,     8,   189,   203,
     144,   145,   146,   147,   148,   -19,    31,   149,   150,    32,
      39,    35,   201,   178,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    40,   185,   149,
     150,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    49,    50,   149,   150,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    51,   192,   149,   150,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   152,    52,
     149,   150,   199,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    54,   181,   149,   150,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    56,   182,   149,   150,    57,     1,     2,     3,     4,
      64,   146,   147,   148,    65,    83,   149,   150,    68,    84,
     -17,  -100,   -17,    70,    85,    86,     5,     6,     7,     8,
      71,    87,    88,    89,   196,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     5,     6,     7,     8,   100,
     101,   102,   -59,    83,    24,    68,    53,    84,    77,    78,
      79,    81,    85,   118,    82,   123,   124,   125,   127,    87,
      88,    89,   128,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     1,   130,   131,   132,   100,   101,   102,
     -59,    83,   133,    68,   151,    84,   135,  -100,   153,   158,
      85,   118,   157,     5,     6,     7,     8,    87,    88,    89,
     160,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   161,   176,   180,  -102,   100,   101,   102,   195,   197,
     188,    68,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   194,   200,   149,   150,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   206,   207,   149,   150,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    29,    10,   149,   150,    72,    55,
     134,   187,   202
};

static const yytype_uint8 yycheck[] =
{
       0,   181,   182,    90,    51,    21,    51,    58,    35,    23,
      10,    83,    84,    85,    23,    66,    63,   197,    63,    23,
      24,    13,    22,     0,    21,    17,    23,   207,    31,    23,
      22,    23,    35,    80,    34,    51,   123,    64,    65,    43,
      44,    45,    46,    35,    36,    45,    38,    39,    40,    41,
      42,    51,   124,   125,    57,    47,    48,    49,   130,    19,
      20,    64,    65,    63,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    21,   151,
      23,   153,    51,    52,    23,    24,   158,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      50,    53,    19,    20,    43,    44,    45,    46,   180,   196,
      12,    13,    14,    15,    16,    22,    22,    19,    20,    27,
      23,    22,   194,   195,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    28,    55,    19,
      20,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    51,    23,    19,    20,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    53,    52,    19,    20,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    51,    23,
      19,    20,   192,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    54,    51,    19,    20,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    51,    51,    19,    20,    52,    23,    24,    25,    26,
      22,    14,    15,    16,    22,    13,    19,    20,    53,    17,
      21,    22,    23,    52,    22,    23,    43,    44,    45,    46,
      54,    29,    30,    31,    50,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    13,    21,    53,    23,    17,    23,    51,
      51,    50,    22,    23,    50,    22,    22,    22,    50,    29,
      30,    31,    23,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    23,    22,    22,    22,    47,    48,    49,
      50,    13,    54,    53,     3,    17,    50,    22,    22,    22,
      22,    23,    50,    43,    44,    45,    46,    29,    30,    31,
      51,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    51,    23,    50,    22,    47,    48,    49,    22,    32,
      51,    53,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    52,    50,    19,    20,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    51,    51,    19,    20,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    22,     0,    19,    20,    63,    45,
     106,   178,   195
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    24,    25,    26,    43,    44,    45,    46,    57,
      59,    61,    62,    63,    64,    71,    78,    23,    23,    23,
       0,    58,    59,    50,    21,    23,    67,    72,    53,    58,
      65,    22,    27,    73,    79,    22,    62,    63,    69,    23,
      28,    74,    24,    63,    80,    81,    69,    70,    23,    51,
      23,    53,    23,    23,    54,    80,    51,    52,    68,    75,
      61,    64,    76,    77,    22,    22,    66,    62,    53,    82,
      52,    54,    76,    69,    69,    82,    83,    23,    51,    51,
      60,    50,    50,    13,    17,    22,    23,    29,    30,    31,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      47,    48,    49,    61,    82,    84,    85,    86,    87,    89,
      90,    91,    92,    93,    95,    97,    98,   102,    23,    95,
      95,    95,    99,    22,    22,    22,    86,    50,    23,    96,
      22,    22,    22,    54,    84,    50,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    19,
      20,     3,    51,    22,    86,    95,    95,    50,    22,    95,
      51,    51,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    23,    95,    95,   101,
      50,    51,    51,    95,    94,    55,   100,    94,    51,    95,
      85,    85,    52,    51,    52,    22,    50,    32,    88,    63,
      50,    95,   101,    86,    85,    51,    51,    51,    85
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 12:

/* Line 1455 of yacc.c  */
#line 78 "parser_m.y"
    {
                                  switch(pass){
                                    case LEVEL_2:
                                      if(class_decl && !func_scope){
                                        add_field_to_class(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), get_element((yyvsp[(1) - (2)].stringLiteral), 0, delim), get_num_of_pair_braces((yyvsp[(1) - (2)].stringLiteral)));
                                      }
                                      if(func_decl){
                                        add_param_to_func(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), get_element((yyvsp[(1) - (2)].stringLiteral), 0, delim), get_num_of_pair_braces((yyvsp[(1) - (2)].stringLiteral)));
                                      }
                                      break;
                                    case LEVEL_3:
                                      if (class_decl && !func_scope){
                                        insert_field(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), T_ID_lineo, T_ID_colno, get_element((yyvsp[(1) - (2)].stringLiteral), 0, delim), get_num_of_pair_braces((yyvsp[(1) - (2)].stringLiteral)), curr_class->name);
                                      } else if (func_decl){
                                        insert_param(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), T_ID_lineo, T_ID_colno, get_element((yyvsp[(1) - (2)].stringLiteral), 0, delim), get_num_of_pair_braces((yyvsp[(1) - (2)].stringLiteral)));
                                      } else {
                                        insert_local_var(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), T_ID_lineo, T_ID_colno, get_element((yyvsp[(1) - (2)].stringLiteral), 0, delim), get_num_of_pair_braces((yyvsp[(1) - (2)].stringLiteral)));
                                      }
                                      break;
                                  }
                                ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 100 "parser_m.y"
    {(yyval.stringLiteral) = (yyvsp[(1) - (1)].stringLiteral);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 101 "parser_m.y"
    {(yyval.stringLiteral) = (yyvsp[(1) - (1)].stringLiteral);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 102 "parser_m.y"
    {(yyval.stringLiteral) = (yyvsp[(1) - (1)].stringLiteral);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 103 "parser_m.y"
    {(yyval.stringLiteral) = (yyvsp[(1) - (1)].stringLiteral);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 104 "parser_m.y"
    {(yyval.stringLiteral) = (yyvsp[(1) - (1)].stringLiteral);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 105 "parser_m.y"
    {(yyval.stringLiteral) = (yyvsp[(1) - (2)].stringLiteral);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 107 "parser_m.y"
    {
                                  func_decl = true;
                                  func_scope = true;
                                  switch(pass){
                                    case LEVEL_2:
                                      curr_func = add_to_func_list(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), get_element((yyvsp[(1) - (2)].stringLiteral), 0, delim), (curr_class!=NULL) ? curr_class->name : NULL, get_num_of_pair_braces((yyvsp[(1) - (2)].stringLiteral)));
                                      if(class_decl){
                                        add_to_vtable(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), curr_class->name);
                                      }
                                      break;
                                    case LEVEL_3:
                                      move_in_new_scope(lineno, colno);
                                      curr_func = find_func(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), get_type_id(curr_class->name));
                                      reference_to_function(curr_func->name, T_ID_lineo, T_ID_colno, (curr_class!=NULL) ? curr_class->name : NULL);
                                      break;
                                  }
                                ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 124 "parser_m.y"
    {
                                        func_decl = false;
                                        switch(pass){
                                          case LEVEL_2:
                                            curr_func = NULL;
                                            break;
                                          case LEVEL_3:
                                            curr_func = NULL;
                                            break;
                                        }
                                      ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 135 "parser_m.y"
    {
                                        func_scope = false;
                                          switch(pass){
                                            case LEVEL_3:
                                              move_out_from_scope(lineno, colno);
                                              break;
                                          }
                                      ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 144 "parser_m.y"
    {
                                    func_decl = true;
                                    func_scope = true;
                                    switch(pass){
                                      case LEVEL_2:
                                        curr_func = add_to_func_list(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), get_element((yyvsp[(1) - (2)].stringLiteral), 0, delim), (curr_class!=NULL) ? curr_class->name : NULL, get_num_of_pair_braces((yyvsp[(1) - (2)].stringLiteral)));
                                        if(class_decl){
                                          add_to_vtable(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), curr_class->name);
                                        }
                                        break;
                                      case LEVEL_3:
                                        move_in_new_scope(lineno, colno);
                                        curr_func = find_func(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim), get_type_id(curr_class->name));
                                        reference_to_function(curr_func->name, T_ID_lineo, T_ID_colno, (curr_class!=NULL) ? curr_class->name : NULL);
                                        break;
                                    }
                                  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 161 "parser_m.y"
    {
                                        func_decl = false;
                                          switch(pass){
                                            case LEVEL_2:
                                            curr_func = NULL;
                                            break;
                                            case LEVEL_3:
                                            curr_func = NULL;
                                            break;
                                          }
                                        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 172 "parser_m.y"
    {
                                          func_scope = false;
                                            switch(pass){
                                              case LEVEL_3:
                                                  move_out_from_scope(lineno, colno);
                                                  break;
                                            }
                                        ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 187 "parser_m.y"
    {
                                      class_decl = true;
                                      switch(pass){
                                        case LEVEL_1:
                                          add_to_type_list((yyvsp[(2) - (2)].stringLiteral));
                                          add_to_class_list((yyvsp[(2) - (2)].stringLiteral));
                                          break;
                                        case LEVEL_2:
                                          curr_class = find_class((yyvsp[(2) - (2)].stringLiteral));
                                          break;
                                        case LEVEL_3:
                                          move_in_new_scope(lineno, colno);
                                          curr_class_scope = curr_scope->id;
                                          curr_class = find_class((yyvsp[(2) - (2)].stringLiteral));
                                          break;
                                      }
                                    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 204 "parser_m.y"
    {
                                                      class_decl = false;
                                                      switch(pass){
                                                        case LEVEL_2:
                                                          curr_class = NULL;
                                                          break;
                                                        case LEVEL_3:
                                                          curr_class = NULL;
                                                          move_out_from_scope(lineno, colno);
                                                          break;
                                                      }
                                                    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 218 "parser_m.y"
    {
                                        switch(pass){
                                          case LEVEL_2:
                                            set_father(curr_class, (yyvsp[(2) - (2)].stringLiteral));
                                            break;
                                        }
                                      ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 239 "parser_m.y"
    {
                            switch(pass){
                              case LEVEL_3:
                                move_in_new_scope(lineno, colno);
                                break;
                            }
                          ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 247 "parser_m.y"
    {
                            switch(pass){
                              case LEVEL_3:
                                move_out_from_scope(lineno, colno);
                                break;
                            }
                          ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 261 "parser_m.y"
    {
                            switch(pass){
                              case LEVEL_3:
                              move_in_new_scope(lineno, colno);
                              break;
                            }
                          ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 269 "parser_m.y"
    {
                            switch(pass){
                              case LEVEL_3:
                                move_out_from_scope(lineno, colno);
                                break;
                            }
                          ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 313 "parser_m.y"
    {
                                switch(pass){
                                  case LEVEL_3:
                                    if (class_decl){
                                      curr_entity = create_entity((char * ) "this", create_loc(T_ID_lineo, T_ID_colno), curr_class_scope, curr_class->name, 0, NULL, false, 0, 0.0, NULL, false);
                                    }
                                    break;
                                }
                              ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 341 "parser_m.y"
    {
                                    switch(pass){
                                      case LEVEL_3: //TODO memory allocation handling in tac
                                        down_casting(get_element((yyvsp[(2) - (2)].stringLiteral), 0, delim));
                                      break;
                                    }
                                  ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 348 "parser_m.y"
    {
                                    //TODO memory allocation handling in tac
                                  ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 353 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_3:
                                                reference(get_element((yyvsp[(1) - (1)].stringLiteral), 0, delim), T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 360 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_3:
                                                chain_reference_tracking_entity(get_element((yyvsp[(3) - (3)].stringLiteral), 0, delim), T_ID_lineo, T_ID_colno, false);
                                                break;
                                              }
                                          ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 369 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_3:
                                                reference_to_function(get_element((yyvsp[(1) - (1)].stringLiteral), 0, delim), T_ID_lineo, T_ID_colno, (curr_class!=NULL) ? curr_class->name : NULL);
                                                break;
                                            }
                                          ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 377 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_3:
                                                chain_reference_tracking_entity(get_element((yyvsp[(3) - (3)].stringLiteral), 0, delim), T_ID_lineo, T_ID_colno, true);
                                                break;
                                            }
                                          ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 389 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(INT_TYPE, (yyvsp[(1) - (1)].intLiteral), 0.0, NULL, false);
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(INT_TYPE, (yyvsp[(1) - (1)].intLiteral), 0.0, NULL,false)->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 399 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(DBL_TYPE, 0, (yyvsp[(1) - (1)].doubleLiteral), NULL, false);
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(DBL_TYPE, 0, (yyvsp[(1) - (1)].doubleLiteral), NULL,false)->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 409 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(BOOL_TYPE, 0, 0.0, NULL, (yyvsp[(1) - (1)].booleanLiteral));
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(BOOL_TYPE, 0, 0.0, NULL,(yyvsp[(1) - (1)].booleanLiteral))->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 419 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_1:
                                                add_to_const_list(STR_TYPE, 0, 0.0, (yyvsp[(1) - (1)].stringLiteral), false);
                                                break;
                                              case LEVEL_3:
                                                reference(find_const(STR_TYPE, 0, 0.0, (yyvsp[(1) - (1)].stringLiteral), false)->name, T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 429 "parser_m.y"
    {
                                            switch(pass){
                                              case LEVEL_3:
                                                reference((char *) "NULL", T_ID_lineo, T_ID_colno);
                                                break;
                                            }
                                          ;}
    break;



/* Line 1455 of yacc.c  */
#line 2058 "parser_m.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 437 "parser_m.y"

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
    show_scopes(sym_file);
    show_symbol_table(sym_file, num_of_input_file_lines);
    show_hash_table(sym_file);
    fclose(info_file);
    fclose(sym_file);
  	return 0;
}

void yyerror(char const *s) {
    //todo: error handling
}

