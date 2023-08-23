#include "simple_shell.h"
/**
 * launch- launches a new process
 * @args: an array of strings
 * return: 1 on success -1 on failure
 */
int launch(char **args)
{
	char **environ = NULL;
	pid_t pid = fork();
	int status;

	if (_strcmp(args[0], "exit") == 0)
		return (exit_status(args));
	if (pid == 0)
	{
		char *path = getenv("PATH");
		char *dir = strtok(path, ";");

		while (dir != NULL)
		{
			char *command_path = malloc(strlen(dir) + strlen(args[0]) + 2);

			sprintf(command_path, "%s/%s", dir, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				args[0] = command_path;
				break;
			}
			free(command_path);
			dir = strtok(NULL, ";");
		}
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	return (1);
}
