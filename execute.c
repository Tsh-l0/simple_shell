#include "shell.h"

/**
 * execute_command - Executes the user input
 *
 * @args: An array representing the user command and arguments
 * @cmd_num: The number of commands executed
 *
 * Return: Nothing (void)
 */

int execute_command(char **args, int cmd_num)
{
	pid_t child_pid; /* Process ID for fork */
	int status; /* Status of the child process */
	(void)cmd_num;

	child_pid = fork(); /* Create a new process */

	if (child_pid == -1) /* Check if fork failed */
	{
		perror("Fork failure");
		return (-1);
	}

	if (child_pid == 0) /* Child process */
	{
		printf("Executing command: %s\n", args[0]);
		/* Execute the command */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve error"); /* Print if execve fails */
			exit(EXIT_FAILURE);
		}
	}

	else /* Parent process */
	{
		wait(&status); /* Wait for the child process to complete */
		printf("Command finished with status: %d\n", status);
	}

	return (0); /* Indicate success */
}
