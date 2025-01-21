#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char	*read_line(int fd, char *stack);
char	*crop_line(char *stack, int *remainings);
char	*remaining_part(char *str, int remainings);
char	*get_next_line(int fd);

int		ft_strlen(char *str);
int		ft_linelen(char *str);
char	*ft_strjoin(char *old_str, char *buff);
char	*ft_strchr(char *str, char c);

#endif