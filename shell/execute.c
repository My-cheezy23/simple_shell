#include "simple_shell.h"
/**
 * execute - executes a coomand
 * @args: array of arguments
 * return: 1 on success 0 on failure
 */
int execute(char **args)
{
	char **args1 = args;
	char **args2 = NULL;
	int i;

	if (args[0] != NULL)
	{
		return (1);
	}
	for (i = 0; args[i] != NULL; i++)
	{
		if (_strcmp(args[i], "|") == 0)
		{
			args[i] = NULL;
			args2 = &args[i + 1];
			break;
		}
	}
	if (args2 != NULL)
	{
		return (piping(args1, args2));
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		return (cd_builtin(args));
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		return (echo_builtin(args));
	}
	else if (strcmp(args[0], "env") == 0)
	{
		return (env_builtin(args));
	}
	else
	{
		return (launch(args));
	}
}
