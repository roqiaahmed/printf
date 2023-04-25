#include "main.h"
/**
 * print_char_system - print character
 * @c: the input
 * Return: no return value
 */

int _write_char(char c)
{
return (write(1, &c, 1));
}

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _write_char('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_int - Prints an integer
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_int(va_list list)
{
	int num_length;

	num_length = print_number(list);
	return (num_length);
}


/**
 * print_int - function for printing intgers
 * @num: the input number
 * @c: the format
 * Return: the number of intgers printed
 */
// int print_int(int num, char c)
// {
// char buffer[12];
// int i = 0;
// int is_negative = 0;
// int num_chars_printed;

// /* Check if the number is negative*/
// if (num < 0 && c != 'u')
// {
// is_negative = 1;
// num = -num;
// }
// if (num < 0 && c == 'u')
// num = -num;
// /* Convert the integer to a string in reverse order*/
// do {
// buffer[i++] = '0' + num % 10;
// num /= 10;
// } while (num > 0);
// /* Add a '-' sign if the number is negative*/
// if (is_negative)
// {
// buffer[i++] = '-';
// }
// num_chars_printed = i - 1;
// while (i > 0)
// {
// print_char_system(buffer[--i]);
// }
// return (num_chars_printed);
// }
