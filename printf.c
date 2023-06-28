#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * _printf - prints anything
 * @format: string format
 * Return: (Success)
 */
int _printf(char *format, ...)
{ 
	va_list list; int bi = 0, a = 0; char BUFF[BF_SIZE];
	char *ptr;
	int d = 0;

	va_start(list, format);

	for (a = 0; format[a] != '\0'; a++)
	{
	if (format[a] != '%')
	{
		if (format[a] != '\\')
		{	
		BUFF[bi] = format[a];
		}
		else
		{
			switch (format[a + 1])
			{
				case 'n':
					BUFF[bi] = '\n';
					break;
			}
		}
		bi++;

	}
	else
	{
		switch (format[a + 1])
		{
			case 's':
				ptr = va_arg(list, char *);

	
				while (ptr[d] != '\0')
				{
					BUFF[bi] = ptr[d];
					d++;
					bi++;
				}
		
				a = a + 1;
				break;

			case 'c':
				 BUFF[bi] = va_arg(list, int);

				 bi++;
				 a = a + 1;
				 break;
			case '%':
				 BUFF[bi] = '%';

				 bi++;
				 a = a + 1;
				 break;
			default:
				bi = -20;
				break;
		}
	}
	}
	va_end(list);

	if (bi < 0)
	{
	return (write(2, "error\n", 6));
	}
	else
	{

return (write(1, &BUFF, bi));
}
}
