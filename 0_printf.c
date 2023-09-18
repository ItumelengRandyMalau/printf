#include "main.h"
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format.
 * @format: character string(input).
 * Return: number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
	#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int charsto_print = 0;
	va_list num_args;

	if (format == null)
		return (-1);

	va_list (num_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			charsto_print++;
		}
		else
		{
			format++;
		if (*format == '\0')
			break;
		if (*format == '%')
		{
			write(1, format, 1);
			charsto_print++;
		}
		else if (*format == 'c')
		{
			char cc = va_arg(num_args, int);

			write(1, &cc, 1);
			charsto_print++;
		}
		else if (*format == 's')
		{
			char *ptr = va_arg(num_args, char*);
			int str_len = 0;

			while (ptr[str_len] != '\0')
				str_len++;
			write(1, ptr, str_len);
			charsto_print += str_len;
		}
	}
	format++;
}
va_end(num_args);
return (charsto_print);
