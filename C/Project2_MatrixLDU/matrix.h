#pragma once

// Allocate memory for the new matrix and return a pointer to it.
double** create_matrix(int row_count, int column_count);

// Allocate memory for the new matrix and return a pointer to it.
double** create_matrix_0(int row_count, int column_count);

// Read a matrix from a file and save it to the allocated memory.
void load_matrix(FILE* file_to_read, double** loaded_matrix, int row_count, int column_count);

// Print the matrix to the console.
void print_matrix_console(double** matrix, int row_count, int column_count);

// Free matrix memory.
void free_matrix(double** matrix, int row_count, int column_count);