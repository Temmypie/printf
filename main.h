#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS  */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - The Struct op
 *
 * @fmt: The format.
 * @fn: The associated funtion.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * struct fmt_t - The Struct op
 *
 * @fmt: The format.
 * @fm_t: The associated function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, char buffer[], int flags, int width, int precision, int size);

/* Funtions for printing chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_perc(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions for printing numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsi(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function for non printable characters */
int print_non_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion for printing memory */
int print_point(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functionns for other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function for string in reverse*/
int print_reve(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*for string in rot 13*/
int print_ro13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* For width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char pad, char ext_ch);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char pad, char ext_ch, int pad_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
