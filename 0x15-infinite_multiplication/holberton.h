#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <stdio.h>

int lenth(char *str);
char *create_xarray(int size);
char *zeroes_num(char *str);
int convert_digit(char c);
void get_prod(char *prod, char *mult, int digit, int zeroes);
void add_nums(char *final_prod, char *next_prod, int next_len);
int _putchar(char c);


#endif
