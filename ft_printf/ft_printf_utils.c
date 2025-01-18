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
	int	i;

	i = -1;
	if (s != NULL)
	{
		i = ft_strlen(s);
		write(1, s, i);
	}
	else
		ft_putstr("(NULL)");
	return (i);
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

int	ft_putptr(void *ptr)
{
	int	len;
	int	ctrl;

	len = 0;
	ctrl = 0;
	if (ft_putstr("0x") == -1) //! ne ALAKA
		return (-1);
	len += 2;
	ctrl = ft_puthex((unsigned long)ptr, 'x');
	if (ctrl == -1)
		return (-1);
	len += ctrl;
	return (len);
}

void ft_unsigned(long n)
{
	if (n >= 10)
		ft_unsigned(n / 10);
	ft_putchar ('0' + n);
}

int ft_putunsigned(long n) //! duzelt
{
	int len;

	len = 0;
	if (n<0 && n>=-4294967296)
		n=4294967296-n;
	else if (n>429496725)
		n-=429496725; 
	else if (n<-4294967296)
		n+=-4294967296;
	if (n==-4294967296)
		return(ft_putstr("-4294967296"));
	else if(n<0)
	{
		len += ft_putchar('-');
		n*=-1;
	}
	ft_unsigned(n);
	while(n>0)
	{
		len++;
		n/=10;
	}
	return (len);
}
