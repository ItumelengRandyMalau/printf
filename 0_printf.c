#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int print_c(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int _strlen(char *str);

/**
 * _printf - proto
 * @format: number
 * Return: unknown
*/

int _printf(const char *format, ...)
{
	va_list args;
	int total_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (int i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					total_chars += print_c(args);
					break;
				case 's':
					total_chars += print_string(args);
					break;
				case 'd':
				case 'i':
					total_chars += print_number(args);
					break;
				case '%':
					total_chars += write(1, "%", 1);
					break;
				default:
					total_chars += write(1, &format[i - 1], 2);
					break;
			}
		}
		else
		{
			total_chars += write(1, &format[i], 1);
		}
	}

	va_end(args);
	return (total_chars);
}

/**
 * print_c - proto
 * @args: number
 * Return: Unknown
*/

int print_c(va_list args)
{
	return (write(1, &(char){va_arg(args, int)}, 1));
}

/**
 * print_string - proto
 * @args: number
 * Return: Unknown
*/

int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	return (write(1, str ? str : "(null)", _strlen(str ? str : "(null)")));
}

/**
 * print_number - proto
 * @args: number
 * Return: Unknown
*/

int print_number(va_list args)
{
	int n = va_arg(args, int);
	char buffer[20];
	int i = 0, total_chars = 0;

	if (n == 0)
		return (write(1, "0", 1));

	if (n < 0)
	{
		total_chars += write(1, "-", 1);
		n = -n;
	}

	while (n > 0)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}

	while (--i >= 0)
	{
		total_chars += write(1, &buffer[i], 1);
	}

	return (total_chars);
}
