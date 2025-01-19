/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:47:39 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/19 20:26:38 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = -1;
	if (s != NULL)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
	else
		ft_putstr("(Null)");
	return (len);
}

int	ft_putint(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putunsigned(unsigned int a)
{
	int	len;

	len = 0;
	if (a >= 10)
		len += ft_putunsigned(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (len + 1);
}
