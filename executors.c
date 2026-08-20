#include "shell.h"

int execute_command(char **args, char **env)
{
	pid_t pid;

	if (args == NULL || args[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	return (0);
}