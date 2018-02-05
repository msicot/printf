/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:23:13 by msicot            #+#    #+#             */
/*   Updated: 2018/02/02 16:27:59 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_format_delim(const char *f, t_arg *l, va_list ap)
{
	char	*s;

	s = NULL;
	l->zero = (l->point == 1 && f[LEN] != 'c') ? 0 : l->zero;
//	printf("width->%d<-\n", l->width);///
	if (f[LEN] == '%')
		s = ft_pourc(l);
	else if (f[LEN] == 'd' || f[LEN] == 'i' || f[LEN] == 'D')
	{
		l->l = (f[LEN] == 'D') ? 1 : l->l;
		if (!(s = ft_is_d(ap, l)))
			return ;
	}
	else if (f[LEN] == 's')
	{
	//	ft_putstr("f[LEN] = s\n"); ///;
		if (!(s = ft_string(l, ap)))
			return ;
	}

	else if (f[LEN] == 'o' || f[LEN] == 'O')
	{
		if (!(s = (ft_is_octal(ap, l))))
			return ;
	}
	else if (f[LEN] == 'u' || f[LEN] == 'U')
	{
		l->l = (f[LEN] == 'U') ? 1 : l->l;
		if (!(s = ft_is_u(ap, l)))
			return ;
	}
	else if (f[LEN] == 'x' || f[LEN] == 'X')
	{
		l->x = (f[LEN] == 'X') ? 1 : 0;
		if(!(s = ft_is_x(ap, l)))
			return ;
	}
	else if (f[LEN] == 'c')
	{
		if (!(s = ft_is_c(ap,l)))
			return ;
	}
	else
	{
		++LEN;
		return ;
	}
	if (s != NULL)
		ft_mna(s, l);
	ft_strdel(&s);
	++LEN;
//	ft_putstr("test end of format\n"); //DEL
}
