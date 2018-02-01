/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:09:01 by msicot            #+#    #+#             */
/*   Updated: 2018/02/01 18:08:16 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*
static void ft_check_0(char *val, t_arg *l)
{
	if (ft_strlen(val) == 1 && l->point == 1 && l->preci == 0)
	{
		if (l->width != 0)
		{
			if (val[0] == '0')
				val[0] = ' ';
		}
		else
			val[0] = '\0';
	}
}
*/

static void	ft_fill_it(char **s, char *val,  t_arg *l, int k)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
//	ft_check_0(val, l);
	if (l->preci >= l->width && l->preci != 0)
		ft_preci_d(s, val, l, k);
	else //if (l->preci < l->width)
		ft_width_d(s, val, l, k);
}

static char	*ft_integer_o(uintmax_t val, t_arg *l)
{
	char 		*s;
	char		*num;
	int			k;

	if (!(num = ft_itoa_base(val, 8)))
		return (NULL);
	k = ft_champs(num, l);
//	printf("champs -->%d\n", k + 9);
	if (!(s = ft_strnew(k)))
		return (NULL);
	ft_fill_it(&s, num, l, k);
	ft_strdel(&num);
	return (s);

}

static char	*ft_is_octal2(va_list ap, t_arg *l)
{
	if (l->j == 1)
		return (ft_integer_o(va_arg(ap, uintmax_t ), l));
	if (l->ll == 1)
		return (ft_integer_o((va_arg(ap, unsigned long long)), l));
	if (l->l == 1)
		return (ft_integer_o((va_arg(ap, long unsigned int)), l));
	if (l->z == 1)
		return (ft_integer_o((va_arg(ap, size_t)), l));
	if (l->hh == 1)
		return (ft_integer_o(((unsigned char)(va_arg(ap, unsigned int))), l));
	if (l->h == 1)
		return (ft_integer_o(((va_arg(ap, unsigned int))), l));
	return (ft_integer_o((va_arg(ap, unsigned int)), l));
}

char	*ft_is_octal(t_arg *l, va_list ap)
{
	char 		*s;

	l->sign = 0;
	l->plus = 0;
	l->o = 1;
	if (!(s = ft_is_octal2(ap, l)))
		return (NULL);
	return (s);

}
