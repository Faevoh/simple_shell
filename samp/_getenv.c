#include "main.h"

/**
  *_getenv - searches the environment list
  *@name: environment to retrieve
  *Return: returns a pointer to the value part of the environment variable
  */
char *_getenv(const char *name)
{
	size_t nameLen;
	char **env;

	if (name == NULL || *name == '\0' || environ == NULL)
	{
		return (NULL);
	}
	nameLen = _strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, nameLen) == 0 && (*env)[nameLen] == '=')
		{
			return (*env + nameLen + 1);
		}
	}
	return (NULL);
}
