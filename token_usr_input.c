#include "shell.h"

/**
 * tokenize_input - Splits user input into an array of tokens
 * @line: The user input
 * Return: An array of tokens
 */
char **tokenize_input(char *line)
{

	int buffer = 64; /* Buffer size for tokens */
	int index_tokens = 0; /* Index to store tokens */
	char **tokens = malloc(buffer * sizeof(char *)); /* Array of tokens */
	char *token; /* Single token */
	int ab;

	if (!tokens) /* Check if memory allocation failed */
	{
		perror("Memory not allocated\n");
		return (NULL);
	}

	token = strtok(line, " \n"); /* Get the first token */
	while (token != NULL) /* Tokenize until the end */
	{
		tokens[index_tokens] = token; /* Store the token in array */
		index_tokens++;

		if (index_tokens >= buffer) /* Realloc size if buffer is exceed */
		{
			char **new_tokens = malloc((buffer + 64) * sizeof(char *));

			if (!tokens)
			{
				perror("Memory not allocated\n");
				free(tokens);
				return (NULL);
			}

			for (ab = 0; ab < buffer; ab++)
				new_tokens[ab] = tokens[ab];

			free(tokens);
			tokens = new_tokens;
			buffer += 64;
		}

		token = strtok(NULL, " \n"); /* Get the next token */
	}
	tokens[index_tokens] = NULL; /* Mark the end of token arr */
	return (tokens);
}
