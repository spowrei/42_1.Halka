/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:39:15 by mukaplan          #+#    #+#             */
/*   Updated: 2024/11/18 13:59:35 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	size_t	size;

	size = ft_strlen(s1) + 1;
	buffer = (char *)malloc(size);
	if (buffer == NULL)
		return (NULL);
	ft_memcpy(buffer, s1, size);
	return (buffer);
}
