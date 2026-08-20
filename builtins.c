#include "shell.h"
#include <stdlib.h>
#include <string.h>

int check_builtin(char **args, char **env)
{
	(void)env;

	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(0);
	}

	return (0);
}
