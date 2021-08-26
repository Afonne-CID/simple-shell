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


/*
 * locate - locates path
 *
 * Return: 0 on success, -1 otherwise
 */
int locate(void)
{
	int i;
	char *token, *string, *input, **inputs;
	char *path[] = {"/bin/", "/usr/bin/", "/usr/sbin/", "/sbin/",
		"/usr/local/bin/", "/usr/local/sbin/", NULL};
	string = retrieve_input();
	input = strtok(string, " ");
	inputs = _tokenizer(string, " \t\n\r");

	for (i = 0; path[i]; i++)
	{
		token = malloc(sizeof(_strlen(path[i])) + 1);
		if (!token)
		{
			free(string);
			return (-1);
		}
		_strcpy(token, path[i]);
		token = _realloc(token, _strlen(token), _strlen(token) + _strlen(input));
		if (!token)
		{
			free(string);
			free(token);
			return (-1);
		}
		_strcat(token, input);
		if (access(token, F_OK) == 0)
		{
			pid_t child_pid = fork();

			if (child_pid == 0)
			{
				execve(token, inputs, environ);
				perror("hsh");
				free(string);
				free(token);
				exit(1);
			}
			else if (child_pid > 0)
			{
				int status;

				do {
					waitpid(child_pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
			else
			{
				free(string);
				free(token);
				perror("hsh");
			}
			return (0);
		}
		free(string);
		free(token);
	}
	perror("hsh");
	return (-1);
}
