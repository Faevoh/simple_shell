#include "main.h"

/**
  *cmdPath - Handles the command PATH
  *@cmmand: command input to find
  *Return: returns file path
  */

char *cmdPath(char *cmmand)
{
	struct stat path_st;
	char *dir_path;
	char *cpy_dirPath;
	char *dir_token;
	char *full_dirPath;

	if (cmmand[0] == '/')
	{
		if (stat(cmmand, &path_st) == 0)
		{
			return (_strdup(cmmand));
		}
		return (NULL);
	}
	dir_path = getenv("PATH");
	if (dir_path == NULL)
	{
		return (NULL);
	}
	cpy_dirPath = _strdup(dir_path);
	dir_token = strtok(cpy_dirPath, ":");
	while (dir_token != NULL)
	{
		full_dirPath = malloc(_strlen(dir_token) + _strlen(cmmand) + 2);
		_strcpy(full_dirPath, dir_token);
		_strcat(full_dirPath, "/");
		_strcat(full_dirPath, cmmand);
		if (stat(full_dirPath, &path_st) == 0)
		{
			free(cpy_dirPath);
			return (full_dirPath);
		}

		free(full_dirPath);
		dir_token = strtok(NULL, ":");
	}
	free(cpy_dirPath);
	return (NULL);
}
