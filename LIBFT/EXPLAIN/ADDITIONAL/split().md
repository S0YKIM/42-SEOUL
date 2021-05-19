⭐split()
=============

PROTOTYPE
----------
        char **ft_split(char const *s, char c);
        
PARAMETERS
----------
        #1. The string to be split.
        #2. The delimiter character.
        
RETURN VALUE
-----------
        The array of new strings resulting from the split. NULL if the allocation fails.

DESCRIPTION
-----------
        Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.
        The array must be ended by a NULL pointer.

* 문자열 `s`에서 문자 `c` 를 기준으로 나눈 문자열들을 반환한다.
* 메모리 할당 시에 필요하기에 최종적으로 반환되는 문자열들의 개수를 세는 함수를 만들었다.
* 메모리 할당이 실패할 경우 지금까지 할당된 메모리를 free()해주는 함수를 만들었다.

</br>
</br>
</br>
</br>
</br>
