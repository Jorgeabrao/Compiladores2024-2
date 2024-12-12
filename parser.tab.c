/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtbl.h"
#include "hashtbl.c"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
void production_print(const char* production);
void yyerror(const char *s);
extern struct hashMap *sym_table;
void yyerror(const char *s);
int checkType( char *name, char *encounteredType);
int idsCheckType( char *name, char *name2);
char* mathCheck(char *ar1, char *ar2, char *op);
char* idMathCheck(char *ar1, char *ar2, char *op, char *ar2type);
char* idsMathCheck(char *ar1, char *ar2, char *op);

int verb = 0; //1 to activate verbose mode
int verbose = 1;
char* aux;
int i = 0;
int error = 0;
extern int line_num;
extern int col_num;
extern int eof;
extern int func;
extern char *escopo;


#line 103 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCAO = 258,
    FIMFUNCAO = 259,
    CHAMA = 260,
    RETORNA = 261,
    TIPO = 262,
    ARGS = 263,
    FIMARGS = 264,
    ESCREVA = 265,
    REAL = 266,
    CARACTERE = 267,
    SE = 268,
    ENTAO = 269,
    FIMSE = 270,
    ENQUANTO = 271,
    FACA = 272,
    FIMENQUANTO = 273,
    CHAMADA = 274,
    SENAO = 275,
    ID_OU_FUNC = 276,
    INTEIRO = 277,
    LITERAL = 278,
    OP_RELACIONAL = 279,
    OP_ARITMETICO = 280,
    ATRIBUICAO = 281,
    ABRE_PAR = 282,
    FECHA_PAR = 283,
    VIRGULA = 284,
    PONTO_E_VIRG = 285,
    COMENTARIO = 286,
    FIM_DE_ARQ = 287,
    RNUMERO = 288,
    NUMERO = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser.y"

    char *str;
    int num;
    float fnum;

#line 196 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    37,    35,     2,    36,     2,    38,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    63,    69,    70,    71,    77,    78,    79,
      83,    84,    85,    91,    92,    96,    97,    98,    99,   100,
     103,   106,   112,   113,   114,   117,   123,   124,   125,   129,
     130,   131,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   146,   149,   152,   155,   158,   164,   165,   166,   167,
     171,   174,   177,   180,   181,   184,   187,   193,   194,   195,
     199,   200,   203,   206,   212,   213,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   236,   239,   242,   245,   248,   251,   254,
     257,   263,   267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCAO", "FIMFUNCAO", "CHAMA",
  "RETORNA", "TIPO", "ARGS", "FIMARGS", "ESCREVA", "REAL", "CARACTERE",
  "SE", "ENTAO", "FIMSE", "ENQUANTO", "FACA", "FIMENQUANTO", "CHAMADA",
  "SENAO", "ID_OU_FUNC", "INTEIRO", "LITERAL", "OP_RELACIONAL",
  "OP_ARITMETICO", "ATRIBUICAO", "ABRE_PAR", "FECHA_PAR", "VIRGULA",
  "PONTO_E_VIRG", "COMENTARIO", "FIM_DE_ARQ", "RNUMERO", "NUMERO", "'+'",
  "'-'", "'*'", "'/'", "$accept", "programa", "assinatura", "tipo_funcao",
  "args", "lista_vars", "vars", "vars_cont", "tipo", "codigo", "atribuido",
  "lista_id", "se_entao", "senao_op", "cond", "nome_funcao", "eof", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,    -8,    -8,    59,   -52,   -52,   131,   -52,   -52,    87,
       9,    84,    86,   100,     3,   151,   -52,   -52,    70,    83,
      89,   -52,   -52,   178,   104,   -52,   178,   -52,   -52,    94,
     -52,   178,   -52,   -52,   155,   -52,   -52,   -52,   112,    27,
     155,   119,   263,   -52,    31,    54,    30,    30,    30,    15,
      74,   -52,   115,     0,   -52,   -52,   -52,   -52,   124,   -52,
     178,   -52,   201,   178,   -52,   178,   178,   178,   178,   134,
      72,    92,   140,    99,   141,    64,   164,   173,   185,    93,
     179,   180,   195,   178,   -52,   173,    15,   113,   -52,   -52,
     178,   -52,    32,   -52,   -52,   -52,   -52,   -52,   -52,   -12,
     187,    45,   192,    49,   197,   198,    53,   212,   237,     5,
     233,   -52,    26,   -52,    68,   -52,   -52,   -52,   -52,   -52,
     224,    51,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   223,
     223,   223,   223,   236,    26,    26,   225,   -52,   232,   239,
     243,   248,   113,   -52,   113,   -52,   259,   259,   259,   259,
     245,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     255,   265,   266,   267,   268,   178,   -52,   -52,   -52,   -52,
     -52,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    91,     3,     0,     2,     1,     0,
       0,     0,     0,     0,     0,     0,    28,    26,     0,     0,
       0,    27,     4,     0,     0,    11,     0,     9,     7,     0,
       8,     0,    92,    45,     0,    44,    38,    37,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,    34,    21,    43,     6,     0,    42,
       0,     5,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,     0,    15,    18,
       0,    36,     0,    12,    10,    40,    31,    41,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,    55,     0,    46,    48,    47,    32,    17,
       0,     0,    16,    33,    82,    88,    85,    83,    84,    66,
      69,    68,    67,    89,    90,    78,    81,    80,    79,    74,
      77,    76,    75,    86,    87,    70,    73,    72,    71,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,    25,     0,    23,    65,    65,    65,    65,
       0,    59,    57,    53,    52,    49,    51,    50,    24,    22,
       0,     0,     0,     0,     0,     0,    64,    61,    62,    63,
      60,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,     7,   282,   273,   -16,   -52,    71,    33,   -52,   -23,
     -51,   -34,   -52,    18,   133,   -52,   277
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,     5,    34,    22,    42,    23,   122,    24,    25,
      83,   156,    26,   181,    74,     6,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    85,    89,    54,    41,    78,   151,     3,    56,   124,
       1,   125,     2,     4,    16,    17,    77,    36,    57,   152,
      78,    79,   126,    80,    61,    21,    86,   154,    59,    87,
      88,    69,    65,    81,    82,   119,    79,    91,    80,    93,
      94,    32,    95,    96,    97,    98,   128,   155,    81,    82,
     134,    70,   163,    71,   144,    67,   -58,    60,    49,     8,
     118,    66,    55,    72,    73,   108,   129,   123,   130,   157,
     135,    46,   136,   100,   145,     1,   146,     2,   131,   132,
     164,   165,   137,   138,    68,    43,   147,   148,     1,   158,
       2,   159,   109,   102,   113,    29,   101,    47,    27,    28,
     105,   160,   161,    38,    31,    52,    32,    39,    29,    30,
      48,    27,    28,    64,   120,    49,   103,    31,   114,    32,
     171,   172,    30,   106,    55,    53,   166,   167,   168,   169,
     170,   -39,     9,    58,   121,    10,    11,    12,    13,    14,
      29,    15,    16,    17,    18,    84,   -39,    19,     1,   -39,
       2,   -39,    20,    21,    90,   -39,    50,   186,    99,    10,
      11,    12,   191,    14,   104,    15,    16,    17,    18,   107,
     -39,    19,    44,   -39,    45,   -39,    20,    21,   -39,    50,
      75,    76,    10,    11,    12,   182,   183,   184,    15,    16,
      17,    18,   110,   -39,    19,   178,   -39,   179,   -39,    20,
      21,   -39,    50,   111,   112,    10,    11,    12,   127,   115,
     116,    15,    16,    17,    18,   133,   -39,    19,   139,   -39,
     140,   -39,    92,    21,    50,   117,   149,    10,    11,    12,
     141,   142,   143,    15,    16,    17,    18,    50,   -39,    19,
      10,    11,    12,   -39,    20,    21,    15,    16,    17,    18,
     153,   150,    19,   162,   -39,   173,    50,    20,    21,    10,
      11,    12,   174,   185,    62,    15,    16,    17,    18,   175,
     -39,    19,    63,   176,    16,    17,    20,    21,   177,   180,
     187,   188,   189,   190,     7,    21,    40,    37
};

static const yytype_uint8 yycheck[] =
{
      23,     1,    53,    26,     1,     5,     1,     0,    31,    21,
       1,    23,     3,    21,    11,    12,     1,    10,    34,    14,
       5,    21,    34,    23,    40,    22,    26,     1,     1,    29,
      30,     1,     1,    33,    34,    86,    21,    60,    23,    62,
      63,    32,    65,    66,    67,    68,     1,    21,    33,    34,
       1,    21,     1,    23,     1,     1,    30,    30,    26,     0,
      83,    30,    30,    33,    34,     1,    21,    90,    23,     1,
      21,     1,    23,     1,    21,     1,    23,     3,    33,    34,
      29,    30,    33,    34,    30,    14,    33,    34,     1,    21,
       3,    23,    28,     1,     1,    21,    24,    27,    11,    12,
       1,    33,    34,    19,    30,     1,    32,    21,    21,    22,
      27,    11,    12,    42,     1,    26,    24,    30,    25,    32,
     154,   155,    22,    24,    30,    21,   149,   150,   151,   152,
     153,     0,     1,    21,    21,     4,     5,     6,     7,     8,
      21,    10,    11,    12,    13,    30,    15,    16,     1,    18,
       3,    20,    21,    22,    30,     0,     1,   180,    24,     4,
       5,     6,   185,     8,    24,    10,    11,    12,    13,    28,
      15,    16,    21,    18,    23,    20,    21,    22,     0,     1,
      47,    48,     4,     5,     6,   167,   168,   169,    10,    11,
      12,    13,    28,    15,    16,   162,    18,   164,    20,    21,
      22,     0,     1,    30,    19,     4,     5,     6,    21,    30,
      30,    10,    11,    12,    13,    23,    15,    16,    21,    18,
      23,    20,    21,    22,     1,    30,    14,     4,     5,     6,
      33,    34,    34,    10,    11,    12,    13,     1,    15,    16,
       4,     5,     6,    20,    21,    22,    10,    11,    12,    13,
      17,    14,    16,    29,    18,    30,     1,    21,    22,     4,
       5,     6,    30,    18,     1,    10,    11,    12,    13,    30,
      15,    16,     9,    30,    11,    12,    21,    22,    30,    20,
      15,    15,    15,    15,     2,    22,    13,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    40,    21,    41,    54,    41,     0,     1,
       4,     5,     6,     7,     8,    10,    11,    12,    13,    16,
      21,    22,    43,    45,    47,    48,    51,    11,    12,    21,
      22,    30,    32,    40,    42,    55,    40,    55,    19,    21,
      42,     1,    44,    45,    21,    23,     1,    27,    27,    26,
       1,    48,     1,    21,    48,    30,    48,    43,    21,     1,
      30,    43,     1,     9,    45,     1,    30,     1,    30,     1,
      21,    23,    33,    34,    53,    53,    53,     1,     5,    21,
      23,    33,    34,    49,    30,     1,    26,    29,    30,    49,
      30,    48,    21,    48,    48,    48,    48,    48,    48,    24,
       1,    24,     1,    24,    24,     1,    24,    28,     1,    28,
      28,    30,    19,     1,    25,    30,    30,    30,    48,    49,
       1,    21,    46,    48,    21,    23,    34,    21,     1,    21,
      23,    33,    34,    23,     1,    21,    23,    33,    34,    21,
      23,    33,    34,    34,     1,    21,    23,    33,    34,    14,
      14,     1,    14,    17,     1,    21,    50,     1,    21,    23,
      33,    34,    29,     1,    29,    30,    48,    48,    48,    48,
      48,    50,    50,    30,    30,    30,    30,    30,    46,    46,
      20,    52,    52,    52,    52,    18,    48,    15,    15,    15,
      15,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    42,    42,    42,
      43,    43,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    46,    46,    46,    46,    47,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       4,     1,     4,     1,     2,     3,     4,     4,     3,     3,
       3,     3,     3,     2,     3,     2,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     8,     4,     2,     2,     0,
       4,     4,     3,     3,     2,     2,     2,     2,     2,     4,
       4,     4,     4,     4,     2,     2,     3,     2,     0,     2,
       8,     8,     8,     8,     2,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 62 "parser.y"
                      { func--; production_print("programa -> FUNCAO assinatura");if(eof == 1 && func == 0) return 0;}
#line 1513 "parser.tab.c"
    break;

  case 3:
#line 63 "parser.y"
                      {
        yyerrok;
        yyclearin;if(eof == 1) return 0;}
#line 1521 "parser.tab.c"
    break;

  case 4:
#line 69 "parser.y"
                     {production_print("assinatura -> nome_funcao args");}
#line 1527 "parser.tab.c"
    break;

  case 5:
#line 70 "parser.y"
                                        {production_print("assinatura -> nome_funcao TIPO tipo_funcao args");}
#line 1533 "parser.tab.c"
    break;

  case 6:
#line 71 "parser.y"
                                         {
        yyerrok;
        yyclearin;}
#line 1541 "parser.tab.c"
    break;

  case 7:
#line 77 "parser.y"
              {production_print("tipo_funcao -> CARACTERE");}
#line 1547 "parser.tab.c"
    break;

  case 8:
#line 78 "parser.y"
              {production_print("tipo_funcao -> INTEIRO");}
#line 1553 "parser.tab.c"
    break;

  case 9:
#line 79 "parser.y"
           {production_print("tipo_funcao -> REAL");}
#line 1559 "parser.tab.c"
    break;

  case 10:
#line 83 "parser.y"
                                   {production_print("args -> ARGS lista_vars FIMARGS codigo");}
#line 1565 "parser.tab.c"
    break;

  case 11:
#line 84 "parser.y"
             {production_print("args -> codigo");}
#line 1571 "parser.tab.c"
    break;

  case 12:
#line 85 "parser.y"
                                   {
        yyerrok;
        yyclearin;}
#line 1579 "parser.tab.c"
    break;

  case 13:
#line 91 "parser.y"
         {production_print("lista_vars -> vars");}
#line 1585 "parser.tab.c"
    break;

  case 14:
#line 92 "parser.y"
                      {production_print("lista_vars -> lista_vars vars");}
#line 1591 "parser.tab.c"
    break;

  case 15:
#line 96 "parser.y"
                                 {production_print("vars -> tipo ID_OU_FUNC PONTO_E_VIRG"); }
#line 1597 "parser.tab.c"
    break;

  case 16:
#line 97 "parser.y"
                                        {production_print("vars -> tipo ID_OU_FUNC VIRGULA vars_cont");}
#line 1603 "parser.tab.c"
    break;

  case 17:
#line 98 "parser.y"
                                           {production_print("vars -> tipo ID_OU_FUNC ATRIBUICAO atribuido"); aux = get_type(sym_table, (yyvsp[-2].str), escopo);}
#line 1609 "parser.tab.c"
    break;

  case 18:
#line 99 "parser.y"
                                {}
#line 1615 "parser.tab.c"
    break;

  case 19:
#line 100 "parser.y"
                              {
        yyerrok;
        yyclearin;}
#line 1623 "parser.tab.c"
    break;

  case 20:
#line 103 "parser.y"
                           {
        yyerrok;
        yyclearin;}
#line 1631 "parser.tab.c"
    break;

  case 21:
#line 106 "parser.y"
                                   {
         yyerrok;
        yyclearin;}
#line 1639 "parser.tab.c"
    break;

  case 22:
#line 112 "parser.y"
                                 {production_print("vars_cont -> ID_OU_FUNC VIRGULA vars_cont");}
#line 1645 "parser.tab.c"
    break;

  case 23:
#line 113 "parser.y"
                              {production_print("vars_cont -> ID_OU_FUNC PONTO_E_VIRG");}
#line 1651 "parser.tab.c"
    break;

  case 24:
#line 114 "parser.y"
                             {
        yyerrok;
        yyclearin;}
#line 1659 "parser.tab.c"
    break;

  case 25:
#line 117 "parser.y"
                      {
        yyerrok;
        yyclearin;}
#line 1667 "parser.tab.c"
    break;

  case 26:
#line 123 "parser.y"
              {production_print("tipo -> CARACTERE");}
#line 1673 "parser.tab.c"
    break;

  case 27:
#line 124 "parser.y"
              {production_print("tipo -> INTEIRO");}
#line 1679 "parser.tab.c"
    break;

  case 28:
#line 125 "parser.y"
           {production_print("tipo -> REAL");}
#line 1685 "parser.tab.c"
    break;

  case 29:
#line 129 "parser.y"
                {production_print("codigo -> vars codigo");}
#line 1691 "parser.tab.c"
    break;

  case 30:
#line 130 "parser.y"
                                          {production_print("codigo -> ESCREVA LITERAL PONTO_E_VIRG codigo");}
#line 1697 "parser.tab.c"
    break;

  case 31:
#line 131 "parser.y"
                                             {production_print("codigo -> ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo");
        if(get_type(sym_table, (yyvsp[-2].str), escopo) != "literal") printf("\033[31mErro:%d:%d: 'escreva' espera tipo 'literal' e '%s' é '%s'\n\033[0m", line_num, col_num, (yyvsp[-2].str), get_type(sym_table, (yyvsp[-2].str), escopo));
        error++;
    }
#line 1706 "parser.tab.c"
    break;

  case 32:
#line 135 "parser.y"
                                             {production_print("codigo -> ID_OU_FUNC ATRIBUICAO atribuido codigo");aux = get_type(sym_table, (yyvsp[-2].str), escopo);}
#line 1712 "parser.tab.c"
    break;

  case 33:
#line 136 "parser.y"
                                                   {production_print("codigo -> CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo");}
#line 1718 "parser.tab.c"
    break;

  case 34:
#line 137 "parser.y"
                      {production_print("codigo -> se_entao codigo");}
#line 1724 "parser.tab.c"
    break;

  case 35:
#line 138 "parser.y"
                                                                      {production_print("codigo -> ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo");}
#line 1730 "parser.tab.c"
    break;

  case 36:
#line 139 "parser.y"
                                             {production_print("codigo -> RETORNA ID_OU_FUNC PONTO_E_VIRG codigo");}
#line 1736 "parser.tab.c"
    break;

  case 37:
#line 140 "parser.y"
                    {production_print("codigo -> FIMFUNCAO");}
#line 1742 "parser.tab.c"
    break;

  case 38:
#line 141 "parser.y"
                         {production_print("codigo -> FIMFUNCAO");}
#line 1748 "parser.tab.c"
    break;

  case 39:
#line 142 "parser.y"
      {production_print("codigo -> epsilon");}
#line 1754 "parser.tab.c"
    break;

  case 40:
#line 143 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 1762 "parser.tab.c"
    break;

  case 41:
#line 146 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 1770 "parser.tab.c"
    break;

  case 42:
#line 149 "parser.y"
                               {
        yyerrok;
        yyclearin;}
#line 1778 "parser.tab.c"
    break;

  case 43:
#line 152 "parser.y"
                               {
        yyerrok;
        yyclearin;}
#line 1786 "parser.tab.c"
    break;

  case 44:
#line 155 "parser.y"
                {
        yyerrok;
        yyclearin;}
#line 1794 "parser.tab.c"
    break;

  case 45:
#line 158 "parser.y"
                     {
        yyerrok;
        yyclearin;}
#line 1802 "parser.tab.c"
    break;

  case 46:
#line 164 "parser.y"
                         {production_print("atribuido -> LITERAL PONTO_E_VIRG"); checkType(aux, "literal");}
#line 1808 "parser.tab.c"
    break;

  case 47:
#line 165 "parser.y"
                          {production_print("atribuido -> NUMERO PONTO_E_VIRG"); checkType(aux, "inteiro");}
#line 1814 "parser.tab.c"
    break;

  case 48:
#line 166 "parser.y"
                           {checkType(aux, "real");}
#line 1820 "parser.tab.c"
    break;

  case 49:
#line 167 "parser.y"
                                                    {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG");
        error++; 
        printf("\033[31mError:%d:%d: Operador não pode ser literal: %s: 'literal'\033[0m\n", line_num, col_num, (yyvsp[-1].str));
    }
#line 1829 "parser.tab.c"
    break;

  case 50:
#line 171 "parser.y"
                                                   {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG");
        if(checkType(aux, mathCheck((yyvsp[-3].str), "inteiro", (yyvsp[-2].str))) == 0) update_value(sym_table, aux, escopo, get_value(sym_table, (yyvsp[-3].str), escopo));
    }
#line 1837 "parser.tab.c"
    break;

  case 51:
#line 174 "parser.y"
                                                    {
        if(checkType(aux, mathCheck((yyvsp[-3].str), "real", (yyvsp[-2].str))) == 0) update_value(sym_table, aux, escopo, get_value(sym_table, (yyvsp[-3].str), escopo));
    }
#line 1845 "parser.tab.c"
    break;

  case 52:
#line 177 "parser.y"
                                                       {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG");
        if(checkType(aux, idsMathCheck((yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[-2].str))) == 0) update_value(sym_table, aux, escopo, get_value(sym_table, (yyvsp[-3].str), escopo));
    }
#line 1853 "parser.tab.c"
    break;

  case 53:
#line 180 "parser.y"
                                          {production_print("atribuido -> CHAMA CHAMADA lista_id PONTO_E_VIRG");}
#line 1859 "parser.tab.c"
    break;

  case 54:
#line 181 "parser.y"
                         {
        yyerrok;
        yyclearin;}
#line 1867 "parser.tab.c"
    break;

  case 55:
#line 184 "parser.y"
                       {
        yyerrok;
        yyclearin;}
#line 1875 "parser.tab.c"
    break;

  case 56:
#line 187 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 1883 "parser.tab.c"
    break;

  case 57:
#line 193 "parser.y"
                        {production_print("lista_id -> ID_OU_FUNC lista_id");}
#line 1889 "parser.tab.c"
    break;

  case 58:
#line 194 "parser.y"
      {production_print("lista_id -> epsilon");}
#line 1895 "parser.tab.c"
    break;

  case 60:
#line 199 "parser.y"
                                                           {production_print("se_entao -> SE ABRE_PAR cond FECHA_PAR ENTAO codigo senao_op FIMSE");}
#line 1901 "parser.tab.c"
    break;

  case 61:
#line 200 "parser.y"
                                                          {
        yyerrok;
        yyclearin;}
#line 1909 "parser.tab.c"
    break;

  case 62:
#line 203 "parser.y"
                                                         {
        yyerrok;
        yyclearin;}
#line 1917 "parser.tab.c"
    break;

  case 63:
#line 206 "parser.y"
                                                             {
        yyerrok;
        yyclearin;}
#line 1925 "parser.tab.c"
    break;

  case 64:
#line 212 "parser.y"
                 {production_print("senao_op -> SENAO codigo");}
#line 1931 "parser.tab.c"
    break;

  case 65:
#line 213 "parser.y"
      {production_print("senao_op -> epsilon");}
#line 1937 "parser.tab.c"
    break;

  case 66:
#line 217 "parser.y"
                                        {production_print("cond -> ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC"); idsCheckType((yyvsp[-2].str), (yyvsp[0].str));}
#line 1943 "parser.tab.c"
    break;

  case 67:
#line 218 "parser.y"
                                      {production_print("cond -> ID_OU_FUNC OP_RELACIONAL NUMERO"); checkType((yyvsp[-2].str), "inteiro");}
#line 1949 "parser.tab.c"
    break;

  case 68:
#line 219 "parser.y"
                                       {checkType((yyvsp[-2].str), "real");}
#line 1955 "parser.tab.c"
    break;

  case 69:
#line 220 "parser.y"
                                       {production_print("cond -> ID_OU_FUNC OP_RELACIONAL LITERAL"); checkType((yyvsp[-2].str), "literal");}
#line 1961 "parser.tab.c"
    break;

  case 70:
#line 221 "parser.y"
                                      {production_print("cond -> NUMERO OP_RELACIONAL ID_OU_FUNC"); checkType((yyvsp[0].str), "inteiro");}
#line 1967 "parser.tab.c"
    break;

  case 71:
#line 222 "parser.y"
                                  {production_print("cond -> NUMERO OP_RELACIONAL NUMERO");}
#line 1973 "parser.tab.c"
    break;

  case 72:
#line 223 "parser.y"
                                   {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'inteiro', mas '%s' é: 'real'\n", line_num, col_num, (yyvsp[-2].str), (yyvsp[0].str));}
#line 1979 "parser.tab.c"
    break;

  case 73:
#line 224 "parser.y"
                                   {production_print("cond -> NUMERO OP_RELACIONAL LITERAL");error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'inteiro', mas '%s' é: 'literal'\n", line_num, col_num, (yyvsp[-2].str), (yyvsp[0].str));}
#line 1985 "parser.tab.c"
    break;

  case 74:
#line 225 "parser.y"
                                       {checkType((yyvsp[0].str), "real");}
#line 1991 "parser.tab.c"
    break;

  case 75:
#line 226 "parser.y"
                                   {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'real', mas '%s' é: 'inteiro'\n", line_num, col_num, (yyvsp[-2].str), (yyvsp[0].str));}
#line 1997 "parser.tab.c"
    break;

  case 76:
#line 227 "parser.y"
                                    {}
#line 2003 "parser.tab.c"
    break;

  case 77:
#line 228 "parser.y"
                                    {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'real', mas '%s' é: 'literal'\n", line_num, col_num, (yyvsp[-2].str), (yyvsp[0].str));}
#line 2009 "parser.tab.c"
    break;

  case 78:
#line 229 "parser.y"
                                       {production_print("cond -> LITERAL OP_RELACIONAL ID_OU_FUNC");checkType((yyvsp[0].str), "literal");}
#line 2015 "parser.tab.c"
    break;

  case 79:
#line 230 "parser.y"
                                   {production_print("cond -> LITERAL OP_RELACIONAL NUMERO"); error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'literal', mas '%s' é: 'inteiro'\n", line_num, col_num, (yyvsp[-2].str), (yyvsp[0].str));}
#line 2021 "parser.tab.c"
    break;

  case 80:
#line 231 "parser.y"
                                    {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'literal', mas '%s' é: 'real'\n", line_num, col_num, (yyvsp[-2].str), (yyvsp[0].str));}
#line 2027 "parser.tab.c"
    break;

  case 81:
#line 232 "parser.y"
                                    {production_print("cond -> LITERAL OP_RELACIONAL LITERAL");}
#line 2033 "parser.tab.c"
    break;

  case 82:
#line 233 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 2041 "parser.tab.c"
    break;

  case 83:
#line 236 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 2049 "parser.tab.c"
    break;

  case 84:
#line 239 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 2057 "parser.tab.c"
    break;

  case 85:
#line 242 "parser.y"
                                 {
        yyerrok;
        yyclearin;}
#line 2065 "parser.tab.c"
    break;

  case 86:
#line 245 "parser.y"
                          {
        yyerrok;
        yyclearin;}
#line 2073 "parser.tab.c"
    break;

  case 87:
#line 248 "parser.y"
                                 {
        yyerrok;
        yyclearin;}
#line 2081 "parser.tab.c"
    break;

  case 88:
#line 251 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 2089 "parser.tab.c"
    break;

  case 89:
#line 254 "parser.y"
                            {
        yyerrok;
        yyclearin;}
#line 2097 "parser.tab.c"
    break;

  case 90:
#line 257 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 2105 "parser.tab.c"
    break;

  case 91:
#line 263 "parser.y"
               {production_print("nome_funcao -> ID_OU_FUNC");}
#line 2111 "parser.tab.c"
    break;


#line 2115 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 269 "parser.y"



void yyerror(const char *s) {
    printf("\033[31mSyntax error: Erro de sintaxe na linha %d, coluna %d: %s\033[0m\n", line_num, col_num, s);
}

void production_print(const char* production) {
    if(verb == 1){
        fprintf(stdout, "Produção utilizada: %s\n", production);
    }
}

int checkType( char *name, char *encounteredType) {
    char *c = get_type(sym_table, name, escopo);
    if(strcmp(c,"error") == 0){
        error++;
        return 1;
    }
    if(strcmp(c,"Não encontrado") == 0){
        error++;
        printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, name);
        return 1;
    }
    if(strcmp(c, encounteredType) == 0){
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com operador\n", line_num, col_num, name);
        }
        return 0;
    }else{
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s', mas encontrado: '%s'\033[0m\n", line_num, col_num, name, c, encounteredType);
        return 2;
    }
}

int idsCheckType( char *name, char *name2) {
    char *c = get_type(sym_table, name, escopo);
    char *t = get_type(sym_table, name2, escopo);
    if(strcmp(c,"Não encontrado") == 0 || strcmp(t,"Não encontrado") == 0){
        if(strcmp(c,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, name);
        }
        if(strcmp(t,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, name2);
        }
        return 1;
    }
    if(strcmp(c, t) == 0){
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s\033", line_num, col_num, name, name2);
        }
        return 0;
    }else{
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s', mas '%s' possui tipo: '%s'\033[0m\n", line_num, col_num, name, c, name2, t);
        return 2;
    }
}
char* idsMathCheck(char *ar1, char *ar2, char *op){
    char *c = get_type(sym_table, ar1, escopo);
    char *t = get_type(sym_table, ar2, escopo);
    char *c1 = get_value(sym_table, ar1, escopo);
    char *t1 = get_value(sym_table, ar2, escopo);
    if(strcmp(c,"Não encontrado") == 0 || strcmp(t,"Não encontrado") == 0){
        if(strcmp(c,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, ar1);
        }
        if(strcmp(t,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, ar2);
        }
        return "error";
    }
    if(strcmp(c, t) != 0){
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s' para realizar a operação: '%s', mas '%s' possui tipo: '%s'\033[0m\n", line_num, col_num, ar1, c, op, ar2, t);
        return "error";
    }else{
        if(strcmp(op,"/") == 0){
            if(strcmp(t1,"0") == 0 || strcmp(t1,"0.0") == 0 ){
                error++;
                printf("\033[31mErro:%d:%d: Divisão por 0 detectada em: %s/%s\033[0m\n", line_num, col_num, ar1, ar2);
                return "error";
            }
            if(c1 == "NULL" || t1 == "NULL"){
                if(c1 == "NULL"){
                    error++;
                    printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
                    return "error";
                }
                if(t1 == "NULL"){
                    error++;
                    printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, t);
                    return "error";
                }
            }
        }
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s e operação aritimética viável\n", line_num, col_num, ar1, ar2);
        }
        return c;
    }
}

char* idMathCheck(char *ar1, char *ar2, char *op, char *ar2type){
    char *c = get_type(sym_table, ar1, escopo);
    char *c1 = get_value(sym_table, ar1, escopo);
    if(strcmp(c,"Não encontrado") == 0){
        if(strcmp(c,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, ar1);
        }
        return "error";
    }
    if(strcmp(c, ar2type) != 0){
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s' para realizar a operação: '%s', mas '%s' possui tipo: '%s'\033[0m\n", line_num, col_num, ar1, c, op, ar2, ar2type);
        return "error";
    }else{
        if(strcmp(op,"/") == 0){
            if(strcmp(ar2,"0") == 0 || strcmp(ar2,"0.0") == 0 ){
                error++;
                printf("\033[31mErro:%d:%d: Divisão por 0 detectada em: %s/%s\033[0m\n", line_num, col_num, ar1, ar2);
                return "error";
            }
            if(strcmp(ar2,"NULL") == 0){                
                error++;
                printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
                return "error";
            }
        }
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s e operação aritimética viável\n", line_num, col_num, ar1, ar2);
        }
        return c;
    }
}

char* mathCheck(char *ar1, char *ar2, char *op){
    char *c = get_type(sym_table, ar1, escopo);
    char *c1 = get_value(sym_table, ar1, escopo);
    if(strcmp(op,"/") == 0){
        if(strcmp(ar2,"0") == 0 || strcmp(ar2,"0.0") == 0 ){
            error++;
            printf("\033[31mErro:%d:%d: Divisão por 0 detectada em: %s/%s\033[0m\n", line_num, col_num, ar1, ar2);
            return "error";
        }
        if(strcmp(c1 ,"NULL") == 0){                
            error++;
            printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
            return "error";
        }
        if(strcmp(ar2,"NULL") == 0){                
            error++;
            printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
            return "error";
        }
    }
    if(verbose == 1){
        printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s e operação aritimética viável\n", line_num, col_num, ar1, ar2);
    }
    return c;
}

int main(int argc, char **argv) {
    int out;
    sym_table = (struct hashMap*) malloc(sizeof(struct hashMap));
    initializeHashMap(sym_table);
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
        if (yyin == NULL) {
            printf("\033[31mFile not found!\033[0m\n");
            exit(1);
        }
    }
    out=yyparse();

    if(error == 0){
        printf("Compilado com sucesso!\n");
    }else{
        printf("\033[31mCompilador falhou!\033[0m\n");
    }
    

    if(!out) {// yyparse == 0 - parsing completed
        fclose(yyin);
    }
    else { //yyparse()==1 - could not complete parsing
        fclose(yyin); // close input file
    }

    free_symbol_table(sym_table);

    return 0;
}
