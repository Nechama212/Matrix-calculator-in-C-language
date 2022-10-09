#ifndef FINDMAT_H
#define FINDMAT_H

#include "mat.h"

/*The function gets the data structure that a pointer saves and the name of a pointer and also gets an array of all the names of the matrix
and returns the corresponding matrix by name*/
mat* get_mat(char mat_name[6], node_mat* matrix_map);

/*All "pre" functions receive a number of pointers according to the number of matrices requested.
According to the function that finds the correct pointer by name, you know which pointer to send to the function
that will perform the operation (read, print, sub, mul, add, trans)*/

void pre_read_mat(char* mat_name, node_mat* matrix_map, double params[16]);

void pre_print_mat(char* mat_name, node_mat* matrix_map);

void pre_add_mat(char* mat_name1, char* mat_name2, char* mat_name3, node_mat* matrix_map);

void pre_sub_mat(char* mat_name1, char* mat_name2, char* mat_name3, node_mat* matrix_map);

void pre_mul_mat(char* mat_name1, char* mat_name2, char* mat_name3, node_mat* matrix_map);

void pre_mul_scalar(char* mat_name1, double scalar, char* mat_name2, node_mat* matrix_map);


void pre_trans_mat(char* mat_name1, char* mat_name2, node_mat* matrix_map);

#endif
