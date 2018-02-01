/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:38:47 by msicot            #+#    #+#             */
/*   Updated: 2018/01/29 10:55:24 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


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
}
