#include <simple_shell.h>

/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * a simple shell program that can be used to execute commands
 * The two modes are: file input mode and interactive mode
 * * Authors: olive x lewis
 * Return: EXIT_SUCCESS upon successful execution
 */

int main(int argc, char **argv)
{
	char *command_line;
	char **command_tokens;
	int execution_status;

	/* Check if file input mode is enabled */
	if (argc > 1)
	{
		/* Execute commands from a file */
		file_input(argv[1]);
		return (EXIT_SUCCESS);
	}

	/* Enter interactive shell mode */
	do {
		/* Display the command prompt */
		prompt();

		/* Read the command from the user */
		command_line = read_line();

		/* Parse the command into tokens */
		command_tokens = parse_line(command_line);

		/* Execute the command */
		execution_status = execute(command_tokens);

		/* Free memory allocated for the command */
		free(command_line);
		free(command_tokens);
	} while (execution_status);

	return (EXIT_SUCCESS);
}

