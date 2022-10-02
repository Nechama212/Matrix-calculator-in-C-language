#ifndef FINDMAT_H
#define FINDMAT_H

#include "macro.c"
void macro_retirement(FILE* inputFile, FILE* outputFile);
void add_node(macro_node**, char*, char*);
void freelist(macro_node*);
char* find_macro_name(macro_node*, char*);
unsigned int get_content_length(FILE*);





#endif
