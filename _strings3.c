#include "main.h"

/**
  *_strcpy - copies the string pointed to
  *@dst: destination string where string is copied
  *@src: source string which string are copied
  *Return: returns destination string
  */
char *_strcpy(char *dst, const char *src)
{
	char *destination = dst;

	while ((*dst++ = *src++) != '\0')
	{};

	return (destination);
}

/**
 * remove_trailing_and_leading_spaces - remove trailing spaces
 * from a string
 *
 * @str: string to remove trailing spaces from
 */
void remove_trailing_and_leading_spaces(char *str)
{
	size_t len = _strlen(str);
	size_t start = 0;

	if (len > 0)
	{
		while (len > 0 && str[len - 1] == ' ')
		{
			len--;
		}
		str[len] = '\0';
	}

	while (str[start] == ' ')
	{
		start++;
	}

	if (start > 0)
	{
		size_t i = start;

		while (str[i] != '\0')
		{
			str[i - start] = str[i];
			i++;
		}
		str[i - start] = '\0';
	}
}

/**
 * tokenize - tokenize a string into ann array of tokens
 *
 * @command: string to tokenize
 * @argv: array to store tokens
 */
void tokenize(char *command, char *argv[MAX_ARGS])
{
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
}

/**
 * num_args - count the number of arguments in an array of arguments
 *
 * @argv: array of arguments
 * Return:  number of arguments in argv
 */
int num_args(char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
		i++;

	return (i);
}

/**
 * _atoi - convert a string to an integer
 *
 * @str: string to convert
 * Return: integer value of str
 */
int _atoi(const char *str)
{
	int n = 0;
	int sign = 1;

	while (*str)
	{
		if (*str == '-')
		{
			sign = -1;
		}
		else if (*str >= '0' && *str <= '9')
		{
			n = n * 10 + (*str - '0');
		}
		else
		{
			break;
		}
		str++;
	}
	return (n * sign);
}
