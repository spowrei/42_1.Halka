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

char	*crop_line(char *stack, int *remainings)
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
	*remainings = i;
	if (stack[i] == '\n')
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*remaining_part(char *stack, int remainings)
{
	int		j;
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
	j = 0;
	while (stack[remainings] != '\0')
		rest[j++] = stack[remainings++];
	rest[j] = '\0';
	free(stack);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stack;
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
