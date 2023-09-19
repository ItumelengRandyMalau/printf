#include "main.h"

int (*get_func(const char *spec))(va_list str_arg);

/**
 * _printf - gives output according to a specified format
 * @format: a string along with specifiers (char, string)
 *
 * Return: the number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list va;
	unsigned int i, p_count = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(va, format);
	for (i = 0; format[i]; i++)
	{
		/* printing formatted part of string */
		if (format[i] == '%')
		{
			func = get_func(&format[i + 1]);
			if (func)
			{
				p_count += func(va);
				i += 2;
			}
		}
		if (format[i] == '\0')
			return (p_count);

		/* printing other characters */
		if (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			p_count++;
		}
		else
		{
			--i;
			continue;
		}
	}
	va_end(va);
	return (p_count);
}

/**
 * get_func - gets the correct function according to the provided specifier
 * @spec: the string specifier
 *
 * Return: pointer to the needed print function
 */

int (*get_func(const char *spec)) (va_list)
{
	print_f formats[] = {
		{"c", p_char},
		{"s", p_string},
		{"d", p_decimal},
		{"b", p_binary},
		{"u", p_unsigned_int},
		{"o", p_octal},
		/*{"x", p_x},*/
		/*{"X", p_X},*/
		{"r", print_rev},
		{"R", print_rot13},
		{"%", p_percentage},
		{NULL, NULL}
	};
	int i = 0;

	/* return the function for required print format */
	while (formats[i].spec)
	{
		if (formats[i].spec[0] == spec[0])
			return (formats[i].func);

		i++;
	}
	return (NULL);
}
