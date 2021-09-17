#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "error_prt.h"

double** create_matrix(int row_count, int column_count)
{
	double** tab = (double**)malloc(sizeof(double*) * (row_count+1));
	if (!tab)
	{
		// allocation error
		error(3, "array");
	}
	for (int i = 1; i <= row_count; i++)
	{
		tab[i] = (double*)malloc(sizeof(double) * (column_count+1));
		if (!tab[i])
		{
			error(3, "array");
		}
	}
	return tab;
}

// matrix elements are overwritten with zeros - calloc
double** create_matrix_0(int row_count, int column_count)
{
	double** tab = (double**)calloc(row_count + 1, sizeof(double*));
	if (!tab)
	{
		// allocation error
		error(3, "array");
	}
	for (int i = 1; i <= row_count; i++)
	{
		tab[i] = (double*)calloc(row_count + 1, sizeof(double));
		if (!tab[i])
		{
			// allocation error
			error(3, "array");
		}
	}
	return tab;
}

void load_matrix(FILE* file_to_read, double** loaded_matrix, int row_count, int column_count)
{
	int i, j;
	for (i = 1; i <= row_count; i++)
		for (j = 1; j <= column_count; j++)
		{
			if (fscanf(file_to_read, "%lf", &loaded_matrix[i][j]) != 1)
			{
				error(1, "matrix reading error");
				printf("\nElement No. %d %d\n", i, j);
			}
		}
}

void print_matrix_console(double** matrix, int row_count, int column_count)
{
	for (int i = 1; i <= row_count; i++)
	{
		for (int j = 1; j <= column_count; j++)
		{
			printf("%lf ", matrix[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(double** matrix, int row_count, int column_count)
{
	if (matrix)
	{
		for (int i = 1; i <= row_count; i++)
		{
			if (matrix[i])
			{
				free(matrix[i]);
			}
		}
		free(matrix);
		matrix = NULL;
	}
}