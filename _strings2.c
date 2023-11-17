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
  *_strncmp - compares the first character of two strings
  *@s1: first string to compare
  *@s2: second string to compare
  *@n: maximum no of character to compare
  *Return: 0
  */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- != 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return ((*s1 - *s2));
		s1++;
		s2++;
	}
	if (n != 0)
		return ((*s1 - *s2));
	return (0);
}

/**
  *_strdup - Duplicates a string
  *@s: string to be duplicated
  *Return: returns pointer to duplicated string
  */
char *_strdup(const char *s)
{
	size_t l;
	char *dupl;

	if (s == NULL)
		return (NULL);
	l = _strlen(s) + 1;
	dupl = (char *)malloc(l);

	if (dupl != NULL)
		_strcpy(dupl, s);
	return (dupl);
}

/**
  *_strcat - concatenates one string to another
  *@dst: destination of string
  *@src: source of string
  *Return: destination
  */
char *_strcat(char *dst, const char *src)
{
	char *destination = dst;

	while (*dst != '\0')
	{
		dst++;
	}
	while ((*dst++ = *src++) != '\0')
	{};
	return (destination);
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
