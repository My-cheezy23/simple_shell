#include "simple_shell.h"

/**
 * string_length - Calculates the length of a given string.
 * @str: The input string.
 * Return: The length of the string.
 * Authors: olive x lewis
 */

size_t string_length(const char *str)
{
	size_t length = 0;

	while (str && *str)
	{
		length++;
		str++;
	}

	return (length);
}

