#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_int(int num);
int print_conver(unsigned int n, int base);
int _putchar(char c);
#endif
