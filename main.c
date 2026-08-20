#include "shell.h"

static int is_blank_line(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != ' ' && line[i] != '\t')
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    char *line;
    char *path;

    while (1)
    {
        printf("$ ");
        line = read_command();
        if (line == NULL)
            break;
        if (is_blank_line(line))
        {
            free(line);
            continue;
        }
        path = get_valid_path(line);
        if (path != NULL)
        {
            execute_command(path);
            free(path);
        }
        free(line);
    }
    return (0);
}
