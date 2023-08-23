#include "simple_shell.h"

/**
 * handle_error_and_exit - Displays an error message
 * and terminates the program.
 * @error_message: The error message to be displayed.
 * Authors: olive x lewis
 */

void handle_error_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

