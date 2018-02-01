/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:57:59 by msicot            #+#    #+#             */
/*   Updated: 2018/02/01 18:26:59 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>	
#include "../libft/inc/libft.h"
#include <stdio.h> //////DELETTTTEEEEEE
#include <limits.h>
# define BUFF_SIZE 32
# define LEN l->len

typedef struct s_arg
{
	char	*str;
	int		len;
	int		zero;
	int		plus;
	int		minus;
	int		blank;
	int		sharp;
	int		point;
	int		pourc;
	int		neg;
	int		preci;
	int		width;
	int		sign;
	int		exit;
	int		wild;
	int		hh;
	int		h;
	int		j;
	int		l;
	int		ll;
	int		z;
	int		us;
	int		o;
}				t_arg;

int		ft_printf(const char *format, ...);
void	ft_flag_reset(t_arg *arg);
char	*ft_itoa_max(intmax_t n);
void	ft_flag_override(t_arg *l);
void	ft_is_flag(const char *format, t_arg *l);
void	ft_error_flag_format();
void	ft_is_preci(const char *f, t_arg *l, va_list ap);
void	ft_is_width(const char *f, t_arg *l, va_list ap);
void	ft_format_delim(const char *f, t_arg *l, va_list ap);
void	ft_lecture(char *buf, t_arg *l, const char *f, va_list ap);
void	ft_merge(char *buf, t_arg *l);
char	*ft_integer(intmax_t val, t_arg *l);
void	ft_mna(char *s, t_arg *l);
void	ft_is_type (const char *f, t_arg *l);
char	*ft_is_d(va_list ap, t_arg *l);
char	*ft_is_u(va_list ap, t_arg *l);
char	*ft_is_octal(t_arg *l, va_list ap);
char	*ft_string(t_arg *l, va_list ap);
char	*ft_pourc(t_arg *l);
char	*ft_itoa_base(intmax_t num, unsigned int base);
char	*ft_itoa_unsigned(uintmax_t n);
void	ft_gnf(t_arg *l, const char *f, va_list ap);
char	*ft_width_int(char *s, t_arg *l);
char	*ft_preci_int(char *s, t_arg *l);
void	ft_preci_d(char **s, char *val, t_arg *l, int k);
void	ft_width_d(char **s, char *val, t_arg *l, int k);
void	ft_width_o(char **s, char *val, t_arg *l, int k);
void	ft_signin(char **s, t_arg *l, int k, int lim);
void	ft_wp_zero(char **s, char *val, t_arg *l, int k);
int		ft_champs(char *s, t_arg *l);

//char	*ft_sign2(char *s, char *sign);

#endif
