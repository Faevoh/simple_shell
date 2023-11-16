#include "main.h"

/**
 * _dstrtok - this is the strtok implementation for this project
 *
 * @str: string
 * @delim: delimiter
 * Return: token
 */

char *_dstrtok(char *str, char const *delim)
{
	static char *ptr;
	char *token;

	if (str != NULL)
		ptr = str;

	while (*ptr != '\0')
	{
		if (strchr(delim, *ptr) != NULL)
		{
			*ptr = '\0';
			token = ptr;
			ptr++;
			return (token);
		}
		else
			ptr++;
	}

	if (*ptr != '\0')
	{
		token = ptr;
		while (*ptr != '\0')
		{
			ptr++;
		}
		return (token);
	}
	return (NULL);
}
