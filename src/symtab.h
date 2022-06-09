

struct symbolRec {
  char *name;             /* name of symbol          */
  int *num;               /* val of symbol          */
  char *text;             /* text of symbol          */
  char *type;             /* type of symbol          */
  struct symbolRec *next;    /* link field              */

};

typedef struct symbolRec symbolRec;

symbolRec *sym_table = (symbolRec *)0;

symbolRec *putsymNum ();

symbolRec *getsymNum ();

symbolRec *putsymText ();

symbolRec *getsymText ();

//-----------NUMBERS-------------

symbolRec * putsymNum ( char *sym_name, int sym_val, char *sym_type ) {
  //printf("AÑADIR: %s ... %d ...||||| ", sym_name, sym_val);

  symbolRec *ptr;
  ptr = (symbolRec *) malloc (sizeof(symbolRec));
  ptr->name = (char *) malloc (strlen(sym_name)+1);
  ptr->num = (int) malloc ((sym_val)+1);
  ptr->type = (char *) malloc (strlen(sym_type)+1);
  strcpy (ptr->name,sym_name);
  ptr->num = sym_val;
  strcpy (ptr->type, sym_type);
  ptr->next = (struct symbolRec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symbolRec * getsymNum ( char *sym_name, int sym_val) {
  symbolRec *ptr;
  for (ptr = sym_table; ptr != (symbolRec *) 0;
       ptr = (symbolRec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {

        sym_val = ptr->num;
	sym_name = ptr->name;
	//printf("get %s ... %d ...||||| ", ptr->name, ptr->num);
        return ptr;
    }
  return 0;
}

symbolRec * updatesymNum ( char *sym_name, int sym_val) {
  symbolRec *ptr;
  for (ptr = sym_table; ptr != (symbolRec *) 0;
       ptr = (symbolRec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
 	ptr->num = sym_val;
	//printf("update %s ... %d ...||||| ", ptr->name, ptr->num );
        return ptr;
    }
  return 0;
}

symbolRec * getvalsymNum ( char *sym_name ) {
  symbolRec *ptr;
  for (ptr = sym_table; ptr != (symbolRec *) 0;
       ptr = (symbolRec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
	//printf("get val of %s ... %d ...||||| ", ptr->name, ptr->num);
        return ptr->num;
    }
  return 0;
}



//-----------TEXT-------------

symbolRec * putsymText ( char *sym_name, char *sym_text, char *sym_type  ) {
  //printf("AÑADIR: %s ... %s ...||||| ", sym_name, sym_text);

  symbolRec *ptr;
  ptr = (symbolRec *) malloc (sizeof(symbolRec));
  ptr->name = (char *) malloc (strlen(sym_name)+1);
  ptr->text = (char *) malloc (strlen(sym_name)+1);
  ptr->type = (char *) malloc (strlen(sym_type)+1);
  strcpy (ptr->name,sym_name);
  strcpy (ptr->text,sym_text);
  strcpy (ptr->type, sym_type);

  ptr->next = (struct symbolRec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symbolRec * getsymText ( char *sym_name, char *sym_text) {
  symbolRec *ptr;
  for (ptr = sym_table; ptr != (symbolRec *) 0;
       ptr = (symbolRec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
        sym_text = ptr->text;
	sym_name = ptr->name;
	//printf("get %s ... %s ...||||| ", ptr->name, ptr->text);
        return ptr;
    }
  return 0;
}

symbolRec * updatesymText ( char *sym_name, char *sym_text) {
  symbolRec *ptr;
  for (ptr = sym_table; ptr != (symbolRec *) 0;
       ptr = (symbolRec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
 	ptr->text = sym_text;
	//printf("update %s ... %s ...||||| ", ptr->name, ptr->text );
        return ptr;
    }
  return 0;
}

symbolRec * getvalsymText ( char *sym_name ) {
  symbolRec *ptr;
  for (ptr = sym_table; ptr != (symbolRec *) 0;
       ptr = (symbolRec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
	//printf("get val of %s ... %s ...||||| ", ptr->name, ptr->text);
        return ptr->text;
    }
  return 0;
}

symbolRec * gettypesymText ( char *sym_name ) {
  symbolRec *ptr;
  for (ptr = sym_table; ptr != (symbolRec *) 0;
       ptr = (symbolRec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
	//printf("get type of %s ... %s ...||||| ", ptr->name, ptr->type);
        return ptr->type;
    }
  return 0;
}