#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*string = "HELLO WORLD";
	char	c;
	
	ft_printf("my : |---|%#0.*X|---|\n", -4, 100);
	printf("ori: |---|%#0.*X|---|\n", -4, 100);

	ft_printf("my : |---|%#04X|---|\n", 0);
	printf("ori: |---|%#04X|---|\n", 0);

	ft_printf("my : |---|%#-4.*X|---|\n", -4, 0);
	printf("ori: |---|%#-4.*X|---|\n", -4, 0);

	ft_printf("my : |---|%#-4.4X|---|\n", 0);
	printf("ori: |---|%#-4.4X|---|\n", 0);

	ft_printf("my : |---|%#-4X|---|\n", 0);
	printf("ori: |---|%#-4X|---|\n", 0);

	/*****     c    *****/
	ft_printf("my : |---|%05.3c|---|\n", 'a');
	printf("ori: |---|%05.3c|---|\n", 'a');

	/*****     s    *****/
	ft_printf("my : |---|%-*5.3s|---|\n", -4,  string);
	printf("ori: |---|%-*5.3s|---|\n", -4, string);

	/*****     %    *****/
	ft_printf("my : |---|%05.3%|---|\n");
	printf("ori: |---|%05.3%|---|\n");

	/*****     p    *****/
	ft_printf("my : |---|%05.3p|---|\n", string);
	printf("ori: |---|%05.3p|---|\n", string);

	/*****     d    *****/
	ft_printf("my : |---|%05.3d|---|\n", 5);
	printf("ori: |---|%05.3d|---|\n", 5);

	/*****     x    *****/
	ft_printf("my : |---|%.3x|---|\n", 100000);
	printf("ori: |---|%.3x|---|\n", 100000);

	/*****    +    *****/
	ft_printf("my : |---|%+05.3d|---|\n", 5);
	printf("ori: |---|%+05.3d|---|\n", 5);

	/*****    space   *****/
	ft_printf("my : |---|%- 5.5d|---|\n", 555);
	printf("ori: |---|%- 5.5d|---|\n", 555);

	/*****    hashtag    *****/
	ft_printf("my : |---|%0#10x|---|\n", 555);
	printf("ori: |---|%0#10x|---|\n", 555);
	
	ft_printf("my : |---|%0#5.3X|---|\n", 999999999);
	printf("ori: |---|%0#5.3X|---|\n", 999999999);

	ft_printf("my : |---|%0#4X|---|\n", 10);
	printf("ori: |---|%0#4X|---|\n", 10);

	/*****    o    *****/
	ft_printf("my : |---|%.6o|---|\n", 555);
	printf("ori: |---|%.6o|---|\n", 555);

	return (0);
}
