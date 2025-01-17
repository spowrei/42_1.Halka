#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_putint(int n);
int		ft_putstr(char *s);
int		ft_puthex(unsigned int a, char c);
int		ft_hex(unsigned int a, char *nums);
int		ft_putptr();

#endif 
