/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:14:38 by msicot            #+#    #+#             */
/*   Updated: 2018/02/12 15:20:44 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_printable(char x)
{
	int s;

	s = (int)x;
	printf("s ->%d<-\n", s);
	s = s >> 3;
	if (s == 30)
		return (4);
	s = s >> 1;
	if (s == 14)
		return (3);
	s = s >> 1;
	if (s == 6)
		return (2);
	return (1);
}

static void	ft_width_s(char **s, t_arg *l)
{
	int		i;
	int		len;
	char	*tmp;
	
	tmp = *s;
	len = 0;
	i = 0;
	if (l->point != 0 && (*s) != NULL)
	{
//		ft_printable(s, l);
		while (i < l->preci)
		{
			len = ft_printable(tmp[i]);
			ft_putnbr(len);
			ft_putchar('\n');
			if (i + len < l->preci)
				i += len;
			else
				break ;
		}
	
//		printf("len->%d\tl->preci->%d\n", (int)ft_strlen(*s), l->preci);
		(*s) = ft_strncpy(*s, *s, i);
	}
}

static char	*ft_is_unic_s(wchar_t u, t_arg *l)
{
	char	*s;
	char	*s2;

	s = NULL;
	s2 = ft_strnew(1);
	l->sign = 0;
	l->neg = 0;
	l->zero = 0;
	if (ft_error_uni(l , u) == 1)
		return (s);
	if (u < 128 || (u <= 255 && MB_CUR_MAX == 1))
	{
		s2[0] = (char)u;
		return (s2);
	}
	else if (u >= 128)
		s = ft_unicode2(u, l);
	return (s);
}


char	*ft_is_unis(va_list ap, t_arg *l)
{
	char	*s;
	wchar_t *u;
	char	*tmp;
	char	*tmp2;
	int	i;
	
	l->x = 1;
	i = 0;
	tmp = NULL;
	s = ft_strnew(0);
	u = va_arg(ap, wchar_t*);
	while (u[i])
	{
		tmp2 = s;
		tmp = ft_is_unic_s(u[i++], l);
		s = ft_strjoin(s, tmp);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
	}
	l->x = 0;
	ft_width_s(&s, l);
//	ft_putstr("test");
	
//	printf("_%s_\n", s);
	return (s);
}
