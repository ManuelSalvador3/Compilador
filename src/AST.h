/* nodos en el árbol de sintaxis abstracta*/ 

int datos[100];
int operadores[100];

int globalContadorNum;
int globalContadorOper;

char *globalOperacion1;

enum bifs {
  B_sqrt = 1,
  B_exp,
  B_log,
  B_print
};

struct ast {
   int nodetype;
   struct ast *l;
   struct ast *r;
};

struct numval { 
   int nodetype;
   double number; 
};

struct flow {
  int nodetype;     /* tipo I o W*/
  struct ast *cond; /* condición */
  struct ast *tl; /* la rama o la lista */ 
  struct ast *el; /* opcional else rama */
};

struct fncall {
  int nodetype;
  struct ast *l;
  enum bifs functype;
};


extern FILE *yyout;


/* construir un AST*/
  struct ast *newast(int nodetype, struct ast *l, struct ast *r); 
  struct ast *newnum(double d);


  struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *tr); 
  struct ast *newfunc(int functype, struct ast *l);

/* evaluar un AST*/ 
  double eval(struct ast *);

/* Eliminar y liberar un AST */ 
  void treefree(struct ast *);


static double callbuiltin(struct fncall *);


struct ast * newast(int nodetype, struct ast *l, struct ast *r) {
  struct ast *a = malloc(sizeof(struct ast));
  if(!a) {
    yyerror("out of space");
    exit(0); 
  }
  a->nodetype = nodetype; a->l = l;
  a->r = r;

  //printf("NEW AST %s ..|| ", a);

  return a;
}

struct ast * newnum(double d) {
  struct numval *a = malloc(sizeof(struct numval));
  if(!a) {
    yyerror("out of space");
    exit(0); 
  }
  a->nodetype = 'K';
  a->number = d;
  //printf("NEW NUM: %s .. %lf ..|| ", a, a->number);

  return (struct ast *)a;
}

double eval(struct ast *a) {
  double v;

  switch(a->nodetype) {
    case 'K': v = ((struct numval *)a)->number; 
	break;
    case '+': v = eval(a->l) + eval(a->r); 
	break;
    case '-': v = eval(a->l) - eval(a->r); 
	break;
    case '*': v = eval(a->l) * eval(a->r); 
	break;
    case '/': v = eval(a->l) / eval(a->r); break; 
    case '|': v = eval(a->l); if(v < 0) v = -v; 
	break;
    case 'M': v = -eval(a->l); 
	break; 
  case 'F': v = callbuiltin((struct fncall *)a); 
  break;
    default: printf("internal error: bad node %c\n", a->nodetype); 
   }
  return v;
}

double evalF(struct flow *f) {
  double v;
  //printf("EVALF||||| ");
	
  switch(f->nodetype) {
  /* while do */
  case 'W':
    v = 0.0;
    if(f->tl) {
          printf("no entra ");
      while( eval(f->cond) != 0) {
        v = eval(f->tl);}
    }
  break;
  case 'I':
    if( eval( (f->cond) != 0)) {
      if( (f->tl)) {
        v = eval(f->tl);
         } else
           v = 0.0;
        } else {
          if(f->el) {
            v = eval(f->el);
          } else
          v = 0.0;
          }
    break;
    
    default: printf("internal error: bad node %c\n", f->nodetype); 
   }
  return v;
}

struct ast * newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *el) {
  //printf("FLOW");

  struct flow *a = malloc(sizeof(struct flow));
  if(!a) {
    yyerror("out of space");
    exit(0); 
  }
  a->nodetype = nodetype; 
  a->cond = cond;
  a->tl = tl;
  a->el = el;

  //fprintf(yyout, "cond: %d\n", a->cond);
  //fprintf(yyout, "tl: %lf\n", a->tl);
  //fprintf(yyout, "el: %lf\n", a->el);

  return (struct ast *)a; 
}

static double callbuiltin(struct fncall *f) {
  enum bifs functype = f->functype; double v = eval(f->l);
  switch(functype) {
    case B_sqrt:
      return sqrt(v);
    case B_exp:
      return exp(v);
    case B_log:
      return log(v);
    case B_print:
      printf("= %4.4g\n", v);
      return v;
    default:
      yyerror("Unknown built-in function %d", functype);
      return 0.0; 
      
  }
}

struct ast * newfunc(int functype, struct ast *l) {
  struct fncall *a = malloc(sizeof(struct fncall));
  if(!a) {
    yyerror("out of space");
    exit(0); }
    a->nodetype = 'F';
    a->l = l;
    a->functype = functype; 
    return (struct ast *)a;
}

void dataOper( struct ast *a) {
  for(int i = 1; i <= globalContadorNum; ++i) {
    fprintf(yyout, "number%d: ", globalContadorNum-i+1);
    fprintf(yyout, ".word %d\n", datos[i]);
  }
  fprintf(yyout, "message: .asciiz \"FIN\"\n");
}

void textOper(struct ast *a) {
  int valFin =0;

  for(int i = 0; i < globalContadorNum; ++i) {
        fprintf(yyout, "lw $t%d", i);
        fprintf(yyout, ", number%d", globalContadorNum-i);
        fprintf(yyout, "($zero)\n");
      }

  int i =0;
  double v;
  int flag = 0;
  int j =0;
  
  for(int i = 1; i <= globalContadorOper; ++i) {
    if (flag == 0) {
      j = i-1;
    }
    switch(operadores[i]) {
     
    case '+': v = eval(a->l) + eval(a->r); 
      fprintf(yyout,"add $t%d, $t%d, $t%d\n", globalContadorNum+j, j+1, j);
      flag = 1;
      j = j +2;
      valFin =globalContadorNum+j;

      break;
    case '-': v = eval(a->l) - eval(a->r); 
      fprintf(yyout,"sub $t%d, $t%d, $t%d\n", globalContadorNum+j, j+1, j);
      flag = 1;
      j = j +2;
      valFin =globalContadorNum+j;

      break;
    case '*': v = eval(a->l) * eval(a->r); 
      fprintf(yyout,"mul $t%d, $t%d, $t%d\n", globalContadorNum+j, j+1, j);
      flag = 1;
      j = j +2;
      valFin =globalContadorNum+j;

      break;
      case '/': v = eval(a->l) / eval(a->r); 
      fprintf(yyout,"div $t%d, $t%d, $t%d\n", globalContadorNum+j, j+1, j);
      flag = 1;
      j = j +2;
      valFin =globalContadorNum+j;
      break;
    }
}

  fprintf(yyout,"li $v0, 1\n");
  fprintf(yyout,"add $a0, $zero, $t%d\n", valFin-2);
  fprintf(yyout,"syscall\n");
}

void textIf(char signo, struct flow *f) {
  int valFin =0;
  //fprintf(yyout, "TOTAL numeros: %d\n", globalContadorNum);
  //fprintf(yyout, "TOTAL signos: %d\n", globalContadorOper);
  //fprintf(yyout, "signo: %c\n", signo);

  for(int i = 0; i < 2; ++i) {
    fprintf(yyout, "addi $t%d, $zero, %d\n", i, datos[i+1]);
  }

  if ( signo == '<') {
    fprintf(yyout, "blt $t0, $t1, operation\n");

  } else if (signo == '>') {
    fprintf(yyout, "bgt $t0, $t1, operation\n");

    /* code */
  } else if (signo == '=') {
    fprintf(yyout, "beq $t0, $t1, operation\n");

    /* code */
  }
  fprintf(yyout, "li $v0, 10\n");
  fprintf(yyout, "syscall\n");

  fprintf(yyout, "operation:\n");


  int x=2;
  for(int i = 0; i < globalContadorNum-2; ++i) {
    fprintf(yyout, "lw $t%d", x);
    fprintf(yyout, ", number%d", i+1);
    fprintf(yyout, "($zero)\n");
    x++;
    }


  int j =0;
  int m =2;

  int NumOp = globalContadorNum - 2;

  for(int i = 1; i <= globalContadorOper; ++i) {

   //fprintf(yyout, "%c\n", operadores[i]);
   //fprintf(yyout, "Contador num: %d\n", globalContadorNum);

    switch(operadores[i]) {
     
    case '+':
      //fprintf(yyout, "suma\n");
      fprintf(yyout,"add $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
      j = j +2;
      m = m +2;
      valFin =NumOp+j;

      break;
    case '-':
      //fprintf(yyout, "resta\n");
      fprintf(yyout,"sub $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
      j = j +2;
      m = m +2;
      valFin =NumOp+j;

      break;
    case '*':
      //fprintf(yyout, "multiplicacion\n");
      fprintf(yyout,"mul $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j );
      j = j +2;
      m = m +2;
      valFin =NumOp+j;

      break;
      case '/':
      //fprintf(yyout, "multiplicacion\n");
      fprintf(yyout,"div $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
      j = j +2;
      valFin =NumOp+j;
      m = m +2;
      break;
    }

}
  fprintf(yyout,"li $v0, 1\n");
  int h =0;
  for(int i = 0; i < globalContadorOper; ++i) {
    fprintf(yyout,"add $a0, $zero, $t%d\n", valFin-h);
    fprintf(yyout,"syscall\n");
    h = h+2;
  }

  fprintf(yyout,"li $v0, 10\n");
  fprintf(yyout,"syscall\n"); 
}

void textWhile(char signo, struct flow *f) {
      int valFin =0;
      //fprintf(yyout, "TOTAL numeros: %d\n", globalContadorNum);
      //fprintf(yyout, "TOTAL signos: %d\n", globalContadorOper);
      //fprintf(yyout, "signo: %c\n", signo);

  //fprintf(yyout, "mESTOY EN TEXT\"\n");
  for(int i = 0; i < 2; ++i) {
    fprintf(yyout, "addi $t%d, $zero, %d\n", i, datos[i+1]);
  }
  fprintf(yyout, "while:\n");

  if ( signo == '>') {
    fprintf(yyout, "blt $t0, $t1, exit\n");

  } else if (signo == '<') {
    fprintf(yyout, "bgt $t0, $t1, exit\n");

  } else if (signo == '=') {
    fprintf(yyout, "beq $t0, $t1, exit\n");

  }
  fprintf(yyout, "jal  operation\n");
  fprintf(yyout, "addi $t0, $t0, 1\n");
  fprintf(yyout, "j while\n");
  
  fprintf(yyout, "exit:\n");
  fprintf(yyout, "li $v0, 4\n");
  fprintf(yyout, "la $a0, message\n");
  fprintf(yyout, "syscall\n");
  fprintf(yyout, "li $v0, 10\n");
  fprintf(yyout, "syscall\n");

  fprintf(yyout, "operation:\n");
  int x=2;
  for(int i = 0; i < globalContadorNum-2; ++i) {
    fprintf(yyout, "lw $t%d", x);
    fprintf(yyout, ", number%d", i+1);
    fprintf(yyout, "($zero)\n");
    x++;
    }

  double v;
  int flag = 0;
  int NumOp = globalContadorNum-2;
  int j =0;
  int m =2;

  
  for(int i = 1; i <= globalContadorOper; ++i) {

   //fprintf(yyout, "%c\n", operadores[i]);
   //fprintf(yyout, "Contador num: %d\n", globalContadorNum);

    switch(operadores[i]) {
     
    case '+':
      //fprintf(yyout, "suma\n");
      fprintf(yyout,"add $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
      j = j +2;
      m = m +2;
      valFin =NumOp+j;

      break;
    case '-':
      //fprintf(yyout, "resta\n");
      fprintf(yyout,"sub $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
      j = j +2;
      m = m +2;
      valFin =NumOp+j;

      break;
    case '*':
      //fprintf(yyout, "multiplicacion\n");
      fprintf(yyout,"mul $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j );
      j = j +2;
      m = m +2;
      valFin =NumOp+j;

      break;
      case '/':
      //fprintf(yyout, "multiplicacion\n");
      fprintf(yyout,"div $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
      j = j +2;
      valFin =NumOp+j;
      m = m +2;
      break;
    }

}
 
  fprintf(yyout,"li $v0, 1\n");
  int h =0;
  for(int i = 0; i < globalContadorOper; ++i) {
    fprintf(yyout,"add $a0, $zero, $t%d\n", valFin-h);
    fprintf(yyout,"syscall\n");
    h = h+2;
  }

  fprintf(yyout,"jr $ra\n");
  fprintf(yyout,"syscall\n");
}

void contadorNumeros(int contador, int val) {
  globalContadorNum = contador;
  datos[globalContadorNum]=val;
  //fprintf(yyout, " %d\n", datos[globalContadorNum]);
  //fprintf(yyout, "CONTADOR NUMERO OPERACIONES: %d\n", contador);
}

void contadorOperadores(int contador, struct ast *a) {
  globalContadorOper = contador;
  operadores[globalContadorOper]=a->nodetype;
  //fprintf(yyout, "Signo: %c\n", operadores[globalContadorOper]);
  //fprintf(yyout, "CONTADOR NUMERO OPERACIONES: %d\n", contador);
}

double evalprint(struct ast *a) {
  double v;
  int count =0;
 

  switch(a->nodetype) {
    case 'K': v = ((struct numval *)a)->number;
	break;

    case '+': /*
	fprintf(yyout, "add  ");
	fprintf(yyout, "XX  ");
	fprintf(yyout, "%lf  ", eval(a->l));
	fprintf(yyout, "%lf\n", eval(a->r));*/
  globalOperacion1="add XX %lf %lf \n", eval(a->l),eval(a->r);
  
	v = eval(a->l) + eval(a->r);  
	break;

    case '-': /*
	fprintf(yyout, "sub  ");
	fprintf(yyout, "XX  ");
	fprintf(yyout, "%lf  ", eval(a->l));
	fprintf(yyout, "%lf\n", eval(a->r));*/

	v = eval(a->l) - eval(a->r);
	break;

    case '*': /*
	fprintf(yyout, "mult  ");
	//fprintf(yyout, "XX  ");
	fprintf(yyout, "%lf  ", eval(a->l));
	fprintf(yyout, "%lf\n", eval(a->r));*/

	v = eval(a->l) * eval(a->r);
	break;

    case '/': /*
	fprintf(yyout, "div  ");
	//fprintf(yyout, "XX  ");
	fprintf(yyout, "%lf  ", eval(a->l));
	fprintf(yyout, "%lf\n", eval(a->r));*/

	v = eval(a->l) / eval(a->r);
	break;

    case '|': v = eval(a->l); if(v < 0) v = -v; 
	break;

    case 'M': v = -eval(a->l); 
	break;

    default: printf("internal error: bad node %c\n", a->nodetype); 
   }
  return v;
}


void treefree(struct ast *a) {
  switch(a->nodetype) {
  /* two subtrees */ case '+':
  case '-':
  case '*':
  case '/':
    treefree(a->r);
  /* one subtree */
  case '|':
  case 'M':
    treefree(a->l);

  /* no subtree */
  case 'K':
    free(a);
    break;
  default: printf("internal error: free bad node %c\n", a->nodetype);
  } 
}