#include "main.h"
/**
 * execute_command - function that executes the shell command
 * @command: takes an input
 */
void execute_command(char *command)
{
pid_t pid;
int status;

	pid = fork();
	if (pid == 0)
	{
	/*Child process*/
	if (execlp(command, command, (char *)NULL) == -1)
	{
	perror("shell");
	exit(EXIT_FAILURE);
	}
	}
	else if (pid < 0)
	{
	perror("shell");
	}
	else
	{
	do {
	waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
