#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: formatted str in which to print the arguments
 * @i: take's a parameter.
 * Return: flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, k;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[k] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = k - 1;

	return (flags);
}

