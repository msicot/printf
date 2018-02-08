/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:09:26 by msicot            #+#    #+#             */
/*   Updated: 2018/02/08 20:17:38 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static void 	ft_width_uni(char **s, char *tmp, t_arg *l, int c)
{
	int		len;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	len  = ft_strlen(tmp);
	if (l->minus == 0)
	{
		while (i < (c - len))
			(*s)[i++] = ' ';
		while (i < c)
			(*s)[i++] = tmp[j++];
	}
	else
	{
		while (i < len)
			(*s)[i++] = tmp[j++];
		while (i < (c))
			(*s)[i++] = ' ';
	}
//	printf("s -<%s<-", *s);
}

static char	*ft_conv(int *tab, t_arg *l)
{
	char	*s;
	int		c;
	int		k;
	int 	i;
	char	tmp[5];
	

	k = 0;
	i = 0;
	while (tab[i] != 0)
		tmp[k++] = (char)tab[i++];
	tmp[k] = '\0';
	c = ft_champs(tmp, l);
	s = ft_strnew(c);
	ft_width_uni(&s, tmp, l, c);
	
//s[k++] =  'x';
//	printf("s->%s<-\n",s);

	return (s);
}
static char	*ft_unicode2(wchar_t u, t_arg *l)
{
	int i[5];

	int z = 0;
	while (z < 5)
		i[z++] = 0;
	if (u >= 128 && u <= 2047)
	{
		i[1] = 128 + (u & 63);
		i[0] = 192 + (u >> 6);
	}
	else if (u > 2047 && u <= 65535)
	{
		i[2] = 128 + (u & 63);
		u = u >> 6;
		i[1] = 128 + (u & 63);
		u = u >> 6;
		i[0] = 224 + u;
	}
	else if (u > 65535 && u <= 2097151)
	{
		i[3] = 128 + (u & 63);
		u = u >> 6;
		i[2] = 128 + (u & 63);
		u = u >> 6;
		i[1] = 128 + (u & 63);
		u = u >> 6;
		i[0] = 240  + u;
	}
	return (ft_conv(i, l));;
}


char	*ft_is_unic(va_list ap, t_arg *l)
{
	wchar_t	u;
	char	*s;

	
	s = NULL;
	l->sign = 0;
	l->neg = 0;
	l->zero = 0;
	l->point = 0;
	l->preci = 0;
	u = va_arg(ap, wchar_t);
//	printf("cur ->%d<-\n", MB_CUR_MAX);
	if (ft_error_uni(l , u) == 1)
		return (s);
	if (u < 128 || (u >= 128 && MB_CUR_MAX == 1))
		s = ft_char_c((char)u, l);
	else if (u >= 128)
		s = ft_unicode2(u, l);
//	ft_width_uni(&sf, s, t_arg *l);
	return (s);
}

/*
static void	ft_fill_tab(int **t, int i)
{
	int j;

	j = 0;
	if (i > 4)
		(*t)[j++] = 240;i // 4
	else if (i > 3)
		(*t)[j++] = 224; // 3
	else if (i > 2)
		(*t)[j++] = 192; // 2
	while (j < i - 1)
		(*t)[j++] = 128; 1 
	(*t)[j++] = 0;
}

static int	**ft_unicode2(int **tab, wchar_t u)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (u <= 2047)
		i = 2;
	else if (u <= 65525)
		i = 3;
	else if (u > 65525)
		i = 4;
	if (!(tab = (int**)malloc(sizeof(int*) + i + 1)))
			return (0);
	while (j < i)
		if (!(tab[j++] = (int*)malloc(sizeof(int))))
			return (0);
	ft_fill_tab(tab, i + 1);
	j = 0;
	while (j <= i)
	{
		printf("tab[%d] ->%d\n",j , (*tab)[j]);
		++j;
	}
	ft_putchar('\n');
	return (tab);
}

static void	ft_conv(int **tab, int j, wchar_t u)
{
	int	t[2];
	int	k;
	int	mask;
	wchar_t tmp;

	k = 0;
	k = j;
	tmp = u;
//	t = (int**)malloc(sizeof(int*));
//	while (k < j)
//		t[k++] = (int *)malloc(sizeof(int));
	//	*t[k+1] = *((u & 63) + &i[1]);
	k  = (*tab)[0] + (u >> 6);
	printf("k ->%d<-\n", k);
	mask = (*tab)[0];
	ft_putendl("test 3");///
	t[0] = k;
	t[1] = (tmp & 63) + (*tab)[1];
ft_putendl("test 4");///

	char *s[2];
	s[0] = ft_itoa_base((uintmax_t)t[0], 16, 0);
	s[1] = ft_itoa_base((uintmax_t)t[1], 16, 0);
	
	ft_printf("s->%s<-\n s2->%s<-\n", s[0], s[1]);///
	
}

char	*ft_is_unic(va_list ap, t_arg *l)
{
	char	*s;
	wchar_t	u;
	int 	**tab;
	int	j;

	j = 0;
	s = NULL;
	tab = NULL;
	u = va_arg(ap, wchar_t);
	if (u <= 255)
	{
		if (!(s = ft_strnew(2)))
			return (NULL);
		s[j++] = (char)u;
		return (s);
	}
	else if (u > 127)
	{
		tab = ft_unicode2(tab, u);
		ft_conv(tab, j, u);
	}
	l->z = 0;
//	free(&i);
	return (s);
}*/
