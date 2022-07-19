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

#define OUT_ARG "-o"

extern FILE *yyin;
extern FILE *yyout;

int compiling_ok = 0;

/**** 	NUMBERS		****/

add_SymNum ( char *sym_name, int sym_val, char *sym_type ) 
{  
	symbolRec *s;
   	s = getsymNum (sym_name,sym_val);
   	if (s == 0)
	{
        s = putsymNum (sym_name,sym_val, sym_type);
        printf( "The variable %s is not defined, it gets defined as %d and of the type %s \n", sym_name, sym_val, sym_type );
   	}
	else
	{
		printf( "The variable %s is already defined, with the value %d and of the type %s \n", sym_name, sym_val, sym_type );
   	}
}

Update_SymNum( char *sym_name, int sym_val )
{ 
	symbolRec *act;

  	if ( getsymNum( sym_name, sym_val ) == 0 ) 
	{
    	printf( "The variable %s is not defined, its %d\n", sym_name, sym_val );
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
        printf( "The variable %s is not defined, it gets defined with the value %s and of %s type \n\n", sym_name, sym_text, sym_type );
   	}
	else 
	{
		printf(RED"\nERROR"RESET" -- The variable %s is already defined, it is of type %s \n\n", sym_name, sym_type );
		printf("\nExiting with "RED"errors."RESET"\n");
		exit(1);
   	}
}

Update_SymText( char *sym_name, char *sym_text  )
{ 
	symbolRec *act;
  	if ( getsymText( sym_name, sym_text ) == 0 )
	{
     	printf( "The variable %s was not found\n", sym_name, sym_text );
  	}
	else
	{
    	act = updatesymText( sym_name, sym_text); 
     	printf( "The variable %s changes it's value to %s\n", act->name, act->text );
  	}
}

char *parsedType;

#line 166 "./src/y.tab.c"

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
  YYSYMBOL_ELSIF = 11,                     /* ELSIF  */
  YYSYMBOL_BIG_THAN = 12,                  /* BIG_THAN  */
  YYSYMBOL_LES_THAN = 13,                  /* LES_THAN  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_PROCEDURE = 15,                 /* PROCEDURE  */
  YYSYMBOL_IS = 16,                        /* IS  */
  YYSYMBOL_END = 17,                       /* END  */
  YYSYMBOL_START = 18,                     /* START  */
  YYSYMBOL_COLUMN = 19,                    /* COLUMN  */
  YYSYMBOL_INTEGER = 20,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 21,                     /* FLOAT  */
  YYSYMBOL_STRING = 22,                    /* STRING  */
  YYSYMBOL_BOOLEAN = 23,                   /* BOOLEAN  */
  YYSYMBOL_IDENTIFICADORSYMB = 24,         /* IDENTIFICADORSYMB  */
  YYSYMBOL_LEFTP_COM = 25,                 /* LEFTP_COM  */
  YYSYMBOL_COL_EQUAL = 26,                 /* COL_EQUAL  */
  YYSYMBOL_RIGHTP_COM = 27,                /* RIGHTP_COM  */
  YYSYMBOL_PUTLINE = 28,                   /* PUTLINE  */
  YYSYMBOL_ENDIF = 29,                     /* ENDIF  */
  YYSYMBOL_TRUE = 30,                      /* TRUE  */
  YYSYMBOL_FALSE = 31,                     /* FALSE  */
  YYSYMBOL_LINE_COMMENT = 32,              /* LINE_COMMENT  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_LOOP = 34,                      /* LOOP  */
  YYSYMBOL_ENDLOOP = 35,                   /* ENDLOOP  */
  YYSYMBOL_EQUALS = 36,                    /* EQUALS  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_IN = 38,                        /* IN  */
  YYSYMBOL_RANGE = 39,                     /* RANGE  */
  YYSYMBOL_FUNCTION = 40,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_SEMI_COLUMN = 42,               /* SEMI_COLUMN  */
  YYSYMBOL_INTEGERNUM = 43,                /* INTEGERNUM  */
  YYSYMBOL_REALNUM = 44,                   /* REALNUM  */
  YYSYMBOL_IDENTIFIER = 45,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_comp = 47,                      /* comp  */
  YYSYMBOL_body = 48,                      /* body  */
  YYSYMBOL_initproc = 49,                  /* initproc  */
  YYSYMBOL_endproc = 50,                   /* endproc  */
  YYSYMBOL_var_name = 51,                  /* var_name  */
  YYSYMBOL_func_name = 52,                 /* func_name  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_beginning = 54,                 /* beginning  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_type = 57,                      /* type  */
  YYSYMBOL_sentence = 58,                  /* sentence  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_if_sentence = 60,               /* if_sentence  */
  YYSYMBOL_calc = 61,                      /* calc  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_nombreFuncion = 63,             /* nombreFuncion  */
  YYSYMBOL_Fun = 64,                       /* Fun  */
  YYSYMBOL_factor = 65,                    /* factor  */
  YYSYMBOL_while_loop = 66,                /* while_loop  */
  YYSYMBOL_for_loop = 67,                  /* for_loop  */
  YYSYMBOL_iter_range = 68                 /* iter_range  */
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
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   139,   142,   144,   146,   152,   166,   170,
     174,   175,   178,   193,   197,   201,   205,   211,   212,   215,
     245,   250,   251,   252,   253,   254,   255,   259,   266,   273,
     281,   315,   350,   385,   428,   449,   466,   486,   495,   501,
     525,   530,   544,   569,   570,   571,   572,   573,   577,   585,
     592
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
  "DIV", "LEFT_P", "RIGHT_P", "IF", "THEN", "ELSIF", "BIG_THAN",
  "LES_THAN", "ELSE", "PROCEDURE", "IS", "END", "START", "COLUMN",
  "INTEGER", "FLOAT", "STRING", "BOOLEAN", "IDENTIFICADORSYMB",
  "LEFTP_COM", "COL_EQUAL", "RIGHTP_COM", "PUTLINE", "ENDIF", "TRUE",
  "FALSE", "LINE_COMMENT", "WHILE", "LOOP", "ENDLOOP", "EQUALS", "FOR",
  "IN", "RANGE", "FUNCTION", "RETURN", "SEMI_COLUMN", "INTEGERNUM",
  "REALNUM", "IDENTIFIER", "$accept", "comp", "body", "initproc",
  "endproc", "var_name", "func_name", "expression", "beginning",
  "statements", "statement", "type", "sentence", "expr", "if_sentence",
  "calc", "function", "nombreFuncion", "Fun", "factor", "while_loop",
  "for_loop", "iter_range", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   -37,    10,   -58,   -23,   -58,    13,   -58,     5,    17,
     -12,   -58,   -58,   213,   -10,   -58,   -58,   132,   -58,   -58,
     -58,   -58,   -58,    -6,   -58,    -1,   -26,    20,   -58,   -26,
       1,     6,    27,   132,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   170,     9,   181,    19,   -58,    51,
     180,   -58,   -26,   -26,   -26,   -26,   132,   -26,   -26,   -26,
      32,   132,   183,   -23,   -58,   -58,   -58,   -58,   -58,     8,
      21,    43,    43,     3,     3,    57,   196,   196,   196,    22,
      63,   -58,   -58,   -58,    28,    36,    -5,   -58,   -58,   -26,
     132,    31,   -58,    34,   183,   132,    33,   185,    78,   -58,
     -58,   -58,    84,   213,   132,    38,    41,    62,   100,   -58,
     -58,    66,   132,   132,   118,   116,    46,    47,    82,   -58,
     -58,    59,   -58
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
       5,    37,    38,    39,     0,     0,     0,     0,    41,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    37,    38,    39,     0,
       0,    30,    31,    32,    33,     0,    34,    35,    36,     0,
       0,    43,    44,    45,     0,     0,     0,    19,    22,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    27,
      48,    50,     0,     0,     0,     0,     0,     0,     0,    29,
      49,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      42,     0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,    42,
      -9,    23,   -52,   -33,   -58,   -27,   -58,   -58,   -58,   -57,
     -58,   -58,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    15,     6,    25,     9,    17,    10,
      11,    23,    33,    34,    35,    44,    36,    49,   118,    70,
      37,    38,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      51,    18,    46,    96,    75,    84,    16,     1,     5,    80,
       7,    52,    53,    54,    55,    57,    58,    41,    42,    43,
      57,    58,     8,    69,    13,    71,    72,    73,    74,    12,
      76,    77,    78,     8,    14,    24,    39,   101,    98,    59,
       8,    40,    51,   102,    59,    45,    47,    51,    54,    55,
      87,    48,   108,    50,    60,    57,    58,    62,    63,    79,
     114,   115,    97,    88,    92,    51,    26,    94,    89,    51,
      95,    90,    26,    99,   103,    51,   100,    18,   111,    59,
     109,    51,    51,   110,   113,    27,    91,    26,   119,    28,
      29,    27,   120,    26,    30,    28,    29,    31,    93,   121,
      30,   122,    32,    31,     0,    86,    27,   105,    32,    26,
      28,    29,    27,     0,   112,    30,    28,    29,    31,   106,
       0,    30,     0,    32,    31,    26,   107,    26,    27,    32,
       0,     0,    28,    29,     0,     0,     0,    30,     0,     0,
      31,    26,     0,     0,    27,    32,    27,   116,    28,    29,
      28,    29,     0,    30,     0,    30,    31,   117,    31,     0,
      27,    32,     0,    32,    28,    29,     0,     0,     0,    30,
       0,     0,    31,    52,    53,    54,    55,    32,     0,     0,
      56,     0,    57,    58,    52,    53,    54,    55,    52,    53,
      54,    55,     0,    57,    58,   104,     0,    57,    58,    52,
      53,    54,    55,     0,     0,     0,    59,     0,    57,    58,
      64,    65,     0,    64,    65,    61,     0,    59,     0,     0,
       0,    59,     0,    66,    67,    68,    81,    82,    83,     0,
       0,     0,    59,    19,    20,    21,    22
};

static const yytype_int8 yycheck[] =
{
      33,    10,    29,     8,    56,    62,    18,    15,    45,    61,
       0,     3,     4,     5,     6,    12,    13,    43,    44,    45,
      12,    13,    45,    50,    19,    52,    53,    54,    55,    16,
      57,    58,    59,    45,    17,    45,    42,    94,    90,    36,
      45,    42,    75,    95,    36,    25,    45,    80,     5,     6,
      42,    45,   104,    26,    45,    12,    13,    38,     7,    27,
     112,   113,    89,    42,    42,    98,     9,    39,    11,   102,
      34,    14,     9,    42,    41,   108,    42,    86,    16,    36,
      42,   114,   115,    42,    18,    28,    29,     9,    42,    32,
      33,    28,    45,     9,    37,    32,    33,    40,    35,    17,
      37,    42,    45,    40,    -1,    63,    28,    29,    45,     9,
      32,    33,    28,    -1,    14,    37,    32,    33,    40,    35,
      -1,    37,    -1,    45,    40,     9,   103,     9,    28,    45,
      -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,    -1,
      40,     9,    -1,    -1,    28,    45,    28,    29,    32,    33,
      32,    33,    -1,    37,    -1,    37,    40,    41,    40,    -1,
      28,    45,    -1,    45,    32,    33,    -1,    -1,    -1,    37,
      -1,    -1,    40,     3,     4,     5,     6,    45,    -1,    -1,
      10,    -1,    12,    13,     3,     4,     5,     6,     3,     4,
       5,     6,    -1,    12,    13,    10,    -1,    12,    13,     3,
       4,     5,     6,    -1,    -1,    -1,    36,    -1,    12,    13,
      30,    31,    -1,    30,    31,    34,    -1,    36,    -1,    -1,
      -1,    36,    -1,    43,    44,    45,    43,    44,    45,    -1,
      -1,    -1,    36,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    47,    48,    49,    45,    51,     0,    45,    53,
      55,    56,    16,    19,    17,    50,    18,    54,    56,    20,
      21,    22,    23,    57,    45,    52,     9,    28,    32,    33,
      37,    40,    45,    58,    59,    60,    62,    66,    67,    42,
      42,    43,    44,    45,    61,    25,    61,    45,    45,    63,
      26,    59,     3,     4,     5,     6,    10,    12,    13,    36,
      45,    34,    38,     7,    30,    31,    43,    44,    45,    61,
      65,    61,    61,    61,    61,    58,    61,    61,    61,    27,
      58,    43,    44,    45,    65,    68,    55,    42,    42,    11,
      14,    29,    42,    35,    39,    34,     8,    61,    58,    42,
      42,    65,    58,    41,    10,    29,    35,    57,    58,    42,
      42,    16,    14,    18,    58,    58,    29,    41,    64,    42,
      45,    17,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    55,    56,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    64,    65,    65,    65,    65,    65,    66,    67,
      68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     1,     1,     3,     1,
       2,     1,     4,     1,     1,     1,     1,     2,     1,     4,
       1,     5,     4,     1,     1,     1,     1,     6,    12,     8,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
      13,     1,     2,     1,     1,     1,     1,     1,     6,     8,
       3
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
#line 134 "./src/parser.y"
{
	printf(YEL"FINISH "RESET" -- ALL "GRN"OK"RESET"\n"); 
	compiling_ok = 1;
}
#line 1326 "./src/y.tab.c"
    break;

  case 4: /* initproc: PROCEDURE var_name IS  */
#line 142 "./src/parser.y"
                                   { printf(BLU"START OF THE PROCEDURE "RESET"-- \n\n");   }
#line 1332 "./src/y.tab.c"
    break;

  case 5: /* endproc: END func_name SEMI_COLUMN  */
#line 144 "./src/parser.y"
                                   { printf("--- \n"BLU"END OF THE PROCEDURE "RESET"\n\n"); }
#line 1338 "./src/y.tab.c"
    break;

  case 6: /* var_name: IDENTIFIER  */
#line 147 "./src/parser.y"
{
	add_SymText ( "Name", (yyvsp[0].string), "string" );
}
#line 1346 "./src/y.tab.c"
    break;

  case 7: /* func_name: IDENTIFIER  */
#line 153 "./src/parser.y"
{
	if (strcmp((yyvsp[0].string), getvalsymText("Name")) == 0) 
	{
		printf("The names at the beginning and the end are the same --> ");
		printf(GRN " CORRECT\n" RESET);
	} 
	else
	{
		printf("The names at the beginning and the end are NOT the same --> "RED"ERROR"RESET" \n");
		exit(1);
	}
}
#line 1363 "./src/y.tab.c"
    break;

  case 8: /* expression: statements beginning sentence  */
#line 166 "./src/parser.y"
                                            {}
#line 1369 "./src/y.tab.c"
    break;

  case 9: /* beginning: START  */
#line 170 "./src/parser.y"
                 {printf("###########################\n "YEL"BEGIN"RESET" \n###########################\n\n");}
#line 1375 "./src/y.tab.c"
    break;

  case 12: /* statement: IDENTIFIER COLUMN type SEMI_COLUMN  */
#line 179 "./src/parser.y"
{ 
	printf("The variable %s gets defined \n", (yyvsp[-3].string));
	(yyval.snum).text = (yyvsp[-3].string); 
	(yyval.snum).type = parsedType;
	add_SymText((yyval.snum).text, (yyval.snum).text, (yyval.snum).type);

	(yyval.snum).node = newast('D', (yyvsp[-3].string), newnum((yyval.snum).type[0]));
	evalprint((yyval.snum).node);	
}
#line 1389 "./src/y.tab.c"
    break;

  case 13: /* type: INTEGER  */
#line 193 "./src/parser.y"
                {
		parsedType= " integer";
		printf(YEL"A variable of type Integer is defined\n"RESET);
	}
#line 1398 "./src/y.tab.c"
    break;

  case 14: /* type: FLOAT  */
#line 197 "./src/parser.y"
                {
		parsedType= "float";
		printf(YEL"A variable of type Float is defined\n"RESET);
	}
#line 1407 "./src/y.tab.c"
    break;

  case 15: /* type: STRING  */
#line 201 "./src/parser.y"
                 {
		parsedType= "string";
		printf(YEL"A variable of type String is defined\n"RESET);
	}
#line 1416 "./src/y.tab.c"
    break;

  case 16: /* type: BOOLEAN  */
#line 205 "./src/parser.y"
                  {
		parsedType= "boolean";
		printf(YEL"A variable of type Boolean is defined\n"RESET);
	}
#line 1425 "./src/y.tab.c"
    break;

  case 19: /* expr: IDENTIFIER COL_EQUAL calc SEMI_COLUMN  */
#line 215 "./src/parser.y"
                                            {
	(yyval.snum).node = newast('A', (yyvsp[-3].string), (yyvsp[-1].snum).node);
	(yyval.snum).node->type = (yyval.snum).type[0];

	(yyval.snum).text= (yyvsp[-3].string);

	if (!(yyval.snum).valid) 
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
	 		add_SymNum((yyvsp[-3].string), eval((yyvsp[-1].snum).node), (yyval.snum).type);
			Update_SymNum( (yyvsp[-3].string), eval((yyvsp[-1].snum).node) ); 
			printf("RESULT OF %s equals to %4.4g \n\n", (yyvsp[-3].string), eval((yyvsp[-1].snum).node));
			evalprint((yyval.snum).node);
		}
	} 
	else 
	{ 
		(yyval.snum).valid = 0;
	}

}
#line 1460 "./src/y.tab.c"
    break;

  case 20: /* expr: if_sentence  */
#line 246 "./src/parser.y"
{
	globalNumCounter = 0;
}
#line 1468 "./src/y.tab.c"
    break;

  case 21: /* expr: PUTLINE LEFTP_COM IDENTIFIER RIGHTP_COM SEMI_COLUMN  */
#line 250 "./src/parser.y"
                                                        { printf("Put_Line\n");   }
#line 1474 "./src/y.tab.c"
    break;

  case 22: /* expr: IDENTIFIER COL_EQUAL factor SEMI_COLUMN  */
#line 251 "./src/parser.y"
                                                                        { printf("Asignacion\n"); }
#line 1480 "./src/y.tab.c"
    break;

  case 23: /* expr: LINE_COMMENT  */
#line 252 "./src/parser.y"
                { printf("COMMENT \n");		 }
#line 1486 "./src/y.tab.c"
    break;

  case 24: /* expr: while_loop  */
#line 253 "./src/parser.y"
                { printf("WHILE LOOP \n\n"); }
#line 1492 "./src/y.tab.c"
    break;

  case 25: /* expr: for_loop  */
#line 254 "./src/parser.y"
                        { printf("FOR LOOP \n\n");	 }
#line 1498 "./src/y.tab.c"
    break;

  case 26: /* expr: function  */
#line 255 "./src/parser.y"
                        { printf("FUNCTION \n\n");	 }
#line 1504 "./src/y.tab.c"
    break;

  case 27: /* if_sentence: IF calc THEN sentence ENDIF SEMI_COLUMN  */
#line 260 "./src/parser.y"
{
	(yyval.snum).node = newast('I', (yyvsp[-4].snum).node, (yyvsp[-2].snum).node);
	dataOper((yyvsp[-4].snum).node);
 	textIf((yyval.snum).globalSignCond,(yyvsp[-4].snum).f);
}
#line 1514 "./src/y.tab.c"
    break;

  case 28: /* if_sentence: IF calc THEN sentence ELSIF calc THEN sentence ELSE sentence ENDIF SEMI_COLUMN  */
#line 267 "./src/parser.y"
{ 
	(yyval.snum).node = newast('I', (yyvsp[-10].snum).node, (yyvsp[-8].snum).node);
	dataOper((yyvsp[-10].snum).node);
 	textIf((yyval.snum).globalSignCond,(yyvsp[-10].snum).f);
}
#line 1524 "./src/y.tab.c"
    break;

  case 29: /* if_sentence: IF calc THEN sentence ELSE sentence ENDIF SEMI_COLUMN  */
#line 274 "./src/parser.y"
{ 
	(yyval.snum).node = newast('I', (yyvsp[-6].snum).node, (yyvsp[-4].snum).node);
	dataOper((yyvsp[-6].snum).node);
 	textIf((yyval.snum).globalSignCond,(yyvsp[-6].snum).f);
}
#line 1534 "./src/y.tab.c"
    break;

  case 30: /* calc: calc ADD calc  */
#line 282 "./src/parser.y"
{ 

	if (!(yyval.snum).valid)
	{
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer")) 
		{
			(yyval.snum).node = newast('+', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);
			(yyval.snum).type = (yyvsp[-2].snum).type;
			printf(YEL"ADD ON of %s type \n" RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).node = newast('+', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);
			(yyval.snum).type = (yyvsp[-2].snum).type;
			printf(YEL"ADD ON of %s type\n"RESET,  (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string") || ((yyvsp[0].snum).type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - ADDING on %s type is not allowed.\n", (yyval.snum).type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
		} 
	} 
	else 
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE ADD ON GETS CANCELLED\n");
	}

}
#line 1572 "./src/y.tab.c"
    break;

  case 31: /* calc: calc SUBS calc  */
#line 316 "./src/parser.y"
{ 

	if (!(yyval.snum).valid) 
	{
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer")) 
		{
			(yyval.snum).node = newast('-', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);

			printf(YEL"SUBTRACTION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).node = newast('-', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);

			printf(YEL"SUBTRACTION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string") || ((yyvsp[0].snum).type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - SUBTRACTION on %s type is not allowed.\n", (yyval.snum).type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
		} 
	} 
	else 
	{
		printf("THERE ARE ERRORS --> THE SUBTRACTION GETS CANCELLED\n");
	}

}
#line 1610 "./src/y.tab.c"
    break;

  case 32: /* calc: calc MULT calc  */
#line 351 "./src/parser.y"
{ 

	if ((yyval.snum).valid == 0) 
	{ 
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer"))
		{
			(yyval.snum).node = newast('*', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).node = newast('*', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string") || ((yyvsp[0].snum).type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - MULTIPLICATION on %s type is not allowed.\n", (yyval.snum).type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
		} 
	}
	else
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE MULTIPLICATION GETS CANCELLED \n");
	}

}
#line 1648 "./src/y.tab.c"
    break;

  case 33: /* calc: calc DIV calc  */
#line 385 "./src/parser.y"
                 {

	if (!(yyvsp[0].snum).value)	
	{ 
		printf(RED "\nERROR" RESET, 30);
		printf(" - Can't divide by 0. \n", 30);
		exit(1);
		(yyval.snum).valid = 1;
	}

	if (!(yyval.snum).valid) 
	{ 
		if (((yyvsp[-2].snum).type == " integer") && ((yyvsp[0].snum).type == " integer"))
		{
			(yyval.snum).node = newast('/', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);

			printf(YEL"DIVISION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "real") && ((yyvsp[0].snum).type == "real"))
		{
			(yyval.snum).node = newast('/', (yyvsp[-2].snum).node,(yyvsp[0].snum).node); 
			evalprint((yyval.snum).node);

			printf(YEL"DIVISION of %s type \n"RESET, (yyval.snum).type);
		} 
		else if (((yyvsp[-2].snum).type == "string") || ((yyvsp[0].snum).type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - DIVISION on %s type is not allowed.\n", (yyval.snum).type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
		}
	}
	else 
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE DIVISION GETS CANCELLED\n");
	}

}
#line 1694 "./src/y.tab.c"
    break;

  case 34: /* calc: calc BIG_THAN calc  */
#line 429 "./src/parser.y"
{
	printf(YEL"\nBIGGER THAN condition\n" RESET);

	if ((yyvsp[-2].snum).value > (yyvsp[0].snum).value) {
		(yyval.snum).booleanCond = 1;
		(yyval.snum).f = (yyval.snum).booleanCond;
		(yyval.snum).globalSignCond = '>';

		printf("Condition BIGGER THAN is true - Is bigger\n");
	}
	else 
	{
		(yyval.snum).booleanCond = 0;
		(yyval.snum).f = (yyval.snum).booleanCond;
		(yyval.snum).globalSignCond = '>';

		printf("Condition BIGGER THAN is false - It's not bigger \n");
	}

}
#line 1719 "./src/y.tab.c"
    break;

  case 35: /* calc: calc LES_THAN calc  */
#line 449 "./src/parser.y"
                     {
	printf(YEL "\NLESS THAN condition.\n" RESET);
	if ((yyvsp[-2].snum).value < (yyvsp[0].snum).value) {
		(yyval.snum).booleanCond =1;
		(yyval.snum).f = (yyval.snum).booleanCond;
		(yyval.snum).globalSignCond = '<';


		printf("Condition LESS THAN is true - It's smaller\n");
	} else {
		(yyval.snum).booleanCond = 0;
		(yyval.snum).f = (yyval.snum).booleanCond;
		(yyval.snum).globalSignCond = '<';

		printf( "Condition LESS THAN is false - It's not smaller\n");
	}
}
#line 1741 "./src/y.tab.c"
    break;

  case 36: /* calc: calc EQUALS calc  */
#line 466 "./src/parser.y"
                   {
	printf(YEL "EQUALS condition\n" RESET);

	if ((yyvsp[-2].snum).value == (yyvsp[0].snum).value) 
	{
		printf("Condition EQUALS is true - It's equal\n");
		(yyval.snum).booleanCond = 1;
		(yyval.snum).f = (yyval.snum).booleanCond;
		(yyval.snum).globalSignCond = '=';
	}
	else
	{
		printf("Condition EQUALS is false - It's equal\n");
		(yyval.snum).booleanCond = 0;
		(yyval.snum).f = (yyval.snum).booleanCond;
		(yyval.snum).globalSignCond = '=';
	}

}
#line 1765 "./src/y.tab.c"
    break;

  case 37: /* calc: INTEGERNUM  */
#line 487 "./src/parser.y"
{ 
	(yyval.snum).node = newnum((yyvsp[0].number));
	(yyval.snum).value = (yyvsp[0].number);
	(yyval.snum).type = " integer";
	(yyval.snum).globalNumCounter = (yyval.snum).globalNumCounter +1;
	numCounter((yyval.snum).globalNumCounter, (yyval.snum).value );
}
#line 1777 "./src/y.tab.c"
    break;

  case 38: /* calc: REALNUM  */
#line 496 "./src/parser.y"
{
	(yyval.snum).node= newnum((yyvsp[0].numberf));
	(yyval.snum).dvalue = (yyvsp[0].numberf); (yyval.snum).type = "real";
}
#line 1786 "./src/y.tab.c"
    break;

  case 39: /* calc: IDENTIFIER  */
#line 502 "./src/parser.y"
{
	(yyval.snum).type = "string";

	if (!getvalsymText((yyvsp[0].string)))
	{
		(yyval.snum).valid = 1;
		printf("The variable %s does NOT exist \n", (yyvsp[0].string));

	} 
	else 
	{
		(yyval.snum).valid = 0;
		(yyval.snum).value = getvalsymNum((yyvsp[0].string));
		(yyval.snum).node= newnum((yyval.snum).value);
		(yyval.snum).globalNumCounter = (yyval.snum).globalNumCounter +1;
		numCounter((yyval.snum).globalNumCounter, (yyval.snum).value );

		printf("The variable %s does exist \n", (yyvsp[0].string));		
	}
}
#line 1811 "./src/y.tab.c"
    break;

  case 40: /* function: FUNCTION nombreFuncion LEFT_P statements RIGHT_P RETURN type IS START sentence Fun END SEMI_COLUMN  */
#line 525 "./src/parser.y"
                                                                                                             {
	//$$.fun = newfunc($4.fun, $11.fun);
}
#line 1819 "./src/y.tab.c"
    break;

  case 41: /* nombreFuncion: IDENTIFIER  */
#line 531 "./src/parser.y"
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
}
#line 1835 "./src/y.tab.c"
    break;

  case 42: /* Fun: RETURN IDENTIFIER  */
#line 544 "./src/parser.y"
                       {

	if (!getvalsymText((yyvsp[0].string)))
	{
		printf("The variable %s has not been defined \n", (yyvsp[0].string));
		printf(RED"\nERROR"RESET" -- Referencing of undefined variable.");
		printf("\nExiting with "RED"errors"RESET".\n");
		exit(1);
	} 
	else 
	{
		printf("It has at least one return\n");
		if (strcmp((yyval.snum).type, gettypesymText((yyvsp[0].string))) == 0) 
		{
			printf("The return type is corret --> "GRN" CORRECT "RESET" \n");		
		}
		else
		{
			printf("The return type doesn't equals the function type --> "RED" ERROR "RESET"\n");		
		}
	}
}
#line 1862 "./src/y.tab.c"
    break;

  case 48: /* while_loop: WHILE calc LOOP sentence ENDLOOP SEMI_COLUMN  */
#line 578 "./src/parser.y"
{ 
	(yyval.snum).node = newast('W', (yyvsp[-4].snum).node, (yyvsp[-2].snum).node);
	dataOper((yyvsp[-4].snum).f);
	textWhile((yyval.snum).globalSignCond, (yyval.snum).f);
}
#line 1872 "./src/y.tab.c"
    break;

  case 49: /* for_loop: FOR IDENTIFIER IN iter_range LOOP sentence ENDLOOP SEMI_COLUMN  */
#line 585 "./src/parser.y"
                                                                         {
	(yyval.snum).node = newast('W', (yyvsp[-6].string), (yyvsp[-2].snum).node);

	printf("BUCLE FOOR\n");
}
#line 1882 "./src/y.tab.c"
    break;


#line 1886 "./src/y.tab.c"

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

#line 596 "./src/parser.y"


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
			yyout = fopen("./out.nodesm", "wt");
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

	if (!compiling_ok) {
		printf(RED "\n\nERROR" RESET, 30);
		printf(" - Unexpected token while parsing. \n");
		printf(RED"\nABORTING ---\n"RESET);
	}

	return 0;
}


yyerror()
{ 
} 
