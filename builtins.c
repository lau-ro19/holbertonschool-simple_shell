#include "shell.h"

/**
 * builtin_env - prints the current environment variables
 * @env: the array of environment variables
 */
void builtin_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
