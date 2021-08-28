#include "shell.h"

/**
 * _strlen - counts the length of a string
 * @str: string to be counter
 *
 * Return: The count
 */
int _strlen(const char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - copys string from dsource to destination
 * @dest: string destination
 * @src: string source
 *
 * Return: address to the new string
 */
char *_strcpy(char *dest, char *src)
{
	int i, cnt;

	i = 0;
	while (*(src + i) != '\0')
		i++;

	cnt = 0;
	while (cnt < i)
	{
		dest[cnt] = src[cnt];
		cnt++;
	}

	dest[cnt] = '\0';
	return (dest);
}

/**
 * _strncpy - copies "n" number of chars of a string
 * @dest: Destination to copy into
 * @src: Source of string to copy
 * @n: number of characters to copy
 *
 * Return: Pointer to copied array of characters
 */
char *_strncpy(char *dest, char *src, int n)
{
	int cnt;

	for (cnt = 0; *(src + cnt) != '\0' && cnt < n;)
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (dest);

}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if both strings are same, something else otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int cnt;

	for (cnt = 0; s1[cnt] == s2[cnt]; cnt++)
	{
		if (s1[cnt] == '\0' && s2[cnt] == '\0')
			return (0);
	}

	return (s1[cnt] - s2[cnt]);
}


/**
 * _strncmp - compaires n number of strings
 * @s1: first string to perform comparison
 * @s2: second string to perfomr compairson with
 * @n: the count of strings to comapire
 *
 * Return: 0 if same, something else otherwise
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
