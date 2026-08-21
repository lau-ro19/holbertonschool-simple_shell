#include "shell.h"

/**
 * print_prompt - display the prompt if running interactively
 */
void print_prompt(void)
{
	char *cwd;

	if (!isatty(STDIN_FILENO))
		return;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		printf("%s$ ", cwd);
		free(cwd);
	}
	else
		printf("$ ");

	fflush(stdout);
}

/**
 * main - entry point for the simple shell
 * @argc: argument count (unused)
 * @argv: argument lists, argv[0] is the program name
 *
 * Return: exit status of the last command
 */
int main(int argc, char **argv)
{
	char *line;
	int line_num;
	int status;

	(void)argc;
	line_num = 0;
	status = 0;
	while (1)
	{
		print_prompt();
		line = read_command();
		if (line == NULL)
			break;
		line_num++;
		if (process_line(line, argv[0], line_num, &status) == 0)
			break;
	}
	return (status);
}
