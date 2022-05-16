/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:48:01 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/16 19:17:22 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
char	*ft_u_itoa(unsigned int n);



int ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return(1);
}
int ft_putstr(char *s)
{
	int i;
	if(!s)
	{
		ft_putstr_fd("(null)", 1);
		i = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		i  =  ft_strlen(s);
	}
	return(i);
}
int ft_putnbr_len(int d)
{
	char*	s;
	int		i;

	s = ft_itoa(d);
	ft_putstr_fd(s, 1);
	i = ft_strlen(s);
	free(s);
	return(i);
}
int ft_putnbr_u(unsigned int d)
{
	char*	s;
	int		i;

	s = ft_u_itoa(d);
	ft_putstr_fd(s, 1);
	i = ft_strlen(s);
	free(s);
	return(i);
}
int	ft_intlen_base(unsigned int nb)
{
	int	result;

	result = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		result++;
		nb /= 16;
	}
	return (result);
}
int	ft_puthex(unsigned int o, char *base)
{
	unsigned int i = 0;
	unsigned int tmp;
	tmp = o;
		if(tmp < 16)
			i += ft_putchar(base[tmp]);
		else
		{
			i += ft_puthex(tmp / 16, base);
			i += ft_puthex(tmp % 16, base);
		}

	return (i);
}
int	ft_put_padress (void const *p, char const *base, int s)
{
	unsigned long adr;
	int x = 0;
	if(!p && s != 1)
		return(ft_putstr("(nil)"));
	adr = (unsigned long) p;
	if(!s)
		x += ft_putstr("0x");
	if(adr < 16)
		x += ft_putchar(base[adr]);
	else
	{
		x += ft_put_padress((const void *)((unsigned long)p / 16), base, 1);
		x += ft_put_padress((const void *)((unsigned long)p % 16), base, 1);
	}

   return (x);
}
int	check_format(char c, va_list l)
{
	int i = 0;
	if(c == 'c')
		i += ft_putchar(va_arg(l, int));
	else if(c == 's')
		i += ft_putstr(va_arg(l, char *));
	else if(c == 'p')
		i += ft_put_padress(va_arg(l, void *),"0123456789abcdef", 0);
	else if(c == 'd')
		i += ft_putnbr_len(va_arg(l, int));
	else if(c == 'i')
		i += ft_putnbr_len(va_arg(l, int));
	else if(c == 'u')
		i += ft_putnbr_u((unsigned int)va_arg(l, unsigned int));
	else if(c == 'x')
		i += ft_puthex(va_arg(l, int), "0123456789abcdef");
	else if(c == 'X')
		i += ft_puthex(va_arg(l, int), "0123456789ABCDEF");
	else if(c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *f, ...)
{
	va_list list;
	va_start(list, f);
	int rest = 0;
	int i = 0;
	while(f[i])
	{
		if(f[i] == '%')
		{
			if(f[i + 1] != 0)
			{
				rest += check_format(f[i+1], list);
				i++;
			}
		}else
			rest += ft_putchar(f[i]);
		i++;
	}
	va_end(list);
	return (rest);
}
