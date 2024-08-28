#include "shell.h"

/**
 * main - Entry point for the UNIX command-line interpreter
 *
 * Description: This UNIX xommand-line interpreter asks the user for
 * an input, tokenizes the input, and executes.
 *
 * Return: 0 on success
 */

int main(void)
{
	char *usr_input = NULL; /* Pointer to user input storage */
	size_t size_usr_input = 0; /* Size of the user input */
	ssize_t count_usr_input; /* Number of chars from getline */
	char **arr_tokens; /* An array of tokens */
	int cmd_count = 0; /* Counter for the number of commands */
	int status = 0; /* Stores the status from the user prompt */

	/* Infinite loop to keep the UNIX shell running */
	while (1)
	{
		cmd_count++; /* Increase command count */
		printf("#cisfun$ "); /* Prompt user input */
		count_usr_input = getline(&usr_input, &size_usr_input, stdin); /* Read the input line */

		if (count_usr_input == -1) /* Check for EOF/ctr+d */
		{
			free(usr_input); /*Free allocated memory */
			return (0);
		}

		arr_tokens = tokenize_input(usr_input); /* Tokenize user input */
		/* Check if the token is exit */
		if (arr_tokens[0] && strcmp(arr_tokens[0], "exit") == 0)
		{
			free(arr_tokens);
			free(usr_input);
			break;
		}
		
		/* Execute the command */
		status = execute_command(arr_tokens, cmd_count);
		free(arr_tokens);
	}
	return (status);
}
