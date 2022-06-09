%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <math.h>
#include "symtab.h"
#include "AST.h"

extern FILE *yyin;
extern FILE *yyout;

int globalError =0;
int globalContadorNum =0;
int globalContadorOper =0;
int globalBoolCond = 0;
char globalSignCond;
char *globalType;


/**** 	NUMBERS		****/

add_SymNum ( char *sym_name, int sym_val, char *sym_type ) 
{  
	symrec *s;
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
	symrec *act;

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
	symrec *s;
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
	symrec *act;
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
		char *tipo;
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
	printf("FINISH -- ALL OK\n"); 
};

body: initproc expression endproc;


initproc: PROCEDURE var_name IS    { printf("START OF THE PROCEDURE -- \n\n");   };

endproc: END func_name SEMI_COLUMN { printf("--- \n END OF THE PROCEDURE \n\n"); };

var_name: IDENTIFIER 
{
	add_SymText ( "Name", $1, "string" );
};


func_name: IDENTIFIER 
{

	if (strcmp($1, getvalsymText("Name")) == 0) 
	{
		printf("The names at the beginning and the end are the same --> CORRECT\n");
	} 
	else
	{
		printf("The names at the beginning and the end are NOT the same --> ERROR \n");
	}
};

expression: statements  beginning  sentence {}
;


beginning: START {printf("###########################\n BEGIN \n###########################\n\n");}
;


statements: statements  statement
	| statement 
;

statement: IDENTIFIER COLUMN tipo SEMI_COLUMN 
{ 
	printf("The variable %s gets defined \n", $1);
	$$.text = $1; add_SymText ( $$.text, $$.text, globalType);
}
;


tipo: INTEGER {
			globalType= "interger";
			printf("A variable of type Integer it's defined\n");
		}
       |FLOAT {
			globalType= "float";
			printf("A variable of type Float it's defined\n");
		}
       |STRING {
			globalType= "string";
			printf("A variable of type String it's defined\n");
		}
       |BOOLEAN {
			globalType= "boolean";
			printf("A variable of type Boolean it's defined\n");
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
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;
	}


	//printf("Condicion: %d \n", $$.booleanCond);


	$$.text= $1;

	if (!globalError) 
	{ 
		if (!getvalsymText($$.text)) 
		{
			printf("The variable %s has not been defined --> ERROR \n", $$.text);
		}
		else
		{
			printf("The variable %s has already been defined --> CORRECT \n", $$.text);
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
| if_sentence {
	//fprintf(yyout, "Sentencia IF\n");
	globalContadorNum = 0;
	//printf("IFFFFFO\n");
	//textOper($1.a);

}

| PUTLINE LEFTP_COM IDENTIFIER RIGHTP_COM SEMI_COLUMN 	{ printf("Put_Line\n");   }
| IDENTIFIER COL_EQUAL factor SEMI_COLUMN 				{ printf("Asignacion\n"); }
| LINE_COMMENT 	{ printf("COMMENT \n");		 }
| while_loop 	{ printf("WHILE LOOP \n\n"); }
| bucle_for 	{ printf("FOR LOOP \n\n");	 }
| function 		{ printf("FUNCTION \n\n");	 }
;


if_sentence: IF calc THEN  sentence  ENDIF SEMI_COLUMN {
	//$$.f = newflow('I', $2.f , $5.f, NULL); 
	//fprintf(yyout, "IFFFFFFFFF\n");
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper($2.a);
	fprintf(yyout, ".text\n");
	textIf(globalSignCond,$2.f);
	fprintf(yyout, "..............................................\n");
	globalContadorNum =0;
	globalContadorOper =0;
	globalBoolCond =0;

}

| IF calc THEN  sentence  ELSE  sentence  ENDIF SEMI_COLUMN { 
	//$$.f = newflow('I', $2.f, $5.f, $9.f); 
	fprintf(yyout, "..............................................\n");
	fprintf(yyout, ".data\n");
	dataOper($2.a);
	fprintf(yyout, ".text\n");
	textIf(globalSignCond,$2.f);
	fprintf(yyout, "..............................................\n");
	globalContadorNum =0;
	globalContadorOper =0;
	globalBoolCond =0;
}
;

/*ARBOL*/
calc:  calc ADD calc { 
	//printf("ADD ON\n");
	globalContadorOper = globalContadorOper + 1;

	if (globalError ==0) { //No hay errores //comprobación de tipos
		if (($1.tipo == "interger") && ($3.tipo == "interger")) {
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.tipo;
			contadorOperadores(globalContadorOper, $$.a);
			printf("ADD ON of %s type \n", $$.tipo);
		} 
		else if (($1.tipo == "real") && ($3.tipo == "real")){
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.tipo;
			contadorOperadores(globalContadorOper, $$.a);
			printf("ADD ON of %s type\n", $$.tipo);
		} 
		else if (($1.tipo == "string")){
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $3.tipo;
			contadorOperadores(globalContadorOper, $$.a);
			printf("ADD ON of %s type \n", $$.tipo);
		} 
		else if (($3.tipo == "string")){
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.tipo;
			contadorOperadores(globalContadorOper, $$.a);
			printf("ADD ON of %s type \n", $$.tipo);
		}
		else if (($3.tipo == "string") && ($1.tipo == "string")){
			$$.a = newast('+', $1.a,$3.a); 
			evalprint($$.a);
			globalType = $1.tipo;
			contadorOperadores(globalContadorOper, $$.a);
			printf("ADD ON of %s type \n", $$.tipo);
		}

	} else {
		printf("THERE ARE ERRORS --> THE ADD ON GETS CANCELLED\n");

	}

}
	|  calc SUBS calc { 
		//printf("SUBTRACTION \n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores
			if (($1.tipo == "interger") && ($3.tipo == "interger")) {
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("SUBTRACTION of %s type \n", $$.tipo);
			} 
			else if (($1.tipo == "real") && ($3.tipo == "real")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("SUBTRACTION of %s type \n", $$.tipo);
			} 
			else if (($1.tipo == "string")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("SUBTRACTION of %s type \n", $$.tipo);
			} 
			else if (($3.tipo == "string")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("SUBTRACTION of %s type \n", $$.tipo);
			}
			else if (($3.tipo == "string") && ($1.tipo == "string")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				globalType = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);

				printf("SUBTRACTION of %s type \n", $$.tipo);


			}
		}  else {
			printf("THERE ARE ERRORS --> THE SUBTRACTION GETS CANCELLED\n");

		}

	}
	|  calc MULT calc { 
		//printf("MULTIPLICATION\n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores
			if (($1.tipo == "interger") && ($3.tipo == "interger")) {
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("MULTIPLICATION of %s type \n", $$.tipo);
			} 
			else if (($1.tipo == "real") && ($3.tipo == "real")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("MULTIPLICATION of %s type \n", $$.tipo);
			} 
			else if (($1.tipo == "string")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("MULTIPLICATION of %s type \n", $$.tipo);


			} 
			else if (($3.tipo == "string")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("MULTIPLICATION of %s type \n", $$.tipo);
			}
			else if (($3.tipo == "string") && ($1.tipo == "string")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				globalType = $1.tipo;
				printf("MULTIPLICATION of %s type \n", $$.tipo);


			}
		} else {
			printf("THERE ARE ERRORS --> THE MULTIPLICATION GETS CANCELLED \n");

		}

	}

	|   calc DIV calc {
		//printf("DIVISION \n");
		globalContadorOper = globalContadorOper + 1;

		if ($3.value == 0) { //No se puede dividir entre 0
			globalError =1;
		}

		if (globalError ==0) { //No hay errores
			if (($1.tipo == "interger") && ($3.tipo == "interger")) {
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("DIVISION of %s type \n", $$.tipo);
			} 
			else if (($1.tipo == "real") && ($3.tipo == "real")){
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("DIVISION of %s type \n", $$.tipo);
			} 
			else if (($1.tipo == "string")){
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("DIVISION of %s type \n", $$.tipo);


			} 
			else if (($3.tipo == "string")){
				$$.a = newast('/', $1.a,$3.a);
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("DIVISION of %s type \n", $$.tipo);

			}
			else if (($3.tipo == "string") && ($1.tipo == "string")){
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				globalType = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);

				//printf("DIVISION of %s type \n", $$.tipo);
			}
		}else {
			printf("THERE ARE ERRORS --> THE DIVISION GETS CANCELLED\n");
		}

	}


	| calc BIG_THAN calc {
		printf("\n BIGGER THAN condition\n");
		globalBoolCond = 1;

		if ($1.value > $3.value) {
			$$.booleanCond =1;
			$$.f = $$.booleanCond ;
			globalSignCond = '>';

			printf("Condition BIGGER THAN is correct - Is bigger\n");


		
		} else {
			$$.booleanCond =0;
			$$.f = $$.booleanCond;
			globalSignCond = '>';

			printf("Condition BIGGER THAN is not correct - It's not bigger \n");

		
		}

	} 
	| calc LES_THAN calc {
		printf("LESS THAN condition\n");
		globalBoolCond = 1;
			if ($1.value < $3.value) {
				$$.booleanCond =1;
				$$.f = $$.booleanCond;
				globalSignCond = '<';


				printf("Condition LESS THAN is correct - It's smaller\n");

		
			} else {
				$$.booleanCond =0;
				$$.f = $$.booleanCond;
				globalSignCond = '<';

				printf("Condition LESS THAN is NOT correct - It's not smaller\n");

			}


	}
	| calc EQUALS calc {
		printf("EQUALS condition\n");
		globalBoolCond = 1;

		if ($1.value == $3.value) {
			printf("Condition EQUALS is correct - It's equal\n");
			$$.booleanCond = 1;
			$$.f = $$.booleanCond;
			globalSignCond = '=';

		
		} else {
			printf("Condition EQUALS is NOT correct - It's equal\n");
			$$.booleanCond = 0;
			$$.f = $$.booleanCond;
			globalSignCond = '=';
		
		}

	}

	| INTEGERNUM { $$.a = newnum($1);
		$$.value = $1;
		$$.tipo = "interger";
		globalContadorNum = globalContadorNum +1;
		contadorNumeros(globalContadorNum, $$.value );
	}

	| REALNUM {
		$$.a= newnum($1);
		$$.dvalue = $1; $$.tipo = "real";


	}
	| IDENTIFIER {
		//printf("variable\n");
		$$.tipo = "string";

		if (getvalsymText($1) == 0 ) {
			globalError = 1;
			printf("The variable %s does NOT exist \n", $1);

		} else {
			globalError = 0;
			$$.value = getvalsymNum($1);
			$$.a= newnum($$.value);
			globalContadorNum = globalContadorNum +1;
			contadorNumeros(globalContadorNum, $$.value );

			printf("The variable %s does exist \n", $1);		
		}
	}
;


function: FUNCTION nombreFuncion LEFT_P statements RIGHT_P RETURN tipo IS  START  sentence  Fun  END SEMI_COLUMN {
	//$$.fun = newfunc($4.fun, $11.fun);
}
;

nombreFuncion: IDENTIFIER {
	if (getvalsymNum($1) == 0 ) {
		add_SymNum($1, 1 , "string");
		printf("No function has the same name ---> CORRECT\n");		
	} else {
		printf("There is a function with that name --> ERROR\n");		
	}
	//fprintf(yyout, "Name function\n");
}  
;

Fun: RETURN IDENTIFIER {

	if (getvalsymText($2) == 0 ) {
		printf("The variable %s has not been defined \n", $2);
	} else {
		printf("It has at least one return\n");
		if (strcmp(globalType, gettypesymText($2)) == 0) {
			printf("The return type is corret -->CORRECT\n");		
		} else {
			printf("The return type doesn't equals the function type --> ERROR\n");		
		}
	}
} 
;



factor: INTEGERNUM //{fprintf(yyout, "  factor--> INTEGERNUM(%d)\n", $1);}
	| REALNUM //{fprintf(yyout, "  factor--> REALNUM(%f)\n"), $1;}
	|IDENTIFIER //{fprintf(yyout, "  factor --> variable(%s)\n", $1);}
	|TRUE //{fprintf(yyout, "  factor --> True\n");}
	|FALSE //{fprintf(yyout, "  factor --> False\n");}
;


while_loop: WHILE calc LOOP  sentence  ENDLOOP SEMI_COLUMN { 
		//$$.f = newflow('W', $2.f, $4.f, NULL);  
 		//fprintf(yyout, "WHILEEEEEE\n");
		//printf("while\n");
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper($2.f);
 		fprintf(yyout, ".text\n");
		textWhile(globalSignCond, $$.f);
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;

 		fprintf(yyout, "..............................................\n");

}
;

bucle_for: FOR factor IN rangos LOOP  sentence  ENDLOOP SEMI_COLUMN
;

rangos: factor RANGE factor //{fprintf(yyout, "Variable\n");}
;


%%
int main(int argc, char *argv[]) {

	if (argc == 1) {
		yyparse();
	}
	if (argc == 2) {
		yyout = fopen( "./salidaAda.txt", "wt" );

		yyin = fopen(argv[1], "rt");

		yyparse();
	}

	return 0;
}


yyerror()
{ 
} 