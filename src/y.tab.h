/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    SUBS = 259,                    /* SUBS  */
    MULT = 260,                    /* MULT  */
    DIV = 261,                     /* DIV  */
    LEFT_P = 262,                  /* LEFT_P  */
    RIGHT_P = 263,                 /* RIGHT_P  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    ELSIF = 266,                   /* ELSIF  */
    BIG_THAN = 267,                /* BIG_THAN  */
    LES_THAN = 268,                /* LES_THAN  */
    ELSE = 269,                    /* ELSE  */
    PROCEDURE = 270,               /* PROCEDURE  */
    IS = 271,                      /* IS  */
    END = 272,                     /* END  */
    START = 273,                   /* START  */
    COLUMN = 274,                  /* COLUMN  */
    INTEGER = 275,                 /* INTEGER  */
    FLOAT = 276,                   /* FLOAT  */
    STRING = 277,                  /* STRING  */
    BOOLEAN = 278,                 /* BOOLEAN  */
    IDENTIFICADORSYMB = 279,       /* IDENTIFICADORSYMB  */
    LEFTP_COM = 280,               /* LEFTP_COM  */
    COL_EQUAL = 281,               /* COL_EQUAL  */
    RIGHTP_COM = 282,              /* RIGHTP_COM  */
    PUTLINE = 283,                 /* PUTLINE  */
    ENDIF = 284,                   /* ENDIF  */
    TRUE = 285,                    /* TRUE  */
    FALSE = 286,                   /* FALSE  */
    LINE_COMMENT = 287,            /* LINE_COMMENT  */
    WHILE = 288,                   /* WHILE  */
    LOOP = 289,                    /* LOOP  */
    ENDLOOP = 290,                 /* ENDLOOP  */
    EQUALS = 291,                  /* EQUALS  */
    FOR = 292,                     /* FOR  */
    IN = 293,                      /* IN  */
    RANGE = 294,                   /* RANGE  */
    FUNCTION = 295,                /* FUNCTION  */
    RETURN = 296,                  /* RETURN  */
    SEMI_COLUMN = 297,             /* SEMI_COLUMN  */
    INTEGERNUM = 298,              /* INTEGERNUM  */
    REALNUM = 299,                 /* REALNUM  */
    IDENTIFIER = 300               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ADD 258
#define SUBS 259
#define MULT 260
#define DIV 261
#define LEFT_P 262
#define RIGHT_P 263
#define IF 264
#define THEN 265
#define ELSIF 266
#define BIG_THAN 267
#define LES_THAN 268
#define ELSE 269
#define PROCEDURE 270
#define IS 271
#define END 272
#define START 273
#define COLUMN 274
#define INTEGER 275
#define FLOAT 276
#define STRING 277
#define BOOLEAN 278
#define IDENTIFICADORSYMB 279
#define LEFTP_COM 280
#define COL_EQUAL 281
#define RIGHTP_COM 282
#define PUTLINE 283
#define ENDIF 284
#define TRUE 285
#define FALSE 286
#define LINE_COMMENT 287
#define WHILE 288
#define LOOP 289
#define ENDLOOP 290
#define EQUALS 291
#define FOR 292
#define IN 293
#define RANGE 294
#define FUNCTION 295
#define RETURN 296
#define SEMI_COLUMN 297
#define INTEGERNUM 298
#define REALNUM 299
#define IDENTIFIER 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 97 "./src/parser.y"

	int number;
	double numberf;
	char *string;
	struct 
	{
		char *type;
		char globalSignCond;
		int value;
		double dvalue;
		char *text;
 		int booleanCond;
		int globalNumCounter;
		int valid;
		struct ast *node;
		struct flow *f;
		struct fncall *fun;
	} snum;

#line 177 "./src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
