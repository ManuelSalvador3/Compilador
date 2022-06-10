%{
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


%}

%token ADD SUBS MULT DIV LEFT_P RIGHT_P IF THEN BIG_THAN LES_THAN ELSE  PROCEDURE IS END START COLUMN INTEGER FLOAT STRING BOOLEAN IDENTIFICADORSYMB LEFTP_COM COL_EQUAL RIGHTP_COM PUTLINE ENDIF TRUE FALSE LINE_COMMENT WHILE LOOP ENDLOOP EQUALS FOR IN RANGE FUNCTION RETURN SEMI_COLUMN

%left ADD SUBS
%left MULT DIV

%token <number> INTEGERNUM 
%token <numberf> REALNUM
%token <string> IDENTIFIER

%type<snum> while_loop if_sentence func_name statement calc expr Fun function

%union 
{
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
}


%start comp

%%

comp: body 
{
	printf(YEL"FINISH "RESET" -- ALL "GRN"OK"RESET"\n"); 
};

body: initproc expression endproc;


initproc: PROCEDURE var_name IS    { printf(BLU"START OF THE PROCEDURE "RESET"-- \n\n");   };

endproc: END func_name SEMI_COLUMN { printf("--- \n"BLU"END OF THE PROCEDURE "RESET"\n\n"); };

var_name: IDENTIFIER 
{
	add_SymText ( "Name", $1, "string" );
};


func_name: IDENTIFIER 
{

	if (strcmp($1, getvalsymText("Name")) == 0) 
	{
		printf("The names at the beginning and the end are the same --> ");
		printf(GRN " CORRECT\n" RESET);
	} 
	else
	{
		printf("The names at the beginning and the end are NOT the same --> "RED"ERROR"RESET" \n");
	}
};

expression: statements  beginning  sentence {}
;


beginning: START {printf("###########################\n "YEL"BEGIN"RESET" \n###########################\n\n");}
;


statements: statements  statement
	| statement 
;

statement: IDENTIFIER COLUMN type SEMI_COLUMN 
{ 
	printf("The variable %s gets defined \n", $1);
	$$.text = $1; add_SymText ( $$.text, $$.text, globalType);
}
;


type: INTEGER {
			globalType= " integer";
			printf(YEL"A variable of type Integer is defined\n"RESET);
		}
       |FLOAT {
			globalType= "float";
			printf(YEL"A variable of type Float is defined\n"RESET);
		}
       |STRING {
			globalType= "string";
			printf(YEL"A variable of type String is defined\n"RESET);
		}
       |BOOLEAN {
			globalType= "boolean";
			printf(YEL"A variable of type Boolean is defined\n"RESET);
		}	
;

sentence: sentence  expr 
	| expr
;

expr: IDENTIFIER  COL_EQUAL calc SEMI_COLUMN {
	if (globalBoolCond == 0) {
		globalBoolCond =0;
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper($3.a);
 		fprintf(yyout, ".text\n");
		textOper($3.a);
 		fprintf(yyout, "..............................................\n");
		globalNumCounter =0;
		globalOpCounter =0;
		globalBoolCond =0;
	}


	//printf("Condicion: %d \n", $$.booleanCond);


	$$.text= $1;

	if (!globalError) 
	{ 
		if (!getvalsymText($$.text)) 
		{
			printf("The variable %s has not been defined -->" RED " ERROR \n" RESET, $$.text);
			printf(RED"\nERROR"RESET" -- Referencing of undefined variable.");
			printf("\nExiting with "RED"errors."RESET"\n");
		exit(1);
		}
		else
		{
			printf("The variable %s has already been defined -->" GRN " CORRECT \n" RESET, $$.text);
	 		add_SymNum($1, eval($3.a), globalType);
			Update_SymNum( $1, eval($3.a) ); 
			printf("RESULT OF %s equals to %4.4g \n\n", $1, eval($3.a));
		}
	} 
	else 
	{ 
		globalError = 0;
	}

}
| if_sentence 
{
	globalNumCounter = 0;
	//printf("Llego 1");
}

| PUTLINE LEFTP_COM IDENTIFIER RIGHTP_COM SEMI_COLUMN 	{ printf("Put_Line\n");   }
| IDENTIFIER COL_EQUAL factor SEMI_COLUMN 				{ printf("Asignacion\n"); }
| LINE_COMMENT 	{ printf("COMMENT \n");		 }
| while_loop 	{ printf("WHILE LOOP \n\n"); }
| bucle_for 	{ printf("FOR LOOP \n\n");	 }
| function 		{ printf("FUNCTION \n\n");	 }
;


if_sentence: IF calc THEN sentence ENDIF SEMI_COLUMN 
{
	//printf("LLEGADA AL 2");
	//$$.f = newflow('I', $2.f , $5.f, NULL); 
	//fprintf(yyout, "IFFFFFFFFF\n");
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper($2.a);
	fprintf(yyout, ".text\n");
	textIf(globalSignCond,$2.f);
	fprintf(yyout, "..............................................\n");
	globalNumCounter =0;
	globalOpCounter =0;
	globalBoolCond =0;

}

| IF calc THEN  sentence  ELSE  sentence  ENDIF SEMI_COLUMN 
{ 
	//$$.f = newflow('I', $2.f, $5.f, $9.f); 
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper($2.a);
	fprintf(yyout, ".text\n");
	textIf(globalSignCond,$2.f);
	fprintf(yyout, "..............................................\n");
	globalNumCounter =0;
	globalOpCounter =0;
	globalBoolCond =0;
}
;

/*ARBOL*/
calc:  calc ADD calc 
{ 
	//printf("ADD ON of\n");
	globalOpCounter = globalOpCounter + 1;

	if (!globalError)
	{
		if (($1.type == " integer") && ($3.type == " integer")) 
		{
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.type;
			opCounter(globalOpCounter, $$.a);
			printf(YEL"ADD ON of %s type \n" RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.type;
			opCounter(globalOpCounter, $$.a);
			printf(YEL"ADD ON of %s type\n"RESET,  $$.type);
		} 
		else if (($1.type == "string"))
		{
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $3.type;
			opCounter(globalOpCounter, $$.a);
			printf(YEL"ADD ON of %s type \n" RESET, $$.type);
		} 
		else if (($3.type == "string"))
		{
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.type;
			opCounter(globalOpCounter, $$.a);
			printf(YEL"ADD ON of %s type \n" RESET, $$.type);
		}
		else if (($3.type == "string") && ($1.type == "string"))
		{
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.type;
			opCounter(globalOpCounter, $$.a);
			printf(YEL"ADD ON of %s type \n" RESET, $$.type);
		}

	} 
	else 
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE ADD ON GETS CANCELLED\n");
	}

}
|  calc SUBS calc 
{ 
	//printf("SUBTRACTION \n");
	globalOpCounter = globalOpCounter + 1;

	if (!globalError) 
	{
		if (($1.type == " integer") && ($3.type == " integer")) 
		{
			$$.a = newast('-', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.a = newast('-', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "string"))
		{
			$$.a = newast('-', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, $$.type);
		} 
		else if (($3.type == "string"))
		{
			$$.a = newast('-', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, $$.type);
		}
		else if (($3.type == "string") && ($1.type == "string"))
		{
			$$.a = newast('-', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.type;
			opCounter(globalOpCounter, $$.a);

			printf(YEL"SUBTRACTION of %s type \n"RESET, $$.type);


		}
	} 
	else 
	{
		printf("THERE ARE ERRORS --> THE SUBTRACTION GETS CANCELLED\n");
	}

}

|  calc MULT calc 
{ 
	//printf("MULTIPLICATION\n");
	globalOpCounter = globalOpCounter + 1;

	if (globalError ==0) 
	{ 
		if (($1.type == " integer") && ($3.type == " integer"))
		{
			$$.a = newast('*', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.a = newast('*', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "string"))
		{
			$$.a = newast('*', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, $$.type);
		} 
		else if (($3.type == "string"))
		{
			$$.a = newast('*', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, $$.type);
		}
		else if (($3.type == "string") && ($1.type == "string"))
		{
			$$.a = newast('*', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			globalType = $1.type;
			printf(YEL"MULTIPLICATION of %s type \n"RESET, $$.type);


		}
	}
	else
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE MULTIPLICATION GETS CANCELLED \n");
	}

}

|  calc DIV calc {
	//printf("DIVISION \n");
	globalOpCounter = globalOpCounter + 1;

	if (!$3.value)	
	{ 
		printf(RED "\nERROR" RESET, 30);
		printf(" - Can't divide by 0. \n", 30);
		exit(1);
		globalError = 1;
	}

	if (!globalError) 
	{ 
		if (($1.type == " integer") && ($3.type == " integer"))
		{
			$$.a = newast('/', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"DIVISION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.a = newast('/', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"DIVISION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "string"))
		{
			$$.a = newast('/', $1.a,$3.a); 
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"DIVISION of %s type \n"RESET, $$.type);


		} 
		else if (($3.type == "string"))
		{
			$$.a = newast('/', $1.a,$3.a);
			evalprint($$.a);
			opCounter(globalOpCounter, $$.a);

			printf(YEL"DIVISION of %s type \n"RESET, $$.type);

		}
		else if (($3.type == "string") && ($1.type == "string"))
		{
			$$.a = newast('/', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.type;
			opCounter(globalOpCounter, $$.a);

			//printf(YEL"DIVISION of %s type \n"RESET, $$.type);
		}
	}
	else 
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE DIVISION GETS CANCELLED\n");
	}

}


| calc BIG_THAN calc 
{
	printf(YEL"\nBIGGER THAN condition\n" RESET);
	globalBoolCond = 1;

	if ($1.value > $3.value) {
		$$.booleanCond = 1;
		$$.f = $$.booleanCond;
		globalSignCond = '>';

		printf("Condition BIGGER THAN is true - Is bigger\n");
	}
	else 
	{
		$$.booleanCond =0;
		$$.f = $$.booleanCond;
		globalSignCond = '>';

		printf("Condition BIGGER THAN is false - It's not bigger \n");
	}

} 
| calc LES_THAN calc {
	printf(YEL "\NLESS THAN condition.\n" RESET);
	globalBoolCond = 1;
	if ($1.value < $3.value) {
		$$.booleanCond =1;
		$$.f = $$.booleanCond;
		globalSignCond = '<';


		printf("Condition LESS THAN is true - It's smaller\n");
	} else {
		$$.booleanCond = 0;
		$$.f = $$.booleanCond;
		globalSignCond = '<';

		printf( "Condition LESS THAN is false - It's not smaller\n");
	}
}
| calc EQUALS calc {
	printf(YEL "EQUALS condition\n" RESET);
	globalBoolCond = 1;

	if ($1.value == $3.value) 
	{
		printf("Condition EQUALS is true - It's equal\n");
		$$.booleanCond = 1;
		$$.f = $$.booleanCond;
		globalSignCond = '=';
	}
	else
	{
		printf("Condition EQUALS is false - It's equal\n");
		$$.booleanCond = 0;
		$$.f = $$.booleanCond;
		globalSignCond = '=';
	}

}

| INTEGERNUM 
{ 
	$$.a = newnum($1);
	$$.value = $1;
	$$.type = " integer";
	globalNumCounter = globalNumCounter +1;
	contadorNumeros(globalNumCounter, $$.value );
}

| REALNUM 
{
	$$.a= newnum($1);
	$$.dvalue = $1; $$.type = "real";
}

| IDENTIFIER 
{
	//printf("variable\n");
	$$.type = "string";

	if (!getvalsymText($1))
	{
		globalError = 1;
		printf("The variable %s does NOT exist \n", $1);

	} 
	else 
	{
		globalError = 0;
		$$.value = getvalsymNum($1);
		$$.a= newnum($$.value);
		globalNumCounter = globalNumCounter +1;
		contadorNumeros(globalNumCounter, $$.value );

		printf("The variable %s does exist \n", $1);		
	}
}
;


function: FUNCTION nombreFuncion LEFT_P statements RIGHT_P RETURN type IS START sentence Fun END SEMI_COLUMN {
	//$$.fun = newfunc($4.fun, $11.fun);
}
;

nombreFuncion: IDENTIFIER
{
	if (!getvalsymNum($1))
	{
		add_SymNum($1, 1 , "string");
		printf("No function has the same name ---> "GRN" CORRECT"RESET"\n");		
	}
	else 
	{
		printf("There is a function with that name --> "RED" ERROR\n"RESET"");		
	}
	//fprintf(yyout, "Name function\n");
}  
;

Fun: RETURN IDENTIFIER {

	if (!getvalsymText($2))
	{
		printf("The variable %s has not been defined \n", $2);
		printf(RED"\nERROR"RESET" -- Referencing of undefined variable.");
		printf("\nExiting with "RED"errors."RESET"\n");
		exit(1);
	} 
	else 
	{
		printf("It has at least one return\n");
		if (strcmp(globalType, gettypesymText($2)) == 0) 
		{
			printf("The return type is corret --> "GRN" CORRECT "RESET" \n");		
		}
		else
		{
			printf("The return type doesn't equals the function type --> "RED" ERROR "RESET"\n");		
		}
	}
} 
;


factor: INTEGERNUM 	//{ fprintf(yyout, "  factor --> INTEGERNUM(%d)\n", $1);}
	| REALNUM 		//{ fprintf(yyout, "  factor --> REALNUM(%f)\n"), $1; 	}
	| IDENTIFIER 	//{ fprintf(yyout, "  factor --> variable(%s)\n", $1); 	}
	| TRUE 			//{ fprintf(yyout, "  factor --> True\n"); 				}
	| FALSE 		//{ fprintf(yyout, "  factor --> False\n"); 			}
;


while_loop: WHILE calc LOOP sentence  ENDLOOP SEMI_COLUMN 
{ 
	//$$.f = newflow('W', $2.f, $4.f, NULL);  
	//fprintf(yyout, "WHILEEEEEE\n");
	//printf("while\n");
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper($2.f);
	fprintf(yyout, ".text\n");
	textWhile(globalSignCond, $$.f);
	globalNumCounter = 0;
	globalOpCounter = 0;
	globalBoolCond = 0;

	fprintf(yyout, "..............................................\n");
}
;

bucle_for: FOR factor IN rangos LOOP  sentence  ENDLOOP SEMI_COLUMN
;

rangos: factor RANGE factor //{fprintf(yyout, "Variable\n");}
;


%%

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