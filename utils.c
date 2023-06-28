#include "main.h"
/**
 * is_printable - prints character.
 * @c: arguemrn
 * Return: 0.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hex_code - function
 * @ascii_code: argument
 * @buffer: argument arr
 * @i: argement
 * Return: 3. (success)
 */
int append_hex_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = ("0123456789ABCDEFG");

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - function
 * @c: argument
 * Return: 0.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
<<<<<<< HEAD
/**
 * convert_size_number - function
 * @num: argument
 * @size: argument
 * Return: num.
 */
long in convert_size_number(long int num, int size)
=======
long int convert_size_number(long int num, int size)
>>>>>>> 0ae1ce799ce1e93d108f64741c5b9aa8e34f488c
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
