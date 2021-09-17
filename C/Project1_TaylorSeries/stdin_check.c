#include <stdio.h>

#include "stdin_check.h"

// Checks if a character other than "/ n" is left in stdin
// If so - display error message and return 1.
// Otherwise return 0.
int is_stdin_not_empty(char next_char)
{
    if (next_char != '\n')
    {
        int letter = 0, special_char = 0;
        printf("\nYou entered invalid characters:\n");

        // Validation of entered characters using ASCII code.
        do
        {
            if (next_char < 48 || next_char > 57)
            {
                if ((next_char > 64 && next_char < 91) || (next_char > 96 && next_char < 123))
                {
                    if (!letter)
                    {
                        printf("- letter\n");
                        letter = 1;
                    }
                }
                else if (!special_char)
                {
                    printf("- \"another character\" (special character, white character, etc.)\n");
                    special_char = 1;
                }
            }
        } while ((next_char = getchar()) != '\n');
        return 1;
    }
    return 0;
}