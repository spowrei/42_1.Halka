#include "ft_printf.h"

void ft_format(va_list arg_list, char type)
{
	if (type == 'u')
		return (ft_unsigned(va_arg((arg_list), unsigned int)));
	else if (type == 'c')
		return (ft_putchar(va_arg((arg_list), int)));
	else if (type == 'i' || type == 'd')
		return (ft_int(va_arg((arg_list), int)));
	else if (type == 'x' || type == 'X') //! ayır
		return (ft_hex(va_arg((arg_list), unsigned int), type));
	else if (type == 'p')
		return (ft_point(va_arg((arg_list), unsigned long), 1));
	else if (type == 's')
		return (ft_putstr(va_arg((arg_list), char *)));
	else
		return (ft_putchar(type));
}

int ft_printf(const char *str, ...) //>  "yazi %c yazi\" yazi", 'm'
{
	va_list arg_list;
	va_start(arg_list, str);

	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ft_formatter(arg_list, *str);
		}
		else
			ft_putchar(*str);
		str++;
	}

	va_end(arg_list);
	// printf("\n");
	return (0); //! duzelt
}

int main()
{
	ft_printf("yazi%c", 'm');

	return (0);
}
