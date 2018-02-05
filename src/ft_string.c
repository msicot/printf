/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:43:48 by msicot            #+#    #+#             */
/*   Updated: 2018/01/29 10:54:38 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


static char	*ft_nul(char *s)
{
	int i;
	char *tmp;

	tmp = s;
	i = 0;
	if (!(s = ft_strnew(6)))
		return (NULL);
	s[i++] = '(';
	s[i++] = 'n';
	s[i++] = 'u';
	s[i++] = 'l';
	s[i++] = 'l';
	s[i++] = ')';
	free(tmp);
	return (s);
}
static void	ft_fill(char **s, char *val, t_arg *l, int k)
{
	int	i;
	int	len;
	int	lim;

	len = (int)ft_strlen(val);
	l->preci = (l->preci >= len) ? len : l->preci;
	lim = (l->point == 0) ? len : l->preci; 
	i = 0;
	if (l->minus == 0)
	{
		while (i < (k - lim))
			(*s)[i++] = (l->zero == 1) ? '0' : ' ';
		while (i < k)
			(*s)[i++] = *val++;
	}
	else
	{
		while (i < (lim)) 
			(*s)[i++] = *val++;
		while (i < k)
			(*s)[i++] = (l->zero == 1) ? '0' : ' ';
	}

}

static int	ft_champs_s(char *s, t_arg *l)
{
	int len;

	len = (s == NULL) ? 6 : (int)ft_strlen(s);
	if (l->point == 1 && l->preci < len)
		len = l->preci;
	len = (l->width > len) ? l->width : len;
	return (len);
}

char		*ft_string(t_arg *l, va_list ap)
{
	char	*s;
	char	*val;
	int	k;

	val = va_arg(ap, char*);
	if (val == NULL)
		if (!(val = ft_nul(val)))
			return (NULL);
	k = ft_champs_s(val, l);
//	printf("champs ->%d<-\n",k);
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill(&s, val, l, k);
	return (s);
}


/*
static char	*ft_preci(char *s, t_arg *l)
{
	char	*tmp;

	if (!(s))
		return (NULL);
	if (l->point == 1)
	{
		tmp = s;
		s  = ft_strncpy(ft_strnew(l->preci), s, l->preci);
		ft_strdel(&tmp);
	}
	return (s);
}

static char	*ft_width(char *s, t_arg *l)
{
	int		i;
	int		j;
	char	*pad;
	char	*tmp;

	if (!(s))
		return (NULL);
	j = 0;
	i = ft_strlen(s);
	if (l->width > i)
	{
		tmp = s;
		j = 0;
		pad = ft_strnew(l->width - i);
		while (j < (l->width - i))
			pad[j++] = (l->zero == 0) ? ' ' : '0';
		s = (l->minus == 1) ? ft_strjoin(s, pad) : ft_strjoin(pad, s);
		ft_strdel(&tmp);
		ft_strdel(&pad);
	}
	return (s);
}

char		*ft_string(t_arg *l, va_list ap)
{
	char	*s;

	s  = va_arg(ap, char *);
	s = ft_strsub(s, 0, ft_strlen(s));
	if (l->preci == 0 && l->point == 1)
	{
		ft_strdel(&s);
		s = ft_strnew(0);
	}
	if (!(s = ft_preci(s, l)))
		return (NULL);
	if (!(s = ft_width(s, l)))
		return (NULL);
	return (s);
}
*/
