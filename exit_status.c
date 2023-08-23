#include "simple_shell.h"

/**
 * exit_status - Built-in function to exit the shell
 * @args: Arguments passed to the function
 * Authors: olive x lewis
 * Return: 0 if successful, 1 if there's an error
 */

int exit_status(char **args)
{
	int exit_code = 0;

	if (args[1] != NULL)
	{
		/*Converts second argument to an integer*/
		exit_code = atoi(args[1]);

		/*If conversion fails, print error message and return error code*/
		if (exit_code == 0 && args[1][0] != '0')
		{
			fprintf(stderr, "hsh: exit: %s: numeric argument required\n", args[1]);
			return (2);  /*Error code changed to 2*/
		}
	}

	exit(exit_code);
	return (0);
}

