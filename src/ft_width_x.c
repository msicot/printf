/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:27:50 by msicot            #+#    #+#             */
/*   Updated: 2018/02/02 16:20:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_sharping(char **s, t_arg *l)
{
	/*
	if (l->sharp == 2 && (l->width < l->preci) && l->point == 1)
	{
		(*s)[i++] = '0';
		(*s)[i++] = 'X';
		l->sharp = 0;
		return (i);
	}
	return (i);
*/
	int i;

	i = 0;
	if (l->sharp == 2)
	{
		while ((*s)[i] == ' ')
			++i;
			(*s)[i++] = '0';
			(*s)[i++] = 'X';
		l->sharp = 0;
	}
}


static void	ft_else_width(char **s, char *val, t_arg *l, int k)
{
	int i;
	int j;
	int	lenf;
	int	lim;

	lenf = ft_strlen(val);
	lim = (l->preci > lenf) ? l->preci : lenf;
	j = 0;
	i = 0;
//	i = ft_sharping(s, l, i)
	while (i < (k - (lim)))
		(*s)[i++] = (l->zero == 1) ? '0' : ' ';
	if (l->preci != 0)
	{
		/*if (l->sharp == 2)
		{
			(*s)[i++] = '0';
			(*s)[i++] = 'X';
			l->sharp = 0;
		}*/
		while (i < (k - lenf))
			(*s)[i++] = '0';
	}
	while (i < (k))
		(*s)[i++] = val[j++];
//	printf("s = %s\n", *s);///
	ft_sharping(s, l, (int)ft_strlen(val));
}

static void ft_minus_d(char **s, char *val, t_arg *l, int k)
{
	int	lenf;
	int	i;
	int j;

	j = 0;
	i = 0;
	lenf = ft_strlen(val) - l->neg;
//	i = ft_sharping(s, l, i);
	if (l->sharp == 2)
	{
		(*s)[i++] = '0';
		(*s)[i++] = 'X';
		l->sharp = 0;
	}
	if (l->preci != 0)
		while (i < (l->preci - (lenf) + l->sign))
			(*s)[i++] = '0';
	while (j < lenf + l->neg)
		(*s)[i++] = val[j++];
	while (i < k)
		(*s)[i++] = ' ';
}

void		ft_width_x(char **s, char *val, t_arg *l, int k)
{
	int i;
	int	len;
	int j;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->width == 0 && l->preci == 0)
		ft_wp_zero_o(s, val, l, k);
	else if (l->minus == 0)
		ft_else_width(s, val, l, k);
	else if (l->minus == 1)
		ft_minus_d(s, val, l, k);
}
