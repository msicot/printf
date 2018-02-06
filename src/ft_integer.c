/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:48:29 by msicot            #+#    #+#             */
/*   Updated: 2018/02/06 12:18:57 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_check_0(char *val, t_arg *l)
{
	if (ft_strlen(val) == 1 && l->point == 1 && l->preci == 0)
	{
		if (l->width != 0)
		{
			if (val[0] == '0')
				val[0] = ' ';
		}
		else
			val[0] = '\0';
	}
}

static void	ft_fill_it(char **s, char *val,  t_arg *l, int k)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	ft_check_0(val, l);
	if (l->preci >= l->width && l->preci != 0)
		ft_preci_d(s, val, l, k);
	else //if (l->preci < l->width)
		ft_width_d(s, val, l, k);
}

int		ft_champs(char *s, t_arg *l)
{
	int		len;
	int		lenf;
	int		sign;
	
	sign = (l->sign == 1 || l->blank == 1)? 1 : 0;
	len = ft_strlen(s) - l->neg;
	lenf = len + sign;
	if (l->preci > (lenf - sign))
		lenf = lenf + (l->preci - len);
	if (l->width > lenf)
		lenf = lenf + (l->width - lenf);
	return (lenf);
}

char		*ft_pourc(t_arg *l)
{
	char	*s;
	int		k;
	char	*tmp;

	l->preci = 0;
	l->point = 0;
	l->plus = 0;
	l->sign = 0;
	l->blank = 0;
	l->zero = l->bkzero;
	if (!(s = ft_strnew(1)))
		return (NULL);
	s[0] = '%';
	k = ft_champs(s, l);
	if (!(tmp = ft_strnew(k)))
		return (NULL);
	ft_fill_it(&tmp, s, l, k);
	return (tmp);
}

char		*ft_integer(intmax_t val, t_arg *l)
{
	char		*s;
	char		*num;
	int			k;

	num = NULL;

	if (!(num = (l->us == 0) ? ft_itoa_max(val) : ft_itoa_unsigned(val)))
		return (NULL);
	if (ft_strchr(num, '-') != NULL)
	{
		l->neg = 1;
		l->sign = 1;
		l->blank = 0;
	}
	k = ft_champs(num, l);
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill_it(&s, num, l, k);
	ft_strdel(&num);
	return (s);
}
