#pragma once
#include "range.h"

// If the user enters incorrect data,
// the functions will ask for them until it is successful.

// Returns a valid formula number received from the user.
int get_valid_formula_number_from_user();

// It writes the correct beginning and end of the range from user
// to variables that were given to the function by pointers.
void get_valid_range_from_user(Range* range, double* start_range, double* end_range);

// Returns a valid number of sub-ranges received from the user.
int get_valid_subranges_count_from_user();

// Returns a valid precision of the result received from the user.
double get_valid_epsilon_from_user();