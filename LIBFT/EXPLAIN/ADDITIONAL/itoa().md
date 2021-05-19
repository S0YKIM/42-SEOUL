⭐itoa()
===================

PROTOTYPE
----------
        char *ft_itoa(int n)
        
PARAMETERS
----------
        #1. the integer to convert.
        
RETURN VALUE
-----------
        The string representing the integer. NULL if the allocation fails.

DESCRIPTION
-----------
        Allocates (with malloc(3)) and returns a string representing the integer received as an argument.
        Negative numbers must be handled.

* 정수형 `n`을 입력 받으면 문자열 형태로 변환하여 반환한다.
* 메모리 할당 시에 필요하므로 `n`의 길이를 세어주는 함수를 만들었다.
* `n` 이 음수일 경우 양수로 바꾸어주는 절댓값 함수를 만들었다.
* `n`이 음수일 경우 메모리 할당 시에 `-` 부호를 위한 자리 하나를 추가해주어야 한다.
</br>
</br>
</br>
</br>
</br>
