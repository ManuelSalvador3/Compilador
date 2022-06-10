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
    BIG_THAN = 266,                /* BIG_THAN  */
    LES_THAN = 267,                /* LES_THAN  */
    ELSE = 268,                    /* ELSE  */
    PROCEDURE = 269,               /* PROCEDURE  */
    IS = 270,                      /* IS  */
    END = 271,                     /* END  */
    START = 272,                   /* START  */
    COLUMN = 273,                  /* COLUMN  */
    INTEGER = 274,                 /* INTEGER  */
    FLOAT = 275,                   /* FLOAT  */
    STRING = 276,                  /* STRING  */
    BOOLEAN = 277,                 /* BOOLEAN  */
    IDENTIFICADORSYMB = 278,       /* IDENTIFICADORSYMB  */
    LEFTP_COM = 279,               /* LEFTP_COM  */
    COL_EQUAL = 280,               /* COL_EQUAL  */
    RIGHTP_COM = 281,              /* RIGHTP_COM  */
    PUTLINE = 282,                 /* PUTLINE  */
    ENDIF = 283,                   /* ENDIF  */
    TRUE = 284,                    /* TRUE  */
    FALSE = 285,                   /* FALSE  */
    LINE_COMMENT = 286,            /* LINE_COMMENT  */
    WHILE = 287,                   /* WHILE  */
    LOOP = 288,                    /* LOOP  */
    ENDLOOP = 289,                 /* ENDLOOP  */
    EQUALS = 290,                  /* EQUALS  */
    FOR = 291,                     /* FOR  */
    IN = 292,                      /* IN  */
    RANGE = 293,                   /* RANGE  */
    FUNCTION = 294,                /* FUNCTION  */
    RETURN = 295,                  /* RETURN  */
    SEMI_COLUMN = 296,             /* SEMI_COLUMN  */
    INTEGERNUM = 297,              /* INTEGERNUM  */
    REALNUM = 298,                 /* REALNUM  */
    IDENTIFIER = 299               /* IDENTIFIER  */
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
#define BIG_THAN 266
#define LES_THAN 267
#define ELSE 268
#define PROCEDURE 269
#define IS 270
#define END 271
#define START 272
#define COLUMN 273
#define INTEGER 274
#define FLOAT 275
#define STRING 276
#define BOOLEAN 277
#define IDENTIFICADORSYMB 278
#define LEFTP_COM 279
#define COL_EQUAL 280
#define RIGHTP_COM 281
#define PUTLINE 282
#define ENDIF 283
#define TRUE 284
#define FALSE 285
#define LINE_COMMENT 286
#define WHILE 287
#define LOOP 288
#define ENDLOOP 289
#define EQUALS 290
#define FOR 291
#define IN 292
#define RANGE 293
#define FUNCTION 294
#define RETURN 295
#define SEMI_COLUMN 296
#define INTEGERNUM 297
#define REALNUM 298
#define IDENTIFIER 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 103 "./src/parser.y"

	int number;
	double numberf;
	char *string;
	struct 
	{
		char *type;
		int value;
		double dvalue;
		char *text;
 		int booleanCond;
		struct ast *a;
		struct flow *f;
		struct fncall *fun;
	} snum;

#line 172 "./src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
