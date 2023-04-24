#include "main.h"
/**
 * print_char - prints a character to stdout
 * @list: a va_list of arguments
 *
 * Return: the number of characters printed
 */
int print_char(va_list list)
{
char c = (char)va_arg(list, int);
write(1, &c, sizeof(char));
return (1);
}
/**
 * print_string - prints a string to stdout
 * @list: a va_list of arguments
 *
 * Return: the number of characters printed
 */
int print_string(va_list list)
{
char *s = va_arg(list, char *);
if (s == NULL)
{
write(1, "(null)", 6);
return (6);
}
else
{
int len = 0;
while (s[len] != '\0')
len++;
write(1, s, len);
return (len);
}
}
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list list;
va_start(list, format);
if (format == NULL || (format[0] == '%' && !format[1])
		|| (format[0] == '%' && format[1] == ' ' && !format[2]))
return (-1);
while (*format != '\0')
{
if (format[0] == '%')
{
format++;
if (format[0] == 'c')
count += print_char(list);
else if (format[0] == 's')
count += print_string(list);
else if (format[0] == 'd' || format[0] == 'i' || format[0] == 'u')
count += print_int(va_arg(list, int), format[0]);
else if (format[0] == 'b' || format[0] == 'o' || format[0] == 'x'
		|| format[0] == 'X')
count += print_conver(va_arg(list, unsigned int), *format);
else if (format[0] == ' ')
	return (-1);
else if (format[0] == '%')
{
char c = '%';
write(1, &c, sizeof(char));
count++;
}
}
else
{
write(1, format, sizeof(char));
count++;
}
format++;
}
va_end(list);
return (count);
}
