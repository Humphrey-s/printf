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
	char c;

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

				if (ptr == NULL || ptr[0] == '\0')
				{
					BUFF[0] = '\0';
				}
				else
				{
				while (ptr[d] != '\0')
				{
					BUFF[bi] = ptr[d];
					d++;
					bi++;
				}
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
				write(1, &c, 1);
		}
	}
	}
	va_end(list);

	if (BUFF[0] == '\0')
	{
	return (write(1,"", 1));
	}
	else
	{

return (write(1, &BUFF, bi));
}
}
