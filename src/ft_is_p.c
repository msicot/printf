/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:50:49 by msicot            #+#    #+#             */
/*   Updated: 2018/02/13 19:38:38 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_is_p(va_list ap, t_arg *l)
{
	char	*s;
//	char 	*tmp;
	uintptr_t x;
	int		i;

	i = 0;
	s = NULL;
	l->sharp = 2;
	x = va_arg(ap, uintptr_t);
	s = ft_integer_x(x, l);
	//ft_putendl(s);
/*	if (x == 0)
	
		}
	//	ft_strdel(&s);
		s[i++] = '0';
		s[i++] = 'x';
		s[i++] = '0';
	}*/
	s = ft_strlowcase(s);
	return (s);
}
