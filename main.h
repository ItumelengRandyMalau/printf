#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _putchar(char c);
int c_handler(va_list arg);
int d_handler(va_list arg);
int print_number(long num, int count);
int s_handler(va_list arg);
int (*selector(char str))(va_list arg);
int _printf(const char *format, ...);

#endif
