#include "simple_shell.h"

/**
 * my_getline - Reads an entire line from a stream
 * and dynamically allocates memory.
 * @lineptr: Pointer to a buffer that will hold the read line.
 * @n: Pointer to the size of the buffer.
 * @stream: Pointer to the stream to read from.
 * Authors: olive x lewis
 * Return: Number of characters read, or -1 if an error occurred.
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = NULL;
	size_t buffer_size = 0;
	ssize_t chars_read = 0;
	int current_char;
	char *new_buffer;
	/* Check if input pointers are valid */
	if (!lineptr || !n || !stream)
	{
		errno = EINVAL;
		return (-1);
	}
	while ((current_char = getc(stream)) != EOF)
	{
		/* Expand the buffer if needed */
		if (buffer_size <= (size_t)chars_read + 1)
		{
			buffer_size = (buffer_size + 1) * 2;
			new_buffer = realloc(line, buffer_size);
			if (!new_buffer)
			{
				free(line);
				return (-1);
			}
			line = new_buffer;
		}
		line[chars_read++] = current_char;
		/* Break loop on encountering a newline character */
		if (current_char == '\n')
			break;
	}
	/* Handle case of no characters read */
	if (chars_read == 0)
	{
		free(line);
		return (-1);
	}
	line[chars_read] = '\0';
	*lineptr = line;
	*n = buffer_size;
	return (chars_read);
}

