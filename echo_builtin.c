#include "simple_shell.h"

/**
 * echo_builtin - Prints arguments to standard output.
 * @args: Array of arguments.
 * authors: olive x lewis
 * Return: Always returns 1 to continue.
 */

int echo_builtin(char **args)
{
	int i = 1;
	char pid_str[20];
	int pid_len;

	while (args[i] != NULL)
	{
		if (strcmp(args[i], "$$") == 0)
		{
			char pid_str[20];
			int pid_len = sprintf(pid_str, "%d", getpid());/*Converts PID to a string*/
			/*Writes PID to std out*/
			write(STDOUT_FILENO, pid_str, pid_len);

		}
		else
		{
			write(STDOUT_FILENO, args[i], strlen(args[i]));
			/*Writes args to standard output*/
		}

		if (args[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);/*Adds a space between args*/

		i++;
	}

	write(STDOUT_FILENO, "\n", 1);/*Appends a newline character*/
	return (1);
}
