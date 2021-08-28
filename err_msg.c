#include "shell.h"

/**
 * err_msg - prints error msg
 */
void err_msg(char **args)
{
	counter *ptr;
	char *space = ": ";
	char *msg, *string = "hsh: ";
	char *cnt;
	ptr = malloc(sizeof(ptr));
	ptr->cnt++;

	msg = malloc(sizeof(char) * _strlen(string));
	if (!msg)
		return;

	_strcpy(msg, string);
	cnt = _tostring(ptr->cnt);

	msg = _realloc(msg, _strlen(msg), _strlen(msg) + _strlen(cnt) + 3);
	if (!msg)
		return;

	_strcat(msg, cnt);
	_strcat(msg, space);

	msg = _realloc(msg, _strlen(msg), _strlen(msg) + _strlen(args[0]) + 1);
	if (!msg)
		return;

	_strcat(msg, args[0]);

	perror(msg);
	return;
}

/**
 * _tostring - converts int to char || integers to strings
 * @num: number to convert
 */
char *_tostring(int num)
{
	int i, rem, len, n;
	char *str;

	len = 0;
	n = num;
	
	while (n != 0)
	{
		len++;
		n /= 10;
	}

	str = malloc(sizeof(char) * (len + 1));

	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len++] = '\0';
	return (str);
}
