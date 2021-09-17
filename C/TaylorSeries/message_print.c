#include <stdio.h>

#include "formulas.h"

// Prints the menu (all added formulas to an array of objects - their value can be calculated using the taylor series).
void menu_prt()
{
    printf("List of formulas:\n");
    for (int i = 0; i < COUNT_OF_FORMULAS; i++)
    {
        printf("%d. %s\n", i, formulas[i].name);
    }
}