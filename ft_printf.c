/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:48:01 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/13 15:10:10 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *f, ...)
{
	va_list list;
	va_start(list, f);
	int i = 0;
	while (f[i])
	{
		if(f[i + 1] != 0 && (f[i] == '%' && f[i + 1] == 'c'))
		{
			ft_putchar_fd(va_arg(list, int), 1);
		}if(f[i + 1] != 0 && (f[i] == '%' && f[i + 1] == 's'))
		{
			ft_putstr_fd(va_arg(list, char *), 1);
		}if(f[i - 1] != '%' && f[i] != '%')
			ft_putchar_fd(f[i], 1);
		i++;
	}
	va_end(list);
	return (0);
}

int main(){
	char c = 'c';
	char * s = "bien jouer";
	ft_printf("coucou %c moi %s", c, s);
}
