#include<stdio.h>
#include <stdlib.h>
#define MAX_ERR_COUNT 5

const static char* error_types[] = { "",
" wrong data",
" opening the file",
" no memory",
" Usage : ",
" unknown ",
};

void error(int error_number, const char* error_message)
{
	int error_type_number;
	error_type_number = error_number >= MAX_ERR_COUNT ? MAX_ERR_COUNT : error_number;
	fprintf(stderr, "Error(%d) - %s %s\n", error_number, error_types[error_type_number], error_message);
	system("pause");
	exit(error_number);
}