/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:46:52 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/22 22:24:06 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

int	ft_format(va_list arg_list, char type)
{
	int	fail;
	int	ret;

	ret = 0;
	fail = 0;
	if (type == 'c')
		return (ft_putchar(va_arg((arg_list), int)));
	else if (type == 's')
		return (ft_putstr(va_arg((arg_list), char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg((arg_list), void *)));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg((arg_list), unsigned int), type));
	else if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'i' || type == 'd')
		ret = ft_putint(va_arg((arg_list), int), &fail);
	else if (type == 'u')
		ret = ft_putunsigned(va_arg((arg_list), unsigned int), &fail);
	else
		return (-1);
	if (fail == 0)
		return (ret);
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		return_value;
	int		ctrl;

	if (str == NULL)
		return (-1);
	va_start(arg_list, str);
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
