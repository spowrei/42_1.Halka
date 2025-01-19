#include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = -1;
	if (s != NULL)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
	else
		ft_putstr("(Null)");
	return (len);
}

int	ft_putint(int n) 
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_hex(unsigned int a, char *nums)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_hex(a / 16, nums);
	write(1, &nums[a % 16], 1);
	return (len + 1);
}

int	ft_puthex(unsigned int a, char c)
{
	if (c == 'X')
		return (ft_hex(a, "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_hex(a, "0123456789abcdef"));
	else 
		return (-1);
}

int	ft_point(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_point(ptr / 16);
	write(1, &"0123456789abcdef"[ptr % 16], 1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;
	
	if(ptr == NULL)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len = ft_point((unsigned long)ptr) +2;
	return (len);
}

int	ft_putunsigned(unsigned int a)
{
	int	len;

	len = 0;
	if (a >= 10)
		len += ft_putunsigned(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (len + 1);
}
