/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:14:38 by msicot            #+#    #+#             */
/*   Updated: 2018/02/13 09:25:46 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_printable(char s)
{
	if ((int)s < 255 && MB_CUR_MAX == 1)
		return (1);
	s = s >> 3;
	if (s == 30)
		return (4);
	s = (s >> 1) & 14;
	if (s == 14)
		return (3);
	s = (s >> 1) & 6;
	if (s == 6)
		return (2);
	return (1);
}

static void	ft_preci_s(char **s, t_arg *l)
{
	int		i;
	int		len;
	char	*tmp;
	
	tmp = *s;
	i = 0;
	if (l->point == 1 && (*s) != NULL)
	{
		if (l->preci == 0)
			ft_bzero(*s, ft_strlen(*s));
		else
		{
			while (i < l->preci)
			{
				len = ft_printable(tmp[i]);
	//			printf("len-->%d<--\n", len);////
				if (len == 1 && i < l->preci)
					++i;
				else if (len > 1 && MB_CUR_MAX == 1)
					break ;
				else if (i + len <= l->preci)
					i += len;
				else if (i + len > l->preci)
					break ;
			}
	//		printf("i->%d<-\n", i);//
			len = (int)ft_strlen(*s);
	//		printf("len=%d i=%d\n", len, i);/////
			while (i < len)
				(*s)[i++] = '\0';
		}
	}
}

static char	*ft_width_s(char *s, t_arg *l)
{
	char	*tmp;
	int		len;
	char	*pad;
	int		i;

	i = 0;
	len = (int)ft_strlen(s);
	tmp = s;
	if (l->width > len)
	{
		if (!(pad = ft_strnew(l->width - len)))
			return (NULL);
		while (i < (l->width - len))
			pad[i++] = ' ';
		if (!(s = (l->minus == 0) ? ft_strjoin(pad, s) : ft_strjoin(s,pad)))
			return (NULL);
	ft_strdel(&pad);
	ft_strdel(&tmp);
	}
	return (s);
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
	if (ft_error_uni_s(l , u) == 1)
		return (s);
	if (u < 128 || (u <= 255 && MB_CUR_MAX == 1))
	{
		s2[0] = (char)u;
//		printf("s2 ->%s<- LEN=%d\n", s2, (int)ft_strlen(s2));///
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
//	printf("s__>%s<__\n", s);///
	ft_preci_s(&s, l);
	if (s != NULL)
	{
	if (!(s = ft_width_s(s, l)))
		return (NULL);
	}
//	ft_putstr("test");///	
	l->x = 0;
//	printf("_%s_\n", s);///
	return (s);
}
