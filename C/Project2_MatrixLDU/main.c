// TASK: Solve a system of linear algebraic equations of the form: "Ax = b" (where x is the unknown) - the method of decomposition into triangular-diagonal factors (LDU).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "menu.h"
#include "file.h"
#include "matrix.h"
#include "vector.h"
#include "calculations.h"

#define FILE_NAME_LEN 30

#pragma warning (disable: 4996)

int main()
{
	menu_prt();

	// Open a file.
	FILE* file_to_read = NULL;
	char file_name[FILE_NAME_LEN];
	open_file(&file_to_read, file_name);

	// Read the order of a square matrix,
	// it is also equal to dimension of vectors.
	int matrix_order; 

	fscanf(file_to_read, "%d", &matrix_order);
	// Save matrix A.
	double** matrix_A = create_matrix(matrix_order, matrix_order);
	load_matrix(file_to_read, matrix_A, matrix_order, matrix_order);
	// Save vector b.
	double* vector_b = create_vector(matrix_order + 1);
	load_vector(file_to_read, vector_b, matrix_order);
	fclose(file_to_read);

	// Print matrix A and vector b.
	/*
	printf("\nMatrix A:\n");
	print_matrix_console(matrix_A, matrix_order, matrix_order);
	printf("\nVector b:\n");
	print_vector_console(vector_b, matrix_order);
	*/

	// Create L, D, U matrices and overwrite them with zeros (calloc).
	double** matrix_L = create_matrix_0(matrix_order, matrix_order);
	double** matrix_D = create_matrix_0(matrix_order, matrix_order);
	double** matrix_U = create_matrix_0(matrix_order, matrix_order);

	// Putting "1" on the main diagonal into the L and U matrices.
	for (int i = 1; i <= matrix_order; i++)
	{
		matrix_L[i][i] = 1;
		matrix_U[i][i] = 1;
	}

	// Putting the first element into matrix D.
	matrix_D[1][1] = matrix_A[1][1];

	// Insert elements into the first column of L and the first row of U.
	for (int i = 2; i <= matrix_order; i++)
	{
		matrix_L[i][1] = matrix_A[i][1] / matrix_D[1][1];
		matrix_U[1][i] = matrix_A[1][i] / matrix_D[1][1];
	}

	// Filling the rest of the elements of matrices.
	for (int i = 2; i <= matrix_order; i++)
	{
		// Matrix D
		double sum_D = 0;
		for (int k = 1; k <= i - 1; k++)
		{
			sum_D += matrix_L[i][k] * matrix_U[k][i] * matrix_D[k][k];
		}
		matrix_D[i][i] = matrix_A[i][i] - sum_D;

		for (int j = i+1; j <= matrix_order; j++)
		{
			// Matrices L and U
			double sum_L = 0;
			double sum_U = 0;
			for (int k = 1; k <= i - 1; k++)
			{
				sum_L += matrix_L[j][k] * matrix_U[k][i] * matrix_D[k][k];
				sum_U += matrix_L[i][k] * matrix_U[k][j] * matrix_D[k][k];
			}
			matrix_L[j][i] = (matrix_A[j][i] - sum_L) / matrix_D[i][i];
			matrix_U[i][j] = (matrix_A[i][j] - sum_U) / matrix_D[i][i];
		}
	}
	printf("\nMatrix L:\n");
	print_matrix_console(matrix_L, matrix_order, matrix_order);
	printf("\nMatrix D:\n");
	print_matrix_console(matrix_D, matrix_order, matrix_order);
	printf("\nMatrix U:\n");
	print_matrix_console(matrix_U, matrix_order, matrix_order);

	// Creating auxiliary vectors.
	double* vector_y = create_vector(matrix_order + 1);
	double* vector_z = create_vector(matrix_order + 1);

	// Putting the first elements into the y and z vectors.
	vector_y[1] = vector_b[1];
	vector_z[1] = vector_y[1] / matrix_D[1][1];

	// Filling the rest of the elements of vectors.
	for (int i = 2; i <= matrix_order; i++)
	{
		double sum_y = 0;
		for (int k = 1; k <= i - 1; k++)
		{
			sum_y += matrix_L[i][k] * vector_y[k];
		}
		vector_y[i] = vector_b[i] - sum_y;

		vector_z[i] = vector_y[i] / matrix_D[i][i];
	}

	printf("\nVector y:\n");
	print_vector_console(vector_y, matrix_order);
	printf("\nVector z:\n");
	print_vector_console(vector_z, matrix_order);

	// Calculation result - vector x.
	double* vector_x = create_vector(matrix_order + 1);
	vector_x[matrix_order] = vector_z[matrix_order];
	for (int i = matrix_order - 1; i > 0; i--)
	{
		double sum_x = 0;
		for (int k = i + 1; k <= matrix_order; k++)
		{
			sum_x += matrix_U[i][k] * vector_x[k];
		}
		vector_x[i] = vector_z[i] - sum_x;
	}

	printf("\n\n********************************************************"
		"\nVector x:\n");
	print_vector_console(vector_x, matrix_order);
	printf("********************************************************\n");

	// Checking over z, y, b vectors.
	/*
	printf("\nCheck the calculations by vectors:\n");
	matrix_x_vector(matrix_U, vector_x, vector_z, matrix_order, matrix_order);
	printf("\nVector z:\n");
	print_vector_console(vector_z, matrix_order);
	matrix_x_vector(matrix_D, vector_z, vector_y, matrix_order, matrix_order);
	printf("\nVector y:\n");
	print_vector_console(vector_y, matrix_order);
	matrix_x_vector(matrix_L, vector_y, vector_b, matrix_order, matrix_order);
	printf("\nResult of the equation - vector b:\n");
	print_vector_console(vector_b, matrix_order);
	*/

	// Checking on L, D, U matrices.
	printf("\n\nCheck the calculations over matrices:\n");
	double** matrix_LD = create_matrix_0(matrix_order, matrix_order);
	matrix_x_matrix(matrix_L, matrix_D, matrix_LD, matrix_order, matrix_order, matrix_order);

	double** matrix_LDU = create_matrix_0(matrix_order, matrix_order);
	matrix_x_matrix(matrix_LD, matrix_U, matrix_LDU, matrix_order, matrix_order, matrix_order);
	printf("\nMatrix L*D*U - A:\n");
	print_matrix_console(matrix_LDU, matrix_order, matrix_order);

	double* vector_b_check = create_vector(matrix_order + 1);
	matrix_x_vector(matrix_LDU, vector_x, vector_b_check, matrix_order, matrix_order);
	printf("\nResult of the equation - vector b:\n");
	print_vector_console(vector_b_check, matrix_order);

	// Free memory.
	free_matrix(matrix_A, matrix_order, matrix_order);
	free_vector(vector_b);
	free_matrix(matrix_L, matrix_order, matrix_order);
	free_matrix(matrix_D, matrix_order, matrix_order);
	free_matrix(matrix_U, matrix_order, matrix_order);
	free_vector(vector_x);
	free_vector(vector_y);
	free_vector(vector_z);

	free_matrix(matrix_LD, matrix_order, matrix_order);
	free_matrix(matrix_LDU, matrix_order, matrix_order);
	free_vector(vector_b_check);

	return 0;
}