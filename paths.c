#include "shell.h"

char *get_path_env(void)
{
    int i;

    i = 0;
    while (environ[i] != NULL)
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
            return (environ[i] + 5);
        i++;
    }
    return (NULL);
}

char *build_path(char *dir, char *command)
{
    char *full_path;
    size_t len;

    len = strlen(dir) + strlen(command) + 2;
    full_path = malloc(len);
    if (full_path == NULL)
        return (NULL);
    sprintf(full_path, "%s/%s", dir, command);
    return (full_path);
}

char *search_in_path(char *command)
{
    char *path_env;
    char *path_copy;
    char *dir;
    char *full_path;

    path_env = get_path_env();
    if (path_env == NULL || *path_env == '\0')
        return (NULL);
    path_copy = strdup(path_env);
    if (path_copy == NULL)
        exit(EXIT_FAILURE);
    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        full_path = build_path(dir, command);
        if (full_path == NULL)
        {
            free(path_copy);
            exit(EXIT_FAILURE);
        }
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }
        free(full_path);
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return (NULL);
}

char *get_valid_path(char *command)
{
    char *result;

    if (command == NULL || *command == '\0')
        return (NULL);
    if (strchr(command, '/') != NULL)
    {
        if (access(command, X_OK) != 0)
            return (NULL);
        result = strdup(command);
        if (result == NULL)
            exit(EXIT_FAILURE);
        return (result);
    }
    return (search_in_path(command));
}
