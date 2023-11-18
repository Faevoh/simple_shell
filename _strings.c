#include "main.h"

/**
  *_strchr - find the first occurrence of a character in a string.
  *@s: the string to search
  *@c: the character to find
  *Return: returns a pointer to the first occurrence of c in the string s
  */
char *_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	else
	{
		return (NULL);
	}
}

/**
  *_strcspn - finds the length(in bytes) of the maximum initial
  *segment of the string
  *@s1: pointer to the string to be searched
  *@s2: set of characters to be excluded
  *Return: returns the count of characters
  */
size_t _strcspn(const char *s1, const char *s2)
{
	const char *s = s1;
	size_t count = 0;

	while (*s != '\0')
	{
		if (_strchr(s2, *s) != NULL)
		{
			break;
		}
		s++;
		count++;
	}
	return (count);
}

/**
  *_strlen - checks the length of a string
  *@s: pointer to the string input
  *Return: number of character in the string
  */
size_t _strlen(const char *s)
{
	const char *strng = s;

	while (*strng)
	{
		strng++;
	}
	return (strng - s);
}

/**
  *_strsep - tokenizes a string based on delimiter
  *@stringp: pointer to the string pointer
  *@delim: the delimiting character
  *Return: returns a pointer to the token
  */
char *_strsep(char **stringp, const char *delim)
{
	char *strt;
	char *end;

	if (*stringp == NULL)
	{
		return (NULL);
	}

	strt = *stringp;
	end = strt + _strcspn(strt, delim);

	if (*end != '\0')
	{
		*end = '\0';
		*stringp = end + 1;
	}
	else
	{
		*stringp = NULL;
	}
	return (strt);
}

/**
  *_strcmp - compare two strings
  *@s1: first string to be compared
  *@s2: second string to be compared
  *Return: 0
  */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

