/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:14:38 by msicot            #+#    #+#             */
/*   Updated: 2018/02/08 19:24:22 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


static char	*ft_is_unic_s(wchar_t u, t_arg *l)
{
	char	*s;

	s = NULL;
	l->sign = 0;
	l->neg = 0;
	l->zero = 0;
	l->point = 0;
	l->preci = 0;
	if (ft_error_uni(l , u) == 1)
		return (s);
	if (u < 128 || (u <= 255 && MB_CUR_MAX == 1))
		s = ft_char_c((char)u, l);
	else if (u >= 128)
		s = ft_unicode2(u, l);
	return (s);
}


char	*ft_is_unis(va_list ap, t_arg *l)
{
	char	*s;
	wchar_t *u;
	char	*tmp;
	int	i;

	i = 0;
	tmp = NULL;
	s = ft_strnew(0);
	u = va_arg(ap, wchar_t*);
	while (u[i])
	{
		tmp = ft_is_unic_s(u[i++], l);	
	}
	i = l->point;
	return (s);
}
