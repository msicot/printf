/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:09:26 by msicot            #+#    #+#             */
/*   Updated: 2018/02/06 16:51:41 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_is_unic(va_list ap, t_arg *l)
{
	char	*s;
	wchar_t	u;
	
	l->preci = (l->point == 1)? l->preci : 0;
	u = va_arg(ap, wchar_t);	
	s = NULL;
	return (s);
}
