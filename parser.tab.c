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

int verb = 1; //1 to activate verbose mode
char* aux;
int i = 0;
int error = 0;
extern int line_num;
extern int col_num;
extern int eof;
extern int func;


#line 95 "parser.tab.c"

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
    INTEIRO = 266,
    REAL = 267,
    CARACTERE = 268,
    SE = 269,
    ENTAO = 270,
    FIMSE = 271,
    ENQUANTO = 272,
    FACA = 273,
    FIMENQUANTO = 274,
    CHAMADA = 275,
    SENAO = 276,
    ID_OU_FUNC = 277,
    NUMERO = 278,
    LITERAL = 279,
    OP_RELACIONAL = 280,
    OP_ARITMETICO = 281,
    ATRIBUICAO = 282,
    ABRE_PAR = 283,
    FECHA_PAR = 284,
    VIRGULA = 285,
    PONTO_E_VIRG = 286,
    COMENTARIO = 287,
    FIM_DE_ARQ = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    char *str;
    int num;
    float fnum;

#line 187 "parser.tab.c"

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
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


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
       2,     2,    36,    34,     2,    35,     2,    37,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    53,    59,    60,    61,    67,    68,    69,
      73,    74,    75,    81,    82,    86,    87,    88,    89,    92,
      95,   101,   102,   103,   106,   112,   113,   114,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     132,   135,   138,   141,   144,   150,   151,   152,   153,   154,
     155,   156,   159,   162,   168,   169,   170,   174,   175,   178,
     181,   187,   188,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   204,   207,   210,   213,   216,   219,   222,
     225,   231,   235
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCAO", "FIMFUNCAO", "CHAMA",
  "RETORNA", "TIPO", "ARGS", "FIMARGS", "ESCREVA", "INTEIRO", "REAL",
  "CARACTERE", "SE", "ENTAO", "FIMSE", "ENQUANTO", "FACA", "FIMENQUANTO",
  "CHAMADA", "SENAO", "ID_OU_FUNC", "NUMERO", "LITERAL", "OP_RELACIONAL",
  "OP_ARITMETICO", "ATRIBUICAO", "ABRE_PAR", "FECHA_PAR", "VIRGULA",
  "PONTO_E_VIRG", "COMENTARIO", "FIM_DE_ARQ", "'+'", "'-'", "'*'", "'/'",
  "$accept", "programa", "assinatura", "tipo_funcao", "args", "lista_vars",
  "vars", "vars_cont", "tipo", "codigo", "atribuido", "lista_id",
  "se_entao", "senao_op", "cond", "nome_funcao", "eof", YY_NULLPTR
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
     285,   286,   287,   288,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -15,   -15,    22,   -47,   -47,   119,   -47,   -47,     1,
       8,    -5,    46,    91,   164,    89,   -47,   -47,   -47,    27,
      45,    85,   -47,   168,    59,   -47,   168,   -47,   -47,   -47,
      97,   168,   -47,   -47,   145,   -47,   -47,   -47,   112,     5,
     145,   120,   257,   -47,    15,    17,    65,    65,    65,    62,
      16,   -47,   113,     0,   -47,   -47,   -47,   -47,   116,   -47,
     168,   -47,   191,   168,   -47,   168,   168,   168,   168,   127,
      32,    55,    58,   125,    23,   131,   132,   163,    28,   155,
     157,   168,   -47,   -47,    62,    60,   -47,   168,   -47,    43,
     -47,   -47,   -47,   -47,   -47,   -47,    83,   171,    68,   175,
      71,   170,    74,   184,   185,    61,   188,   -47,     4,   -47,
      77,   -47,   -47,   -47,   -47,   179,    20,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   210,   210,   210,
     210,   224,     4,     4,   186,   -47,   187,   202,   208,    60,
     -47,    60,   -47,   198,   198,   198,   198,   221,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   243,   226,   229,   234,
     235,   168,   -47,   -47,   -47,   -47,   -47,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    81,     3,     0,     2,     1,     0,
       0,     0,     0,     0,     0,     0,    26,    27,    25,     0,
       0,     0,     4,     0,     0,    11,     0,     8,     9,     7,
       0,     0,    82,    44,     0,    43,    37,    36,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    33,    20,    42,     6,     0,    41,
       0,     5,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,     0,     0,    15,     0,    35,     0,
      12,    10,    39,    30,    40,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    46,    45,    31,    17,     0,     0,    16,    32,    72,
      75,    78,    73,    74,    63,    64,    65,    76,    77,    66,
      67,    68,    79,    80,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
      24,     0,    22,    62,    62,    62,    62,     0,    56,    54,
      50,    49,    48,    47,    23,    21,     0,     0,     0,     0,
       0,     0,    61,    58,    59,    60,    57,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,    10,   250,   248,    31,   -47,    11,   -12,   -47,   -23,
     178,   -21,   -47,   -46,   123,   -47,   253
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,     5,    34,    22,    42,    23,   117,    24,    25,
      81,   144,    26,   167,    73,     6,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    83,     1,    54,     2,   142,    59,     4,    56,     1,
       3,     2,    27,    28,    29,    38,    65,     1,    67,     2,
      36,   150,     8,    30,   104,    43,   143,    84,    46,   109,
      85,    86,    31,    97,    32,   -55,    60,    88,    30,    90,
      91,    32,    92,    93,    94,    95,    66,    31,    68,    32,
     151,   152,   105,    64,   110,    47,    99,    98,   113,   101,
      52,   115,   139,    76,   118,    57,    69,    77,    39,   123,
      49,    61,   128,    48,    55,   133,   140,     1,   145,     2,
     100,    53,   116,   102,    78,    79,    80,    70,    71,    72,
     124,   125,   126,   129,   130,   131,   134,   135,   136,   146,
     147,   148,    27,    28,    29,   119,   120,   121,   168,   169,
     170,    44,    49,    45,   153,   154,   155,   156,   157,   -38,
       9,   158,   159,    10,    11,    12,    13,    14,    55,    15,
      16,    17,    18,    19,    58,   -38,    20,   164,   -38,   165,
     -38,    21,    30,   172,    82,   -38,    50,    87,   177,    10,
      11,    12,    96,    14,   103,    15,    16,    17,    18,    19,
     106,   -38,    20,   107,   -38,    41,   -38,    21,   -38,    50,
      74,    75,    10,    11,    12,    16,    17,    18,    15,    16,
      17,    18,    19,   108,   -38,    20,   111,   -38,   112,   -38,
      21,   -38,    50,   122,   132,    10,    11,    12,   127,   137,
     138,    15,    16,    17,    18,    19,   141,   -38,    20,   149,
     -38,    50,   -38,    89,    10,    11,    12,   160,   161,   166,
      15,    16,    17,    18,    19,    50,   -38,    20,    10,    11,
      12,   -38,    21,   162,    15,    16,    17,    18,    19,   163,
     171,    20,   173,   -38,    50,   174,    21,    10,    11,    12,
     175,   176,     7,    15,    16,    17,    18,    19,    62,   -38,
      20,    40,   114,    37,     0,    21,    63,     0,    16,    17,
      18
};

static const yytype_int16 yycheck[] =
{
      23,     1,     1,    26,     3,     1,     1,    22,    31,     1,
       0,     3,    11,    12,    13,    20,     1,     1,     1,     3,
      10,     1,     0,    22,     1,    14,    22,    27,     1,     1,
      30,    31,    31,     1,    33,    31,    31,    60,    22,    62,
      63,    33,    65,    66,    67,    68,    31,    31,    31,    33,
      30,    31,    29,    42,    26,    28,     1,    25,    81,     1,
       1,     1,     1,     1,    87,    34,     1,     5,    22,     1,
      27,    40,     1,    28,    31,     1,    15,     1,     1,     3,
      25,    22,    22,    25,    22,    23,    24,    22,    23,    24,
      22,    23,    24,    22,    23,    24,    22,    23,    24,    22,
      23,    24,    11,    12,    13,    22,    23,    24,   154,   155,
     156,    22,    27,    24,   137,   138,   139,   140,   141,     0,
       1,   142,   143,     4,     5,     6,     7,     8,    31,    10,
      11,    12,    13,    14,    22,    16,    17,   149,    19,   151,
      21,    22,    22,   166,    31,     0,     1,    31,   171,     4,
       5,     6,    25,     8,    29,    10,    11,    12,    13,    14,
      29,    16,    17,    31,    19,     1,    21,    22,     0,     1,
      47,    48,     4,     5,     6,    11,    12,    13,    10,    11,
      12,    13,    14,    20,    16,    17,    31,    19,    31,    21,
      22,     0,     1,    22,    24,     4,     5,     6,    23,    15,
      15,    10,    11,    12,    13,    14,    18,    16,    17,    30,
      19,     1,    21,    22,     4,     5,     6,    31,    31,    21,
      10,    11,    12,    13,    14,     1,    16,    17,     4,     5,
       6,    21,    22,    31,    10,    11,    12,    13,    14,    31,
      19,    17,    16,    19,     1,    16,    22,     4,     5,     6,
      16,    16,     2,    10,    11,    12,    13,    14,     1,    16,
      17,    13,    84,    10,    -1,    22,     9,    -1,    11,    12,
      13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    39,    22,    40,    53,    40,     0,     1,
       4,     5,     6,     7,     8,    10,    11,    12,    13,    14,
      17,    22,    42,    44,    46,    47,    50,    11,    12,    13,
      22,    31,    33,    39,    41,    54,    39,    54,    20,    22,
      41,     1,    43,    44,    22,    24,     1,    28,    28,    27,
       1,    47,     1,    22,    47,    31,    47,    42,    22,     1,
      31,    42,     1,     9,    44,     1,    31,     1,    31,     1,
      22,    23,    24,    52,    52,    52,     1,     5,    22,    23,
      24,    48,    31,     1,    27,    30,    31,    31,    47,    22,
      47,    47,    47,    47,    47,    47,    25,     1,    25,     1,
      25,     1,    25,    29,     1,    29,    29,    31,    20,     1,
      26,    31,    31,    47,    48,     1,    22,    45,    47,    22,
      23,    24,    22,     1,    22,    23,    24,    23,     1,    22,
      23,    24,    24,     1,    22,    23,    24,    15,    15,     1,
      15,    18,     1,    22,    49,     1,    22,    23,    24,    30,
       1,    30,    31,    47,    47,    47,    47,    47,    49,    49,
      31,    31,    31,    31,    45,    45,    21,    51,    51,    51,
      51,    19,    47,    16,    16,    16,    16,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    40,    41,    41,    41,
      42,    42,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    49,    50,    50,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       4,     1,     4,     1,     2,     3,     4,     4,     3,     3,
       3,     3,     2,     3,     2,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     8,     4,     2,     2,     0,     4,
       4,     3,     3,     2,     2,     2,     2,     4,     4,     4,
       4,     2,     2,     3,     2,     0,     2,     8,     8,     8,
       8,     2,     0,     3,     3,     3,     3,     3,     3,     3,
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
#line 52 "parser.y"
                      { func--; production_print("programa -> FUNCAO assinatura");if(eof == 1 && func == 0) return 0;}
#line 1493 "parser.tab.c"
    break;

  case 3:
#line 53 "parser.y"
                      {
        yyerrok;
        yyclearin;if(eof == 1) return 0;}
#line 1501 "parser.tab.c"
    break;

  case 4:
#line 59 "parser.y"
                     {production_print("assinatura -> nome_funcao args");}
#line 1507 "parser.tab.c"
    break;

  case 5:
#line 60 "parser.y"
                                        {production_print("assinatura -> nome_funcao TIPO tipo_funcao args");}
#line 1513 "parser.tab.c"
    break;

  case 6:
#line 61 "parser.y"
                                         {
        yyerrok;
        yyclearin;}
#line 1521 "parser.tab.c"
    break;

  case 7:
#line 67 "parser.y"
              {production_print("tipo_funcao -> CARACTERE");}
#line 1527 "parser.tab.c"
    break;

  case 8:
#line 68 "parser.y"
              {production_print("tipo_funcao -> INTEIRO");}
#line 1533 "parser.tab.c"
    break;

  case 9:
#line 69 "parser.y"
           {production_print("tipo_funcao -> REAL");}
#line 1539 "parser.tab.c"
    break;

  case 10:
#line 73 "parser.y"
                                   {production_print("args -> ARGS lista_vars FIMARGS codigo");}
#line 1545 "parser.tab.c"
    break;

  case 11:
#line 74 "parser.y"
             {production_print("args -> codigo");}
#line 1551 "parser.tab.c"
    break;

  case 12:
#line 75 "parser.y"
                                   {
        yyerrok;
        yyclearin;}
#line 1559 "parser.tab.c"
    break;

  case 13:
#line 81 "parser.y"
         {production_print("lista_vars -> vars");}
#line 1565 "parser.tab.c"
    break;

  case 14:
#line 82 "parser.y"
                      {production_print("lista_vars -> lista_vars vars");}
#line 1571 "parser.tab.c"
    break;

  case 15:
#line 86 "parser.y"
                                 {production_print("vars -> tipo ID_OU_FUNC PONTO_E_VIRG");}
#line 1577 "parser.tab.c"
    break;

  case 16:
#line 87 "parser.y"
                                        {production_print("vars -> tipo ID_OU_FUNC VIRGULA vars_cont");}
#line 1583 "parser.tab.c"
    break;

  case 17:
#line 88 "parser.y"
                                           {production_print("vars -> tipo ID_OU_FUNC ATRIBUICAO atribuido");}
#line 1589 "parser.tab.c"
    break;

  case 18:
#line 89 "parser.y"
                              {
        yyerrok;
        yyclearin;}
#line 1597 "parser.tab.c"
    break;

  case 19:
#line 92 "parser.y"
                           {
        yyerrok;
        yyclearin;}
#line 1605 "parser.tab.c"
    break;

  case 20:
#line 95 "parser.y"
                                   {
         yyerrok;
        yyclearin;}
#line 1613 "parser.tab.c"
    break;

  case 21:
#line 101 "parser.y"
                                 {production_print("vars_cont -> ID_OU_FUNC VIRGULA vars_cont");}
#line 1619 "parser.tab.c"
    break;

  case 22:
#line 102 "parser.y"
                              {production_print("vars_cont -> ID_OU_FUNC PONTO_E_VIRG");}
#line 1625 "parser.tab.c"
    break;

  case 23:
#line 103 "parser.y"
                             {
        yyerrok;
        yyclearin;}
#line 1633 "parser.tab.c"
    break;

  case 24:
#line 106 "parser.y"
                      {
        yyerrok;
        yyclearin;}
#line 1641 "parser.tab.c"
    break;

  case 25:
#line 112 "parser.y"
              {production_print("tipo -> CARACTERE");}
#line 1647 "parser.tab.c"
    break;

  case 26:
#line 113 "parser.y"
              {production_print("tipo -> INTEIRO");}
#line 1653 "parser.tab.c"
    break;

  case 27:
#line 114 "parser.y"
           {production_print("tipo -> REAL");}
#line 1659 "parser.tab.c"
    break;

  case 28:
#line 118 "parser.y"
                {production_print("codigo -> vars codigo");}
#line 1665 "parser.tab.c"
    break;

  case 29:
#line 119 "parser.y"
                                          {production_print("codigo -> ESCREVA LITERAL PONTO_E_VIRG codigo");}
#line 1671 "parser.tab.c"
    break;

  case 30:
#line 120 "parser.y"
                                             {production_print("codigo -> ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo");}
#line 1677 "parser.tab.c"
    break;

  case 31:
#line 121 "parser.y"
                                             {production_print("codigo -> ID_OU_FUNC ATRIBUICAO atribuido codigo");}
#line 1683 "parser.tab.c"
    break;

  case 32:
#line 122 "parser.y"
                                                   {production_print("codigo -> CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo");}
#line 1689 "parser.tab.c"
    break;

  case 33:
#line 123 "parser.y"
                      {production_print("codigo -> se_entao codigo");}
#line 1695 "parser.tab.c"
    break;

  case 34:
#line 124 "parser.y"
                                                                      {production_print("codigo -> ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo");}
#line 1701 "parser.tab.c"
    break;

  case 35:
#line 125 "parser.y"
                                             {production_print("codigo -> RETORNA ID_OU_FUNC PONTO_E_VIRG codigo");}
#line 1707 "parser.tab.c"
    break;

  case 36:
#line 126 "parser.y"
                    {production_print("codigo -> FIMFUNCAO");}
#line 1713 "parser.tab.c"
    break;

  case 37:
#line 127 "parser.y"
                         {production_print("codigo -> FIMFUNCAO");}
#line 1719 "parser.tab.c"
    break;

  case 38:
#line 128 "parser.y"
      {production_print("codigo -> epsilon");}
#line 1725 "parser.tab.c"
    break;

  case 39:
#line 129 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 1733 "parser.tab.c"
    break;

  case 40:
#line 132 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 1741 "parser.tab.c"
    break;

  case 41:
#line 135 "parser.y"
                               {
        yyerrok;
        yyclearin;}
#line 1749 "parser.tab.c"
    break;

  case 42:
#line 138 "parser.y"
                               {
        yyerrok;
        yyclearin;}
#line 1757 "parser.tab.c"
    break;

  case 43:
#line 141 "parser.y"
                {
        yyerrok;
        yyclearin;}
#line 1765 "parser.tab.c"
    break;

  case 44:
#line 144 "parser.y"
                     {
        yyerrok;
        yyclearin;}
#line 1773 "parser.tab.c"
    break;

  case 45:
#line 150 "parser.y"
                         {production_print("atribuido -> LITERAL PONTO_E_VIRG");}
#line 1779 "parser.tab.c"
    break;

  case 46:
#line 151 "parser.y"
                          {production_print("atribuido -> NUMERO PONTO_E_VIRG");}
#line 1785 "parser.tab.c"
    break;

  case 47:
#line 152 "parser.y"
                                                    {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG");}
#line 1791 "parser.tab.c"
    break;

  case 48:
#line 153 "parser.y"
                                                   {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG");}
#line 1797 "parser.tab.c"
    break;

  case 49:
#line 154 "parser.y"
                                                       {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG");}
#line 1803 "parser.tab.c"
    break;

  case 50:
#line 155 "parser.y"
                                          {production_print("atribuido -> CHAMA CHAMADA lista_id PONTO_E_VIRG");}
#line 1809 "parser.tab.c"
    break;

  case 51:
#line 156 "parser.y"
                         {
        yyerrok;
        yyclearin;}
#line 1817 "parser.tab.c"
    break;

  case 52:
#line 159 "parser.y"
                       {
        yyerrok;
        yyclearin;}
#line 1825 "parser.tab.c"
    break;

  case 53:
#line 162 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 1833 "parser.tab.c"
    break;

  case 54:
#line 168 "parser.y"
                        {production_print("lista_id -> ID_OU_FUNC lista_id");}
#line 1839 "parser.tab.c"
    break;

  case 55:
#line 169 "parser.y"
      {production_print("lista_id -> epsilon");}
#line 1845 "parser.tab.c"
    break;

  case 57:
#line 174 "parser.y"
                                                           {production_print("se_entao -> SE ABRE_PAR cond FECHA_PAR ENTAO codigo senao_op FIMSE");}
#line 1851 "parser.tab.c"
    break;

  case 58:
#line 175 "parser.y"
                                                          {
        yyerrok;
        yyclearin;}
#line 1859 "parser.tab.c"
    break;

  case 59:
#line 178 "parser.y"
                                                         {
        yyerrok;
        yyclearin;}
#line 1867 "parser.tab.c"
    break;

  case 60:
#line 181 "parser.y"
                                                             {
        yyerrok;
        yyclearin;}
#line 1875 "parser.tab.c"
    break;

  case 61:
#line 187 "parser.y"
                 {production_print("senao_op -> SENAO codigo");}
#line 1881 "parser.tab.c"
    break;

  case 62:
#line 188 "parser.y"
      {production_print("senao_op -> epsilon");}
#line 1887 "parser.tab.c"
    break;

  case 63:
#line 192 "parser.y"
                                        {production_print("cond -> ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC");}
#line 1893 "parser.tab.c"
    break;

  case 64:
#line 193 "parser.y"
                                      {production_print("cond -> ID_OU_FUNC OP_RELACIONAL NUMERO");}
#line 1899 "parser.tab.c"
    break;

  case 65:
#line 194 "parser.y"
                                       {production_print("cond -> ID_OU_FUNC OP_RELACIONAL LITERAL");}
#line 1905 "parser.tab.c"
    break;

  case 66:
#line 195 "parser.y"
                                      {production_print("cond -> NUMERO OP_RELACIONAL ID_OU_FUNC");}
#line 1911 "parser.tab.c"
    break;

  case 67:
#line 196 "parser.y"
                                  {production_print("cond -> NUMERO OP_RELACIONAL NUMERO");}
#line 1917 "parser.tab.c"
    break;

  case 68:
#line 197 "parser.y"
                                   {production_print("cond -> NUMERO OP_RELACIONAL LITERAL");}
#line 1923 "parser.tab.c"
    break;

  case 69:
#line 198 "parser.y"
                                       {production_print("cond -> LITERAL OP_RELACIONAL ID_OU_FUNC");}
#line 1929 "parser.tab.c"
    break;

  case 70:
#line 199 "parser.y"
                                   {production_print("cond -> LITERAL OP_RELACIONAL NUMERO");}
#line 1935 "parser.tab.c"
    break;

  case 71:
#line 200 "parser.y"
                                    {production_print("cond -> LITERAL OP_RELACIONAL LITERAL");}
#line 1941 "parser.tab.c"
    break;

  case 72:
#line 201 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 1949 "parser.tab.c"
    break;

  case 73:
#line 204 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 1957 "parser.tab.c"
    break;

  case 74:
#line 207 "parser.y"
                                     {
        yyerrok;
        yyclearin;}
#line 1965 "parser.tab.c"
    break;

  case 75:
#line 210 "parser.y"
                                 {
        yyerrok;
        yyclearin;}
#line 1973 "parser.tab.c"
    break;

  case 76:
#line 213 "parser.y"
                          {
        yyerrok;
        yyclearin;}
#line 1981 "parser.tab.c"
    break;

  case 77:
#line 216 "parser.y"
                                 {
        yyerrok;
        yyclearin;}
#line 1989 "parser.tab.c"
    break;

  case 78:
#line 219 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 1997 "parser.tab.c"
    break;

  case 79:
#line 222 "parser.y"
                            {
        yyerrok;
        yyclearin;}
#line 2005 "parser.tab.c"
    break;

  case 80:
#line 225 "parser.y"
                                  {
        yyerrok;
        yyclearin;}
#line 2013 "parser.tab.c"
    break;

  case 81:
#line 231 "parser.y"
               {production_print("nome_funcao -> ID_OU_FUNC");}
#line 2019 "parser.tab.c"
    break;


#line 2023 "parser.tab.c"

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
#line 237 "parser.y"



void yyerror(const char *s) {
    printf("\033[31mSyntax error: Erro de sintaxe na linha %d, coluna %d: %s\033[0m\n", line_num, col_num, s);
}

void production_print(const char* production) {
    if(verb == 1){
        fprintf(stdout, "Produção utilizada: %s\n", production);
    }
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
            printf("File not found!\n");
            exit(1);
        }
    }
    out=yyparse();

    if(!out) {// yyparse == 0 - parsing completed
        printf("Syntax analyzer finished succesfully.\n");
        fclose(yyin);
        printf("File closed succesfully\n");
    }
    else { //yyparse()==1 - could not complete parsing
        printf("Syntax analyzer failed\n");
        fclose(yyin); // close input file
        printf("File closed succesfully\n");
    }

    free_symbol_table(sym_table);

    return 0;
}
