#include "main.h"

/**
 * main - main function
 * Return: sucess
 */
int main(void)
{
char *input = NULL;
size_t input_size = 0;
char *tokens[2];
int a = 0;
	printHelloWorld(a);


	while (1)
{
	printr("myshell$ ");
	if (getline(&input, &input_size, stdin) == -1)
	{
	if (feof(stdin))
	{
	printr("Exiting...\n");
	break;
	}
	else
	{
	perror("getline");
	exit(EXIT_FAILURE);
	}
	}
	input[strcspn(input, "\n")] = '\0';
	parse_input(input, tokens);
	if (strcmp(tokens[0], "exit") == 0)
	handle_exit();
	else if (strcmp(tokens[0], "env") == 0)
	{
	handle_env();
	}
	else
	{
	execute_command(*tokens);
	}
	}
	free(input);
	return (EXIT_SUCCESS);
}
