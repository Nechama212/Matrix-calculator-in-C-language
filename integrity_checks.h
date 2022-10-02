#ifndef IC_H
#define IC_H

#include "mat.h"

/*The function receives the command line from the user and also an array of strings that will keep me the following string: 
arranged in such a way that it is cleared of spaces at the beginning and end. 
If there are double spaces and there is no comma before or after it leaves one space. Otherwise clears all spaces.*/
void arrange_line(char* str_line, char* formatted_str_line);

/*The function gets the parameters from read_mat in a string and builds an array of doubles with the numbers.
If it is correct numbers returns 1 otherwise returns 0.*/
int make_numbers(char* str, double num_list[DIM*DIM]);

/*The function receives the contents of the scale in a stringand' checks if it is a real number. Returns 0 and 1 accordingly*/
int check_scalar(char* scalar);

/*The function gets a name of a matrix and returns if it is a name that exists in the given matrices. Returns 0 and 1 accordingly*/
int is_mat(char* name);

#endif