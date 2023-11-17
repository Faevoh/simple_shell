#include "main.h"

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
