#include "main.h"
/**
 * print_char_system - print character
 * @c: the input
 * Return: no return value
 */

void print_char_system(char c)
{
write(1, &c, sizeof(char));
}

/**
 * print_int - function for printing intgers
 * @num: the input number
 * Return: the number of intgers printed
 */
int print_int(int num)
{
char buffer[12];
int i = 0;
int is_negative = 0;
int num_chars_printed;

/* Check if the number is negative*/
if (num < 0)
{
is_negative = 1;
num = -num;
}
/* Convert the integer to a string in reverse order*/
do {
buffer[i++] = '0' + num % 10;
num /= 10;
} while (num > 0);
/* Add a '-' sign if the number is negative*/
if (is_negative)
{
buffer[i++] = '-';
}
num_chars_printed = i - 1;
while (i > 0)
{
print_char_system(buffer[--i]);
}
return (num_chars_printed);
}
