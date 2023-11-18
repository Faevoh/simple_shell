#include "main.h"

/**
 * _memcpy - copies memory from the source to destination
 * @dest: destination
 * @src: source
 * @n: size of memory to be copied
 *
 * Return: memory of destination
 */
void *_memcpy(void *dest, void *src, size_t n)
{
	char *destPtr = (char *)dest;
	const char *srcPtr = (const char *)src;

	for (size_t i = 0; i < n; ++i)
	{
		destPtr[i] = srcPtr[i];
	}
	return (dest);
}

/**
 * _realloc - reallocate function
 * @ptr: olld malloc pointer
 * @size: new size
 *
 * Return: new ptr
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (!ptr)
	{
		new_ptr = malloc(size);

		if (!new_ptr)
		{
			return (NULL);
		}
		else if (!size)
		{
			free(ptr);
			return (NULL);
		}
		else
		{
			new_ptr = malloc(size);

			if (!new_ptr)
			{
				return (NULL);
			}
		}
		_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
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
