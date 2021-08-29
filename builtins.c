#include "shell.h"

/**
 * hsh_exit - built in exit command
 */
void hsh_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * hsh_cd - builtin cd (change direcotry) command
 * @args: array of strings
 */
void hsh_cd(char **args)
{
	int status, i;
	size_t size = 0;
	char *current = NULL;

	for (i = 0; args[i];)
		++i;

	if (i > 2)
	{
		printf("1 I am the culpri\n");
		err_msg(args);
	}
	if (i == 1)
	{
		current = getcwd(current, size);
		chdir((const char *)current);
		free(current);
		return;
	}
	else
	{
		status = chdir(args[1]);
		if (status == -1)
		{
			err_msg(args);
		}
	}
}

/**
 * hsh_help - help command
 */
void hsh_help(void)
{
	char *helptext =
		"hsh - The following commands are availabe:\n"
		"      cd          Change the working directory.\n"
		"      exit        Exit the shell.\n"
		"      help        Print this help text.\n";
	printf("%s", helptext);
}

/**
 * fetch_builtin - function pointer
 * @args: parameter to function "fetch_builtin"
 *
 * Return: Calls a function
 */
void (*fetch_builtin(char *args))(void)
{
	int i;

	builtin_t builds[] = {
		{"help", hsh_help},
		{"exit", hsh_exit},
		{NULL, NULL}
	};

	i = 0;
	while (builds[i].member != NULL && builds[i].member != args)
		i++;

	return (builds[i].f);
}
