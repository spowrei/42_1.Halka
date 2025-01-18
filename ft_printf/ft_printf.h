#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
# include <stddef.h>

int		ft_putchar(char c);
int		ft_putint(int n, int len);
int		ft_putstr(char *s);
int		ft_puthex(unsigned int a, char c);
int		ft_hex(unsigned int a, char *nums);
int		ft_putptr();
int		ft_putunsigned();

#endif 
