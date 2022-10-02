#ifndef MAT_H
#define MAT_H

#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>


#define  MAX (2000)
#define NUM_OF_MATS (6)
#define DIM (4)


typedef double mat[DIM][DIM];
	
typedef struct node_mat {
	char* name;
	mat* mat_ptr;
} node_mat;

	

#endif