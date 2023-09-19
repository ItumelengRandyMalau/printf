#include "main.h"
#include "selector.c"
#include "_putchar.c"

/**
 * _printf - prototype
 * 
 * @format: codes
 * @Return: returns
*/

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i;
    int ncount = 0;

    if (format == NULL)
    {
        return -1;
    }

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
        i++;
        if (format[i] == 'c' || format[i] == 'd' || format[i] == 's')
        {
            ncount += selector(format[i])(args);
        }
        else
        {
        ncount += _putchar('%');
        //ncount += _putchar(format[i]);
            continue;
        } 
        }
        else
        {
        ncount += _putchar(format[i]); 
        } 
    }

    return ncount;
}