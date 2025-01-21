#include "get_next_line.h"
#include <unistd.h> 

char	*read_line(int fd, char *stack)
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
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

char	*crop_line(char *stack)
{
	char	*line;
	int		linelen;
	int		i;

	if (!stack || stack[0] == '\0')
		return (NULL);
	i = 0;
	linelen = ft_linelen(stack);
	line = malloc(sizeof(char) * (linelen + 2)); //> + \n + \0 için +2
	if (!line)
		return (NULL);
	while (stack[i] != '\0' && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*remaining_part(char *stack)
{
	int		i;
	int		j;
	char	*rest;

	if (!stack)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\0')
	{
		free(stack);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(stack) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
		rest[j++] = stack[i++];
	rest[j] = '\0';
	free(stack);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stack == NULL)
	{
		stack = (char *)malloc(1 * sizeof(char));
		if (stack == NULL)
			return (NULL);
		stack[0] = '\0';
	}
	stack = read_line(fd, stack);
	if (!stack)
		return (NULL);
	line = crop_line(stack);
	stack = remaining_part(stack);
	return (line);
}
