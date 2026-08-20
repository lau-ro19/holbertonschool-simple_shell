#include "shell.h"

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
