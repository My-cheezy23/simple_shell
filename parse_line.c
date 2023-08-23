#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * parse_line - is the main function
 * @line: line of input
 * return: an array of token, NULL on error
 */
char **parse_line(char *line)
{
	int buffer_size = BUFFER_SIZE;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		panic("parse_line failed: allocaton error");
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[position] = token;
		position++;
		if (position >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			token = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				panic("parse_line failed: allocation error");
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
