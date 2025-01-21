#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4

char	*get_next_line(int fd);
char	*get_line(char *stack);
char	*new_line(char *str);
char	*read_line(int fd, char *stack);

int		ft_strlen(char *str);
int		ft_linelen(char *str);
char	*ft_strjoin(char *old_str, char *buff);
char	*ft_strchr(char *str, char c);

#endif