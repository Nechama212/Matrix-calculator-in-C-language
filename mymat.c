#include "mat.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>


void read_mat(char* name, mat* matrix_ptr, double* params)
{
	int i;
	int j;
	int k = 0;

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			(*matrix_ptr)[i][j] = params[k];
			k++;
		}
	}
}

void print_mat(mat* matrix_ptr)
{
	int i;
	int j;

	printf("\n");
	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			printf("%8.2f\t\t", (*matrix_ptr)[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void add_mat(mat* matrix_ptr, mat* matrix_ptr2, mat* matrix_ptr3)
{
	int i, j;
	mat temp_mat = { 0 };

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			temp_mat[i][j] = (*matrix_ptr)[i][j] + (*matrix_ptr2)[i][j];
		}
	}

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			(*matrix_ptr3)[i][j] = temp_mat[i][j];
		}
	}
}

void sub_mat(mat* matrix_ptr, mat* matrix_ptr2, mat* matrix_ptr3)
{
	int i, j;
	mat temp_mat = { 0 };

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			temp_mat[i][j] = (*matrix_ptr)[i][j] - (*matrix_ptr2)[i][j];
		}
	}

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			(*matrix_ptr3)[i][j] = temp_mat[i][j];
		}
	}
}

void mul_mat(mat* matrix_ptr, mat* matrix_ptr2, mat* matrix_ptr3)
{	
	int i, j,k;
	mat temp_mat = { 0 };

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			for (k = 0; k < DIM; k++)
			{
				temp_mat[i][j] += ((*matrix_ptr)[i][k]) * ((*matrix_ptr2)[k][j]);
			}
			
		}
	}

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			(*matrix_ptr3)[i][j] = temp_mat[i][j];
		}
	}
}


void mul_scalar(mat* matrix_ptr, double scalar, mat* matrix_ptr2)
{
	int i, j;
	mat temp_mat = { 0 };
	
	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			temp_mat[i][j] += (((*matrix_ptr)[i][j]) * scalar);
		}
	}

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			(*matrix_ptr2)[i][j] = temp_mat[i][j];
		}
	}
}




void trans_mat(mat* matrix_ptr, mat* matrix_ptr2)
{	
	int i, j;
	mat temp_mat = { 0 };

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			temp_mat[i][j] = ((*matrix_ptr)[j][i]);
		}
	}

	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
		{
			(*matrix_ptr2)[i][j] = temp_mat[i][j];
		}
	}	
}
