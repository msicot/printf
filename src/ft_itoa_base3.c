#include "libftprintf.h"

static int	ft_nbchar(int nb, int base)
{
	int				nbchar;
	unsigned long	num;

	nbchar = 1;
	if (nb < 0)
	{
		if (base == 10)
		{
			num = nb * -1;
			nbchar++;
		}
		else
			num = UINT_MAX + nb + 1;
	}
	else
		num = nb;
	while (num / base != 0)
	{
		num = num / base;
		nbchar++;
	}
	return (nbchar);
}

char		*ft_itoa_base(intmax_t num, unsigned int base)
{
	intmax_t		nb;
	char			*str;
	int				i;

	i = ft_nbchar(num, base);
	str = ft_strnew(i);
	if (num < 0)
	{
		if (base == 10)
		{
			str[0] = '-';
			nb = num * -1;
		}
		else
			nb = UINT_MAX + num + 1;
	}
	else
		nb = num;
	while (nb / base != 0)
	{
		str[--i] = nb % base + (nb % base > 9 ? 'a' - 10 : '0');
		nb = nb / base;
	}
	str[--i] = nb % base + (nb % base > 9 ? 'a' - 10 : '0');
	return (str);
}
