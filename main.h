#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_int(int num);
int print_conver(unsigned int n, char c);
void print_char_system(char c);
#endif
