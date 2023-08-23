#include "simple_shell.h"

/*
 * parse_line - Parses a line into an array of tokens.
 * @line: line of input
 * Authors: olive x lewis
 * Return: an array of token, NULL on error
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
	token = strtok(line, TOKEN_DELIM);
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
