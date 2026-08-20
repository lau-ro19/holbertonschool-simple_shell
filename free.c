#include "shell.h"

/**
 * free_argv - frees an argument array and its contents
 * @argv: the array to free
 */
void free_argv(char **argv)
{
	int i;

	if (argv == NULL)
		return;
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
