#include "shell.h"

/**
 * retrieve_input - gets line(s) of input
 *
 * Return: the retrieved string
 */
char *retrieve_input(void)
{
	char *string = '\0';
	ssize_t get_cnt;
	size_t cnt;
	char *buffer = NULL;

	get_cnt = getline(&buffer, &cnt, stdin);
	if (get_cnt == -1)
	{
		free(buffer);
		return (NULL);
	}
	
	buffer[cnt - 1] = '\0';
	string = malloc(sizeof(char *) * _strlen(buffer + 1));
	if (!string)
		return (NULL);

	_strcpy(string, buffer);
	free(buffer);

	return (string);
}
