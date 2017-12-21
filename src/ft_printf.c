/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 07:13:57 by msicot            #+#    #+#             */
/*   Updated: 2017/12/21 18:21:03 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	ft_flags(char *format)
{
	printf("lol");
}

int	ft_printf(const char *format, ...)
{
	char	*str;
	t_arg	*arg;
	va_list	ap;
	int		i;
	
	*str = *format;
	i = 0;
	if (!(arg = (t_arg*)malloc(sizeof(t_arg))))
		exit(1);	
	arg->len = 0;
	while (*format)
	{
		if (*format != '%')
		{
			++arg->len;
			ft_putchar(format);
		}
		else
			ft_flags(format);
		*format++;
	}

	printf("%d\n",arg->len);
	va_start (ap, format);
	return (1);
}
