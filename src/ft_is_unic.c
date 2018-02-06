/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:09:26 by msicot            #+#    #+#             */
/*   Updated: 2018/02/06 14:22:42 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_is_unic(va_list ap, t_arg *l)
{
	char	*s;
	
	int i = l->width;
	s = "troll";
	if (ap)
		l->width = i;
	printf("size =%lu\n", sizeof(wchar_t));
	return (s);
}
