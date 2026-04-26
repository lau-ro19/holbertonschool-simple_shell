# include"shell.h"

/**
 * read_line - Reads a line of input from stdin.
 * Return: A pointer to the read line, or NULL on failure.
 */

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
/**
 * tokenize - Splits a line into tokens based on whitespace.
 * @line: The input line to tokenize.
 * Return: An array of strings (tokens), or NULL on failure.
 */