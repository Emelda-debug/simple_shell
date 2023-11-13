#include "main.h"
/**
 * printr- function that prints a command
 * @string: takes a string input
 */

void printr(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}

