#include "main.h"
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
if (format == NULL)
return (-1);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = (char) va_arg(list, int);
write(1, &c, sizeof(char));
count++;
}
else if (*format == 's')
{
char *s = va_arg(list, char *);
int len = 0;
while (s[len] != '\0')
len++;
write(1, s, len);
count += len;
}
else if (*format == '%')
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
