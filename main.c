#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	ft_printf("coucou\n");
	ft_printf("\n");
	//ft_printf("ft_trop\n", "truc");
	//printf("trop\n", "truc");
	char	*s;
	int	tab[] = {65, 65465, 5132, 0, -6545, -1};
	unsigned int num = 65;
	s = NULL;
	unsigned char c = '\200';
	ft_printf("ft: %c = %d\n", c, 656);
	printf("c: %c = %d\n", c, 656);

	ft_printf("ft: %d = %d\n", c, 656);
	printf("c: %c = %d\n", c, 656);

	ft_printf("ft: %p = %d\n", s, 656);
	printf("c: %p = %d\n", s, 656);

	ft_printf("ft: %p = %d\n", tab, 656);
	printf("c: %p = %d\n", tab, 656);

	ft_printf("ft: %p = %u\n", tab, num);
	printf("c: %p = %u\n", tab, num);

	ft_printf("ft: %p = %%%u\n", tab, num);
	printf("c: %p = %%%u\n", tab, num);
	return (0);
}
