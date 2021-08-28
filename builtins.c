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
		perror("cd");
		return;
	}
	if (i == 1)
	{
		current = getcwd(current, size);
		chdir((const char *)current);
		free(current);
		return;
	}

	status = chdir(args[1]);
	if (status == -1)
	{
		perror("hsh: cd");
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
