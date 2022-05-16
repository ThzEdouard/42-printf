/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:32:49 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/16 17:24:29 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
int main(){
	char c = 'c';
	int d = 156;
	int u = -255;
	int i = -15;
	int x = 42924697;

char const *po = "helloss bg tesfk ";

	char * s = "bien jouer";
	int y = ft_printf("\ncoucou %c moi %s est 156 = %d est i = %i, u = %u, x = %x ", c, s, d, i,u, x);
	int p = printf("\ncoucou %c moi %s est 156 = %d est i = %i, u = %u, x = %x ", c, s, d, i,u, x);

	printf("\n%p\nu = %u\ni = %i\n x = %x ", "u", u, i, x);
	 printf("\n y = %d    printf = %d", y, p);


   printf ("\n%p\n", (void *) po);
   printf(" %x ", INT_MIN);
   printf("\n");
   ft_printf(" %x ", INT_MIN);
}
