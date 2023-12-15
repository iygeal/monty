#include "monty.h"

/**
 * is_numeric - Checks if a string is a numeric value
 * @str: The string to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

