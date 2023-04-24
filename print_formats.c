#include "main.h"
/**
 * print_conver - Prints an integer to stdout using the write system call.
 * @n: The integer to print.
 * @c: The format specifier
 * Return: The number of characters printed.
 */
int print_conver(unsigned int n, char c)
{
char *digits = "0123456789abcdef";
char buff[100];
int count = 0;
int i = 0;
int base;
switch (c)
{
case 'b':
base = 2;
break;
case 'o':
base = 8;
break;
case 'x':
base = 16;
break;
case 'X':
digits = "0123456789ABCDEF";
base = 16;
break;
}
if (n == 0)
{
print_char_system('0');
count++;
return (count);
}
while (n > 0)
{
buff[i++] = digits[n % base];
n /= base;
}
while (--i >= 0)
{
print_char_system(buff[i]);
count++;
}
return (count);
}
