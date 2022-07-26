#define TES   "\x1B[33m"
#define RESET "\x1B[0m"

int datos[100];
int operadores[100];

int globalNumCounter;
int globalOpCounter;

char *globalOperacion1;

enum bifs 
{
  B_sqrt = 1,
  B_exp,
  B_log,
  B_print
};

struct ast 
{
  int nodetype;
  char type;
  struct ast *l;
  struct ast *r;
  int number;
};

struct numval 
{ 
  int nodetype;
  int number; 
};

struct flow 
{
  int nodetype;     
  struct ast *cond; 
  struct ast *tl; 
  struct ast *el; 
};


struct fncall 
{
  int nodetype;
  struct ast *l;
  enum bifs functype;
};


extern FILE *yyout;

struct ast *newast(int nodetype, struct ast *l, struct ast *r);

struct ast *newnum(int d);


struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *tr); 
struct ast *newfunc(int functype, struct ast *l);

double eval(struct ast *);

void treefree(struct ast *);

static double callbuiltin(struct fncall *);


struct ast * newast(int nodetype, struct ast *l, struct ast *r) 
{
  struct ast *node = malloc(sizeof(struct ast));
  
  if(!node) 
  {
    yyerror("out of space");
    exit(0); 
  }

  node->nodetype = nodetype; 
  node->l = l;
  node->r = r;

  printf(TES"NEW AST NODE OF TYPE -> \" %s \" || \n"RESET, node);
  return node;
}



struct ast * newnum_ast(int d) 
{
  struct ast *a = malloc(sizeof(struct ast));
  if(!a) 
  {
    yyerror("out of space");
    exit(0); 
  }
  a->nodetype = 'K';
  a->number = d;
  return a;
}


struct ast * newnum(int d) 
{
  struct numval *a = malloc(sizeof(struct ast));
  if(!a) 
  {
    yyerror("out of space");
    exit(0); 
  }
  a->nodetype = 'K';
  a->number = d;

  return (struct ast *) a;
}

double eval(struct ast *a) 
{
  double v;

  switch(a->nodetype)
  {
    case 'K': 
      v = ((struct numval *)a)->number; 
	  break;
  
    case '+': 
      v = eval(a->l) + eval(a->r); 
	  break;
  
    case '-': 
      v = eval(a->l) - eval(a->r); 
	  break;
  
    case '*': 
      v = eval(a->l) * eval(a->r); 
	  break;
  
    case '/': 
      v = eval(a->l) / eval(a->r);  break; 
  
    case '|': 
      v = eval(a->l); if(v < 0) v = -v; 
	  break;
  
    case 'M': 
      v = -eval(a->l); 
	  break; 
  
    case 'F': 
      v = callbuiltin((struct fncall *)a); 
    break;
    //printf("Internal error: Bad node %c\n", a->nodetype); 
    // default:
    //   
  }
  
  return v;
}

double evalF(struct flow *f) 
{
  double v;
	
  switch(f->nodetype) 
  {
    /* while do */
    case 'W':
      v = 0.0;
      if(f->tl) 
      {
        while( eval(f->cond) != 0)
          v = eval(f->tl);
      }
    break;
    case 'F':
    //POR HACER
    //   v = 0.0;
    //   if(f->tl) 
    //   {
    //     while( eval(f->cond) != 0)
    //       v = eval(f->tl);
    //   }
    // break;
    case 'I':
      if( eval( (f->cond) != 0)) 
      {
        if(f->tl) 
          v = eval(f->tl);
        else 
          v = 0.0;
      } 
      else 
      {
        if(f->el) 
          v = eval(f->el);
        else 
          v = 0.0;
      }
      break;
    
    default: printf("Internal error: bad node %c\n", f->nodetype); 
  }

  return v;
}

struct ast * newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *el) 
{
  struct flow *a = malloc(sizeof(struct flow));
  if(!a) 
  {
    yyerror("Out of space");
    exit(0); 
  }

  a->nodetype = nodetype; 
  a->cond = cond;
  a->tl = tl;
  a->el = el;

  return (struct ast *)a; 
}

static double callbuiltin(struct fncall *f) 
{
  enum bifs functype = f->functype; double v = eval(f->l);
  switch(functype) 
  {
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

struct ast * newfunc(int functype, struct ast *l) 
{
  struct fncall *a = malloc(sizeof(struct fncall));
  if(!a) 
  {
    yyerror("out of space");
    exit(0); 
  }
  
  a->nodetype = 'F';
  a->l = l;
  a->functype = functype; 
  
  return (struct ast *)a;
}

void dataOper( struct ast *a)
{
  // fprintf(yyout, ".data\n");
  // for(int i = 1; i <= globalNumCounter; ++i)
  // {
  //   fprintf(yyout, "number%d: ", globalNumCounter-i+1);
  //   fprintf(yyout, ".word %d\n", datos[i]);
  // }
  
}

void textOper(struct ast *a) 
{
  int valFin =0;

  for(int i = 0; i < globalNumCounter; ++i)
  {
    fprintf(yyout, "lw $t%d", i);
    fprintf(yyout, ", number%d", globalNumCounter-i);
    fprintf(yyout, "($zero)\n");
  }

  int i =0;
  double v;
  int flag = 0;
  int j =0;
  
  for(int i = 1; i <= globalOpCounter; ++i)
  {
    if (flag == 0) 
    {
      j = i-1;
    }
    switch(operadores[i])
    {
      case '+': v = eval(a->l) + eval(a->r); 
        fprintf(yyout,"add $t%d, $t%d, $t%d\n", globalNumCounter+j, j+1, j);
        flag = 1;
        j = j +2;
        valFin =globalNumCounter+j;
      break;

      case '-': v = eval(a->l) - eval(a->r); 
        fprintf(yyout,"sub $t%d, $t%d, $t%d\n", globalNumCounter+j, j+1, j);
        flag = 1;
        j = j +2;
        valFin =globalNumCounter+j;
      break;

      case '*': v = eval(a->l) * eval(a->r); 
        fprintf(yyout,"mul $t%d, $t%d, $t%d\n", globalNumCounter+j, j+1, j);
        flag = 1;
        j = j +2;
        valFin =globalNumCounter+j;
      break;

      case '/': v = eval(a->l) / eval(a->r); 
        fprintf(yyout,"div $t%d, $t%d, $t%d\n", globalNumCounter+j, j+1, j);
        flag = 1;
        j = j +2;
        valFin =globalNumCounter+j;
      break;
    }
  }

  fprintf(yyout,"li $v0, 1\n");
  fprintf(yyout,"add $a0, $zero, $t%d\n", valFin-2);
  // fprintf(yyout,"syscall\n");
}

void textIf(char signo, struct flow *f) 
{
  int valFin =0;

  // for(int i = 0; i < 2; ++i)
  //   fprintf(yyout, "addi $t%d, $zero, %d\n", i, datos[i+1]);

  // if ( signo == '<') 
  // {
  //   fprintf(yyout, "blt $t0, $t1, operation\n");
  // }
  // else if (signo == '>') 
  // {
  //   fprintf(yyout, "bgt $t0, $t1, operation\n");
  // }
  // else if (signo == '=')
  // {
  //   fprintf(yyout, "beq $t0, $t1, operation\n");
  // }

  // fprintf(yyout, "li $v0, 10\n");
  // fprintf(yyout, "syscall\n");
  // fprintf(yyout, "operation:\n");

  // int x=2;

  // for(int i = 0; i < globalNumCounter-2; ++i)
  // {
  //   fprintf(yyout, "lw $t%d", x);
  //   fprintf(yyout, ", number%d", i+1);
  //   fprintf(yyout, "($zero)\n");
  //   x++;
  // }


  // int j =0;
  // int m =2;

  // int NumOp = globalNumCounter - 2;

  // for(int i = 1; i <= globalOpCounter; ++i) 
  // {
  //   switch(operadores[i]) 
  //   {
  //     case '+':
  //       fprintf(yyout,"add $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
  //       j = j +2;
  //       m = m +2;
  //       valFin =NumOp+j;
  //     break;

  //     case '-':
  //       fprintf(yyout,"sub $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
  //       j = j +2;
  //       m = m +2;
  //       valFin =NumOp+j;
  //     break;
      
  //     case '*':
  //       fprintf(yyout,"mul $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j );
  //       j = j +2;
  //       m = m +2;
  //       valFin =NumOp+j;
  //     break;

  //     case '/':
  //       fprintf(yyout,"div $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
  //       j = j +2;
  //       valFin =NumOp+j;
  //       m = m +2;
  //     break;
  //   }
  // }

  // fprintf(yyout,"li $v0, 1\n");
  // int h =0;
  
  // for(int i = 0; i < globalOpCounter; ++i) 
  // {
  //   fprintf(yyout,"add $a0, $zero, $t%d\n", valFin-h);
  //   fprintf(yyout,"syscall\n");
  //   h = h+2;
  // }

  // fprintf(yyout,"li $v0, 10\n");
  // fprintf(yyout,"syscall\n"); 
}

// struct test 
// {
//   int nodetype;
//   char type;
//   struct ast *l;
//   struct ast *r;
//   int number;
//   char * texto;
// };
//Left es el la comparacion
void textWhile(char type, int comp1, int comp2, char sign, char *texto, int val2)
{
  // int com1 = comp1;
  // int com2 = comp2;
  // char signo = sign;
  // char * name = texto;
  // int val = val2;
  // fprintf(yyout, "Llego\n");
  // fprintf(yyout, "%d %s %d\n\n", com1, signo, com2);
  //  fprintf(yyout, "lw $t1, \n");
  //     fprintf(yyout, "lw $t2, integer2\n");
  //     fprintf(yyout, "\nwhile:\n");
  //     if (a->l == '<') 
  //       fprintf(yyout, "\tblt $t1, $t2, exit\n");
  //     else 
  //       fprintf(yyout, "\tbgt $t1, $t2, exit\n");
  //     // fprintf(yyout, "%s\n", a->r->number);
  //     // fprintf(yyout, "%d\n", a->r);
  //     // fprintf(yyout, "%s", a->r->r);
  //     if(a->r){

  //     }
     
  //     fprintf(yyout, "\tj while\n");
  //     fprintf(yyout, "exit:\n");


  // int valFin =0;

  // fprintf(yyout, "%s", signo);
  // for(int i = 0; i < 2; ++i) 
  // {
  //   fprintf(yyout, "addi $t%d, $zero, %d\n", i, datos[i+1]);
  // }
  // fprintf(yyout, "while:\n");

  // if ( signo == '>') 
  // {
  //   fprintf(yyout, "blt $t0, $t1, exit\n");
  // } 
  // else if (signo == '<')
  // {
  //   fprintf(yyout, "bgt $t0, $t1, exit\n");
  // } 
  // else if (signo == '=')
  // {
  //   fprintf(yyout, "beq $t0, $t1, exit\n");
  // }

  // fprintf(yyout, "jal  operation\n");
  // fprintf(yyout, "addi $t0, $t0, 1\n");
  // fprintf(yyout, "j while\n");
  
  // fprintf(yyout, "exit:\n");
  // fprintf(yyout, "li $v0, 4\n");
  // fprintf(yyout, "la $a0, message\n");
  // fprintf(yyout, "syscall\n");
  // fprintf(yyout, "li $v0, 10\n");
  // fprintf(yyout, "syscall\n");

  // fprintf(yyout, "operation:\n");
  // int x=2;
  
  // for(int i = 0; i < globalNumCounter-2; ++i)
  // {
  //   fprintf(yyout, "lw $t%d", x);
  //   fprintf(yyout, ", number%d", i+1);
  //   fprintf(yyout, "($zero)\n");
  //   x++;
  // }

  // double v;
  // int flag = 0;
  // int NumOp = globalNumCounter-2;
  // int j =0;
  // int m =2;

  
  // for(int i = 1; i <= globalOpCounter; ++i)
  // {
  //   switch(operadores[i]) 
  //   {
  //     case '+':
  //       fprintf(yyout, "suma\n");
  //       fprintf(yyout,"add $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
  //       j = j +2;
  //       m = m +2;
  //       valFin =NumOp+j;
  //     break;

  //     case '-':
  //       fprintf(yyout, "resta\n");
  //       fprintf(yyout,"sub $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
  //       j = j +2;
  //       m = m +2;
  //       valFin =NumOp+j;
  //     break;

  //     case '*':
  //       fprintf(yyout, "multiplicacion\n");
  //       fprintf(yyout,"mul $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j );
  //       j = j +2;
  //       m = m +2;
  //       valFin =NumOp+j;
  //     break;
      
  //     case '/':
  //       fprintf(yyout, "multiplicacion\n");
  //       fprintf(yyout,"div $t%d, $t%d, $t%d\n", NumOp+m, NumOp-j+1, NumOp-j);
  //       j = j +2;
  //       valFin =NumOp+j;
  //       m = m +2;
  //     break;
  //   }
  // }
 
  // fprintf(yyout,"li $v0, 1\n");
  // int h =0;
  // for(int i = 0; i < globalOpCounter; ++i) 
  // {
  //   fprintf(yyout,"add $a0, $zero, $t%d\n", valFin-h);
  //   fprintf(yyout,"syscall\n");
  //   h = h+2;
  // }

  // fprintf(yyout,"jr $ra\n");
  // fprintf(yyout,"syscall\n");
}

void numCounter(int contador, int val) 
{
  globalNumCounter = contador;
  datos[globalNumCounter] = val;
}

void opCounter(int contador, struct ast *a) 
{
  globalOpCounter = contador;
  operadores[globalOpCounter] = a->nodetype;
}

double evalprint(struct ast *a) 
{
  double v;
  int count = 0;
  
  switch(a->nodetype) 
  {
    case 'K':
      v = ((struct numval *)a)->number;
    break;
    

    case 'D': // Declaration
      switch(a->r->number) {
        case 'f': // Float
          fprintf(yyout, "%s: .float\n", a->l);
          break;
        case 'i': // Integer
          fprintf(yyout, "%s: .word 0\n", a->l);
          break;
        case 's': // String
          fprintf(yyout, "%s: .asciiz \n", a->l);
          break;
        case 'b': // Boolean
          fprintf(yyout, "%s: .word \n", a->l);
          break;
        default: 
          printf("internal error: bad value type of node %c\n", a->nodetype); 
          break;
      }
      
      break;

    case 'P':
      if((eval(a->r))) {
        
        fprintf(yyout, "\nli $v0 1 \n");
        fprintf(yyout, "lw, $a1, %s \n", a->r);
        fprintf(yyout, "move $a0, $a1\n");
        // fprintf(yyout, "add $a0, $zero, %4.4g \n",eval(a->r));
        fprintf(yyout, "syscall \n");
      } else {
        fprintf(yyout, "\nli $v0 2 \n");
        fprintf(yyout, "add $a0, $zero, %4.4g \n",eval(a->r));
        fprintf(yyout, "syscall \n");
      }
      fprintf(yyout, "la $a0, '\\n' \n");
      fprintf(yyout, "li $v0, 11 \n");
      fprintf(yyout, "syscall \n\n");
      
      break;

    case 'A': // Assignment 
      switch(a->type) {
        case 'f': // Float
          if(a->l == 'integer2') {
            fprintf(yyout, " \n");
            
          }else {
            fprintf(yyout, "lw $a0, %s \n", a->l);
            fprintf(yyout, "la $a0, %s \n", a->l);
            fprintf(yyout, "li $a1, %4.4g \n", eval(a->r)); //nuevo valor
            fprintf(yyout, "sb $a1 0($a0)\n", eval(a->r)); //Guardas el valor
          }
          
          
          
          break;
        case 'i': // Integer
          if(a->l == 'integer2' || eval(a->r) == 70 || eval(a->r) == 88 || eval(a->r) == 10) {
            fprintf(yyout, " \n");
            
          }else {
            fprintf(yyout, "lw $a0, %s \n", a->l);
            fprintf(yyout, "la $a0, %s \n", a->l);
            fprintf(yyout, "li $a1, %4.4g \n", eval(a->r)); //nuevo valor
            fprintf(yyout, "sb $a1 0($a0)\n\n", eval(a->r)); //Guardas el valor
          }
          //fprintf(yyout, "lw $a2, %s \n\n", a->l);
          // fprintf(yyout, "la $t0, %s \n", a->l);
          // fprintf(yyout, "addi $t0, $zero, %4.4g \n", eval(a->r));
          break;
        case 's': // String
          fprintf(yyout, "%s: .asciiz %4.4g \n", a->l, eval(a->r));
          break;
        case 'b': // Boolean
          fprintf(yyout, "la $t0, %s \n", a->l);
          fprintf(yyout, "addi $t0, $zero, %4.4g \n", eval(a->r));
          break;
        default: 
          printf("internal error: bad value type of node %c\n", a->nodetype); 
          break;
      }
      break;

    case 'I':
      fprintf(yyout, "lw $t3, %s\n", a->l->l);
      fprintf(yyout, "lw $t4, %s\n", a->l->r);
      fprintf(yyout, "#Bucle IF\n", a->l->r);
      if (a->l->number == '<') 
        fprintf(yyout, "\tbgt $t3, $t4, ifetiqueta\n");
      else 
        fprintf(yyout, "\tblt $t3, $t4, ifetiqueta\n");
      if(a->r->nodetype == 'A') {
        fprintf(yyout, "\tlw $a0, %s \n", a->r->l);
        fprintf(yyout, "\tla $a0, %s \n", a->r->l);
        fprintf(yyout, "\tli $a1, %4.4g \n", eval(a->r->r)); //nuevo valor
        fprintf(yyout, "\tsb $a1 0($a0)\n"); //Guardas el valor  
        fprintf(yyout, "\tlw $t3, %s \n\n", a->r->l);
        //fprintf(yyout, "\tmove $t1, $a2, %s \n\n", a->r->l);

      }
      fprintf(yyout, "ifetiqueta:\n");
      
      break;
    case 'W':
      fprintf(yyout, "lw $t1, %s\n", a->l->l);
      fprintf(yyout, "lw $t2, %s\n", a->l->r);
      fprintf(yyout, "\nwhile:\n");
      if (a->l->number == '<') {
        fprintf(yyout, "\tbgt $t1, $t2, exit\n");
      } else {
        fprintf(yyout, "\tblt $t1, $t2, exit\n");
      }
      if(a->r->nodetype == 'A') {
        //Es una asignación
        //Se le da el valor 
        fprintf(yyout, "\tlw $a0, %s \n", a->r->l);
        fprintf(yyout, "\tla $a0, %s \n", a->r->l);
        fprintf(yyout, "\tli $a1, %4.4g \n", eval(a->r->r)); //nuevo valor
        fprintf(yyout, "\tsb $a1 0($a0)\n"); //Guardas el valor  
        fprintf(yyout, "\tlw $t2, %s \n\n", a->r->l);
        //fprintf(yyout, "\tmove $t1, $a2, %s \n\n", a->r->l);

      }
      fprintf(yyout, "\tj while\n");
      fprintf(yyout, "exit:\n");
      // fprintf(yyout, "--------[%s]-----[%4.4g]", a->r->l, eval(a->r->r));
      // fprintf(yyout, "\nType of right node in while is: %c\n", a->r->nodetype);
      // fprintf(yyout, "\taddi $t2, $zero, %4.4g\n", eval(a->r->r));
      // fprintf(yyout, "%s\n", a->r->number);
      // fprintf(yyout, "%d\n", a->r);
      // fprintf(yyout, "%s", a->r->r);

      break;
    
    case '+': 
      globalOperacion1="add XX %lf %lf \n", eval(a->l),eval(a->r);
      // fprintf(yyout,"syscall\n");

      v = eval(a->l) + eval(a->r);  
    break;

    case '-': 
      v = eval(a->l) - eval(a->r);
    break;

    case '*': 
      v = eval(a->l) * eval(a->r);
    break;

    case '/': 
      v = eval(a->l) / eval(a->r);
    break;
    
    case '|': 
      v = eval(a->l); if(v < 0) v = -v; 
    break;

    case 'M':
      v = -eval(a->l); 
    break;

    default: 
      printf("internal error: bad node %c\n", a->nodetype); 
    break;
  }

  return v;
}


void treefree(struct ast *a) 
{
  switch(a->nodetype) 
  {
    /* two subtrees */ 
    case '+':
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
    default: 
      printf("internal error: free bad node %c\n", a->nodetype);
  } 
}