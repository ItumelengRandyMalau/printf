#include "main.h"

/**
 * print_rot13 - makes a string into rot13.
 * @R: string to convert
 * Return: size of the output
 */
int print_rot13(va_list R)
{
	int a, b, count = 0;
	char *r;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	r = va_arg(R, char *);
	if (r == NULL)
		r = "(null)";
	for (a = 0; r[a] != '\0'; a++)
	{
		for (b = 0; input[b] != '\0'; b++)
		{
			if (r[a] == input[b])
			{
				_putchar(output[b]);
				count++;
				break;
			}
		}
	}
	return (count);
}
