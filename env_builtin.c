#include "simple_shell.h"

/**
 * env_builtin- is the main function
 * @args:terminates command line arguments to NULL
 * Authors: olive x lewis
 * Return: 1 on success 0 on failure
 */

int env_builtin(char **args)
{
	char **env = environ;

	if (args[1] == NULL)
	{
		/*prints enviroment variables*/
		while (*env != NULL)
		{
			size_t len = strlen(*env);

			write(STDOUT_FILENO, *env, len);
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
	return (1);
}
