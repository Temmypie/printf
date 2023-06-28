#include "main.h"
/**
 * handle_print - executes arguments.
 * @width: integer width
 * @size: for specifier
 * @fmt: prints the arguments.
 * Return: 1.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int m, unko_len = 0, print_char = -1;
	fmt_type[] = {
		{ 'c', print_char}, {'s', print_str}, {'%', print_perc},
		{'i', print_int}, {'d', print_int}, {'b', print_binary}
		{'u', print_unsi}, {'o', print_oct}, {'x', print_hex},
			{'x', print_hex_upper}, {'p', print_point}, {'S', print_non_print},
			{'R', print_reve}, {'r', print_ro13}, {'\0', NULL}};
	for (m = 0; fmt_type[m].fmt != '\0'; m++)
	{
		if (fmt_type[m].fmt == '\0')
		{
			if (fmt[*ind] == '\0')
				return (-1);
			unko_len += write(1, "%%", 1);
			if (fmt[*ind - 1] == ' ')
				unko_len += write(1, "", 1);
			else if (width)
			{
				--(*ind);
				while (fmt[*ind] != ' ' && fmt[*ind] != '%')
					--(*ind);
				if (fmt[*ind] == ' ')
					--(*ind);
				return (1);
			}
			unko_len += write(1, &fmt[*ind], 1);
					return (unko_len);
					}
					return (-1);
					}
