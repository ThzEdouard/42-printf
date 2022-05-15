/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:48:01 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/15 19:50:39 by eflaquet         ###   ########.fr       */
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
int	ft_intlen_base(int nb)
{
	int	result;

	result = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		result++;
		nb *= -1;
	}
	while (nb != 0)
	{
		result++;
		nb /= 16;
	}
	return (result);
}
int	ft_puthex(int o, int u)
{
	int i = ft_intlen_base(o);
	int tmp;
	char *f = ft_calloc(sizeof(char) , (i));
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
int	check_format(char c, va_list l)
{
	int i = 0;
	if(c == 'c')
		i += ft_putchar(va_arg(l, int));
	else if(c == 's')
		i += ft_putstr(va_arg(l, char *));
	else if(c == 'p')
		i += 1;
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

int main(){
	char c = 'c';
	int d = 156;
	int u = -255;
	int i = -15;
	int x = 5966968;
	char * s = "bien jouer";
	ft_printf("coucou %c moi %s est 156 = %d est i = %i, u = %u, x = %x est attention %% %", c, s, d, i,u, x);
	printf("\n%p\nu = %u\ni = %i\n x = %x ", "e", u, i, x);
}
