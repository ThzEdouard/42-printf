/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:32:49 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/16 00:50:52 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <inttypes.h>

#include "ft_printf.h"

int main(){
	char c = 'c';
	int d = 156;
	int u = -255;
	int i = -15;
	int x = 42924697;

char const *po = "helloss bg tesfk ";

	char * s = "bien jouer";
	int y = ft_printf("\ncoucou %c moi %s est 156 = %d est i = %i, u = %u, x = %x est attention %% p = %p %s", c, s, d, i,u, x,  po, NULL);
	int p = printf("\ncoucou %c moi %s est 156 = %d est i = %i, u = %u, x = %x est attention %% p = %p %s", c, s, d, i,u, x,  po, NULL);

	 printf("\n%p\nu = %u\ni = %i\n x = %x ", "u", u, i, x);
	 printf("\n y = %d    printf = %d", y, p);


   printf ("\n%p\n", (void *) po);
   printf(" NULL %s NULL ", NULL);
   printf("\n");
   ft_printf(" NULL %s NULL ", NULL);
}
