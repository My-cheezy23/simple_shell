#include "simple_shell.h"

/**
 * prompt - Displays the user-friendly shell prompt.
 * Authors: olive x lewis
 */

void prompt(void)
{
	char *prompt_message = "$";
	/*Updated prompt message for clarity*/

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt_message, strlen(prompt_message));
		fflush(stdout);
	}
}

