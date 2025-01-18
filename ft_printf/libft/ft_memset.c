/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:41:11 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/18 14:36:50 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*b_char;

	b_char = b;
	i = 0;
	while (i < len)
	{
		b_char[i] = c;
		i++;
	}
	return (b);
}
