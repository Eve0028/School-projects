#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void matrix_x_vector(double** matrix, double* vector, double* vector_result, int row_count, int column_count)
{
	for (int i = 1; i <= row_count; i++)
	{
		double r = 0;
		for (int k = 1; k <= column_count; k++)
			r += matrix[i][k] * vector[k];
		vector_result[i] = r;
	}
}

void matrix_x_matrix(double** matrix_A, double** matrix_B, double** matrix_result, int row_count_A, int column_count_A, int column_count_B)
{
	for (int i = 1; i <= row_count_A; i++)
		for (int k = 1; k <= column_count_A; k++)
			for (int j = 1; j <= column_count_B; j++)
				matrix_result[i][j] = matrix_result[i][j] + matrix_A[i][k] * matrix_B[k][j];
}