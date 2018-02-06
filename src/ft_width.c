/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:00:28 by msicot            #+#    #+#             */
/*   Updated: 2018/02/06 15:21:05 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_else_width(char **s, char *val, t_arg *l, int k)
{
	int i;
	int j;
	int	lenf;
	int	lim;

	lenf = ft_strlen(val) - l->neg;
	lim = (l->preci > lenf) ? l->preci : lenf;
	j = 0;
	i = 0;
	while (i < (k - (lim)))
	{
		if (i == 0 && l->blank == 1)
			(*s)[i++] = ' ';
		(*s)[i++] = (l->zero == 1) ? '0' : ' ';
	}
	if (l->preci != 0)
	{
		while (i < (k - lenf))
			(*s)[i++] = '0';
	}
	while (i < (k))
		(*s)[i++] = (l->neg == 1) ? val[++j] : val[j++];
	ft_signin(s, l, k, lim);
}
static void ft_minus_d(char **s, char *val, t_arg *l, int k)
{
	int	lenf;
	int	i;
	int j;

	j = 0;
	i = 0;
	lenf = ft_strlen(val) - l->neg;
	if (l->blank == 1)
		(*s)[i++] = ' ';
	else if (l->sign == 1)
		(*s)[i++] = (l->neg == 1) ? val[j++] : '+';
	if (l->preci != 0)
	{
		while (i < (l->preci - (lenf) + l->sign))
			(*s)[i++] = '0';
	}
	while (j < lenf + l->neg)
	{
		(*s)[i++] = val[j++];
	}
	while (i < k)
		(*s)[i++] = ' ';
}

void		ft_width_d(char **s, char *val, t_arg *l, int k)
{
	int i;
	int	len;
	int j;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->width == 0 && l->preci == 0)
		ft_wp_zero(s, val, l, k);
	else if (l->minus == 0)
		ft_else_width(s, val, l, k);
	else if (l->minus == 1)
		ft_minus_d(s, val, l, k);
}
/*
char		*ft_preci_int(char *s, t_arg *l)
{
	char	*tmp;
	char	*pad;
	int		j;
	int		len;

	len = ft_strlen(s);
	tmp = s;
	j = 0;
	if (l->preci == 0)
		return (s);
	if (l->preci > len)
	{
		if (!(pad = ft_strnew(l->preci - len)))
			return (NULL);
		while (j < (l->preci - len))
		{
			pad[j] = '0';
			++j;
		}
//		printf("pad --->%s<---\n", pad);
		s = ft_strjoin(pad, s);
		ft_strdel(&pad);
		ft_strdel(&tmp);
	}
	return (s);
}

char		*ft_width_int(char *s, t_arg *l)
{
	char	*tmp;
	char	*pad;
	int		j;
	int		len;
	int		k;
	
	k = 0;
	if (l->sign == 1 || l->blank == 1)
		k = 1;
	j = 0;
	len = ft_strlen(s);
	if (l->width > len + l->sign)
	{
		tmp = s;
		if (!(pad = ft_strnew(l->width - len - k)))
			return (NULL);
		while (j < (l->width - len - k))
			pad[j++] = (l->zero == 1) ? '0' : ' ';
		if (l->minus == 1)
			s = ft_strjoin(s, pad);
		else
			s = ft_strjoin(pad, s);
		ft_strdel(&tmp);
		ft_strdel(&pad);
	}
	return (s);
}*/
