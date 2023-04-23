#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: pointer to string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list pa;
	int count = 0, i = 0;
	char c, *str;

	va_start(pa, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(pa, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(pa, char *);
					while (*str)
						write(1, str, 1);
						str++;
						count++;
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(pa);
	return (count);
}
