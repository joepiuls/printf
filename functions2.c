#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a ptr var
 * @types: list of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get the width
 * @precision: specification precision
 * @size: specifies the size
 * Return: Number of char printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, pdd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, pdd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pdd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, pdd, extra_c, pdd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non-printable chars
 * @types: List of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: specifies the size
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[i]))
			buffer[j + offset] = str[j];
		else
			offset += append_hexa_code(str[j], buffer, j + offset);

		j++;
	}

	buffer[j + offset] = '\0';

	return (write(1, buffer, j + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints a reverse str.
 * @types: list of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get the width
 * @precision: Precision specification
 * @size: specifies the size
 * Return: Numbers of char printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int k, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
		;

	for (k = k - 1; k >= 0; k--)
	{
		char z = str[k];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: specifies the size
 * Return: Numbers of char printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char l;
	char *str;
	unsigned int k, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[k])
			{
				l = out[j];
				write(1, &l, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			l = str[j];
			write(1, &l, 1);
			count++;
		}
	}
	return (count);
}


