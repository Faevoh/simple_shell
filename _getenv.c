#include "main.h"

/**
  *_getenv - searches the environment list
  *@name: environment to retrieve
  *Return: returns a pointer to the value part of the environment variable
  */
char *_getenv(const char *name)
{
	size_t nameLen;
	size_t i;

	if (name == NULL || *name == '\0' || environ == NULL)
	{
		return (NULL);
	}
	nameLen = _strlen(name);

	for (i = 0; environ[i] != NULL; ++i)
	{
		if (_strncmp(environ[i], name, nameLen) == 0 && environ[i][nameLen] == '=')
		{
			return (environ[i] + nameLen + 1);
		}
	}
	return (NULL);
}
