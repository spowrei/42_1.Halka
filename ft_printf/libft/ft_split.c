/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:37:01 by mukaplan          #+#    #+#             */
/*   Updated: 2024/11/18 14:00:33 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_new_word(char **cursor, char c)
{
	char			*temp;
	unsigned int	len;
	char			*word;

	len = 0;
	while (**cursor == c)
		(*cursor)++;
	temp = *cursor;
	while (**cursor != c && **cursor != '\0')
	{
		len++;
		(*cursor)++;
	}
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, temp, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	i;
	unsigned int	word_count;
	char			*cursor;

	i = 0;
	cursor = (char *)s;
	word_count = ft_word_count(s, c);
	strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (strings == NULL)
		return (NULL);
	strings[word_count] = NULL;
	while (i < word_count)
	{
		strings[i] = ft_new_word(&cursor, c);
		if (strings[i] == NULL)
		{
			while (--i >= 0)
				free (strings[i]);
			free (strings);
			return (NULL);
		}
		i++;
	}
	return (strings);
}
