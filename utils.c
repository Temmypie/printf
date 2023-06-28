#include "main.h"
/**
 * is_util - defines a character.
 * @c: character.
 * Return: 0.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return(0);
}
int append_hex_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEFG";
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
