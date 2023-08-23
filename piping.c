#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * piping - pipes two commands
 * @args1:frist command
 * @args2:second command
 * return: 1 on success 0 on failure
 */
int piping(char **args1, char **args2)
{
	int pipefd[2];
	pid_t pid1, pid2;
	int status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (0);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		return (0);
	} else if (pid1 == 0)
	{       close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execvp(args1[0], args1);
		perror("execvp");
		_exit(EXIT_FAILURE);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		return (0);
	} else if (pid2 == 0)
	{       close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		execvp(args2[0], args2);
		perror("execvp");
		_exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status) == 0);
}
