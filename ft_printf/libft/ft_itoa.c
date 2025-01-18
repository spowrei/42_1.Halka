/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:21:34 by mukaplan          #+#    #+#             */
/*   Updated: 2024/11/18 14:00:43 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_digit(int n)
{
	int	digit;

	if (n == 0)
		return (1);
	digit = 0;
	if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*str;
	int		coefficient;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = ft_digit(n);
	coefficient = 1;
	if (n < 0)
	{
		coefficient = -1;
		n *= -1;
	}
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (str == NULL)
		return (NULL);
	str[digit] = '\0';
	while (digit-- > 0)
	{
		str[digit] = '0' + (n % 10);
		n /= 10;
	}
	if (coefficient < 0)
		str[0] = '-';
	return (str);
}
