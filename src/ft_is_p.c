/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:50:49 by msicot            #+#    #+#             */
/*   Updated: 2018/02/06 11:45:36 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_is_p(va_list ap, t_arg *l)
{
	char	*s;
//	char 	*tmp;
	uintptr_t x;

	s = NULL;
	l->sharp = 2;
	l->point = 0;
	l->preci = 0;
	x = va_arg(ap, uintptr_t);
//	printf("p -->%lu<--\n", x);
	s = ft_integer_x(x, l);
	if (x == 0)
	{
		ft_strdel(&s);
//		printf("test\n");
		s = ft_strnew(3);
		s[0] = '0';
		s[1] = 'x';
		s[2] = '0';
		return (ft_string_p(s, l));
	}
	s = ft_strlowcase(s);
	return (s);
}
