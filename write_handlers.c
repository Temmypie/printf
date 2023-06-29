#include "main.h"
/**
 * handle_writes - ouputs a string
 * @size: size
 * @width: width
 * @buffer: arrays that handle prints
 * Return: 0.
 */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
	int m = 0;
	char pad = '';
	UNUSED(prec);
	UNUSED(size);
	if (flags & F_ZERO)
		pad  '0';
	buffer[m] = c;
	buffer[m] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; m < width - 1; m++)
			buffer[BUFF_SIZE - m - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - m - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char pad = ' ', ext_char = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_negative)
		ext_char = '-';
	else if (flags & F_PLUS)
		ext_char = '+';
	else if (flags & F_SPACE)
		ext_char = ' ';

	return (write_num(ind, buffer, flags, width, precision,	length, pad, ext_char));
}
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c)
{
	int i, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (ext_ch != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (ext_ch)
				buffer[--ind] = ext_ch;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (ext_ch)
				buffer[--ind] = ext_ch;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (ext_ch)
				buffer[--pad_start] = ext_ch;
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (ext_ch)
		buffer[--ind] = ext_ch;
	return (write(1, &buffer[ind], length));
}


