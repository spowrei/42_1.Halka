#include "get_next_line.h"
#include <fcntl.h> //> gerek var mı #include <stddef.h> koy yerine ?
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*read_line(int fd, char *stack)
{
	char	*buffer;
	int		read_byte;

	if (!stack)
		return (NULL);
	read_byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stack, '\n') && read_byte != 0) //! stack başlatılmadan işlem görüyor!!
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

char	*new_line(char *str)
{
	int		i;
	int		j;
	char	*rest;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*get_line(char *stack)
{
	char	*line;
	int		linelen;
	int		i;

	if (!stack || stack[0] == '\0')
		return (NULL);
	i = 0;
	linelen = ft_linelen(stack);
	line = malloc(sizeof(char) * (linelen + 2)); //>  neden + 2
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

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = read_line(fd, stack);
	if (!stack)
		return (NULL);
	line = get_line(stack);
	stack = new_line(stack);
	return (line);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    int i = 0;
    while (i<5)
    {
		line = get_next_line(fd);
		if (!line)
		{
			printf("HATAA!!!\n");
			return (0);
		}
        printf("%s", line);
        free(line);
		i++;
    }
	close(fd);
    return (0);
}