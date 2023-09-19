#include "main.h"

/**
 * powten - calculates the number of units according to the number's digits
 * @power: the digits of number
 *
 * Return: the units in tens
 */

int units(int power)
{
	int i, result = 1;

	for (i = 1; i < power; i++)
		result *= 10;

	return (result);
}

/**
 * p_unsigned_int - prints in an unsigned(positive) integer format to stdout,
 * coverted from a decimal integer.
 * @b: the integer
 *
 * Return: the number of characters printed
 */

int p_unsigned_int(va_list ui)
{
	int unsig, num;
	int quotient = 1, len = 0, p_count = 0;

	unsig = va_arg(ui, int);
	num = unsig;

	if (num < 0)
		num = UINT_MAX - num;

	/* getting number of digits */
	for ( ; num != 0; num /= 10)
		len++;

	num = unsig;
	if (num < 0)
		num = UINT_MAX - num;
	/* returns the number of times for division of number */
	quotient = units(len);

	while (num != 0)
	{
		_putchar((num / quotient) + 48);
		num %= quotient;
		quotient /= 10;
		p_count++;
	}
	return (p_count);
}
