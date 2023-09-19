#include "main.h"
#include "handler.c"
/**
 * selector - prototype
 *
 * @str: string
 * Return: returns
 */

int (*selector(char str))(va_list arg)
{
	if (str == 'c')
	{
		return (&c_handler);
	}
	else if (str == 'd')
	{
		return (&d_handler);
	}
	else if (str == 's')
	{
		return (&s_handler);
	}
	return (0);
}
