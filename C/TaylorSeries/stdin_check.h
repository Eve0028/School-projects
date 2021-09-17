#pragma once

// If a character other than \n is left in stdin - display error message and return 1.
// Otherwise return 0.
int is_stdin_not_empty(char next_char);