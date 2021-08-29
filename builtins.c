#include "shell.h"

/**
 * hsh_exit - built in exit command
 *
 * Return: status
 */
int hsh_exit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
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
 *
 * Return: Retuns status code
 */
int hsh_help(void)
{
	char *helptext =
		"hsh - The following commands are availabe:\n"
		"      cd          Change the working directory.\n"
		"      exit        Exit the shell.\n"
		"      help        Print this help text.\n";
	printf("%s", helptext);
	return (0);
}

/**
 * fetch_builtin - gets the right function to run
 * @args: argument content command
 */
void fetch_builtin(char *args)
{
	if (_strcmp(args, "exit") == 0)
		hsh_exit();
	if (_strcmp(args, "help") == 0)
		hsh_help();
	if (args[0] == EOF || args[0] == -1)
		hsh_exit();
}
