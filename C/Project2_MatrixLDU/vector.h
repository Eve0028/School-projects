#pragma once

// Allocate memory for a new vector and return a pointer to it.
double* create_vector(int vector_dim);

// Read a vector from a file and save it to the allocated memory.
void load_vector(FILE* file_to_read, double* loaded_vector, int vector_dim);

// Print the vector to the console.
void print_vector_console(double* vector, int vector_dim);

// Free vector memory.
void free_vector(double* vector);