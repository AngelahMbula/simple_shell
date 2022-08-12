#include "shell.h"

/**
 * strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
extern size_t strlen(const char *s)
{
	int length = 0;

	if (*s)
		for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * strncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

char **_strtok(char *s, char *delim)
{
	static char *remainder;
	char **tokens = NULL;

	if (!s)
	{
		s = remainder;
		if (!s)
			return (NULL);
	}
	s += strspn(s, (char *)delim);
	if (!*s)
	{
		remainder = NULL;
		return (NULL);
	}
	s = _strpbrk(" ", (char *)delim);
	if (s)
	{
		*s = '\0';
		remainder = s + 1;
	}
	else
		remainder = NULL;
	return tokens;
}

char *_strpbrk(char *s, char *accept)
{
	unsigned int i = 0, r = 0;

	for (i = 0; s[i]; i++)
	{
		for (r = 0; accept[r]; r++)
			if (s[i] == accept[r])
				return (s + i);
	}
	return (NULL);
}
