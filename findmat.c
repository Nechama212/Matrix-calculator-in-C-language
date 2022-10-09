#include "findmat.h"
#include "mymat.h"
#include "mat.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>

mat* get_mat(char mat_name[6], node_mat* matrix_map)
{
	int i;
	for (i = 0; i < NUM_OF_MATS; i++)
	{
		if (!strcmp(mat_name, matrix_map[i].name))
		{
			return matrix_map[i].mat_ptr;
		}
	}

	return NULL;
}

void pre_read_mat(char* mat_name, node_mat* matrix_map, double params[16])
{
	mat* mat1 = NULL;

	mat1 = get_mat(mat_name, matrix_map);
	if (mat1 == NULL)
	{
		printf("Matrix not found!\n");
		return;
	}

	read_mat(mat_name, mat1, params);
}



void pre_print_mat(char* mat_name, node_mat* matrix_map)
{
	mat* mat1 = NULL;

	mat1 = get_mat(mat_name, matrix_map);
	if (mat1 == NULL)
	{
		printf("Matrix not found!\n");
		return;
	}

	print_mat(mat1);
}

void pre_add_mat(char* mat_name1, char* mat_name2, char* mat_name3, node_mat* matrix_map)
{
	mat* mat1 = NULL;
	mat* mat2 = NULL;
	mat* mat3 = NULL;
	
	mat1 = get_mat(mat_name1, matrix_map);
	mat2 = get_mat(mat_name2, matrix_map);
	mat3 = get_mat(mat_name3, matrix_map);

	if ((mat1 == NULL) ||
		(mat2 == NULL) ||
		(mat3 == NULL))
	{
		printf("Matrix not found!\n");
		return;
	}

	add_mat(mat1, mat2, mat3);
}

void pre_sub_mat(char* mat_name1, char* mat_name2, char* mat_name3, node_mat* matrix_map)
{
	mat* mat1 = NULL;
	mat* mat2 = NULL;
	mat* mat3 = NULL;

	mat1 = get_mat(mat_name1, matrix_map);
	mat2 = get_mat(mat_name2, matrix_map);
	mat3 = get_mat(mat_name3, matrix_map);

	if ((mat1 == NULL) ||
		(mat2 == NULL) ||
		(mat3 == NULL))
	{
		printf("Matrix not found!\n");
		return;
	}

	sub_mat(mat1, mat2, mat3);
}

	
void pre_mul_mat(char* mat_name1, char* mat_name2, char* mat_name3, node_mat* matrix_map)
{
	mat* mat1 = NULL;
	mat* mat2 = NULL;
	mat* mat3 = NULL;

	mat1 = get_mat(mat_name1, matrix_map);
	mat2 = get_mat(mat_name2, matrix_map);
	mat3 = get_mat(mat_name3, matrix_map);

	if ((mat1 == NULL) ||
		(mat2 == NULL) ||
		(mat3 == NULL))
	{
		printf("Matrix not found!\n");
		return;
	}

	mul_mat(mat1, mat2, mat3);
}

void pre_mul_scalar(char* mat_name1, double scalar, char* mat_name2, node_mat* matrix_map)
{
	mat* mat1 = NULL;
	mat* mat2 = NULL;

	mat1 = get_mat(mat_name1, matrix_map);
	mat2 = get_mat(mat_name2, matrix_map);

	if ((mat1 == NULL) ||
		(mat2 == NULL))
	{
		printf("Matrix not found!\n");
		return;
	}

	mul_scalar(mat1, scalar, mat2);
}


void pre_trans_mat(char* mat_name1, char* mat_name2, node_mat* matrix_map)
{
	mat* mat1 = NULL;
	mat* mat2 = NULL;

	mat1 = get_mat(mat_name1, matrix_map);
	mat2 = get_mat(mat_name2, matrix_map);

	if ((mat1 == NULL) ||
		(mat2 == NULL))
	{
		printf("Matrix not found!\n");
		return;
	}

	trans_mat(mat1, mat2);
}