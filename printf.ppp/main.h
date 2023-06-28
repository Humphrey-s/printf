#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

#define BF_SIZE 1024




int _printf(char *format, ...);
void put_char(char buff[], va_list list, int **bi, int **a);
void _switch(char buff[], char *fmt, va_list list, int *bi, int *a);

typedef struct char_type {

	char p;
	
	int (*f)(char BUFF[], char *fmt, int *b, va_list list);
} d_type;

int string_print(char BUFF[], char *fmt, int *b, va_list);
int char_print(char BUFF[], char *fmt, int *b, va_list list);
int percent_print(char BUFF[], char *fmt, int *b, va_list list);

int (*_fmorg(char c))(char BUFF[], char *fmt, int *b, va_list);
#endif
