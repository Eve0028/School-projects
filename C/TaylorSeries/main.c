#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "message_print.h"
#include "user_input.h"
#include "formulas.h"

#pragma warning(disable: 4996)

int main()
{
    menu_prt();

    int formula_nr = get_valid_formula_number_from_user();

    double a, b;
    get_valid_range_from_user(&formulas[formula_nr].range, &a, &b);

    int subranges_nr = get_valid_subranges_count_from_user();

    double eps = get_valid_epsilon_from_user();

    FILE* fw;
    if (!(fw = fopen("results.txt", "w")))
    {
        printf("File opening error\n");
        exit(2);
    }

    fprintf(fw,"\tx\t\t\ttaylor_series(x)\t\t%s\tnumber of words\tstop condition\n"
        "-------------------------------------------------------------------------------------\n", formulas[formula_nr].name);
    int word_nr = 0, condition = 0;
    double result_f, result = 0;
    double step = (b - a) / subranges_nr;
    for (double x = a; x <= b; x += step)
    {
        result_f = formulas[formula_nr].taylor_series(x, eps, &word_nr, &condition, &result);
        fprintf(fw,"%6.2lf\t\t%9.7lf\t\t%11.7lf\t\t\t\t\t%d\t\t\t\t\t\t%d\n", x, result_f, result, word_nr, condition);
        // condition: 0 - precision, 1 - max number of words of the sequence, 2 - both at once
    }  
    fprintf(fw," -------------------------------------------------------------------------------------\n\n");
    fclose(fw);

    return 0;
}
