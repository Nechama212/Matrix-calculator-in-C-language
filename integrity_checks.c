#include "integrity_checks.h"
#include "mat.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>



void remove_white_spaces(char* line)
{
	if (line == NULL)
	{
		return;
	}

	/* When string is empty */
	if (line[0] == '\0')
		return;

	/* if the adjacent characters are same */
	if (((line[0] == ' ') && (line[1] == ' ')) ||
		((line[0] == '\t') && (line[1] == '\t')) ||
		((line[0] == ' ') && (line[1] == '\t')) ||
		((line[0] == '\t') && (line[1] == ' ')) ||
		((line[0] == ' ') && (line[1] == ',')) ||
		((line[0] == '\t') && (line[1] == ',')) ||
		((line[0] == ',') && (line[1] == ' ')) ||
		((line[0] == ',') && (line[1] == '\t')))
	{

		int i = 0;
		if (((line[0] == ',') && (line[1] == ' ')) ||
			((line[0] == ',') && (line[1] == '\t')))
		{
			i = 1;
		}

		/* Shift character by one to left */
		while (line[i] != '\0') {
			line[i] = line[i + 1];
			i++;
		}

		/* Check on Updated String line */
		remove_white_spaces(line);
	}

	/* If the adjacent characters are not same
	   Check from line+1 string address */
	remove_white_spaces(line + 1);
}


void remove_white_space_edges(char* str_line)
{
	char* temp = NULL;
	char* end = NULL;
	char* temp_str = str_line;
	/* Trim leading space */
	while ((*temp_str == ' ') || (*temp_str == '\t'))
	{
		temp_str++;
	}

	/* All spaces */
	if (*temp_str == '\0')
	{
		str_line[0] = '\0';
		return;
	}

	/* Trim trailing space */
	end = temp_str + strlen(temp_str) - 1;
	while ((end > temp_str) && ((*end == ' ') || (*end == '\t')))
	{
		end--;
	}

	/* Write new null terminator character */
	end[1] = '\0';

	temp = (char*)malloc(strlen(str_line) + 1);
	if (temp == NULL)
	{
		printf("No free space!");
		exit(-1);
	}

	strcpy(temp, temp_str);
	strcpy(str_line, temp);

	free(temp);
}


void arrange_line(char* str_line, char* formatted_str_line)
{
	if ((str_line == NULL) || (formatted_str_line == NULL))
	{
		return;
	}

	strcpy(formatted_str_line, str_line);
	remove_white_space_edges(formatted_str_line);

	if (strlen(formatted_str_line) > 1)
	{
		remove_white_spaces(formatted_str_line);
	}

	if (formatted_str_line[strlen(formatted_str_line) - 1] == '\n')
	{
		formatted_str_line[strlen(formatted_str_line) - 1] = '\0';
	}

}



int make_numbers(char* str, double num_list[DIM*DIM])
{
	int i = 0;
	char* token = NULL;
	char* endptr =NULL;
	double number = 0;

	token = strtok(str, ",");
	while (token != NULL)
	{
		number = strtod(token, &endptr);
		if (endptr != (token + strlen(token)))
		{
			printf("Invalid number has provided!");
			return 0;
		}
		

		num_list[i] = number;
		i++;

		if (i == DIM*DIM)
		{
			break;
		}

		token = strtok(NULL, ",");
	}

	return 1;
}


int check_scalar(char* scalar)
{
	int i = 0;
	for (i = 0; i < strlen(scalar); i++)
		if ((isdigit(scalar[i])))
			return 0;
	return 1;

}

int is_mat(char* name)
{
	if (!(strcmp(name, "MAT_A")) || !(strcmp(name, "MAT_B")) || !(strcmp(name, "MAT_C")) || !(strcmp(name, "MAT_D")) || !(strcmp(name, "MAT_E"))
		|| !(strcmp(name, "MAT_F")))
		return 1;
	return 0;
}





