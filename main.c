#include"shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Argument count.
 * @argv: Argument vector (array of strings).
 * @env: Environment variables.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv, char **env)

char*line;

while(1)
{

    if(isatty(STDIN_FILENO))
    write( 1, "$ ", 2);

    line=read_line();
    if(line==NULL)
    {
        free(line);
        exit(0);
    }

    if(line[0]=='\n')
    {
        free(line);
        continue;
    }

    
}
