#include "main.h"

/**
 * p_binary - prints binary to stdout, coverted from an unsigned int.
 * @b: the unsigned integer
 *
 * Return: the number of characters printed
 */

int p_binary(va_list b)
{
	unsigned int bin, num;
	unsigned int b_list[100];
	int i, len, p_count = 0;

	bin = va_arg(b, unsigned int);
	num = bin;

	/* getting the number of digits */
	for (len = 0; num != 0; num /= 2)
		len++;

/*	better memory management */
/*	b_list[] = malloc(len * sizeof(int));*/

	/* adding binary conversion backwards into b_list array */
	i = len - 1;
	while (bin != 0)
	{
		b_list[i] = bin % 2;
		bin /= 2;
		i--;
	}

	for (i = 0; i < len; i++)
	{
		_putchar(b_list[i] + 48);
		p_count++;
	}

	return (p_count);
}
