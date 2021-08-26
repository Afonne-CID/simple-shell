#include "shell.h"

/**
 * executor - executes our shell ("hsh")
 * @token: the path of our command
 */
void executor(char *token)
{
	char *string = retrieve_input();
	char **inputs = _tokenizer(string, " ");
	pid_t child_pid = fork();
	char *path[] = {"/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin"};


	if (child_pid == 0)
	{
		execve(token, inputs, path);
		perror("hsh");
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
		perror("hsh");
	}
}
