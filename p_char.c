#include "main.h"

/**
 * p_char - prints to stdout in char format
 * @c: va_list pointer
 *
 * Return: 1 (the number of times p_char prints)
 */

int p_char(va_list c)
{
	unsigned char ch;

	ch = va_arg(c, int);
	_putchar(ch);
	return (1);
}

int p_percentage(va_list symbol)
{
	int p_count = 0;

	UNUSED(symbol);

	_putchar('%');
	p_count++;

	return (p_count);
}
