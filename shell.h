#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *read_command(void);
char *get_valid_path(char *command);
int execute_command(char *path);

#endif
