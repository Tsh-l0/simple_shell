#include "shell.h"

/**
 * exit_cmd - Exits the shell
 *
 * @args: The command arguments
 *
 * Return: -1 Indicates the shell exit
 */
int exit_cmd(char **args)
{
	/* args is not used; exits the shell */
	(void)args;
	return (-1);
}

/**
 * print_env - Prints the current environment
 *
 * @args: The command arguments
 *
 * Return: 0 success
 */
int print_env(char **args)
{
	char **env = environ;

	/* Prints all environment variables */
	(void)args;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
