#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted str in which to print the arg
 * @i: list of arguments to be printed.
 * @list: list of arg.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int j = *i + 1;
	int pres = -1;

	if (format[j] != '.')
		return (pres);

	pres = 0;

	for (j += 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			pres *= 10;
			pres += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			pres = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = j - 1;

	return (pres);
}

