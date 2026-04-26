#include "shell.h"

/**
 * read_line - Reads a line of input from stdin.
 *
 * Return: A pointer to the read line, or NULL on failure.
 */
char *read_line(void)
{
	char *line;
	size_t n;
	ssize_t chars;

	line = NULL;
	n = 0;

	chars = getline(&line, &n, stdin);
	if (chars == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * tokenize - Splits a line into tokens based on whitespace.
 * @line: The input line to tokenize.
 *
 * Return: An array of strings (tokens), or NULL on failure.
 */
char **tokenize(char *line)
{
	char **tokens;
	char *token;
	int bufsize;
	int i;

	bufsize = 64;
	i = 0;
	tokens = malloc(bufsize * sizeof(char *));

	if (tokens == NULL)
	{
		return (NULL);
	}

	token = strtok(line, " \n\t");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				return (NULL);
			}
		}
		token = strtok(NULL, " \n\t");
	}
	tokens[i] = NULL;
	return (tokens);
}
