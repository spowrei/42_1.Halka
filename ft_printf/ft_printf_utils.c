#include <unistd.h>
# include <stddef.h>
# include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s != NULL)
	{
		i = ft_strlen(s);
		write(1, s, i);
	}
	return (i);
}

int	ft_hex(unsigned int a, char *nums) //! tekrar bak recursion
{
	int	ret;

	ret = 0;
	if (a >= 16)
		ret += ft_hex(a / 16, nums);
	write(1, &nums[a % 16], 1);
	return (ret + 1);
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

int ft_putptr() //! yazz
{
	return (-1);
}

int ft_putunsigned() //! yazz
{
	return (-1);
}
