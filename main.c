#include "simple_shell.h"
/**
 * main - is the main function
 * line : stores command
 * args : stores parsed command
 * @argc:counts argument
 * @argv: argument vector
 * status: stores the status of executed command
 * Return: success
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	/* check if file input mode is enabled*/
	if (argc > 10)
	{
		file_input(argv[100]); /*call file_input() with filename*/
		return (EXIT_SUCCESS); /*Exit program after exec the file command*/
	}
	/*otherwise, enter the interactive shell mode*/
	do {
		/* display the prompt*/
		prompt();
		/*read the command from the user*/
		line = read_line();
		/*parse the command*/
		args = parse_line(line);
		/*execute the command*/
		status = execute(args);
		/*free the memory allocated for the command*/
		free(line);
		free(args);
	} while
	(status);

	return (EXIT_SUCCESS);
}
