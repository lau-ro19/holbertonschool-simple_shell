#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * check_builtin - Checks and executes shell built-in commands
 * @args: Array of argument strings
 * @env: Array of environment variables
 *
 * Return: 1 if a built-in was executed, 0 otherwise
 */
int check_builtin(char **args, char **env)
{
	int i;

	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(0);
	}

	if (strcmp(args[0], "env") == 0)
	{
		if (env != NULL)
		{
			for (i = 0; env[i] != NULL; i++)
			{
				write(STDOUT_FILENO, env[i], strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		return (1);
	}

	return (0);
}
