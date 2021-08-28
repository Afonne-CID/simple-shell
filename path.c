#include "shell.h"

/**
 * _getenv - gets $PATH
 * @var: passed environ variable
 *
 * Return: Double pointer to variable path
 */
char **_getenv(const char *var)
{
	int index, len;

	len = _strlen(var);
	for (index = 0; environ[index] != NULL; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
		{
			return (&environ[index]);
		}
	}

	return (NULL);
}


/**
 * locate - locates path of the input command and calls hsh_exec
 *
 * Return: 0 on success, -1 otherwise
 */
int locate(void)
{
	int i;
	char *string, *token, *input, **inputs;
	char *path[] = {"/usr/bin/", "/usr/sbin/", "/usr/local/bin/",
		"/usr/local/sbin/", NULL};
	string = retrieve_input();
	if (!string || (_strcmp(string, "\n") == 0) || *string == 9 || (_strcmp(string, "\r") == 0) || *string == ' ')
	{
		free(string);
		return (0);
	}
	inputs = _tokenizer(string, " \t\n\r");
	input = strtok(string, " ");

	if (_strcmp(inputs[0], "cd") == 0)
		hsh_cd(inputs);
	if (_strcmp(inputs[0], "help") == 0)
		hsh_help();
	if (_strcmp(inputs[0], "exit") == 0)
		hsh_exit();
	if (inputs[0][0] == EOF)
		hsh_exit();

	for (i = 0; path[i]; i++)
	{
		token = malloc(sizeof(_strlen(path[i])) + 1);
		if (!token)
			return (-1);
		_strcpy(token, path[i]);
		token = _realloc(token, _strlen(token), _strlen(token) + _strlen(input));
		if (!token)
		{
			free(token);
			return (-1);
		}
		_strcat(token, input);
		hsh_exec(token, inputs);
		return (0);
	}
	return (0);
}
