#include <stdio.h>
#include <stdarg.h>
#include "ft_printf_utils.c" //!!!!!!! sil

int ft_printf(const char *str, ...) //>  "yazi %c yazi\" yazi", 'm'
{
	va_list arg_liste;
	va_start(arg_liste, str);

	while (*str != '\0')
	{
		ft_putchar_fd(*str,1);
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			if (*str == 'i')
			{
				ft_putnbr_fd(va_arg(arg_liste, int),1);
			}
			else if (*str == 'c')
			{
				ft_putchar_fd(va_arg(arg_liste, char),1);
			}
			else if (*str == 's')
			{
				ft_putstr_fd(va_arg(arg_liste, char*),1);
			}
			else
			{
				ft_putchar_fd('%',1);
			}
		}
		str++;
	}

	va_end(arg_liste);
	//printf("\n");
	return(0); //! duzelt
}

int main()
{
	ft_printf("yazi%c",'m');

	return (0);
}
