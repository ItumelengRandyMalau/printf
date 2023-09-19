#include "main.h"

/**
 * c_handler - prototype
 * 
 * @arg: codes
 * Return: returns
*/

int c_handler(va_list arg)
{
	int count;
	char get_char = va_arg(arg, int);
	count = _putchar(get_char);

	return (count);
}

/**
 * d_handler - prototype
 *
 * @arg: codes
 * Return: returns
*/

int d_handler(va_list arg)
{
	int count;
	int val = va_arg(arg, int);
	count = print_number(val, 0);

	return (count);
}

/**
 * s_handler - prototype
 *
 * @arg: codes
 * Return: returns
*/

int s_handler(va_list arg)
{
	int count = 0;
	char *ptr = va_arg(arg, char *);

	if (ptr == NULL)
	{
		ptr = "(null)";
	}

	while (*ptr)
	{
		count += _putchar(*ptr);
		ptr++;
	}

	return (count);
}
