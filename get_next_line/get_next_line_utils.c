#include "get_next_line.h" //! gerek var mı

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
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!old_str)
	{
		old_str = (char *)malloc(1 * sizeof(char));
		old_str[0] = '\0';
	}
	if (!old_str || !buff)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(old_str) + ft_strlen(buff)) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	j = 0;
	if (old_str)
		while (old_str[++i] != '\0') //> i = 0, old_str[i++] olamaz mı
			new_str[i] = old_str[i];
	while (buff[j] != '\0')
		new_str[i++] = buff[j++];
	new_str[ft_strlen(old_str) + ft_strlen(buff)] = '\0'; //> newstr[i] = '\0' olamaz mı
	free(old_str);
	return (new_str);
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
