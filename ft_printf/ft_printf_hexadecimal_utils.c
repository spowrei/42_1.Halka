/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:11:43 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/19 20:41:05 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_hex(unsigned int a, char *nums)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_hex(a / 16, nums);
	write(1, &nums[a % 16], 1);
	return (len + 1);
}

int	ft_puthex(unsigned int a, char c)
{
	if (c == 'X')
		return (ft_hex(a, "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_hex(a, "0123456789abcdef"));
	else
		return (-1);
}

int	ft_point(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_point(ptr / 16);
	write(1, &"0123456789abcdef"[ptr % 16], 1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len = ft_point((unsigned long)ptr) + 2;
	return (len);
}
