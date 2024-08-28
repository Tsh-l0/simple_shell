#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
int execute_command(char **args, int cmd_num);
char **tokenize_input(char *line);
int exit_cmd(char **args);
int print_env(char **args);
char *find_path(char *cmd);

extern char **environ; /* Declare environ as an external variable */

#endif /* SHELL_H */
