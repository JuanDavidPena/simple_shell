#include "shell.h"
/**
 * _strcpy - Copies a str
 * @dest:Destination
 * @src:Source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates 2 strings
 * @dest:First String
 * @src:Second String
 * Return:pointer to resulting str
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strchr - Locates a char inside a str
 * @s:String to search in
 * @c:Char to locate
 * Return: Pointer to the wanted char
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);

	return (s);
}

/**
 * _strncmp - Checks if 2 strings have n number of identycal chars
 * @s1: Str 1
 * @s2: Str 2
 * @n: Amount of chars to compare.
 * Return: 1 if it finds a difference. 0 if not.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - duplicates a str
 * @str:String
 * Return: pointer to duplicate.
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
