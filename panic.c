#include "simple_shell.h"

/**
 * panic - Displays an error message
 * and terminates the program.
 * @message: The error message to be displayed.
 * Authors: olive x lewis
 */

void panic(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

