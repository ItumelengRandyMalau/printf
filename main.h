#ifndef PRINTF
#define PRINTF
#define UINT_MAX 4294967295
#define UNUSED(x) (void)(x)

/* macros that might be removed */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* for the normal specifiers */
int _putchar(char c);
int _printf(const char *format, ...);
int p_char(va_list c);
int p_decimal(va_list d);
int p_string(va_list s);
int p_binary(va_list b);
int p_unsigned_int(va_list u);
int p_octal(va_list o);
int p_x(va_list x);
int p_X(va_list X);
int p_rev(va_list r);
int print_rev(va_list r);
int print_rot13(va_list R);
int get_flags(const char *format, int *i);

/* the symbols */
int p_percentage(va_list symbol);

/**
 * print_format - Struct print_format
 *
 * @spec: the string specifier char
 * @func: the function associated
 */

typedef struct print_format
{
	char *spec;
	int (*func)(va_list str_arg);
} print_f;

#endif /* #ifndef PRINTF */
