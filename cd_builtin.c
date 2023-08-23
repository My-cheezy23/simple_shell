#include "simple_shell.h"

/**
 * cd_builtin - Change the current working directory
 * @args: Array of arguments including the command and path
 * Authors: olive x lewis
 * Return: 1 on success, 0 on failure
 */

int cd_builtin(char **args)
{
	char *new_dir = getcwd(NULL, 0);
	char *prev_dir = getenv("OLDPWD");

	if (!args[1])
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
		}
	}
	else if	(_strcmp(args[1], "-") == 0)
	{
		if (!prev_dir)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
		}
		else if	(chdir(prev_dir) != 0)
		{
			perror("cd");
		}
	else
		{
			printf("%s\n", prev_dir);
		}
	}
	else if (chdir(args[1]) != 0)
	{
		perror("cd");
	}
	if (!new_dir)
	{
		panic("getcwd failed");
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", new_dir, 1);
	free(new_dir);
	return (1);
}
