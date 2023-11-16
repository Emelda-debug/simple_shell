#include "main.h"
/**
 * handle_env- function that handles environ
 */
void handle_env(void)
{
	char **env;
	char **environ = NULL;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

