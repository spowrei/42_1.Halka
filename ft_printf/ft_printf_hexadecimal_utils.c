/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:11:43 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:08 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static	int	ft_hex(unsigned int a, char *nums, int *fail)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_hex(a / 16, nums, fail);
	if (0 > write(1, &nums[a % 16], 1))
		*fail = 1;
	return (len + 1);
}

int	ft_puthex(unsigned int a, char c)
{
	int	ret;
	int	fail;

	fail = 0;
	if (c == 'X')
		ret = ft_hex(a, "0123456789ABCDEF", &fail);
	else if (c == 'x')
		ret = ft_hex(a, "0123456789abcdef", &fail);
	else
		return (-1);
	if (fail == 1)
		return (-1);
	return (ret);
}

static	int	ft_point(unsigned long ptr, int *fail)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_point(ptr / 16, fail);
	if (0 > write(1, &"0123456789abcdef"[ptr % 16], 1))
		*fail = 1;
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	fail;

	fail = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len = ft_point((unsigned long)ptr, &fail) + 2;
	if (fail == 1)
		return (-1);
	return (len);
}
