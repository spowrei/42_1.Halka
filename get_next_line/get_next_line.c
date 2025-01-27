/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukaplan <mukaplan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:54:11 by mukaplan          #+#    #+#             */
/*   Updated: 2025/01/27 16:26:22 by mukaplan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static	char	*read_line(int fd, char *stack)
{
	char	*buffer;
	int		read_byte;

	read_byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stack, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (stack);
			free (buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

static	char	*crop_line(char *stack, int *remainings)
{
	char	*line;
	int		i;

	if (!stack || stack[0] == '\0')
		return (NULL);
	i = 0;
	line = malloc(sizeof(char) * (ft_linelen(stack) + 2));
	if (!line)
		return (NULL);
	while (stack[i] != '\0' && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	*remainings = i;
	if (stack[i] == '\n')
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static	char	*remaining_part(char *stack, int remainings)
{
	int		i;
	char	*rest;

	if (!stack)
		return (NULL);
	if (stack[remainings] == '\0')
	{
		free(stack);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(stack) - remainings));
	if (!rest)
		return (NULL);
	remainings++;
	i = 0;
	while (stack[remainings] != '\0')
		rest[i++] = stack[remainings++];
	rest[i] = '\0';
	free(stack);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*line;
	int			remainings;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stack)
	{
		stack = (char *)malloc(1 * sizeof(char));
		if (!stack)
			return (NULL);
		stack[0] = '\0';
	}
	stack = read_line(fd, stack);
	if (!stack)
		return (NULL);
	remainings = 0;
	line = crop_line(stack, &remainings);
	stack = remaining_part(stack, remainings);
	return (line);
}
