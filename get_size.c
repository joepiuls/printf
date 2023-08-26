#include "main.h"

/**
 * get_size - calculate the size to cast the argument
 * @format: formatted str in which to print the arguments
 * @i: list of arg to be printed.
 *
 * Return: precision.
 */
int get_size(const char *format, int *i)
{
	int j = *i + 1;
	int size = 0;

	if (format[j] == 'l')
		size = S_LONG;
	else if (format[j] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = j - 1;
	else
		*i = j;

	return (size);
}




