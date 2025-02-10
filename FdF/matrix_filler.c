#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //! sil

static int	ft_matris_x_size(char *str)
{
	int	i;
	int j;
	int space_count;

	if(!str)
		return (-1);
	space_count = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		j = 0;
		while (str[i] == ' ')
		{
			i++;
			j=1;
		}
		if (str[i] != '\0' && str[i] != '\n')
			i++;
		space_count += j;
	}
	return (space_count + 1);
}

static int	ft_matris_y_size(char *str)
{
	int i;
	int n;
	
	i = 0;
	n = 0;
	while (str[i]!='\0')
	{
		if (str[i]=='\n')
			n++;
		i++;
	}

	return (n);
}

static	char	*read_file(int fd, char *stack)
{
	char	*buffer;
	int		read_byte;
	int		buffer_size;

	buffer_size = 4096;
	read_byte = 1;
	buffer = malloc(sizeof(char) * (buffer_size + 1));
	if (!buffer)
		return (NULL);
	while (read_byte != 0)
	{
		read_byte = read(fd, buffer, buffer_size);
		if (read_byte == -1)
		{
			free (stack);
			free (buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free (buffer);
	return (stack);
}

int matris_filler(int fd, int ***matris, int *size_x, int *size_y)
{
	char	*stack;
	int		i;
	int		j;

	if (fd < 0)
		return (-1);
	stack = (char *)malloc(1 * sizeof(char));
	if (!stack)
		return (-1);
	stack[0] = '\0';
	stack = read_file(fd, stack);
	if (!stack)
		return (-1);
	*size_x = ft_matris_x_size(stack);
	*size_y = ft_matris_y_size(stack);
	i = 0;
	j = 0;
	*matris = (int**)malloc(*size_y * sizeof(int*)); //! free kontrollerini
	while(i < *size_y)
	{
		(*matris)[i] = (int*)malloc(*size_x * sizeof(int));
		i++;
	}
	i=0;
	while (*stack != '\0')
	{
		if(*stack == '\n')
		{
			i++;
			if (i==*size_y)
				break;
			j = 0;
			stack++;
		}
		(*matris)[i][j] = ft_atoi(stack);
		while (*stack == ' ')
			stack++;
		while (*stack >= '0' && *stack <= '9')
			stack++;
		j++;
	}
	return (0);
}