#include "shell.h"

/**
 * _tokenizer - tokenizes a string into chunks
 * @str: the string to tokenize
 * @delim: delimeter
 *
 * Return: Double pointer to string (array of arrays)
 */
char **_tokenizer(char *str, char *delim)
{
	char **token_holder, **holder, *token;
	unsigned int length;
	int i;

	length = _strlen(str);
	if (length == 0)
		return (NULL);

	token_holder = malloc((sizeof(char *)) * (length + 1));
	if (token_holder == NULL)
		return (NULL);

	i = 0;
	token = strtok(str, delim);
	while (token != NULL)
	{
		token_holder[i] = malloc(_strlen(token) + 1);
		if (token_holder[i] == NULL)
		{
			free_mem(token_holder);
			return (NULL);
		}

		_strcpy(token_holder[i], token);
		token = strtok(NULL, delim);
		i++;
	}

	token_holder[i] = NULL;
	holder = token_holder;
	free_mem(token_holder);
	return (holder);
}
