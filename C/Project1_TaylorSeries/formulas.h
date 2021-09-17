#pragma once
#include "range.h"

#define COUNT_OF_FORMULAS 3  // Number of formulas 

// FORMULA 0 - (1 - x)^(1/3)
// Returns the result of the formula #0 calculated using a Taylor series.
double taylor_series_0(double x, double eps, int* word_nr, int* condition, double* result);

// FORMULA 1 - (1 + x)^(-3/2)
double taylor_series_1(double x, double eps, int* word_nr, int* condition, double* result);

// FORMULA 2 - ln(x)
double taylor_series_2(double x, double eps, int* word_nr, int* condition, double* result);

typedef struct Formula
{
	int index;
	const char* name;

	// Returns the result of the formula calculated using a Taylor series.
	double (*taylor_series)();
	
	// The range within which the given formula can be calculated by using the method used in the taylor_series function.
	Range range;
}Formula;

// An array of objects that stores information about formulas.
static Formula formulas[COUNT_OF_FORMULAS] = {
	{ 0, "(1 - x)^(1/3)",  taylor_series_0, {{"-1 <= a < 1", -1, 0, 0}, {"a < b <= 1", 1, 0, 0}}},
	{ 1, "(1 + x)^(-3/2)", taylor_series_1, {{"-1 < a < 1", -1, 0, 1},  {"a < b < 1", 1, 0, 1  }}},
	{ 2, "ln(x)",          taylor_series_2, {{"0 < a < inf", 0, 0, 1},  {"a < b < inf", 1, 1, 1}}}
};