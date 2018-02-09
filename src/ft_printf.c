/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 07:13:57 by msicot            #+#    #+#             */
/*   Updated: 2018/02/09 16:17:33 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_arg	l;
	int		i;

	if (!(l.str = ft_strnew(0)))
		return (0);
	l.flen = 0;
	l.len = 0;
	l.add = 0;
	l.loop = 0;
	l.exit = 0;
	va_start(ap, format);
	ft_gnf(&l, format, ap);
//	printf("l->str end --> %s<--\n", l.str);
//	ft_lecture(buf, &l, format, ap);
	va_end(ap);
	if (l.exit != 3)
		ft_putstr(l.str);
	i = (l.exit > 1) ? -1 : (ft_strlen(l.str));
	ft_strdel(&l.str);
	return (i + l.add + l.flen);
}
