/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:04:55 by msicot            #+#    #+#             */
/*   Updated: 2018/02/01 17:07:08 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_len(intmax_t num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num /= 10;
		++i;
	}
	return (i);
}

static char	*ft_rev(char *s)
{
	char	*tmp;
	int		i;
	int		len;
	char	t;

	i = -1;
	len = ft_strlen(s);
	tmp = s;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (++i < --len)
	{
		t = tmp[i];
		tmp[i] = tmp[len];
		tmp[len] = t;
	}
	ft_strdel(&tmp);
	return (s);
}

char		*ft_itoa_base(uintmax_t num, unsigned int base)
{
	int		i;
	char	*s;
	int		rem;

	i = 0;
	if (base > 16 || base < 2)
		return (NULL);
	if (num == 0)
	{
		if (!(s = ft_strnew(0)))
			return (NULL);
		s[0] = '0';
		return (s);
	}
	s = ft_strnew(ft_len(num));
	while (num != 0)
	{
		rem = num % base;
		s[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= base;
	}
	ft_rev(s);
	return (s);
}
