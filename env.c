#include "main.h"
/**
 * handle_env- function that handles environ
 */
void handle_env(void)
{
extern char **environ;
char **env;
char *env_var = getenv("PATH");
	for (env = environ; *env != NULL; env++)
	{
	printf("%s\n", *env);
}

	if (env_var != NULL)
	{
	printf("PATH=%s\n", env_var);
	}
	else
	{
	printf("PATH environment variable not found\n");
	}
}

