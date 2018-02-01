/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:00:28 by msicot            #+#    #+#             */
/*   Updated: 2018/01/31 12:32:00 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_wp_zero(char **s, char *val, t_arg *l, int k)
{
	int i;
	int j;
	int	len;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->blank == 1)
		(*s)[i++] = ' ';
	else if (l->sign == 1)
		(*s)[i++] = (l->neg == 1) ? val[j++] : '+';
	while (i < k && j < len)
		(*s)[i++] = val[j++];
}

static void	ft_else_width(char **s, char *val, t_arg *l, int k)
{
	int i;
	int j;
	int	len;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->zero == 1)
	{
		if (l->sign == 1)
			(*s)[i++] = (l->neg == 1) ? val[j++] : '+';
		while (i < (k - len - l->neg))
			(*s)[i++] = '0';
		while (i < k && j < len)
			(*s)[i++] = val[j++];
	}
	else
	{
		while (i < (k - len - l->neg))
			(*s)[i++] = ' ';
		if (l->sign == 1)
			(*s)[i++] = (l->neg == 1) ? val[j++] : '+';
		while (i < k && j < len)
			(*s)[i++] = val[j++];
	}
}

void	ft_width_sup(char **s, char *val, t_arg *l, int k)
{
	int i;
	int	len;
	int j;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->width == 0 && l->preci == 0)
		ft_wp_zero(s, val, l, k);
	else if (l->minus == 0)
		ft_else_width(s, val, l, k);
//	else if (l->minus == 1)


	/* premier char ?? 
	 * si l->blank == 1 espace compris dans la longueur de width
	 * si l->sign -> il faut mettre un sign si le flag _ == 0
	 *
	 *
	 *
	 * */

}

void	ft_preci_sup(char **s, char *val, t_arg *l, int k)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(val);
	j = 0;
	i = 0;
	if (l->blank == 1)
		(*s)[i++] = ' ';
	else if (l->sign == 1)
		(*s)[i++] = (l->neg == 1) ? val[j++] : '+';
	while (i < (k - (len - l->neg)))
		(*s)[i++] = '0';
	while (i < k && j < len)
		(*s)[i++] = val[j++];
}


char	*ft_preci_int(char *s, t_arg *l)
{
	char	*tmp;
	char	*pad;
	int		j;
	int		len;

	len = ft_strlen(s);
	tmp = s;
	j = 0;
	if (l->preci == 0)
		return (s);
	if (l->preci > len)
	{
		if (!(pad = ft_strnew(l->preci - len)))
			return (NULL);
		while (j < (l->preci - len))
		{
			pad[j] = '0';
			++j;
		}
//		printf("pad --->%s<---\n", pad);
		s = ft_strjoin(pad, s);
		ft_strdel(&pad);
		ft_strdel(&tmp);
	}
	return (s);
}

char	*ft_width_int(char *s, t_arg *l)
{
	char	*tmp;
	char	*pad;
	int		j;
	int		len;
	int		k;
	
	k = 0;
	if (l->sign == 1 || l->blank == 1)
		k = 1;
	j = 0;
	len = ft_strlen(s);
	if (l->width > len + l->sign)
	{
		tmp = s;
		if (!(pad = ft_strnew(l->width - len - k)))
			return (NULL);
		while (j < (l->width - len - k))
			pad[j++] = (l->zero == 1) ? '0' : ' ';
		if (l->minus == 1)
			s = ft_strjoin(s, pad);
		else
			s = ft_strjoin(pad, s);
		ft_strdel(&tmp);
		ft_strdel(&pad);
	}
	return (s);
}
