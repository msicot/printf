/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:38:47 by msicot            #+#    #+#             */
/*   Updated: 2018/02/13 13:36:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	ft_fill_it_d(&tmp, s, l, k);
	return (tmp);
}

/*

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



char		*ft_pourc(t_arg *l)
{
	char	*s;

	s = ft_strnew(1);
	s[0] = '%';
	return (ft_string();
}

static char	*ft_preci(char *s, t_arg *l)
{
	int		j;
	int		i;
	char	*pad;
	char	*tmp;

	if (!(s))
		return (NULL);
	i = ft_strlen(s);
	if (l->preci > i)
	{
		tmp = s;
		j = 0;
		pad = ft_strnew(l->preci - i);
		while (j < (l->preci - i))
		{
			pad[j] = '0';
			++j;
		}
		s = ft_strjoin(pad, s);
		ft_strdel(&tmp);
	}
	return (s);
}

static char	*ft_width(char *s, t_arg *l)
{
	int		i;
	int		j;
	char	*pad;
	char	*tmp;

	if (!(s))
		return (NULL);
	j = 0;
	i = ft_strlen(s);
	l->sign = ((l->plus == 1 || l->neg == 1) && l->minus == 1) ? 1 : 0;
	if (l->width > i)
	{
		tmp = s;
		j = 0;
		pad = ft_strnew(l->width - i - l->sign);
		while (j < (l->width - i - l->sign))
		{
			pad[j] = (l->zero == 0) ? ' ' : '0';
			++j;
		}
		s = (l->minus == 1) ? ft_strjoin(s, pad) : ft_strjoin(pad, s);
		ft_strdel(&tmp);
	}
	return (s);
}

char		*ft_pourc(t_arg *l)
{
	char	*s;

	s = ft_strnew(1);
	s[0] = '%';
	if (!(s = ft_preci(s, l)))
		return (NULL);
	if (l->width > l->preci)
		if (!(s = ft_width(s, l)))
			return (NULL);
	return (s);
}*/
