#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "error_prt.h"

double* create_vector(int vector_dim)
{
	double* vector = (double*)malloc((unsigned)vector_dim * sizeof(double));
	if (!vector)
	{
		// allocation error
		error(3, "vector");
	}
	return vector;
}

void load_vector(FILE* file_to_read, double* loaded_vector, int vector_dim)
{
	for (int i = 1; i <= vector_dim; i++)
		if (fscanf(file_to_read, "%lf", &loaded_vector[i]) != 1)
		{
			error(1, "vector reading error");
			printf("Element no. %d\n", i);
		}
}

void print_vector_console(double* vector, int vector_dim)
{
	for (int k = 1; k <= vector_dim; k++)
		printf("%lf ", vector[k]);
	printf("\n");
}

void free_vector(double* vector)
{
	free(vector);
	vector = NULL;
}