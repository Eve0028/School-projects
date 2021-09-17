#pragma once

// Martrix-vector multiplication.
void matrix_x_vector(double** matrix, double* vector, double* vector_result, int row_count, int column_count);

// Multiplication of two matrices.
void matrix_x_matrix(double** matrix_A, double** matrix_B, double** matrix_result, int row_count_A, int column_count_A, int column_count_B);