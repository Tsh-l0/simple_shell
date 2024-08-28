#include "shell.h"

/**
 * find_path - Finds a command in a path
 *
 * @cmd: - The command to find
 *
 * Return: The full path to the command if found,
 * NULL if not found
 */
char *find_path(char *cmd)
{
	char *path, *cpy_path, *drctry;
	char full_path[1024];

	/* Get the PATH environment variable */
	path = getenv("PATH");
	if (!path)
		return (NULL);

	/* Make a copy of PATH using strtok */
	cpy_path = strdup(path);
	if (!cpy_path)
		return (NULL);

	/* Split the PATH into directories and search for cmnd */
	drctry = strtok(cpy_path, ":");
	while (drctry)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", drctry, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(cpy_path);
			return (strdup(full_path));
		}

		drctry = strtok(NULL, ":");
	}

	free(cpy_path);
	return (NULL);
}
