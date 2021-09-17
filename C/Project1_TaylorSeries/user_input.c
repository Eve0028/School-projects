#include <stdio.h>

#include "user_input.h"
#include "formulas.h"
#include "stdin_check.h"

#pragma warning(disable: 4996)

int get_valid_formula_number_from_user()
{
    int formula_nr = 0;
    do
    {
        printf("\nEnter number of formula: \n");
        scanf("%d", &formula_nr);

        if (is_stdin_not_empty(getchar()))
            continue;
        else if (formula_nr < 0 || formula_nr >= COUNT_OF_FORMULAS)
        {
            printf("You entered an incorrect number.\n");
        }
        else
            return formula_nr;

    } while (1);

    return formula_nr;
}

void get_valid_range_from_user(Range* range, double* start_range, double* end_range)
{
    do
    {
        printf("\nEnter start of the range: \n");
        scanf("%lf", start_range);

        if (is_stdin_not_empty(getchar())) 
            continue;
        else if (range_contain(range, *start_range) && *start_range != range->end.value)
            break;
        printf("You entered an incorrect start of the range (%s).\n", range->start.name);

    } while (1);

    do
    {
        printf("\nEnter end of the range: \n");
        scanf("%lf", end_range);

        if (is_stdin_not_empty(getchar()))
            continue;
        else if (range_contain(range, *end_range) && *end_range > *start_range)
            break;
        printf("You entered an incorrect end of the range (%s).\n", range->end.name);

    } while (1);
}

int get_valid_subranges_count_from_user()
{
    int subranges_nr = 10;
    do
    {
        printf("\nEnter a number of sub-ranges (an integer):\n");
        scanf("%d", &subranges_nr);

        if (is_stdin_not_empty(getchar()))
            continue;
        else if (subranges_nr < 1)
            printf("You entered an incorrect number of sub-ranges (range: subranges_nr >= 1).\n");
        else
            break;

    } while (1);

    return subranges_nr;
}

double get_valid_epsilon_from_user()
{
    int eps = 0.001;
    do
    {
        printf("\nEnter a precision of the result:\n");
        scanf("%d", &eps);

        if (is_stdin_not_empty(getchar()))
            continue;
        else if (eps < 0 || eps > 1)
        {
            printf("You entered the wrong precision of the result (range: 0 <= eps <= 1).\n");
        }
        else
            break;

    } while (1);

    return eps;
}
