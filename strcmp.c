#include "simple_shell.h"

/**
 * _strcmp - compares 2 strings
 * @s1: first string
 * @s2: second string
 * Authors: olive x lewis
 * Return: <, ==, > 0 if s1 is found
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
		return (*s1 - *s2);
}
