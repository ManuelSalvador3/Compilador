%{
#include "y.tab.h"

%}

%option noyywrap

digit       [0-9]
character   [a-zA-Z]
symbolchar  [a-zA-Z_\.]


%%
[ \t]+ ;

\n   ;


"+" 		{ return ADD;       }
"-" 		{ return SUBS;      }
"*" 		{ return MULT;      } 
"/" 		{ return DIV;       }
"(" 		{ return LEFT_P;    }
")" 		{ return RIGHT_P;   }
"if"  		{ return IF;        }
"then" 		{ return THEN;      }
">" 		{ return BIG_THAN;  }
"<" 		{ return LES_THAN;  }
"else" 		{ return ELSE;      }
"procedure" { return PROCEDURE; }
"is" 		{ return IS;        }
"end"		{ return END;       }
"begin" 	{ return START;     }
":" 		{ return COLUMN;    }
"Integer" 	{ return INTEGER;   }
"Float" 	{ return FLOAT;     }
"String" 	{ return STRING;    }
"Boolean"	{ return BOOLEAN;   }
":=" 		{ return COL_EQUAL; }
"(\"" 		{ return LEFTP_COM; }
"\")" 		{ return RIGHTP_COM;}
"Put_Line"	{ return PUTLINE;   }
"end if" 	{ return ENDIF;     }
"True" 		{ return TRUE;      }        
"False" 	{ return FALSE;     }
"while" 	{ return WHILE;     }
"loop" 		{ return LOOP;      }
"end loop" 	{ return ENDLOOP;   }
"=" 		{ return EQUALS;    }
"for"		{ return FOR;       }
"in"		{ return IN;        }
".."		{ return RANGE;     }
"function"	{ return FUNCTION;  }
"return"	{ return RETURN;    }
";" 		{ return SEMI_COLUMN;   }
"--".* 		{ return LINE_COMMENT;  }

{character}({character}|{digit})* yylval.string=strdup(yytext); return IDENTIFIER; 
{symbolchar}+ return IDENTIFICADORSYMB; 


[-+]?{digit}+ yylval.number=atoi(yytext); return INTEGERNUM;

[-+]?{digit}+(.{digit}+)?((E|e)[-+]?{digit}+)? yylval.numberf=atof(yytext); return REALNUM;

%%
