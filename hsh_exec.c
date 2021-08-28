#include "shell.h"

/**
 * hsh_exec - executs our shell
 * @token: path to command
 * @args: array of strings of comand to execute with args
 *
 * Return: status
 */
int hsh_exec(char *token, char **args)
{
	if (access(token, F_OK) == 0)
	{
		pid_t child_pid = fork();

		if (child_pid == 0)
		{
			execve(token, args, environ);
			perror("hsh");
			exit(-1);
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
			return (-1);
		}
	}
	else
	{
		perror("hsh");
		return (-1);
	}
	return (0);
}
