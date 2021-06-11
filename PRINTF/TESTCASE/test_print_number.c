#include <stdio.h>

int		main(void)
{	/*******    음수와 0 플래그   *******/
	printf("%05d\n", -5);
	// -0005 출력

	/*******    precision: 0, 정수: 0    *******/
	printf("%05.d\n", 0);
	// 아무것도 출력되지 않음
	
	printf("%05.p\n", 0);
	return (0);
}
