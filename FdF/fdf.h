#ifndef FDF_H
# define FDF_H

int		ft_matris_len(char *str);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *old_str, char *buff);
char	*ft_strdup(const char *str);
int matris_filler(int fd, int ***matris, int *size_x, int *size_y);

#endif