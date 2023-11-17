#include "main.h"

/**
  *_getLine - reads the users input
  *@lineptr: storage for inputs
  *@l: size of inputs
  *@stream: input source
  *Return: no of read inputs
  */

ssize_t _getLine(char **lineptr, size_t *l, FILE *stream)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t inputRead;

	inputRead = getline(&line, &len, stream);

	if (inputRead == -1)
	{
		free(line);
		return (-1);
	}
	else
	{
		*lineptr = line;
		*l = len;
	}

	return (inputRead);
}
