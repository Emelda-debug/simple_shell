#include "main.h"

/**
 * parse_input - function that takes user input
 * @input: the command to be typed by user
 * @tokens: token count
 */
void parse_input(char *input, char **tokens)
{
char *token;
int token_count = 0;

	token = strtok(input, " \t\n\r\a");
	while (token != NULL)
	{
	tokens[token_count++] = token;
	token = strtok(NULL, " \t\n\r\a");
	if (token_count > 2)
	{
	fprintf(stderr, "Too many arguments\n");
	exit(EXIT_FAILURE);
	}
	}
	tokens[token_count] = NULL;
}
