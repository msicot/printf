/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:57:50 by msicot            #+#    #+#             */
/*   Updated: 2018/02/08 17:58:57 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_fill(char **s, t_arg *l, int k, char c)
{
	int i;

	i = 0;
	l->add = (c == '\0'/* && l->minus == 0*/) ? ++l->add : l->add;
	if (l->minus == 0 || c == 0)
	{
		while (i < k - 1)
			(*s)[i++] = (l->zero == 1) ? '0' : ' ';
		if (i < k)
		{
	//		if (c == 0 && l->minus == 1 && l->width == 0)
	
			(*s)[i] = (c == '\0') ? '\0' : c;
		}
	}
	else 
	{
		if (i < k)
			(*s)[i++] = (c == '\0') ? '\0' : c;
		while (i < k)
			(*s)[i++] = (l->zero == 1) ? '0' : ' ';
	}
}

static int	ft_champs_c(char c, t_arg *l)
{
	int len;

	len = 1;
	len = (c != '\0') ? len: len;
	len = (l->width > len) ? len + (l->width - len) : len;
	return (len);

}
char	*ft_char_c(char c, t_arg *l)
{
	char	*s;
	int	k;

	k = ft_champs_c(c, l);
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill(&s, l, k, c);
	return (s);
}

char	*ft_is_c(va_list ap, t_arg *l)
{
	if (l->l == 1)
		return (ft_is_unic(ap, l));
	return (ft_char_c((char)va_arg(ap, int), l));
}
