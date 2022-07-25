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
    	printf( "The variable %s value now equals to %d\n", act->name, act->num );
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
%}

%union 
{
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
}

%token ADD SUBS MULT DIV LEFT_P RIGHT_P IF THEN ELSIF BIG_THAN LES_THAN ELSE PROCEDURE IS END START COLUMN INTEGER FLOAT STRING BOOLEAN IDENTIFICADORSYMB LEFTP_COM COL_EQUAL RIGHTP_COM PUTLINE ENDIF TRUE FALSE LINE_COMMENT WHILE LOOP ENDLOOP EQUALS FOR IN RANGE FUNCTION RETURN SEMI_COLUMN

%left ADD 	SUBS
%left MULT 	DIV

%token <number> 	INTEGERNUM 
%token <numberf> 	REALNUM
%token <string> 	IDENTIFIER

%type<snum> while_loop if_sentence for_loop func_name statement calc sentence expr Fun function put_line


%start comp

%%

comp: body 
{
	printf(YEL"FINISH "RESET" -- ALL "GRN"OK"RESET"\n"); 
	compiling_ok = 1;
};

body: initproc expression endproc;


initproc: PROCEDURE var_name IS    { 
	
	printf(BLU"START OF THE PROCEDURE "RESET"-- \n\n");   };

endproc: END func_name SEMI_COLUMN { 
	printf("--- \n"BLU"END OF THE PROCEDURE "RESET"\n\n"); };

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
		exit(1);
	}
};

expression: statements  beginning  sentence {}
;


beginning: START {
	fprintf(yyout, "\n.text \n");
	printf("###########################\n "YEL"BEGIN"RESET" \n###########################\n\n");}
;


statements: statements  statement
	| statement 
;

statement: IDENTIFIER COLUMN type SEMI_COLUMN 
{ 
	printf("The variable %s gets defined \n", $1);
	$$.text = $1; 
	$$.type = parsedType;
	add_SymText($$.text, $$.text, $$.type);

	$$.node = newast('D', $1, newnum_ast($$.type[0]));
	evalprint($$.node);	
}
;



type: 
	INTEGER {
		parsedType= "integer";
		printf(YEL"A variable of type Integer is defined\n"RESET);
	}
	| FLOAT {
		parsedType= "float";
		printf(YEL"A variable of type Float is defined\n"RESET);
	}
	| STRING {
		parsedType= "string";
		printf(YEL"A variable of type String is defined\n"RESET);
	}
	| BOOLEAN {
		parsedType= "boolean";
		printf(YEL"A variable of type Boolean is defined\n"RESET);
	}	
;

sentence: sentence  expr 
	| expr
;

expr: IDENTIFIER COL_EQUAL calc SEMI_COLUMN {
	$$.node = newast('A', $1, $3.node);
	$$.node->type = $$.type[0];

	$$.text= $1;

	if (!$$.valid) 
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
	 		add_SymNum($1, eval($3.node), $$.type);
			Update_SymNum( $1, eval($3.node) ); 
			printf("RESULT OF %s equals to %4.4g \n\n", $1, eval($3.node));
			evalprint($$.node);
		}
	} 
	else 
	{ 
		$$.valid = 0;
	}

}
| if_sentence 
{
	globalNumCounter = 0;
}

| put_line 	{ printf("Put_Line\n");   }
| IDENTIFIER COL_EQUAL factor SEMI_COLUMN 				{ printf("Asignacion\n"); }
| LINE_COMMENT 	{ printf("COMMENT \n");		 }
| while_loop 	{ printf("WHILE LOOP \n\n"); }
| for_loop 		{ printf("FOR LOOP \n\n");	 }
| function 		{ printf("FUNCTION \n\n");	 }
;


if_sentence: IF calc THEN sentence ENDIF SEMI_COLUMN 
{
	$$.node = newast('I', $2.globalSignCond, $4.node);

	// expr: IDENTIFIER COL_EQUAL calc SEMI_COLUMN {
	// $$.node = newast('A', $1, $3.node);
	// $$.node->type = $$.type[0];

	// $$.node
	// fprintf(yyout, "\n%s\n", $$.type[0]);
	evalprint($$.node);
	// dataOper($2.node);
 	// textIf($$.globalSignCond,$2.f);
}

| IF calc THEN sentence ELSIF calc THEN sentence ELSE sentence ENDIF SEMI_COLUMN
{ 
	$$.node = newast('I', $2.globalSignCond, $4.node);
	dataOper($2.node);
 	textIf($$.globalSignCond,$2.f);
}

| IF calc THEN sentence ELSE sentence ENDIF SEMI_COLUMN 
{ 
	$$.node = newast('I', $2.globalSignCond, $4.node);
	dataOper($2.node);
 	textIf($$.globalSignCond,$2.f);
}
;

calc: calc ADD calc 
{ 

	if (!$$.valid)
	{
		if (($1.type == "integer") && ($3.type == "integer")) 
		{
			$$.node = newast('+', $1.node,$3.node); 
			evalprint($$.node);
			$$.type = $1.type;
			printf(YEL"ADD ON of %s type \n" RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.node = newast('+', $1.node,$3.node); 
			evalprint($$.node);
			$$.type = $1.type;
			printf(YEL"ADD ON of %s type\n"RESET,  $$.type);
		} 
		else if (($1.type == "string") || ($3.type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - ADDING on %s type is not allowed.\n", $$.type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
		} 
	} 
	else 
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE ADD ON GETS CANCELLED\n");
	}

}
|  calc SUBS calc 
{ 

	if (!$$.valid) 
	{
		if (($1.type == "integer") && ($3.type == "integer")) 
		{
			$$.node = newast('-', $1.node,$3.node); 
			evalprint($$.node);

			printf(YEL"SUBTRACTION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.node = newast('-', $1.node,$3.node); 
			evalprint($$.node);

			printf(YEL"SUBTRACTION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "string") || ($3.type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - SUBTRACTION on %s type is not allowed.\n", $$.type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
		} 
	} 
	else 
	{
		printf("THERE ARE ERRORS --> THE SUBTRACTION GETS CANCELLED\n");
	}

}

|  calc MULT calc 
{ 

	if ($$.valid == 0) 
	{ 
		if (($1.type == "integer") && ($3.type == "integer"))
		{
			$$.node = newast('*', $1.node,$3.node); 
			evalprint($$.node);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.node = newast('*', $1.node,$3.node); 
			evalprint($$.node);

			printf(YEL"MULTIPLICATION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "string") || ($3.type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - MULTIPLICATION on %s type is not allowed.\n", $$.type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
		} 
	}
	else
	{
		printf("THERE ARE "RED"ERRORS"RESET" --> THE MULTIPLICATION GETS CANCELLED \n");
	}

}

|  calc DIV calc {

	if (!$3.value)	
	{ 
		printf(RED "\nERROR" RESET, 30);
		printf(" - Can't divide by 0. \n", 30);
		exit(1);
		$$.valid = 1;
	}

	if (!$$.valid) 
	{ 
		if (($1.type == "integer") && ($3.type == "integer"))
		{
			$$.node = newast('/', $1.node,$3.node); 
			evalprint($$.node);

			printf(YEL"DIVISION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "real") && ($3.type == "real"))
		{
			$$.node = newast('/', $1.node,$3.node); 
			evalprint($$.node);

			printf(YEL"DIVISION of %s type \n"RESET, $$.type);
		} 
		else if (($1.type == "string") || ($3.type == "string"))
		{
			printf(RED "\nERROR" RESET, 30);
			printf(" - DIVISION on %s type is not allowed.\n", $$.type, 30);
			printf("\nExiting with "RED"errors."RESET"\n");

			exit(1);
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

	if ($1.value > $3.value) {
		$$.booleanCond = 1;
		$$.f = $$.booleanCond;
		$$.globalSignCond = '>';
		
		$$.node->l = $1.text;
		$$.node->r = $3.text;
		$$.node->number = $$.globalSignCond;

		printf("Condition WHILE HELLO BIGGER THAN is true - Is bigger\n");
	}
	else 
	{
		$$.booleanCond = 0;
		$$.f = $$.booleanCond;
		$$.globalSignCond = '>';
		$$.node->l = $1.text;
		$$.node->r = $3.text;
		$$.node->number = $$.globalSignCond;

		printf("Condition BIGGER THAN is false - It's not bigger \n");
	}

} 
| calc LES_THAN calc {
	printf(YEL "\NLESS THAN condition.\n" RESET);
	if ($1.value < $3.value) {
		$$.booleanCond =1;
		$$.f = $$.booleanCond;
		$$.globalSignCond = '<';
		$$.node->l = $1.text;
		$$.node->r = $3.text;
		$$.node->number = $$.globalSignCond;

		printf("Condition LESS THAN is true - It's smaller\n");
	} else {
		$$.booleanCond = 0;
		$$.f = $$.booleanCond;
		$$.globalSignCond = '<';
		$$.node->l = $1.text;
		$$.node->r = $3.text;

		$$.node->number = $$.globalSignCond;

		printf( "Condition LESS THAN is false - It's not smaller\n");
	}
}
| calc EQUALS calc {
	printf(YEL "EQUALS condition\n" RESET);

	if ($1.value == $3.value) 
	{
		printf("Condition EQUALS is true - It's equal\n");
		$$.booleanCond = 1;
		$$.f = $$.booleanCond;
		$$.globalSignCond = '=';
	}
	else
	{
		printf("Condition EQUALS is false - It's equal\n");
		$$.booleanCond = 0;
		$$.f = $$.booleanCond;
		$$.globalSignCond = '=';
	}

}

| INTEGERNUM 
{ 
	$$.node = newnum($1);
	$$.value = $1;
	$$.type = "integer";
	$$.globalNumCounter = $$.globalNumCounter +1;
	numCounter($$.globalNumCounter, $$.value );
}

| REALNUM 
{
	$$.node= newnum($1);
	$$.dvalue = $1; $$.type = "real";
}

| IDENTIFIER 
{
	$$.type = "string";

	if (!getvalsymText($1))
	{
		$$.valid = 1;
		printf("The variable %s does NOT exist \n", $1);

	} 
	else 
	{
		$$.valid = 0;
		$$.value = getvalsymNum($1);
		$$.node= newnum($$.value);
		$$.globalNumCounter = $$.globalNumCounter +1;
		numCounter($$.globalNumCounter, $$.value );

		printf("The variable %s does exist \n", $1);	
		$$.text = $1;	
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
}  
;

Fun: RETURN IDENTIFIER {

	if (!getvalsymText($2))
	{
		printf("The variable %s has not been defined \n", $2);
		printf(RED"\nERROR"RESET" -- Referencing of undefined variable.");
		printf("\nExiting with "RED"errors"RESET".\n");
		exit(1);
	} 
	else 
	{
		printf("It has at least one return\n");
		if (strcmp($$.type, gettypesymText($2)) == 0) 
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


factor: INTEGERNUM 	
	| REALNUM 		
	| IDENTIFIER 	
	| TRUE 			
	| FALSE 		
;


while_loop: WHILE calc LOOP sentence ENDLOOP SEMI_COLUMN 
{ 
	$$.node = newast('W', $2.node, $4.node);
	evalprint($$.node);
	dataOper($2.f);
}
;

put_line: PUTLINE LEFT_P IDENTIFIER RIGHT_P SEMI_COLUMN {
	// printf("Test de que funciona el PUT LINE");
	symbolRec *s;
   	s = getsymNum ($3,NULL);
	//Saca el tipo de datos que es
	fprintf(yyout, "%s", $3); //El resultado es el nombre de la variable
	
	//Con eso puedo sacar el tipo
	//$1.type == "integer")
	// printf("A: %s, B: %d", s->name, s->num);
	$$.node = newnum(s->num);
	$$.node = newast('P', $3, $$.node);
	evalprint($$.node);
	
	//Hacer la mierda necesaria 
}

for_loop: FOR IDENTIFIER IN iter_range LOOP sentence ENDLOOP SEMI_COLUMN {
	$$.node = newast('W', $2, $6.node);

	printf("BUCLE FOOR\n");
}
;

iter_range: factor RANGE factor 
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
			yyout = fopen("./out.nodesm", "wt");
			fprintf(yyout, ".data \n");
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