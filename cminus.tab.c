/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *msg);


#line 88 "cminus.tab.c"

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

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ELSE = 3,                       /* ELSE  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_MAIS = 9,                       /* MAIS  */
  YYSYMBOL_MENOS = 10,                     /* MENOS  */
  YYSYMBOL_VEZES = 11,                     /* VEZES  */
  YYSYMBOL_SOBRE = 12,                     /* SOBRE  */
  YYSYMBOL_MENORQ = 13,                    /* MENORQ  */
  YYSYMBOL_MENORI = 14,                    /* MENORI  */
  YYSYMBOL_MAIORQ = 15,                    /* MAIORQ  */
  YYSYMBOL_MAIORI = 16,                    /* MAIORI  */
  YYSYMBOL_IGUAL = 17,                     /* IGUAL  */
  YYSYMBOL_DIF = 18,                       /* DIF  */
  YYSYMBOL_PONVIR = 19,                    /* PONVIR  */
  YYSYMBOL_VIRG = 20,                      /* VIRG  */
  YYSYMBOL_EPAREN = 21,                    /* EPAREN  */
  YYSYMBOL_DPAREN = 22,                    /* DPAREN  */
  YYSYMBOL_ECOLCH = 23,                    /* ECOLCH  */
  YYSYMBOL_DCOLCH = 24,                    /* DCOLCH  */
  YYSYMBOL_ECHAVE = 25,                    /* ECHAVE  */
  YYSYMBOL_DCHAVE = 26,                    /* DCHAVE  */
  YYSYMBOL_RECEBE = 27,                    /* RECEBE  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_NUM = 29,                       /* NUM  */
  YYSYMBOL_ACOM = 30,                      /* ACOM  */
  YYSYMBOL_ERROR = 31,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_programa = 33,                  /* programa  */
  YYSYMBOL_decl_lista = 34,                /* decl_lista  */
  YYSYMBOL_decl = 35,                      /* decl  */
  YYSYMBOL_var_decl = 36,                  /* var_decl  */
  YYSYMBOL_fun_decl = 37,                  /* fun_decl  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_param_lista = 39,               /* param_lista  */
  YYSYMBOL_tipo_espec = 40,                /* tipo_espec  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_comp_decl = 42,                 /* comp_decl  */
  YYSYMBOL_local_decl = 43,                /* local_decl  */
  YYSYMBOL_stmt_lista = 44,                /* stmt_lista  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_exp_decl = 46,                  /* exp_decl  */
  YYSYMBOL_selec_decl = 47,                /* selec_decl  */
  YYSYMBOL_it_decl = 48,                   /* it_decl  */
  YYSYMBOL_retorno_decl = 49,              /* retorno_decl  */
  YYSYMBOL_exp = 50,                       /* exp  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simp_exp = 52,                  /* simp_exp  */
  YYSYMBOL_relacional = 53,                /* relacional  */
  YYSYMBOL_soma_exp = 54,                  /* soma_exp  */
  YYSYMBOL_soma = 55,                      /* soma  */
  YYSYMBOL_termo = 56,                     /* termo  */
  YYSYMBOL_mult = 57,                      /* mult  */
  YYSYMBOL_fator = 58,                     /* fator  */
  YYSYMBOL_ativ = 59,                      /* ativ  */
  YYSYMBOL_arg_lista = 60,                 /* arg_lista  */
  YYSYMBOL_ident = 61,                     /* ident  */
  YYSYMBOL_num = 62                        /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    26,    26,    28,    38,    40,    42,    45,    55,    67,
      80,    92,    93,   100,   110,   112,   118,   125,   130,   136,
     147,   151,   155,   157,   166,   172,   182,   188,   192,   196,
     200,   204,   209,   213,   215,   221,   229,   236,   240,   246,
     253,   258,   262,   270,   276,   281,   287,   293,   299,   305,
     311,   318,   324,   329,   334,   340,   346,   351,   356,   362,
     366,   370,   374,   379,   386,   393,   403,   408,   414
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ELSE", "IF", "INT",
  "RETURN", "VOID", "WHILE", "MAIS", "MENOS", "VEZES", "SOBRE", "MENORQ",
  "MENORI", "MAIORQ", "MAIORI", "IGUAL", "DIF", "PONVIR", "VIRG", "EPAREN",
  "DPAREN", "ECOLCH", "DCOLCH", "ECHAVE", "DCHAVE", "RECEBE", "ID", "NUM",
  "ACOM", "ERROR", "$accept", "programa", "decl_lista", "decl", "var_decl",
  "fun_decl", "params", "param_lista", "tipo_espec", "param", "comp_decl",
  "local_decl", "stmt_lista", "stmt", "exp_decl", "selec_decl", "it_decl",
  "retorno_decl", "exp", "var", "simp_exp", "relacional", "soma_exp",
  "soma", "termo", "mult", "fator", "ativ", "arg_lista", "ident", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      56,   -20,   -20,    14,    56,   -77,   -77,   -77,   -77,    24,
      11,   -77,   -77,   -77,    57,    10,    57,   -77,    29,    44,
      45,   -20,   -77,   -77,    49,    55,    64,    76,    70,    61,
      64,    12,   -77,   -77,   -77,    77,   -77,   -77,    81,   -20,
     -17,    84,   -77,     6,   -77,   -77,   -77,    50,    66,   -77,
     -77,   -77,   -77,   -77,    90,    85,   -77,   109,    37,   -77,
     -77,    67,   -77,   -77,     6,    -4,   -77,    95,     6,    93,
     -77,   -77,    78,   -77,   -77,   -77,     6,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,     6,     6,   -77,   -77,     6,
       1,     6,    94,   -77,   106,   -77,   -77,   -77,   -77,    43,
      37,   -77,   -77,   -77,    88,   105,    92,    92,     6,   -77,
     -77,   127,   -77,   -77,    92,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,    67,     0,
       0,     1,     3,     7,     0,     0,     0,    15,    12,     0,
      11,     0,    14,    68,     0,     0,     0,     0,    17,     0,
       0,     0,     9,    16,    13,     0,     8,    10,     0,     0,
       0,     0,    33,     0,    22,    24,    28,     0,     0,    26,
      27,    29,    30,    31,     0,    60,    40,    44,    52,    56,
      61,    41,    62,    18,     0,     0,    37,     0,     0,     0,
      20,    23,     0,    21,    25,    32,     0,    53,    54,    46,
      45,    47,    48,    49,    50,     0,     0,    57,    58,     0,
       0,     0,     0,    38,     0,    59,    19,    39,    60,    43,
      51,    55,    64,    66,     0,     0,     0,     0,     0,    63,
      42,    34,    36,    65,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   128,   -26,   -77,   115,   -77,   -77,   107,
      16,   -77,    86,   -47,   -77,   -77,   -77,   -77,   -40,   -76,
     -77,   -77,    51,   -77,    52,   -77,    46,   -77,   -77,     5,
     122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    19,    20,    21,    22,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    85,    57,    86,    58,    89,    59,    60,   104,    61,
      62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    74,    66,    69,    43,    45,     9,    10,     8,    98,
      98,     8,    23,    98,    11,    13,    38,    39,    40,    15,
      41,    71,    43,   102,    92,    74,    28,    43,    94,     8,
      23,    42,    16,    43,     8,    23,    97,    31,    44,    23,
       8,    23,    32,    13,    65,    14,    37,    15,    87,    88,
     103,   105,    77,    78,    38,    39,    40,   -16,    41,   111,
     112,     1,    17,     2,    18,    27,    26,   115,   113,    42,
      38,    43,    40,    29,    41,    31,    70,    30,     8,    23,
      36,    17,    38,    33,    40,    42,    41,    43,    90,    31,
      91,    31,    73,    35,     8,    23,    38,    42,    40,    43,
      41,    63,    64,    31,    96,    68,     8,    23,   108,    75,
     109,    42,    76,    43,    93,    95,   106,    31,    77,    78,
       8,    23,    79,    80,    81,    82,    83,    84,   107,   110,
     114,    25,    12,    72,    34,   101,    99,    24,   100
};

static const yytype_int8 yycheck[] =
{
      40,    48,    19,    43,    21,    31,     1,     2,    28,    85,
      86,    28,    29,    89,     0,    19,     4,     5,     6,    23,
       8,    47,    21,    22,    64,    72,    21,    21,    68,    28,
      29,    19,    21,    21,    28,    29,    76,    25,    26,    29,
      28,    29,    26,    19,    39,    21,    30,    23,    11,    12,
      90,    91,     9,    10,     4,     5,     6,    28,     8,   106,
     107,     5,     5,     7,     7,    20,    22,   114,   108,    19,
       4,    21,     6,    24,     8,    25,    26,    22,    28,    29,
      19,     5,     4,     7,     6,    19,     8,    21,    21,    25,
      23,    25,    26,    23,    28,    29,     4,    19,     6,    21,
       8,    24,    21,    25,    26,    21,    28,    29,    20,    19,
      22,    19,    27,    21,    19,    22,    22,    25,     9,    10,
      28,    29,    13,    14,    15,    16,    17,    18,    22,    24,
       3,    16,     4,    47,    27,    89,    85,    15,    86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    33,    34,    35,    36,    37,    28,    61,
      61,     0,    35,    19,    21,    23,    21,     5,     7,    38,
      39,    40,    41,    29,    62,    38,    22,    20,    61,    24,
      22,    25,    42,     7,    41,    23,    19,    42,     4,     5,
       6,     8,    19,    21,    26,    36,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    54,    56,    58,
      59,    61,    62,    24,    21,    61,    19,    50,    21,    50,
      26,    36,    44,    26,    45,    19,    27,     9,    10,    13,
      14,    15,    16,    17,    18,    53,    55,    11,    12,    57,
      21,    23,    50,    19,    50,    22,    26,    50,    51,    54,
      56,    58,    22,    50,    60,    50,    22,    22,    20,    22,
      24,    45,    45,    50,     3,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    42,    42,    43,    43,    44,    44,    45,    45,    45,
      45,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     6,
       6,     1,     1,     3,     1,     1,     1,     2,     4,     4,
       3,     3,     2,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     5,     7,     5,     2,     3,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     4,     3,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: decl_lista  */
#line 26 "cminus.y"
                      {savedTree = yyvsp[0];}
#line 1216 "cminus.tab.c"
    break;

  case 3: /* decl_lista: decl_lista decl  */
#line 29 "cminus.y"
                  {
                    YYSTYPE t = yyvsp[-1];
                    if(t != NULL){
                      while(t->sibling != NULL) t = t->sibling;
                      t->sibling = yyvsp[0];
                      yyval = yyvsp[-1];
                    }
                    else yyval = yyvsp[0];
                  }
#line 1230 "cminus.tab.c"
    break;

  case 4: /* decl_lista: decl  */
#line 38 "cminus.y"
                        {yyval = yyvsp[0];}
#line 1236 "cminus.tab.c"
    break;

  case 5: /* decl: var_decl  */
#line 40 "cminus.y"
                {yyval = yyvsp[0];}
#line 1242 "cminus.tab.c"
    break;

  case 6: /* decl: fun_decl  */
#line 42 "cminus.y"
                      {yyval = yyvsp[0];}
#line 1248 "cminus.tab.c"
    break;

  case 7: /* var_decl: INT ident PONVIR  */
#line 46 "cminus.y"
              {
                yyval = newExpNode(TypeK);
                yyval->type = IntegerK;
                yyval->attr.name = "inteiro";
                yyval->child[0] = yyvsp[-1];
                yyvsp[-1]->nodekind = StmtK;
                yyvsp[-1]->kind.stmt = VarK;
                yyvsp[-1]->type = IntegerK;
						  }
#line 1262 "cminus.tab.c"
    break;

  case 8: /* var_decl: INT ident ECOLCH num DCOLCH PONVIR  */
#line 56 "cminus.y"
                {
                  yyval = newExpNode(TypeK);
                  yyval->type = IntegerK;
                  yyval->attr.name = "inteiro";
                  yyval->child[0] = yyvsp[-4];
                  yyvsp[-4]->nodekind = StmtK;
                  yyvsp[-4]->kind.stmt = VarK;
                  yyvsp[-4]->type = IntegerK; 
                  yyvsp[-4]->attr.len = yyvsp[-2]->attr.val;
                }
#line 1277 "cminus.tab.c"
    break;

  case 9: /* fun_decl: INT ident EPAREN params DPAREN comp_decl  */
#line 68 "cminus.y"
                {
                  yyval = newExpNode(TypeK);
                  yyval->type = IntegerK;
                  yyval->attr.name = "inteiro";
                  yyval->child[0] = yyvsp[-4];
                  yyvsp[-4]->child[0] = yyvsp[-2];
                  yyvsp[-4]->child[1] = yyvsp[0];
                  yyvsp[-4]->nodekind = StmtK;
                  yyvsp[-4]->kind.stmt = FunK;
                  yyvsp[-4]->type = IntegerK;
                  yyvsp[-2]->type = IntegerK;
                }
#line 1294 "cminus.tab.c"
    break;

  case 10: /* fun_decl: VOID ident EPAREN params DPAREN comp_decl  */
#line 81 "cminus.y"
                {
                  yyval = newExpNode(TypeK);
                  yyval->type = VoidK;
                  yyval->attr.name = "void";
                  yyval->child[0] = yyvsp[-4];
                  yyvsp[-4]->child[0] = yyvsp[-2];
                  yyvsp[-4]->child[1] = yyvsp[0];
                  yyvsp[-4]->nodekind = StmtK;
                  yyvsp[-4]->kind.stmt = FunK;
                }
#line 1309 "cminus.tab.c"
    break;

  case 11: /* params: param_lista  */
#line 92 "cminus.y"
                     {yyval = yyvsp[0];}
#line 1315 "cminus.tab.c"
    break;

  case 12: /* params: VOID  */
#line 94 "cminus.y"
        {
				  yyval = newExpNode(TypeK);
          yyval->attr.name = "void";
          yyval->child[0] = NULL;
				}
#line 1325 "cminus.tab.c"
    break;

  case 13: /* param_lista: param_lista VIRG param  */
#line 101 "cminus.y"
            {
              YYSTYPE t = yyvsp[-2];
              if(t != NULL){
                while(t->sibling != NULL)
                t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-2];
              }else yyval = yyvsp[0];
            }
#line 1339 "cminus.tab.c"
    break;

  case 14: /* param_lista: param  */
#line 110 "cminus.y"
                    {yyval = yyvsp[0];}
#line 1345 "cminus.tab.c"
    break;

  case 15: /* tipo_espec: INT  */
#line 113 "cminus.y"
                  {
                    yyval = newExpNode(TypeK);
                    yyval->attr.name = "inteiro";
                    yyval->type = IntegerK;
                  }
#line 1355 "cminus.tab.c"
    break;

  case 16: /* tipo_espec: VOID  */
#line 119 "cminus.y"
                  {
                    yyval = newExpNode(TypeK);
                    yyval->attr.name = "void";
                    yyval->type = VoidK;
                  }
#line 1365 "cminus.tab.c"
    break;

  case 17: /* param: tipo_espec ident  */
#line 126 "cminus.y"
      {
        yyval = yyvsp[-1];
        yyval->child[0]= yyvsp[0];
      }
#line 1374 "cminus.tab.c"
    break;

  case 18: /* param: tipo_espec ident ECOLCH DCOLCH  */
#line 131 "cminus.y"
      {
        yyval= yyvsp[-3];
        yyval->child[0]= yyvsp[-2];
      }
#line 1383 "cminus.tab.c"
    break;

  case 19: /* comp_decl: ECHAVE local_decl stmt_lista DCHAVE  */
#line 137 "cminus.y"
              {
                YYSTYPE t = yyvsp[-2];
                if(t != NULL){
                  while(t->sibling != NULL)
                  t = t->sibling;
                  t->sibling = yyvsp[-1];
                  yyval = yyvsp[-2];
                } 
                else yyval = yyvsp[-1];
              }
#line 1398 "cminus.tab.c"
    break;

  case 20: /* comp_decl: ECHAVE local_decl DCHAVE  */
#line 148 "cminus.y"
              {
                yyval = yyvsp[-1];
              }
#line 1406 "cminus.tab.c"
    break;

  case 21: /* comp_decl: ECHAVE stmt_lista DCHAVE  */
#line 152 "cminus.y"
              {
                yyval = yyvsp[-1];
              }
#line 1414 "cminus.tab.c"
    break;

  case 22: /* comp_decl: ECHAVE DCHAVE  */
#line 155 "cminus.y"
                              {}
#line 1420 "cminus.tab.c"
    break;

  case 23: /* local_decl: local_decl var_decl  */
#line 158 "cminus.y"
                  {
                    YYSTYPE t = yyvsp[-1];
                    if(t != NULL){
                      while(t->sibling != NULL) t = t->sibling;
                      t->sibling = yyvsp[0];
                      yyval = yyvsp[-1];
                    }else yyval = yyvsp[0];
                  }
#line 1433 "cminus.tab.c"
    break;

  case 24: /* local_decl: var_decl  */
#line 167 "cminus.y"
                  {
                    yyval = yyvsp[0];
                  }
#line 1441 "cminus.tab.c"
    break;

  case 25: /* stmt_lista: stmt_lista stmt  */
#line 173 "cminus.y"
                {
                    YYSTYPE t = yyvsp[-1];
                    if(t != NULL){
                      while(t->sibling != NULL)
                      t = t->sibling;
                      t->sibling = yyvsp[0];
                      yyval = yyvsp[-1];
                    }else yyval = yyvsp[0];
                  }
#line 1455 "cminus.tab.c"
    break;

  case 26: /* stmt_lista: stmt  */
#line 183 "cminus.y"
                  {
                    yyval = yyvsp[0];
                  }
#line 1463 "cminus.tab.c"
    break;

  case 27: /* stmt: exp_decl  */
#line 189 "cminus.y"
          {
            yyval = yyvsp[0];
          }
#line 1471 "cminus.tab.c"
    break;

  case 28: /* stmt: comp_decl  */
#line 193 "cminus.y"
          {
            yyval = yyvsp[0];
          }
#line 1479 "cminus.tab.c"
    break;

  case 29: /* stmt: selec_decl  */
#line 197 "cminus.y"
          {
            yyval = yyvsp[0];
          }
#line 1487 "cminus.tab.c"
    break;

  case 30: /* stmt: it_decl  */
#line 201 "cminus.y"
          {
            yyval = yyvsp[0];
          }
#line 1495 "cminus.tab.c"
    break;

  case 31: /* stmt: retorno_decl  */
#line 205 "cminus.y"
          {
            yyval = yyvsp[0];
          }
#line 1503 "cminus.tab.c"
    break;

  case 32: /* exp_decl: exp PONVIR  */
#line 210 "cminus.y"
                {
                  yyval = yyvsp[-1];
                }
#line 1511 "cminus.tab.c"
    break;

  case 34: /* selec_decl: IF EPAREN exp DPAREN stmt  */
#line 216 "cminus.y"
              {
                yyval = newStmtNode(IfK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1521 "cminus.tab.c"
    break;

  case 35: /* selec_decl: IF EPAREN exp DPAREN stmt ELSE stmt  */
#line 222 "cminus.y"
             {
                yyval = newStmtNode(IfK);
                yyval->child[0] = yyvsp[-4];
                yyval->child[1] = yyvsp[-2];
                yyval->child[2] = yyvsp[0];
             }
#line 1532 "cminus.tab.c"
    break;

  case 36: /* it_decl: WHILE EPAREN exp DPAREN stmt  */
#line 230 "cminus.y"
              {
                yyval = newStmtNode(WhileK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1542 "cminus.tab.c"
    break;

  case 37: /* retorno_decl: RETURN PONVIR  */
#line 237 "cminus.y"
              {
                yyval = newStmtNode(ReturnK);
              }
#line 1550 "cminus.tab.c"
    break;

  case 38: /* retorno_decl: RETURN exp PONVIR  */
#line 241 "cminus.y"
              {
                yyval = newStmtNode(ReturnK);
                yyval->child[0] = yyvsp[-1];
              }
#line 1559 "cminus.tab.c"
    break;

  case 39: /* exp: var RECEBE exp  */
#line 247 "cminus.y"
          {
            yyval = newStmtNode(AssignK);
            yyval->attr.name = yyvsp[-2]->attr.name;
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
          }
#line 1570 "cminus.tab.c"
    break;

  case 40: /* exp: simp_exp  */
#line 254 "cminus.y"
          {
            yyval = yyvsp[0];
          }
#line 1578 "cminus.tab.c"
    break;

  case 41: /* var: ident  */
#line 259 "cminus.y"
    {
      yyval = yyvsp[0];
    }
#line 1586 "cminus.tab.c"
    break;

  case 42: /* var: ident ECOLCH exp DCOLCH  */
#line 263 "cminus.y"
    {
      yyval = yyvsp[-3];
      yyval->child[0] = yyvsp[-1];
      yyval->kind.exp = VetK;
      yyval->type = IntegerK;
    }
#line 1597 "cminus.tab.c"
    break;

  case 43: /* simp_exp: soma_exp relacional soma_exp  */
#line 271 "cminus.y"
                  {
                      yyval = yyvsp[-1];
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[0];
                  }
#line 1607 "cminus.tab.c"
    break;

  case 44: /* simp_exp: soma_exp  */
#line 277 "cminus.y"
                  {
                    yyval = yyvsp[0];
                  }
#line 1615 "cminus.tab.c"
    break;

  case 45: /* relacional: MENORI  */
#line 282 "cminus.y"
            {
              yyval = newExpNode(OpK);
              yyval->attr.op = MENORI;                            
              yyval->type = BooleanK;
            }
#line 1625 "cminus.tab.c"
    break;

  case 46: /* relacional: MENORQ  */
#line 288 "cminus.y"
           {
            yyval = newExpNode(OpK);
            yyval->attr.op = MENORQ;                            
						yyval->type = BooleanK;
           }
#line 1635 "cminus.tab.c"
    break;

  case 47: /* relacional: MAIORQ  */
#line 294 "cminus.y"
           {
            yyval = newExpNode(OpK);
            yyval->attr.op = MAIORQ;                            
						yyval->type = BooleanK;
           }
#line 1645 "cminus.tab.c"
    break;

  case 48: /* relacional: MAIORI  */
#line 300 "cminus.y"
           {
            yyval = newExpNode(OpK);
            yyval->attr.op = MAIORI;                            
						yyval->type = BooleanK;
           }
#line 1655 "cminus.tab.c"
    break;

  case 49: /* relacional: IGUAL  */
#line 306 "cminus.y"
           {
            yyval = newExpNode(OpK);
            yyval->attr.op = IGUAL;                            
						yyval->type = BooleanK;
           }
#line 1665 "cminus.tab.c"
    break;

  case 50: /* relacional: DIF  */
#line 312 "cminus.y"
           {
            yyval = newExpNode(OpK);
            yyval->attr.op = DIF;                            
						yyval->type = BooleanK;
           }
#line 1675 "cminus.tab.c"
    break;

  case 51: /* soma_exp: soma_exp soma termo  */
#line 319 "cminus.y"
              {
                yyval = yyvsp[-1];
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1685 "cminus.tab.c"
    break;

  case 52: /* soma_exp: termo  */
#line 325 "cminus.y"
               {
                yyval = yyvsp[0];
               }
#line 1693 "cminus.tab.c"
    break;

  case 53: /* soma: MAIS  */
#line 330 "cminus.y"
      {
        yyval = newExpNode(OpK);
        yyval->attr.op = MAIS;  
      }
#line 1702 "cminus.tab.c"
    break;

  case 54: /* soma: MENOS  */
#line 335 "cminus.y"
     {
      yyval = newExpNode(OpK);
      yyval->attr.op = MENOS;  
     }
#line 1711 "cminus.tab.c"
    break;

  case 55: /* termo: termo mult fator  */
#line 341 "cminus.y"
      {
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
      }
#line 1721 "cminus.tab.c"
    break;

  case 56: /* termo: fator  */
#line 347 "cminus.y"
      {
        yyval = yyvsp[0];
      }
#line 1729 "cminus.tab.c"
    break;

  case 57: /* mult: VEZES  */
#line 352 "cminus.y"
      {
        yyval = newExpNode(OpK);
        yyval->attr.op = VEZES; 
      }
#line 1738 "cminus.tab.c"
    break;

  case 58: /* mult: SOBRE  */
#line 357 "cminus.y"
      {
        yyval = newExpNode(OpK);
        yyval->attr.op = SOBRE; 
      }
#line 1747 "cminus.tab.c"
    break;

  case 59: /* fator: EPAREN exp DPAREN  */
#line 363 "cminus.y"
      {
        yyval = yyvsp[-1];
      }
#line 1755 "cminus.tab.c"
    break;

  case 60: /* fator: var  */
#line 367 "cminus.y"
      {
        yyval = yyvsp[0];
      }
#line 1763 "cminus.tab.c"
    break;

  case 61: /* fator: ativ  */
#line 371 "cminus.y"
      {
        yyval = yyvsp[0];
      }
#line 1771 "cminus.tab.c"
    break;

  case 62: /* fator: num  */
#line 375 "cminus.y"
      {
        yyval = yyvsp[0];
      }
#line 1779 "cminus.tab.c"
    break;

  case 63: /* ativ: ident EPAREN arg_lista DPAREN  */
#line 380 "cminus.y"
          {
            yyval = yyvsp[-3];
            yyval->child[0] = yyvsp[-1];
            yyval->nodekind = StmtK;
            yyval->kind.stmt = CallK;
          }
#line 1790 "cminus.tab.c"
    break;

  case 64: /* ativ: ident EPAREN DPAREN  */
#line 387 "cminus.y"
          {
            yyval = yyvsp[-2];
            yyval->nodekind = StmtK;
            yyval->kind.stmt = CallK;
          }
#line 1800 "cminus.tab.c"
    break;

  case 65: /* arg_lista: arg_lista VIRG exp  */
#line 394 "cminus.y"
          {
            YYSTYPE t = yyvsp[-2];
            if(t != NULL){
              while(t->sibling != NULL)
              t = t->sibling;
              t->sibling = yyvsp[0];
              yyval = yyvsp[-2];
            } else yyval = yyvsp[0];
          }
#line 1814 "cminus.tab.c"
    break;

  case 66: /* arg_lista: exp  */
#line 404 "cminus.y"
          {
            yyval = yyvsp[0];
          }
#line 1822 "cminus.tab.c"
    break;

  case 67: /* ident: ID  */
#line 409 "cminus.y"
      {
      yyval = newExpNode(IdK);
      yyval->attr.name = copyString(tokenString);
      }
#line 1831 "cminus.tab.c"
    break;

  case 68: /* num: NUM  */
#line 415 "cminus.y"
      {
        yyval = newExpNode(ConstK);
        yyval->attr.val = atoi(tokenString);
        yyval->type = IntegerK;
      }
#line 1841 "cminus.tab.c"
    break;


#line 1845 "cminus.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 422 "cminus.y"



/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

int yyerror(char * message)
{ 
  char * errortype;

  if (Error) {errortype="lexico"; message = (!(*tokenString) ? "comentario inacabado":"lexema invalido");}
  else {errortype = "sintatico"; Error=TRUE;}

  fprintf(listing,"Erro %s na linha %d: %s\n",errortype,lineno,message);
  fprintf(listing,"Token: ");
  printToken(yychar,tokenString);
  return 0;
}

TreeNode * parse(void){
  yyparse();
  return savedTree;
}
