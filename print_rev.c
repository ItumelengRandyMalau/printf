#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
  * print_rev - prints the dtring reverse
  * @r: the string to be printed
  * Return: character to be printed
  */
int print_rev(va_list r)
{
	char *snt;
	int i, j;

	snt = va_arg(r, char *);
	if (snt == NULL)
		snt = ")llun(";
	for (i = 0; snt[i] != '\0'; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(snt[i]);
		j++;
	}
	return (j);
}
