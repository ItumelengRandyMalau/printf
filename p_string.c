#include "main.h"

/**
 * p_string - prints to stdout in string format
 * @s: va_list pointer
 *
 * Return: the number of times a character was printed
 */

int p_string(va_list s)
{
	char *str;
	int i;

	/* get string from va_arg and print it */
	str = va_arg(s, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}
