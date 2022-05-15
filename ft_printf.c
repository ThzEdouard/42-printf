/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:48:01 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/15 23:35:10 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*ft_u_itoa(unsigned int n);



int ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return(1);
}
int ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
	return(ft_strlen(s));
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
int	ft_puthex(unsigned int o, int u)
{
	unsigned int i = ft_intlen_base(o);
	unsigned int tmp;
	char *f = ft_calloc(sizeof(char) , (i + 1));
	while(o != 0)
	{
		tmp = o % 16;
		if(tmp < 10)
			tmp = tmp + 48;
		else
		{
			if(u == 0)
				tmp = (tmp + 55) + 32;
			else
				tmp = (tmp + 55);
		}
		f[--i] = tmp;
		o /= 16;
	}
	i = ft_putstr(f);
	return (i);
}
int my_put_padress (void const *p)
{
   unsigned long adr;
   char const *base;
   char res[9];
   int i;
int x = 0;
   adr = (unsigned long) p;
   base = "0123456789abcdef";
   i = 8;
   while ((adr / 16) > 0 || i >= 8)
   {
      res[i] = base[(adr % 16)];
      adr /= 16;
      i--;
   }
   res[i] = base[(adr % 16)];
   	x += ft_putstr ("0x");
   while (i < 9)
   {
      x += ft_putchar (res[i]);
      i++;
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
		i += my_put_padress(va_arg(l, void *));
	else if(c == 'd')
		i += ft_putnbr_len(va_arg(l, int));
	else if(c == 'i')
		i += ft_putnbr_len(va_arg(l, int));
	else if(c == 'u')
		i += ft_putnbr_u((unsigned int)va_arg(l, unsigned int));
	else if(c == 'x')
		i += ft_puthex(va_arg(l, int), 0);
	else if(c == 'X')
		i += ft_puthex(va_arg(l, int), 1);
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
			if(f[i + 1] != 0 && (rest += check_format(f[i+1], list)))
				i++;
		}else
			rest += ft_putchar(f[i]);
		i++;
	}
	va_end(list);
	return (rest);
}
