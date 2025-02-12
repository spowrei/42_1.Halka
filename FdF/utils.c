#include <stdlib.h>
#include <stdio.h> //! sil

static	int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*buffer;
	int	size;
	int	i;

	size = ft_strlen(str) + 1;
	buffer = (char *)malloc(size * sizeof(char));
	if (buffer == NULL)
		return (NULL);
			i = 0;
			while (i < size)
			{
				buffer[i] = str[i];
				i++;
			}		
	return (buffer);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				number;
	int				coefficient;

	i = 0;
	number = 0;
	coefficient = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		coefficient = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number = number + (str[i] - '0');
		i++;
	}
	number *= coefficient;
	return (number);
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
