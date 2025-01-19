#include "ft_printf.h"

int ft_format(va_list arg_list, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg((arg_list), int)));
	else if (type == 's')
		return (ft_putstr(va_arg((arg_list), char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg((arg_list), unsigned long), 1));
	else if (type == 'i' || type == 'd')
		return (ft_putint(va_arg((arg_list), int), 0));
	else if (type == 'u')
		return (ft_putunsigned(va_arg((arg_list), unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg((arg_list), unsigned int), type));
	else
		return (ft_putchar('%'));
}

int ft_printf(const char *str, ...) //>  "yazi %c yazi\" yazi", 'm'
{
	va_list arg_list;
	va_start(arg_list, str);
	int return_value;
	int ctrl;

	ctrl = 0;
	return_value = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ctrl = ft_format(arg_list, *str);
			if (ctrl == -1)
				return (-1);
			return_value += ctrl;
		}
		else
			return_value += ft_putchar(*str);
		if (*str != '\0')
			str++;
	}
	va_end(arg_list);
	return (return_value);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
	

	return (0);
}
