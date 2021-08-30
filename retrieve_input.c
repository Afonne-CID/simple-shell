#include "shell.h"

/**
 * retrieve_input - gets line(s) of input
 *
 * Return: the retrieved string
 */
char *retrieve_input(void)
{
	ssize_t get_cnt;
	size_t cnt;
	char *next = NULL;
	char *buffer = NULL;

	get_cnt = getline(&buffer, &cnt, stdin);
	if (get_cnt == -1)
	{
		_putchar(10);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	buffer[cnt - 1] = '\0';
	while (buffer[_strlen(buffer) - 2] == '\\')
	{
		buffer[_strlen(buffer) - 2] = '\0';
		next = buf_size(next, buffer);
		_strcat(next, buffer);
		prompt2();
		get_cnt = getline(&buffer, &cnt, stdin);
		if (get_cnt == -1)
		{
			_putchar(10);
			free(buffer);
			free(next);
			exit(EXIT_FAILURE);
		}
	}
	next = buf_size(next, buffer);
	_strcat(next, buffer);
	return (next);
}
