#include "main.h"
#include <stdarg.h>

/**
 * _printf- function that produces output according to a format.
 * @format: input string.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count, i = 0;
	va_list data;

	va_start(data, format);

	for (; format[i] != '\0';)
	{
		if (format[i] != '%')
		{
			count = count + _putchar(format[i]);
			 i++;
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			if (format[i + 1] == 'c')
			{
				count = count + _putcha(va_arg(data, int));
			}
			else if (format[i + 1] == 's')
			{
				count = count + print_string(va_arg(data, char *));
			}
			else if (format[i + 1] == '%')
			{
				count = count + _putchar('%');
			}
			i += 2;
		}
	}
	return (count);
}
/**
 * print_string - function that prints string
 * @string: input string
 * Return: nothing
 */
int print_string(char *string)
{
	int i;
	int count = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		count = count + _putchar(string[i]);
	}
	return (count);
}
