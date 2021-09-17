#include <math.h>

#include "formulas.h"
#define WRD_NR 250  // Maximum NUMBER OF WORDS

// FORMULA 0 - (1 - x)^(1/3)
double taylor_series_0(double x, double eps, int* word_nr, int* condition, double* result)
{
    *result = pow(1 - x, 1. / 3);
    double first_part = 1;
    double sum = 1;

    for (*word_nr = 1; *word_nr < WRD_NR; (*word_nr)++)
    {
        first_part = first_part * (x * ((*word_nr - 1.) * 3 - 1)) / (*word_nr * 3.);
        sum = sum + first_part;

        if (fabs(sum - *result) < eps)
        {
            if (*word_nr == WRD_NR)
                *condition = 2;
            else
                *condition = 0;
            return sum;
        }
    }
    *condition = 1;
    // condition: 0 - precision, 1 - max number of words of the sequence, 2 - both at once

    return sum;
}

// FORMULA 1 - (1 + x)^(-3/2)
double taylor_series_1(double x, double eps, int* word_nr, int* condition, double* result)
{
    *result = pow(1 + x, -3. / 2);
    double first_part = 1;
    double sum = 1;

    for (*word_nr = 1; *word_nr < WRD_NR; (*word_nr)++)
    {
        first_part = first_part * (x * (*word_nr * 2. + 1)) / (*word_nr * 2.) * -1;
        sum = sum + first_part;

        if (fabs(sum - *result) < eps)
        {
            if (*word_nr == WRD_NR)
                *condition = 2;
            else
                *condition = 0;
            return sum;
        }
    }
    *condition = 1;

    return sum;
}

// FORMULA 2 - ln(x)
double taylor_series_2(double x, double eps, int* word_nr, int* condition, double* result)
{
    *result = log(x);

    double first_part = (x - 1) / (x + 1);
    double sum = first_part * 2;

    for (*word_nr = 1; *word_nr < WRD_NR; (*word_nr)++)
    {
        sum = sum + pow(first_part, 2. * *word_nr + 1) / (2. * *word_nr + 1) * 2;

        if (fabs(sum - *result) < eps)
        {
            if (*word_nr == WRD_NR)
                *condition = 2;
            else
                *condition = 0;
            return sum;
        }
    }
    *condition = 1;

    return sum;
}