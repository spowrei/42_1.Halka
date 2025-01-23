/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:54:06 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/23 13:54:07 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *old_str, char *buff)
{
	int		i;
	int		j;
	char	*ret;

	if (!old_str)
	{
		old_str = (char *)malloc(1 * sizeof(char));
		old_str[0] = '\0';
	}
	if (!old_str || !buff)
		return (NULL);
	ret = malloc(sizeof(char) * ((ft_strlen(old_str) + ft_strlen(buff)) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	if (old_str)
		while (old_str[++i] != '\0')
			ret[i] = old_str[i];
	while (buff[j] != '\0')
		ret[i++] = buff[j++];
	ret[i] = '\0';
	free(old_str);
	return (ret);
}

char	*ft_strchr(char *str, char c)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	return (NULL);
}
