#include "main.h"

/**
  *_getenv - searches the environment list
  *@name: environment to retrieve
  *Return: returns a pointer to the value part of the environment variable
  */
char *_getenv(const char *name, char **envp)
{
	size_t nameLen;
	size_t i;

	if (name == NULL || *name == '\0' || envp == NULL)
	{
		return (NULL);
	}
	nameLen = _strlen(name);
	printf("Searching for: %s\n", name);

	for (i = 0; envp[i] != NULL; ++i)
	{
		if (_strncmp(envp[i], name, nameLen) == 0 && envp[i][nameLen] == '=')
		{
			return (envp[i] + nameLen + 1);
		}
	}
	return (NULL);
}
