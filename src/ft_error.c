/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:08:13 by msicot            #+#    #+#             */
/*   Updated: 2018/02/09 17:32:35 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_error_uni(t_arg *l, wchar_t u)
{
	if (u < 0)
	{
		l->exit = 3;
		return (1);
	}
	else if (u > 255 && MB_CUR_MAX == 1)
	{
		l->exit = 2;
		return (1);
	}
	else if (u >= 0xD800 && u <= 0xDB7f)
	{
		l->exit = 2;
		return (1);
	}
	else if (u >= 0x11ffff)
	{
		l->exit = 2;
		return (1);
	}
	else if ((u >= 0xDC00 && u <= 0xDFFF)  || u > 2097151)
	{
		l->exit = 2;
		return (1);
	}
	else if (u >= 0xAC00 && u <= 0xD7AF)
	{
		ft_putstr("test\n");
		l->exit = 2;
		return (1);
	}
	return (0);

}
