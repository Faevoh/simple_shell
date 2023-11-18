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

