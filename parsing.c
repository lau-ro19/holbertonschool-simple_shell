#include "shell.h"

/**
 * count_tokens - counts whitespace-separated tokens in a string
 * @line: the string to examine
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

char *read_command(void)
{
	char *line;
	size_t bufsize;
	ssize_t nread;

	line = NULL;
	bufsize = 0;
	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';
	return (line);
}
