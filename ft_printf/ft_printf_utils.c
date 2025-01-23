/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:47:39 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/22 22:23:36 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[len] != '\0')
		len++;
	return (write(1, s, len));
}

int	ft_putint(int n, int *fail)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_putint(n / 10, fail);
	if (0 > write(1, &"0123456789"[n % 10], 1))
		*fail = 1;
	return (len + 1);
}

int	ft_putunsigned(unsigned int n, int *fail)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10, fail);
	if (0 > write(1, &"0123456789"[n % 10], 1))
		*fail = 1;
	return (len + 1);
}
