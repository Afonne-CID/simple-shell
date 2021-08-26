#include "shell.h"



/**
 * _getenv - gets $PATH
 * @var: passed environ variable
 *
 * Return: Double pointer to variable path
 */
char *_getenv(const char *var)
{
	int index, len;

	len = _strlen(var);
	for (index = 0; environ[index] != NULL; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
		{
			return (environ[index]);
		}
	}

	return (NULL);
}

/**
 * locate - locates a command in PATH
 */
void locate(void)
{
	int i;
	char *token, *string, **input;
	char *path[] = {
		"/bin/",
		"/usr/bin/",
		"/usr/sbin/",
		"/sbin/",
		"/usr/local/bin/",
		"/usr/local/sbin/",
		NULL
	};

	string = retrieve_input();
	input = _tokenizer(string, " ");

	for (i = 0; path[i]; i++)
	{
		token = malloc(sizeof(_strlen(path[i])) + 1);
		if (!token)
			return;

		_strcpy(token, path[i]);

		token = _realloc(token, _strlen(token), _strlen(token) + _strlen(input[0]));
		if (!token)
			return;

		_strcat(token, input[0]);
		if (stat(token, &stats) == 0)
		{
			printf("%s\n", token);
			executor(token);
			exit(EXIT_SUCCESS);
		}
	}
	perror("stat");
	exit(EXIT_FAILURE);
}
