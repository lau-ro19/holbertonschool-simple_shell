#include "shell.h"

char *get_valid_path(char *command)
{
    char *path;

    if (command == NULL || *command == '\0')
        return (NULL);
    if (access(command, X_OK) != 0)
    {
        fprintf(stderr, "%s: command not found\n", command);
        return (NULL);
    }
    path = strdup(command);
    if (path == NULL)
    {
        fprintf(stderr, "shell: fatal: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return (path);
}
