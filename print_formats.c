#include "main.h"
/**
 * _putchar - Writes a character to stdout using the write system call.
 * @c: The character to write.
 * Return: 1 on success, -1 on failure.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_int - Prints an integer to stdout using the write system call.
 * @n: The integer to print.
 * @base: The base for conversion (e.g., 10 for decimal, 16 for hexadecimal, etc.).
 * Return: The number of characters printed.
 */
int print_conver(unsigned int n, int base)
{
	char digits[] = "0123456789ABCDEF";
	char buffer[100];
	int count = 0;
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	while (n > 0)
	{
		buffer[i++] = digits[n % base];
		n /= base;
	}

	while (--i >= 0)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}
