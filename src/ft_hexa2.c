/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:58:32 by msicot            #+#    #+#             */
/*   Updated: 2018/02/02 16:21:41 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_check_0x(char **val, t_arg *l)
{
	if ((*val)[0] == '0' && ft_strlen(*val) == 1)
	{
		l->sharp = 0;
		if (l->point == 1 && l->preci == 0)
		{
			if (l->width > 0)
				(*val)[0] = ' ';
			else
				(*val)[0] = '\0';
		}
	}
}

static void	ft_fill_it(char **s, char *val,  t_arg *l, int k)
{
	int		j;
	int		i;
	int		len;
	int	x;

	j = 0;
	i = 0;
	if (l->sharp == 2 && val[0] != '0')
	{
		len = (int)ft_strlen(val);
		if (l->preci <=  len + l->sharp)
		{
			x = (l->preci - len > 0) ? l->preci - len : 0;
		//	printf("preci = %d\n",l->preci);
			l->preci = len + (x) + l->sharp;
		}
	}
	if (l->preci >= l->width && l->preci != 0)
		ft_preci_x(s, val, l, k);
	else //if (l->preci < l->width)
		ft_width_x(s, val, l, k);
}

static int	ft_champs_x(char **s, t_arg *l)
{
	int len;
	int lenf;

	len = (int)ft_strlen(*s);
	ft_check_0x(s, l);
	lenf = len + l->sharp;;
	if (l->preci > (lenf - l->sharp))
		lenf = lenf + (l->preci - (lenf - l->sharp));
	if (l->width > lenf)
		lenf = lenf + (l->width - lenf);
	return (lenf);

}

char	*ft_integer_x(uintmax_t val, t_arg *l)
{
	char 		*s;
	char		*num;
	int			k;

	if (!(num = ft_itoa_base(val, 16, l->neg)))
		return (NULL);
	k = ft_champs_x(&num, l);
//	printf("champs =->%d<-\n", k + 9); // / / /
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill_it(&s, num, l, k);
	ft_strdel(&num);
	return (s);

}
