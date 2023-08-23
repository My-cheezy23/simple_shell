#include "simple_shell.h"

/**
 * file_input - Read and execute commands from a file.
 * @filename: The name of the file to read.
 * Authors: olive x lewis
 * Return: 0 on success, 1 on failure.
 */

int file_input(char *filename)
{
	FILE *file_pointer = fopen(filename, "r");
	char *line = NULL;
	size_t buffer_size = 0;
	int status = 0;

	if (file_pointer == NULL)
	{
		perror("file_input");
		return (1);
	}

	while (my_getline(&line, &buffer_size, file_pointer) != -1)
	{
		char **args = parse_line(line);

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				status = exit_status(args);

			}
			else
			{
				status = execute(args);
			}
		}
		free(args);
		if (status != 0)
		{
			break;
		}
	}
	free(line);
	fclose(file_pointer);
	return (status);
}
