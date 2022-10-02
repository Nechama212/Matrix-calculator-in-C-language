#include "mat.h"
#include "findmat.h"
#include "mymat.h"
#include "integrity_checks.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	/*declarition of the all names of command*/
	char s_cmds[][11] = { "read_mat" ,
						  "print_mat",
						  "add_mat",
						  "sub_mat",
						  "mul_mat",
						  "mul_scalar",
					      "trans_mat" };

	mat MAT_A = { 0 };
	mat MAT_B = { 0 };
	mat MAT_C = { 0 };
	mat MAT_D = { 0 };
	mat MAT_E = { 0 };
	mat MAT_F = { 0 };

	node_mat matrix_map[] = { {"MAT_A", NULL},
							{"MAT_B", NULL},
							{"MAT_C", NULL},
							{"MAT_D", NULL},
							{"MAT_E", NULL},
							{"MAT_F", NULL} };
			
	/*declarition of the all arrays of command*/
	char* first_comm = NULL;
	char* second_comm = NULL;
	char* params = NULL;
	char* third_comm = NULL; /*If there will be a command with 2 matrices*/
	char* fourth_comm = NULL;
	char* check_last_comm = NULL;
	char buf[MAX] = { 0 };/* all command line*/
	char  new_buf[MAX] = { 0 };/* all command line, clean*/
	char* cmd = NULL;
	const char* stop_cmd = "stop";

	double scalar = 0;
	char* ptr;
	int i;
	int name_comm_found;
	double num_list[DIM * DIM] = { 0 };
	
	matrix_map[0].mat_ptr = &MAT_A;
	matrix_map[1].mat_ptr = &MAT_B;
	matrix_map[2].mat_ptr = &MAT_C;
	matrix_map[3].mat_ptr = &MAT_D;
	matrix_map[4].mat_ptr = &MAT_E;
	matrix_map[5].mat_ptr = &MAT_F;


	while (1)
	{
		printf("\n$ ");

		/*input the entire command line*/
		if (fgets(buf, MAX, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		if (buf[0] == '\n')
		{
			continue;
		}

		arrange_line(buf, new_buf);

		for (i = 0; i < strlen(new_buf) - 1; i++)
		{
			if ((new_buf[i] == ',') && (new_buf[i + 1] == ','))
			{
				printf("Multiple consecutive commas!\n");
				break;
			}
		}

		if (new_buf[0] == ',')
		{
			printf("Leading comma\n");
			continue;
		}
		else if (new_buf[strlen(new_buf)-1] == ',')
		{
			printf("Extraneous text after end of command\n");
			continue;
			
		}

		cmd = strtok(new_buf, " ");/*put \0 after white space*/

		if (cmd == NULL)
		{
			printf("line syntax error\n");
			continue;
		}

		if (!strcmp(stop_cmd, cmd))
		{
			if (buf[strlen(buf) - 1] == '\n')
			{
				buf[strlen(buf) - 1] = '\0';
			}

			if (strlen(buf) != strlen(stop_cmd))
			{
				printf("Extraneous text after end of command\n");
				continue;
			}

			printf("\n");
			exit(0);
		}

		name_comm_found = 0;/*False*/
		for (i = 0; i < sizeof(s_cmds)/sizeof(s_cmds[0]); i++)
		{
			if (!strcmp((s_cmds[i]), cmd))
			{
				name_comm_found = 1;
				break;
			}
		}

		if (!name_comm_found)
		{
			if (strchr(cmd, ',') != NULL)
			{
				fprintf(stdout, "Illegal comma.\n");
			}
			else
			{
				fprintf(stdout, "Undefined command name (%s).\n", cmd);
			}
		}

		first_comm = new_buf + strlen(cmd) + 1;/*pointer to name's matrix*/
		if (!(strcmp(cmd, "read_mat")))
		{
			memset(num_list, 0, sizeof(num_list));

			if (strchr(first_comm, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			second_comm = strtok(first_comm, ",");/*pointer to name's matrix, put \0 after matrix name */
			if (second_comm == NULL)
			{
				printf("Missing MAT name\n");
			}

			params = second_comm + strlen(second_comm) + 1;/*pointer to paramters command*/
			if (params == NULL)
			{
				printf("Missing argument\n");
			}
			else if (make_numbers(params, num_list))
			{
				pre_read_mat(second_comm, matrix_map,num_list);
			}
			else
			{
				printf("The numbers is not correct!\n");
			}

		}
		else if (!(strcmp(cmd, "print_mat")))
		{
			/*char* temp = new_buf + strlen(cmd) + 1;pointer to name's matrix*/
			second_comm = strtok(first_comm, "\0"); /*pointer to name's matrix, put \0 after matrix name */

			if (second_comm == NULL)
			{
				printf("Mat name has not been provided!\n");
				continue;
			}

			check_last_comm = strtok(second_comm + strlen(second_comm) + 1, "\n");
			if (check_last_comm == NULL)
			{
				if (is_mat(second_comm) == 1)
				{
					pre_print_mat(second_comm, matrix_map);
				}
				else
				{
					printf("Undefined matrix name\n");
				}
			}
			else
			{
				printf("Extraneous text after end of command\n");
			}
			
		}
		else if (!(strcmp(cmd, "add_mat")))
		{			
			if (strchr(first_comm, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			second_comm = strtok(first_comm, ",");/* pinter to the second name matrix*/
			if (second_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(second_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			if (strchr(second_comm + strlen(second_comm) + 1, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			third_comm = strtok(second_comm + strlen(second_comm) + 1, ",");/* the first name matrix*/
			if (third_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(third_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			fourth_comm = strtok(third_comm + strlen(third_comm) + 1, ",");/* the second name matrix*/
			if (fourth_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(fourth_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			check_last_comm = strtok(fourth_comm + strlen(fourth_comm) + 1, "\n");
			if (check_last_comm == NULL)
			{
				pre_add_mat(second_comm, third_comm, fourth_comm, matrix_map);
			}
			else
			{
				printf("Extraneous text after end of command\n");
			}
		}
		else if (!(strcmp(cmd, "sub_mat")))
		{
			if (strchr(first_comm, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			second_comm = strtok(first_comm, ",");/* the second name matrix*/
			if (second_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(second_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			if (strchr(second_comm + strlen(second_comm) + 1, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			third_comm = strtok(second_comm + strlen(second_comm) + 1, ",");/* the first name matrix*/
			if (third_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(third_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			fourth_comm = strtok(third_comm + strlen(third_comm) + 1, ",");/* the second name matrix*/
			if (fourth_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(fourth_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			check_last_comm = strtok(fourth_comm + strlen(fourth_comm) + 1, "\n");;/*put \0 after matrix name*/
			if (check_last_comm == NULL)
			{
				pre_sub_mat(second_comm, third_comm, fourth_comm, matrix_map);
			}
			else
			{
				printf("Extraneous text after end of command\n");
			}
		}
		else if (!(strcmp(cmd, "mul_mat")))
		{
			if (strchr(first_comm, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			second_comm = strtok(first_comm, ",");/* the second name matrix*/
			if (second_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(second_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			if (strchr(second_comm + strlen(second_comm) + 1, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			third_comm = strtok(second_comm + strlen(second_comm) + 1, ",");/* the first name matrix*/
			if (third_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(third_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			fourth_comm = strtok(third_comm + strlen(third_comm) + 1, ",");/* the second name matrix*/
			if (fourth_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(fourth_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			check_last_comm = strtok(fourth_comm + strlen(fourth_comm) + 1, "\n");;/*put \0 after matrix name*/
			if (check_last_comm == NULL)
			{
				pre_mul_mat(second_comm, third_comm, fourth_comm, matrix_map);
			}
			else
			{
				printf("Extraneous text after end of command\n");
			}
		}
		else if (!(strcmp((s_cmds[i]), "mul_scalar")))
		{
			if (strchr(first_comm, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			second_comm = strtok(first_comm, ",");/* the second name matrix*/
			if (second_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(second_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			if (strchr(second_comm + strlen(second_comm) + 1, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			third_comm = strtok(second_comm + strlen(second_comm) + 1, ",");/* the first name matrix*/
			if (third_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			fourth_comm = strtok(third_comm + strlen(third_comm) + 1, ",");/* the second name matrix*/
			if (fourth_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(fourth_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			check_last_comm = strtok(fourth_comm + strlen(fourth_comm) + 1, "\n");;/*put \0 after matrix name*/
			if (check_last_comm == NULL)
			{
				if (check_scalar(second_comm) == 0)
				{
					printf("Not a scalar\n");
				}
				else
				{
					scalar = strtod(third_comm, &ptr);/*convert string to double*/
					pre_mul_scalar(second_comm, scalar, fourth_comm, matrix_map);
				}
			}
			else
			{
				printf("Extraneous text after end of command\n");
			}
		}
		else if (!(strcmp((s_cmds[i]), "trans_mat")))
		{
			if (strchr(first_comm, ',') == NULL)
			{
				printf("Missing comma!\n");
				continue;
			}

			second_comm = strtok(first_comm, ",");/* the second name matrix*/
			if (second_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}			

			if (!is_mat(second_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			third_comm = strtok(second_comm + strlen(second_comm) + 1, ",");/* the first name matrix*/
			if (third_comm == NULL)
			{
				printf("Missing parameter!\n");
				continue;
			}

			if (!is_mat(third_comm))
			{
				printf("Undefined matrix name\n");
				continue;
			}

			check_last_comm = strtok(third_comm + strlen(third_comm) + 1, "\n");;/*put \0 after matrix name*/
			if (check_last_comm == NULL)
			{

				pre_trans_mat(second_comm, third_comm, matrix_map);
			}
			else
			{
				printf("Extraneous text after end of command\n");
			}
		}
	}

	return 0;
}
