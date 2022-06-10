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
#line 1 "./src/parser.y"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <math.h>
#include "symtab.h"
#include "AST.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "string.h"


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[35m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

#define OUT_ARG "-o"

extern FILE *yyin;
extern FILE *yyout;

int globalError =0;
int globalNumCounter =0;
int globalOpCounter =0;
int globalBoolCond = 0;
char globalSignCond;
char *globalType;


/**** 	NUMBERS		****/

add_SymNum ( char *sym_name, int sym_val, char *sym_type ) 
{  
	symbolRec *s;
   	s = getsymNum (sym_name,sym_val);
   	if (s == 0)
	{
        s = putsymNum (sym_name,sym_val, sym_type);
        printf( "The variable %s it's not defined, it gets defined as %d and of the type %s \n", sym_name, sym_val, sym_type );
   	}
	else
	{
		printf( "The variable %s it's already defined, with the value %d and of the type %s \n", sym_name, sym_val, sym_type );
   	}
}

Update_SymNum( char *sym_name, int sym_val )
{ 
	symbolRec *act;

  	if ( getsymNum( sym_name, sym_val ) == 0 ) 
	{
    	printf( "The variable %s it's not defined, it's %d\n", sym_name, sym_val );
  	}
	else
	{
    	act = updatesymNum( sym_name, sym_val); 
    	printf( "The variable %s values now equals to %d\n", act->name, act->num );
  	}
}

/**** 	TEXTS 		****/


add_SymText ( char *sym_name, char *sym_text, char *sym_type ) 
{  
	symbolRec *s;
   	s = getsymText (sym_name,sym_text);
   	if (s == 0)
	{
        s = putsymText (sym_name,sym_text, sym_type);
        printf( "The variable %s it's not defined, it gets defined with the value %s and of %s type \n\n", sym_name, sym_text, sym_type );
   	}
	else 
	{
        printf( "The variable %s it's already defined, it's of type %s \n\n", sym_name, sym_text, sym_type );
   	}
}

Update_SymText( char *sym_name, char *sym_text  )
{ 
	symbolRec *act;
  	if ( getsymText( sym_name, sym_text ) == 0 )
	{
     	printf( "The variable %s it's not found\n", sym_name, sym_text );
  	}
	else
	{
    	act = updatesymText( sym_name, sym_text); 
     	printf( "The variable %s changes it's value to %s\n", act->name, act->text );
  	}
}



#line 171 "./src/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUBS = 4,                       /* SUBS  */
  YYSYMBOL_MULT = 5,                       /* MULT  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_LEFT_P = 7,                     /* LEFT_P  */
  YYSYMBOL_RIGHT_P = 8,                    /* RIGHT_P  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_BIG_THAN = 11,                  /* BIG_THAN  */
  YYSYMBOL_LES_THAN = 12,                  /* LES_THAN  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_PROCEDURE = 14,                 /* PROCEDURE  */
  YYSYMBOL_IS = 15,                        /* IS  */
  YYSYMBOL_END = 16,                       /* END  */
  YYSYMBOL_START = 17,                     /* START  */
  YYSYMBOL_COLUMN = 18,                    /* COLUMN  */
  YYSYMBOL_INTEGER = 19,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_BOOLEAN = 22,                   /* BOOLEAN  */
  YYSYMBOL_IDENTIFICADORSYMB = 23,         /* IDENTIFICADORSYMB  */
  YYSYMBOL_LEFTP_COM = 24,                 /* LEFTP_COM  */
  YYSYMBOL_COL_EQUAL = 25,                 /* COL_EQUAL  */
  YYSYMBOL_RIGHTP_COM = 26,                /* RIGHTP_COM  */
  YYSYMBOL_PUTLINE = 27,                   /* PUTLINE  */
  YYSYMBOL_ENDIF = 28,                     /* ENDIF  */
  YYSYMBOL_TRUE = 29,                      /* TRUE  */
  YYSYMBOL_FALSE = 30,                     /* FALSE  */
  YYSYMBOL_LINE_COMMENT = 31,              /* LINE_COMMENT  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_LOOP = 33,                      /* LOOP  */
  YYSYMBOL_ENDLOOP = 34,                   /* ENDLOOP  */
  YYSYMBOL_EQUALS = 35,                    /* EQUALS  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_IN = 37,                        /* IN  */
  YYSYMBOL_RANGE = 38,                     /* RANGE  */
  YYSYMBOL_FUNCTION = 39,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_SEMI_COLUMN = 41,               /* SEMI_COLUMN  */
  YYSYMBOL_INTEGERNUM = 42,                /* INTEGERNUM  */
  YYSYMBOL_REALNUM = 43,                   /* REALNUM  */
  YYSYMBOL_IDENTIFIER = 44,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_comp = 46,                      /* comp  */
  YYSYMBOL_body = 47,                      /* body  */
  YYSYMBOL_initproc = 48,                  /* initproc  */
  YYSYMBOL_endproc = 49,                   /* endproc  */
  YYSYMBOL_var_name = 50,                  /* var_name  */
  YYSYMBOL_func_name = 51,                 /* func_name  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_beginning = 53,                 /* beginning  */
  YYSYMBOL_statements = 54,                /* statements  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_sentence = 57,                  /* sentence  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_if_sentence = 59,               /* if_sentence  */
  YYSYMBOL_calc = 60,                      /* calc  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_nombreFuncion = 62,             /* nombreFuncion  */
  YYSYMBOL_Fun = 63,                       /* Fun  */
  YYSYMBOL_factor = 64,                    /* factor  */
  YYSYMBOL_while_loop = 65,                /* while_loop  */
  YYSYMBOL_bucle_for = 66,                 /* bucle_for  */
  YYSYMBOL_rangos = 67                     /* rangos  */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   135,   135,   140,   143,   145,   147,   153,   167,   171,
     175,   176,   179,   187,   191,   195,   199,   205,   206,   209,
     252,   258,   259,   260,   261,   262,   263,   267,   284,   300,
     355,   413,   471,   538,   560,   578,   599,   608,   614,   639,
     644,   659,   684,   685,   686,   687,   688,   692,   710,   713
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
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUBS", "MULT",
  "DIV", "LEFT_P", "RIGHT_P", "IF", "THEN", "BIG_THAN", "LES_THAN", "ELSE",
  "PROCEDURE", "IS", "END", "START", "COLUMN", "INTEGER", "FLOAT",
  "STRING", "BOOLEAN", "IDENTIFICADORSYMB", "LEFTP_COM", "COL_EQUAL",
  "RIGHTP_COM", "PUTLINE", "ENDIF", "TRUE", "FALSE", "LINE_COMMENT",
  "WHILE", "LOOP", "ENDLOOP", "EQUALS", "FOR", "IN", "RANGE", "FUNCTION",
  "RETURN", "SEMI_COLUMN", "INTEGERNUM", "REALNUM", "IDENTIFIER",
  "$accept", "comp", "body", "initproc", "endproc", "var_name",
  "func_name", "expression", "beginning", "statements", "statement",
  "type", "sentence", "expr", "if_sentence", "calc", "function",
  "nombreFuncion", "Fun", "factor", "while_loop", "bucle_for", "rangos", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -39,    28,   -60,   -10,   -60,    22,   -60,    20,    35,
     -13,   -60,   -60,    -1,    10,   -60,   -60,    96,   -60,   -60,
     -60,   -60,   -60,    17,   -60,    18,   -20,    41,   -60,   -20,
      87,    26,    43,    96,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   133,    29,   143,   -60,   -60,   -60,
     -60,   -60,    38,   -60,    65,   127,   -60,   -20,   -20,   -20,
     -20,    96,   -20,   -20,   -20,    52,    96,    87,   -10,   -60,
     -60,   -60,     5,    39,    21,    21,     1,     1,    16,   147,
     147,   147,    51,    30,    57,    63,    -2,   -60,   -60,    96,
      56,   -60,    58,    87,    96,    60,    62,   -60,   -60,   -60,
      76,    -1,    61,    70,    89,   -60,   -60,   102,    96,    82,
      80,   109,   -60,    92,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     6,     0,     1,     0,     0,
       0,    11,     4,     0,     0,     3,     9,     0,    10,    13,
      14,    15,    16,     0,     7,     0,     0,     0,    23,     0,
       0,     0,     0,     8,    18,    20,    26,    24,    25,    12,
       5,    36,    37,    38,     0,     0,     0,    45,    46,    42,
      43,    44,     0,    40,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     0,     0,    29,    30,    31,    32,     0,    33,
      34,    35,     0,     0,     0,     0,     0,    19,    22,     0,
       0,    21,     0,     0,     0,     0,     0,    27,    47,    49,
       0,     0,     0,     0,     0,    28,    48,     0,     0,     0,
       0,     0,    41,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,    66,
      -9,    40,   -59,   -33,   -60,    24,   -60,   -60,   -60,   -52,
     -60,   -60,   -60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    15,     6,    25,     9,    17,    10,
      11,    23,    33,    34,    35,    44,    36,    54,   111,    52,
      37,    38,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    18,    78,    73,    16,     5,    95,    83,    57,    58,
      59,    60,    62,    63,     1,    84,    62,    63,    19,    20,
      21,    22,    41,    42,    43,    26,    59,    60,     7,    89,
      96,     8,    62,    63,     8,   100,    64,    12,    13,    26,
      64,    99,     8,    27,    90,    56,    87,    28,    29,   109,
      56,    14,    30,    46,    24,    31,    64,    27,    39,    40,
      32,    28,    29,    56,    92,    45,    30,    56,    55,    31,
      53,    26,    68,    65,    32,    67,    56,    18,    82,    72,
      88,    74,    75,    76,    77,    26,    79,    80,    81,    27,
     102,    26,    91,    28,    29,    93,    94,    97,    30,    98,
     101,    31,   105,    27,   107,    26,    32,    28,    29,    27,
     103,   106,    30,    28,    29,    31,    47,    48,    30,   108,
      32,    31,   110,    27,   112,   113,    32,    28,    29,    49,
      50,    51,    30,   114,    86,    31,    57,    58,    59,    60,
      32,   104,     0,    61,    62,    63,    57,    58,    59,    60,
      57,    58,    59,    60,    62,    63,    47,    48,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    69,
      70,    71,     0,     0,     0,     0,    66,     0,    64,     0,
       0,     0,    64
};

static const yytype_int8 yycheck[] =
{
      33,    10,    61,    55,    17,    44,     8,    66,     3,     4,
       5,     6,    11,    12,    14,    67,    11,    12,    19,    20,
      21,    22,    42,    43,    44,     9,     5,     6,     0,    13,
      89,    44,    11,    12,    44,    94,    35,    15,    18,     9,
      35,    93,    44,    27,    28,    78,    41,    31,    32,   108,
      83,    16,    36,    29,    44,    39,    35,    27,    41,    41,
      44,    31,    32,    96,    34,    24,    36,   100,    25,    39,
      44,     9,     7,    44,    44,    37,   109,    86,    26,    55,
      41,    57,    58,    59,    60,     9,    62,    63,    64,    27,
      28,     9,    41,    31,    32,    38,    33,    41,    36,    41,
      40,    39,    41,    27,    15,     9,    44,    31,    32,    27,
      34,    41,    36,    31,    32,    39,    29,    30,    36,    17,
      44,    39,    40,    27,    44,    16,    44,    31,    32,    42,
      43,    44,    36,    41,    68,    39,     3,     4,     5,     6,
      44,   101,    -1,    10,    11,    12,     3,     4,     5,     6,
       3,     4,     5,     6,    11,    12,    29,    30,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    42,
      43,    44,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
      -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    46,    47,    48,    44,    50,     0,    44,    52,
      54,    55,    15,    18,    16,    49,    17,    53,    55,    19,
      20,    21,    22,    56,    44,    51,     9,    27,    31,    32,
      36,    39,    44,    57,    58,    59,    61,    65,    66,    41,
      41,    42,    43,    44,    60,    24,    60,    29,    30,    42,
      43,    44,    64,    44,    62,    25,    58,     3,     4,     5,
       6,    10,    11,    12,    35,    44,    33,    37,     7,    42,
      43,    44,    60,    64,    60,    60,    60,    60,    57,    60,
      60,    60,    26,    57,    64,    67,    54,    41,    41,    13,
      28,    41,    34,    38,    33,     8,    57,    41,    41,    64,
      57,    40,    28,    34,    56,    41,    41,    15,    17,    57,
      40,    63,    44,    16,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    54,    55,    56,    56,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      62,    63,    64,    64,    64,    64,    64,    65,    66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     1,     1,     3,     1,
       2,     1,     4,     1,     1,     1,     1,     2,     1,     4,
       1,     5,     4,     1,     1,     1,     1,     6,     8,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,    13,
       1,     2,     1,     1,     1,     1,     1,     6,     8,     3
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
  case 2: /* comp: body  */
#line 136 "./src/parser.y"
{
	printf(YEL"FINISH "RESET" -- ALL "GRN"OK"RESET"\n"); 
}
#line 1311 "./src/y.tab.c"
    break;

  case 4: /* initproc: PROCEDURE var_name IS  */
#line 143 "./src/parser.y"
                                   { printf(BLU"START OF THE PROCEDURE "RESET"-- \n\n");   }
#line 1317 "./src/y.tab.c"
    break;

  case 5: /* endproc: END func_name SEMI_COLUMN  */
#line 145 "./src/parser.y"
                                   { printf("--- \n"BLU"END OF THE PROCEDURE "RESET"\n\n"); }
#line 1323 "./src/y.tab.c"
    break;

  case 6: /* var_name: IDENTIFIER  */
#line 148 "./src/parser.y"
{
	add_SymText ( "Name", (yyvsp[0].string), "string" );
}
#line 1331 "./src/y.tab.c"
    break;

  case 7: /* func_name: IDENTIFIER  */
#line 154 "./src/parser.y"
{

	if (strcmp((yyvsp[0].string), getvalsymText("Name")) == 0) 
	{
		printf("The names at the beginning and the end are the same --> ");
		printf(GRN " CORRECT\n" RESET);
	} 
	else
	{
		printf("The names at the beginning and the end are NOT the same --> "RED"ERROR"RESET" \n");
	}
}
#line 1348 "./src/y.tab.c"
    break;

  case 8: /* expression: statements beginning sentence  */
#line 167 "./src/parser.y"
                                            {}
#line 1354 "./src/y.tab.c"
    break;

  case 9: /* beginning: START  */
#line 171 "./src/parser.y"
                 {printf("###########################\n "YEL"BEGIN"RESET" \n###########################\n\n");}
#line 1360 "./src/y.tab.c"
    break;

  case 12: /* statement: IDENTIFIER COLUMN type SEMI_COLUMN  */
#line 180 "./src/parser.y"
{ 
	printf("The variable %s gets defined \n", (yyvsp[-3].string));
	(yyval.snum).text = (yyvsp[-3].string); add_SymText ( (yyval.snum).text, (yyval.snum).text, globalType);
}
#line 1369 "./src/y.tab.c"
    break;

  case 13: /* type: INTEGER  */
#line 187 "./src/parser.y"
              {
			globalType= " integer";
			printf(YEL"A variable of type Integer is defined\n"RESET);
		}
#line 1378 "./src/y.tab.c"
    break;

  case 14: /* type: FLOAT  */
#line 191 "./src/parser.y"
              {
			globalType= "float";
			printf(YEL"A variable of type Float is defined\n"RESET);
		}
#line 1387 "./src/y.tab.c"
    break;

  case 15: /* type: STRING  */
#line 195 "./src/parser.y"
               {
			globalType= "string";
			printf(YEL"A variable of type String is defined\n"RESET);
		}
#line 1396 "./src/y.tab.c"
    break;

  case 16: /* type: BOOLEAN  */
#line 199 "./src/parser.y"
                {
			globalType= "boolean";
			printf(YEL"A variable of type Boolean is defined\n"RESET);
		}
#line 1405 "./src/y.tab.c"
    break;

  case 19: /* expr: IDENTIFIER COL_EQUAL calc SEMI_COLUMN  */
#line 209 "./src/parser.y"
                                             {
	if (globalBoolCond == 0) {
		globalBoolCond =0;
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper((yyvsp[-1].snum).a);
 		fprintf(yyout, ".text\n");
		textOper((yyvsp[-1].snum).a);
 		fprintf(yyout, "..............................................\n");
		globalNumCounter =0;
		globalOpCounter =0;
		globalBoolCond =0;
	}


	//printf("Condicion: %d \n", $$.booleanCond);


	(yyval.snum).text= (yyvsp[-3].string);

	if (!globalError) 
	{ 
		if (!getvalsymText((yyval.snum).text)) 
		{
			printf("The variable %s has not been defined -->" RED " ERROR \n" RESET, (yyval.snum).text);
			printf(RED"\nERROR"RESET" -- Referencing of undefined variable.");
			printf("\nExiting with "RED"errors."RESET"\n");
		exit(1);
		}
		else
		{
			printf("The variable %s has already been defined -->" GRN " CORRECT \n" RESET, (yyval.snum).text);
	 		add_SymNum((yyvsp[-3].string), eval((yyvsp[-1].snum).a), globalType);
			Update_SymNum( (yyvsp[-3].string), eval((yyvsp[-1].snum).a) ); 
			printf("RESULT OF %s equals to %4.4g \n\n", (yyvsp[-3].string), eval((yyvsp[-1].snum).a));
		}
	} 
	else 
	{ 
		globalError = 0;
	}

}
#line 1453 "./src/y.tab.c"
    break;

  case 20: /* expr: if_sentence  */
#line 253 "./src/parser.y"
{
	globalNumCounter = 0;
	//printf("Llego 1");
}
#line 1462 "./src/y.tab.c"
    break;

  case 21: /* expr: PUTLINE LEFTP_COM IDENTIFIER RIGHTP_COM SEMI_COLUMN  */
#line 258 "./src/parser.y"
                                                        { printf("Put_Line\n");   }
#line 1468 "./src/y.tab.c"
    break;

  case 22: /* expr: IDENTIFIER COL_EQUAL factor SEMI_COLUMN  */
#line 259 "./src/parser.y"
                                                                        { printf("Asignacion\n"); }
#line 1474 "./src/y.tab.c"
    break;

  case 23: /* expr: LINE_COMMENT  */
#line 260 "./src/parser.y"
                { printf("COMMENT \n");		 }
#line 1480 "./src/y.tab.c"
    break;

  case 24: /* expr: while_loop  */
#line 261 "./src/parser.y"
                { printf("WHILE LOOP \n\n"); }
#line 1486 "./src/y.tab.c"
    break;

  case 25: /* expr: bucle_for  */
#line 262 "./src/parser.y"
                { printf("FOR LOOP \n\n");	 }
#line 1492 "./src/y.tab.c"
    break;

  case 26: /* expr: function  */
#line 263 "./src/parser.y"
                        { printf("FUNCTION \n\n");	 }
#line 1498 "./src/y.tab.c"
    break;

  case 27: /* if_sentence: IF calc THEN sentence ENDIF SEMI_COLUMN  */
#line 268 "./src/parser.y"
{
	//printf("LLEGADA AL 2");
	//$$.f = newflow('I', $2.f , $5.f, NULL); 
	//fprintf(yyout, "IFFFFFFFFF\n");
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper((yyvsp[-4].snum).a);
	fprintf(yyout, ".text\n");
	textIf(globalSignCond,(yyvsp[-4].snum).f);
	fprintf(yyout, "..............................................\n");
	globalNumCounter =0;
	globalOpCounter =0;
	globalBoolCond =0;

}
#line 1518 "./src/y.tab.c"
    break;

  case 28: /* if_sentence: IF calc THEN sentence ELSE sentence ENDIF SEMI_COLUMN  */
#line 285 "./src/parser.y"
{ 
	//$$.f = newflow('I', $2.f, $5.f, $9.f); 
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper((yyvsp[-6].snum).a);
	fprintf(yyout, ".text\n");
	textIf(globalSignCond,(yyvsp[-6].snum).f);
	fprintf(yyout, "..............................................\n");
	globalNumCounter =0;
	globalOpCounter =0;
	globalBoolCond =0;
}
#line 1535 "./src/y.tab.c"
    break;

  case 29: /* calc: calc ADD calc  */
#line 301 "./src/parser.y"
{ 
	//printf("ADD ON of\n");
	globalOpCounter = globalOpCounter + 1;

	if (!globalError)
	{
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer")) 
		{
			(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			globalType = (yyvsp[-2].snum).type;
			opCounter(globalOpCounter, (yyval.snum).a);
			printf(YEL"ADD ON of %s type \n" RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			globalType = (yyvsp[-2].snum).type;
			opCounter(globalOpCounter, (yyval.snum).a);
			printf(YEL"ADD ON of %s type\n"RESET,  (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			globalType = (yyvsp[0].snum).type;
			opCounter(globalOpCounter, (yyval.snum).a);
			printf(YEL"ADD ON of %s type \n" RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[0].snum).type == "string"))
		{
			(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			globalType = (yyvsp[-2].snum).type;
			opCounter(globalOpCounter, (yyval.snum).a);
			printf(YEL"ADD ON of %s type \n" RESET, (yyval.snum).type);
		}
		else if (((yyvsp[0].snum).type == "string") && ((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			globalType = (yyvsp[-2].snum).type;
			opCounter(globalOpCounter, (yyval.snum).a);
			printf(YEL"ADD ON of %s type \n" RESET, (yyval.snum).type);
		}

	} 
	else 
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE ADD ON GETS CANCELLED\n");
	}

}
#line 1594 "./src/y.tab.c"
    break;

  case 30: /* calc: calc SUBS calc  */
#line 356 "./src/parser.y"
{ 
	//printf("SUBTRACTION \n");
	globalOpCounter = globalOpCounter + 1;

	if (!globalError) 
	{
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer")) 
		{
			(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[0].snum).type == "string"))
		{
			(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, (yyval.snum).type);
		}
		else if (((yyvsp[0].snum).type == "string") && ((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			globalType = (yyvsp[-2].snum).type;
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, (yyval.snum).type);


		}
	} 
	else 
	{
		printf("THERE ARE ERRORS --> THE SUBTRACTION GETS CANCELLED\n");
	}

}
#line 1655 "./src/y.tab.c"
    break;

  case 31: /* calc: calc MULT calc  */
#line 414 "./src/parser.y"
{ 
	//printf("MULTIPLICATION\n");
	globalOpCounter = globalOpCounter + 1;

	if (globalError ==0) 
	{ 
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer"))
		{
			(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[0].snum).type == "string"))
		{
			(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, (yyval.snum).type);
		}
		else if (((yyvsp[0].snum).type == "string") && ((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			globalType = (yyvsp[-2].snum).type;
			printf(YEL"MULTIPLICATION of %s type \n"RESET, (yyval.snum).type);


		}
	}
	else
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE MULTIPLICATION GETS CANCELLED \n");
	}

}
#line 1716 "./src/y.tab.c"
    break;

  case 32: /* calc: calc DIV calc  */
#line 471 "./src/parser.y"
                 {
	//printf("DIVISION \n");
	globalOpCounter = globalOpCounter + 1;

	if (!(yyvsp[0].snum).value)	
	{ 
		printf(RED "\nERROR" RESET, 30);
		printf(" - Can't divide by 0. \n", 30);
		exit(1);
		globalError = 1;
	}

	if (!globalError) 
	{ 
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer"))
		{
			(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"DIVISION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"DIVISION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"DIVISION of %s type \n"RESET, (yyval.snum).type);


		} 
		else if (((yyvsp[0].snum).type == "string"))
		{
			(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a);
			evalprint((yyval.snum).a);
			opCounter(globalOpCounter, (yyval.snum).a);

			printf(YEL"DIVISION of %s type \n"RESET, (yyval.snum).type);

		}
		else if (((yyvsp[0].snum).type == "string") && ((yyvsp[-2].snum).type == "string"))
		{
			(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
			evalprint((yyval.snum).a);
			globalType = (yyvsp[-2].snum).type;
			opCounter(globalOpCounter, (yyval.snum).a);

			//printf(YEL"DIVISION of %s type \n"RESET, $$.type);
		}
	}
	else 
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE DIVISION GETS CANCELLED\n");
	}

}
#line 1786 "./src/y.tab.c"
    break;

  case 33: /* calc: calc BIG_THAN calc  */
#line 539 "./src/parser.y"
{
	printf(YEL"\nBIGGER THAN condition\n" RESET);
	globalBoolCond = 1;

	if ((yyvsp[-2].snum).value > (yyvsp[0].snum).value) {
		(yyval.snum).booleanCond = 1;
		(yyval.snum).f = (yyval.snum).booleanCond;
		globalSignCond = '>';

		printf("Condition BIGGER THAN is true - Is bigger\n");
	}
	else 
	{
		(yyval.snum).booleanCond =0;
		(yyval.snum).f = (yyval.snum).booleanCond;
		globalSignCond = '>';

		printf("Condition BIGGER THAN is false - It's not bigger \n");
	}

}
#line 1812 "./src/y.tab.c"
    break;

  case 34: /* calc: calc LES_THAN calc  */
#line 560 "./src/parser.y"
                     {
	printf(YEL "\NLESS THAN condition.\n" RESET);
	globalBoolCond = 1;
	if ((yyvsp[-2].snum).value < (yyvsp[0].snum).value) {
		(yyval.snum).booleanCond =1;
		(yyval.snum).f = (yyval.snum).booleanCond;
		globalSignCond = '<';


		printf("Condition LESS THAN is true - It's smaller\n");
	} else {
		(yyval.snum).booleanCond = 0;
		(yyval.snum).f = (yyval.snum).booleanCond;
		globalSignCond = '<';

		printf( "Condition LESS THAN is false - It's not smaller\n");
	}
}
#line 1835 "./src/y.tab.c"
    break;

  case 35: /* calc: calc EQUALS calc  */
#line 578 "./src/parser.y"
                   {
	printf(YEL "EQUALS condition\n" RESET);
	globalBoolCond = 1;

	if ((yyvsp[-2].snum).value == (yyvsp[0].snum).value) 
	{
		printf("Condition EQUALS is true - It's equal\n");
		(yyval.snum).booleanCond = 1;
		(yyval.snum).f = (yyval.snum).booleanCond;
		globalSignCond = '=';
	}
	else
	{
		printf("Condition EQUALS is false - It's equal\n");
		(yyval.snum).booleanCond = 0;
		(yyval.snum).f = (yyval.snum).booleanCond;
		globalSignCond = '=';
	}

}
#line 1860 "./src/y.tab.c"
    break;

  case 36: /* calc: INTEGERNUM  */
#line 600 "./src/parser.y"
{ 
	(yyval.snum).a = newnum((yyvsp[0].number));
	(yyval.snum).value = (yyvsp[0].number);
	(yyval.snum).type = " integer";
	globalNumCounter = globalNumCounter +1;
	contadorNumeros(globalNumCounter, (yyval.snum).value );
}
#line 1872 "./src/y.tab.c"
    break;

  case 37: /* calc: REALNUM  */
#line 609 "./src/parser.y"
{
	(yyval.snum).a= newnum((yyvsp[0].numberf));
	(yyval.snum).dvalue = (yyvsp[0].numberf); (yyval.snum).type = "real";
}
#line 1881 "./src/y.tab.c"
    break;

  case 38: /* calc: IDENTIFIER  */
#line 615 "./src/parser.y"
{
	//printf("variable\n");
	(yyval.snum).type = "string";

	if (!getvalsymText((yyvsp[0].string)))
	{
		globalError = 1;
		printf("The variable %s does NOT exist \n", (yyvsp[0].string));

	} 
	else 
	{
		globalError = 0;
		(yyval.snum).value = getvalsymNum((yyvsp[0].string));
		(yyval.snum).a= newnum((yyval.snum).value);
		globalNumCounter = globalNumCounter +1;
		contadorNumeros(globalNumCounter, (yyval.snum).value );

		printf("The variable %s does exist \n", (yyvsp[0].string));		
	}
}
#line 1907 "./src/y.tab.c"
    break;

  case 39: /* function: FUNCTION nombreFuncion LEFT_P statements RIGHT_P RETURN type IS START sentence Fun END SEMI_COLUMN  */
#line 639 "./src/parser.y"
                                                                                                             {
	//$$.fun = newfunc($4.fun, $11.fun);
}
#line 1915 "./src/y.tab.c"
    break;

  case 40: /* nombreFuncion: IDENTIFIER  */
#line 645 "./src/parser.y"
{
	if (!getvalsymNum((yyvsp[0].string)))
	{
		add_SymNum((yyvsp[0].string), 1 , "string");
		printf("No function has the same name ---> "GRN" CORRECT"RESET"\n");		
	}
	else 
	{
		printf("There is a function with that name --> "RED" ERROR\n"RESET"");		
	}
	//fprintf(yyout, "Name function\n");
}
#line 1932 "./src/y.tab.c"
    break;

  case 41: /* Fun: RETURN IDENTIFIER  */
#line 659 "./src/parser.y"
                       {

	if (!getvalsymText((yyvsp[0].string)))
	{
		printf("The variable %s has not been defined \n", (yyvsp[0].string));
		printf(RED"\nERROR"RESET" -- Referencing of undefined variable.");
		printf("\nExiting with "RED"errors."RESET"\n");
		exit(1);
	} 
	else 
	{
		printf("It has at least one return\n");
		if (strcmp(globalType, gettypesymText((yyvsp[0].string))) == 0) 
		{
			printf("The return type is corret --> "GRN" CORRECT "RESET" \n");		
		}
		else
		{
			printf("The return type doesn't equals the function type --> "RED" ERROR "RESET"\n");		
		}
	}
}
#line 1959 "./src/y.tab.c"
    break;

  case 47: /* while_loop: WHILE calc LOOP sentence ENDLOOP SEMI_COLUMN  */
#line 693 "./src/parser.y"
{ 
	//$$.f = newflow('W', $2.f, $4.f, NULL);  
	//fprintf(yyout, "WHILEEEEEE\n");
	//printf("while\n");
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper((yyvsp[-4].snum).f);
	fprintf(yyout, ".text\n");
	textWhile(globalSignCond, (yyval.snum).f);
	globalNumCounter = 0;
	globalOpCounter = 0;
	globalBoolCond = 0;

	fprintf(yyout, "..............................................\n");
}
#line 1979 "./src/y.tab.c"
    break;


#line 1983 "./src/y.tab.c"

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

#line 717 "./src/parser.y"


int file_isreg(const char *path)
{
    struct stat st;

    if (stat(path, &st) < 0)
        return -1;

    return S_ISREG(st.st_mode);
}

int main(int argc, char *argv[])
{

	if (argc == 1)
		yyparse();


	if (argc >= 2)
	{
		if (argc == 4) 
		{
			if (!strcmp(OUT_ARG, argv[2])) 
				yyout = fopen(argv[3], "wt");
			else
			{
				printf(RED"ERROR "RESET"- Invalid argument.\n", 30);
				exit(1);
			}

			
		}
		else 
		{
			yyout = fopen("./out.asm", "wt");
		}
		if (file_isreg(argv[1]) == 1)
			yyin = fopen(argv[1], "rt");
		else 
		{
			printf(RED "\nERROR" RESET, 30);
			printf("- Can't open input file. \n");
			exit(1);
		}

		yyparse();
	}

	return 0;
}


yyerror()
{ 
} 
