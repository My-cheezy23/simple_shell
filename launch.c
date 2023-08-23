#include "simple_shell.h"

/**
 * launch - Launches a new process to execute a given command.
 * @args: Null-terminated array of strings
 * representing command and its arguments.
 * Authors: olive x lewis
 * Return: 1 on success, -1 on failure
 */

int launch(char **args)
{
	pid_t pid = fork();
	int status;

	if (_strcmp(args[0], "exit") == 0)
		return (exit_status(args));

	if (pid == 0)
	{    /*Child process*/
		char *path = getenv("PATH");   /*Search for the command in PATH*/
		char *dir = strtok(path, ":");

		while (dir)
		{
			char *cmd_path = malloc(strlen(dir) + strlen(args[0]) + 2);

			sprintf(cmd_path, "%s/%s", dir, args[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				args[0] = cmd_path;  /*Command found in this directory*/
				break;
			}
			free(cmd_path);
			dir = strtok(NULL, ":");
		}
		if (execve(args[0], args, NULL) == -1)  /*Execute the command*/
		{
			perror("execve");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork");  /*Fork error*/
	else
	{
		do {  /*Parent process*/
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

