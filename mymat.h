#ifndef MYMAT_H
#define MYMAT_H

#include "mat.h"
/*The function gets the name of the command, the pointer to the matrix and an array of numbers that it has to fill. 
The function fills the selected matrix with the numbers from the user*/
void read_mat(char* name, mat* matrix_ptr, double* params);


/*The function receives the pointer to the matrix that it needs to fill and prints*/
void print_mat(mat* matrix_ptr);


/*/*The function receives the pointer to the first and second and third matrices. 
Connects the first matrices plus the second and stores the result in the third matrix*/
void add_mat(mat* matrix_ptr, mat* matrix_ptr2, mat* matrix_ptr3);


/*The function receives the pointer to the first and second and third matrices. 
Subtracts the first matrices wuth the second and stores the result in the third matrix*/
void sub_mat(mat* matrix_ptr, mat* matrix_ptr2, mat* matrix_ptr3);


/*The function receives the pointer to the first and second and third matrices. 
mul the first matrices with the second and stores the result in the third matrix*/
void mul_mat(mat* matrix_ptr, mat* matrix_ptr2, mat* matrix_ptr3);


/*The function receives the pointer to the first and second matrix and scalar. 
The function doubles the first matrix with the scalar and stores the result in the second matrix*/
void mul_scalar(mat* matrix_ptr, double scalar, mat* matrix_ptr2);


/*The function receives the pointer to the first and second matrix.
Performs a transition of the first matrix and stores the result in the second matrix.*/
void trans_mat(mat* matrix_ptr, mat* matrix_ptr2);

#endif