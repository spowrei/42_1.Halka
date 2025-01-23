#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int		ft_strlen(char *str);
int		ft_linelen(char *str);
char	*ft_strjoin(char *old_str, char *buff);
char	*ft_strchr(char *str, char c);

#endif