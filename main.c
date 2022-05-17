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

	char	*coco;
	coco = NULL;
	char	**super;
	super = malloc(sizeof(char *) * 3);
	super[0] = "hahaha";
	super[1] = "";
	super[2] = NULL;

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

	ft_printf("tests : %p\n", coco);
	printf("tests : %p\n", coco);
	int	i = 0;
	while (super[i])
	{
		printf("coco %c \n", 78);
		ft_printf("super %c %i = %x = %X = %s = %p de %p avec %%%% %\n", 78, i, 897, 90, super[i], super[i], super);
		i++;
	}
	return (0);
}
