#include <stdio.h>
#include <stdlib.h>
/**
 * read_line - is the main function
 * description: reads a line from stdin and stores it in buffer
 * return:pointer to the line read
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buffer_size = 0;

	/*get line from stdin*/
	if (getline(&line, &buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			panic("read_line failed");
		}
	}
	return (line);
}
