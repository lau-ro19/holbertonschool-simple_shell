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
char **tokenize(char *line)
{
    int bufsize = 64,
    int i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        if (i >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)            
            {
                perror("realloc");
                exit(EXIT_FAILURE); 
            }
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[i] = NULL;
    return (tokens);
}
