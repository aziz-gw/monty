#include "monty.h"

/**
 * is_numeric - Checks if a string is numeric.
 * @str: String to be checked.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != '-')
			return (0);

		str++;
	}

	return (1);
}
