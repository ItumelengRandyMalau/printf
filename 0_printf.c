#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int index, total_chars = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list arg_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buff_index++] = format[index];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &index);
			width = get_width(format, &index, arg_list);
			precision = get_precision(format, &index, arg_list);
			size = get_size(format, &index);
			++index;
			printed_chars = handle_print(format, &index, arg_list, buffer,
							flags, width, precision, size);
			if (printed_chars == -1)
				return (-1);
			total_chars += printed_chars;
		}
	}

	print_buffer(buffer, &buff_index);
	va_end(arg_list);

	return (total_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Char array
 * @buff_index: Index representing current length of buffer
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
