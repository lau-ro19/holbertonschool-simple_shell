#include "shell.h"

/**
 * count_tokens - counts whitespace-separated tokens in a string
 * @line: the string to count token from
 *
 * Return: number of tokens found
 */
static int count_tokens(char *line)
{
	char *copy;
	char *token;
	int count;

	count = 0;
	copy = strdup(line);
	if (copy == NULL)
		return (0);
	token = strtok(copy, " \t");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \t");
	}
	free(copy);
	return (count);
}

/**
 * split_line - splits a command line into an argument array
 * @line: the line to split
 *
 * Return: NULL-terminated array of arguments, or NULL on failure
 */
char **split_line(char *line)
{
	char **argv;
	char *token;
	int count;
	int i;

	count = count_tokens(line);
	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
		return (NULL);
	i = 0;
	token = strtok(line, " \t");
	while (token != NULL)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			free_argv(argv);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * read_command - reads the user command in stdin
 *
 * Return: line read
 */
char *read_command(void)
{
	char *line;
	size_t buffer_size;
	ssize_t nread;

	line = NULL;
	buffer_size = 0;
	nread = getline(&line, &buffer_size, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';
	return (line);
}

/**
 * process_line - processes one line of input
 * @line: the raw input line, freed by this function
 * @prog_name: name of the executable used to start the shell
 * @line_num: current command number
 * @status: pointer to the shell's exit status, updated here
 *
 * Return: 1 to continue the loop, 0 to exit the shell
 */
int process_line(char *line, char *prog_name, int line_num, int *status)
{
	char **args;
	char *path;

	args = split_line(line);
	free(line);
	if (args == NULL)
		return (1);
	if (args[0] == NULL)
	{
		free_argv(args);
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		free_argv(args);
		return (0);
	}
	path = get_valid_path(args[0]);
	if (path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
			prog_name, line_num, args[0]);
		*status = 127;
	}
	else
	{
		execute_command(path, args);
		free(path);
		*status = 0;
	}
	free_argv(args);
	return (1);
}
