#include <stdio.h>
i

int		main(void)
{
	char	*str = "abcdefg";

	/*****     d     *****/
	printf("%+5.3d\n", 5);
	printf("%5.3+d\n", 5);

	/*****     x     *****/
	printf("%+5.3x\n", 5);
	printf("%5.3+x\n", 5);
	// + 무시됨

	/*****     c     *****/
	printf("%+5.3c\n", 'a');
	printf("%5.3+c\n", 'a');
	// + 무시됨
	
	/*****     p     *****/
	printf("%+5.3p\n", str);
	printf("%5.3+p\n", str);
	// + 무시됨

	/*****     u     *****/
	printf("%+5.3u\n", 1);
	printf("%5.3+u\n", 1);
	// + 무시됨
	return (0);
}
