#include "main.h"
#include "_putchar.c"

int print_number(long num, int count)
{
    if (num < 0)
    {
        _putchar('-');
        count++;
        num = num * -1;
    }
    if (num/10)
    {
    count = print_number(num/10, count);
    }
    _putchar(num%10 + '0');
    return (count + 1);
}