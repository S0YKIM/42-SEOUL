#include /* header */

int ft_printf(const char * format, ...)
{
	ap	// 가변인자 포인터 선언
	len     // 총 출력 길이 저장할 변수 선언

	while ( /* format[i] 가 '\0'만날때까지  */)
	{
		// 구조체 초기화
		if (/* format[i] 가 '%' 만났다면 */)
		{
			while (/* format[i] 가 type 만날때까지 */)
				// 구조체에 각 플래그 할당!
			if (/* 현재 인덱스에서 format[i] 가 type인가??  */)
				// 출력모듈로 이동
		}
		else /* format[i] 가 '%' 안만났다면 */
		{
			// 그냥 char 출력 && 출력 길이 + 1
		}
		
	}
	return (/* 총 출력 길이 */);
}
