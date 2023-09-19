#include "main.h"

/**
 * p_octal - prints in octal format to stdout,
 * coverted from a decimal integer.
 * @b: the integer
 *
 * Return: the number of characters printed
 */

int p_octal(va_list o)
{
	unsigned int oct, num;
	unsigned int o_list[100];
	int i, len, p_count = 0;

	oct = va_arg(o, unsigned int);
	num = oct;

	/* getting the number of digits */
	for (len = 0; num != 0; num /= 8)
		len++;

/*	better memory management */
/*	b_list[] = malloc(len * sizeof(int));*/

	/* adding binary conversion backwards into b_list array */
	i = len - 1;
	while (oct != 0)
	{
		o_list[i] = oct % 8;
		oct /= 8;
		i--;
	}

	for (i = 0; i < len; i++)
	{
		_putchar(o_list[i] + 48);
		p_count++;
	}

	return (p_count);
}
