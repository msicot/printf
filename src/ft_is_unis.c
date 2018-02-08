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

char	*ft_is_unis(va_list ap, t_arg *l)
{
	char	*s;

	s = ft_strnew(1);
	wchar_t *u;
	u = va_arg(ap, wchar_t*);
	int i ;
	i = l->point;
	return (s);
}
