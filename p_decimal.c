#include "main.h"

/**
 * p_decimal - prints in decimal integer format to stdout
 * @d: the integer
 *
 * Return: the number of times a character was printed
 */

int p_decimal(va_list d)
{
	int num, temp, units = 1, p_count = 0;

	num = va_arg(d, int);
	if (num < 0)
	{
		num *= -1;
		_putchar('-');
		p_count++;
	}
	temp = num;

	while (temp >= 10)
	{
		temp /= 10;
		units *= 10;
	}

	while (num != 0)
	{
		_putchar((num / units) + 48);
		p_count++;
		num %= units;
		units /= 10;
	}

	return (p_count);
}
