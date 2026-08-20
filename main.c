#include "shell.h"

/**
 * main - entry point for the simple shell
 * @argc: argument count (unused)
 * @argv: argument vector, argv[0] is the program name
 *
 * Return: exit status of the last command
 */
int main(int argc, char **argv)
{
    char *line;
    char **args;
    char *path;
    char *prog_name;
    int line_num;
    int status;

    (void)argc;
    prog_name = argv[0];
    line_num = 0;
    status = 0;
    while (1)
    {
        printf("$ ");
        line = read_command();
        if (line == NULL)
            break;
        args = split_line(line);
        free(line);
        if (args == NULL)
            continue;
        if (args[0] == NULL)
        {
            free_argv(args);
            continue;
        }
        line_num++;
        path = get_valid_path(args[0]);
        if (path == NULL)
        {
            fprintf(stderr, "%s: %d: %s: not found\n",
                prog_name, line_num, args[0]);
            status = 127;
        }
        else
        {
            execute_command(path, args);
            free(path);
            status = 0;
        }
        free_argv(args);
    }
    return (status);
}
