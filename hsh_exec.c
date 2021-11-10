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
	pid_t child_pid;
	int status;

	if (access(token, X_OK) == 0)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			if ((execve(token, args, environ) == -1))
			{
				err_msg(args);
				exit(-1);
			}
		}
		else if (child_pid > 0)
		{

			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		else
		{
			err_msg(args);
			return (-1);
		}
	}
	else
	{
		err_msg(args);
		return (-1);
	}
	return (0);
}
