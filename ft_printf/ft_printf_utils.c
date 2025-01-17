//#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int n) //!gerekli mi
{
	long	nb;
	int len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
		nb = (nb * -1);
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		len++;	
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (len);
}

void	ft_putstr(char *s)
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

int	ft_putint(int a)
{
	return (ft_putnbr(a));
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

int	ft_hex(unsigned int a, char *nums) //! tekrar bak recursion
{
	int	ret;

	ret = 0;
	if (a >= 16)
		ret += ft_hex(a / 16, nums);

		write(1, &nums[a % 16], 1);

	return (ret + 1);
}

int ft_putptr() //! yazz
{
	return (-1);
}
