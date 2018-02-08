/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:11:31 by msicot            #+#    #+#             */
/*   Updated: 2018/02/08 16:10:29 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_retrieve(const char *f, t_arg *l, va_list ap)
{
	ft_is_flag(f, l);
	ft_is_width(f, l, ap);
	ft_is_preci(f, l, ap);
	ft_is_type(f, l);
	ft_format_delim(f, l, ap);
}

void		ft_merge(char *buf, t_arg *l)
{
	char *tmp;

	if (!(buf) || !(l->str))
		return ;
	tmp = l->str;
	if (!(l->str = ft_strjoin(l->str, buf)))
		return ;
	ft_strdel(&tmp);
	ft_bzero(buf, BUFF_SIZE + 1);
}

void		ft_gnf(t_arg *l, const char *f, va_list ap)
{
	char	*buf;
	int		i;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return ;
	while (f[LEN])
	{
		i = 0;
		while (f[LEN] != '%' && f[LEN] && i < BUFF_SIZE)
		{
			buf[i] = f[LEN];
			++i;
			++LEN;
			l->loop = 1;
		}
		ft_merge(buf, l);
		if (f[LEN] == '%')
		{
			ft_flag_reset(l);
			++LEN;
			ft_retrieve(f, l, ap);
		}
		if (f[LEN] == '\0' || l->exit != 0)
			break ;
	}
	ft_strdel(&buf);
}
/*
void		ft_lecture2(t_arg *l, const char *f, va_list ap)
{
	int		i;
	char	buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	while (f[LEN])
	{
		i = 0;
		while (f[LEN] != '%' && f[LEN] && i < BUFF_SIZE)
		{
			if (i == 31)
			{
				ft_putendl(buf);
				ft_merge(buf, l);
			}
			buf[i] = f[LEN];
		//	ft_putchar(buf[i]);
			++i;
			++LEN;
		}
		if (f[LEN] == '\0')
			ft_merge(buf, l);
		if (f[LEN] == '%')
		{
			ft_merge(buf, l);
			ft_bzero(buf, BUFF_SIZE + 1);
			ft_lecture(buf, l, f, ap);
		}
	}
}
void		ft_lecture(char *buf, t_arg *l, const char *f, va_list ap)
{
	while (f[LEN])
	{
		while (f[LEN] != '%' && f[LEN])
		{
			if ((LEN % BUFF_SIZE) == 0)
				ft_merge(buf, l);
			buf[LEN % BUFF_SIZE] = f[LEN];
			++LEN;
		}
		if (f[LEN] == '\0')
			ft_merge(buf, l);
		if (f[LEN] == '%')
		{
			ft_flag_reset(l);
			ft_merge(buf, l);
			++LEN;
		}
		break ;
	}
	ft_lecture2(l, f, ap);
}
*/
