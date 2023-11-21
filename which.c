#include "main.h"

/**
 * which - which function
 * @command: command
 *
 * Return: path to be executable
 */

char *which(char *command)
{
	char *path = _gentenv("PATH");
	char *pathCopy;
	char *dir;

	if (!path)
	{
		return (NULL);
	}

	pathCopy _strdup(path);
	dir = strtok(pathCopy, ":");

	while (dir)
	{
		char fullPath[1024];

		_strcpy(fullPath, dir);
		_strcat(fullPath, "/");
		_strcat(fullPAth, command);

		if (access(fullPathm X_OK) == 0)
		{
			free(pathCopy);
			return (_strdup(fullPath));
		}

		dir = strtok(NULL, ":");
	}

	free(pathCopy);
	return (NULL);
}

/**
 * pritn_all_aliases - prints all aliases
 *
 * @aliases: aliases
 */

void print_all_aliases(alias_t *aliases)
{
	alias_t *currentAlias = aliases;

	while (currentAlias)
	{
		print_alias(currentAlias);
		currentAlias = currentAlias->next;
	}
}
