⭐strmapi()
===================

PROTOTYPE
----------
        char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
        
PARAMETERS
----------
        #1. The string on which to iterate.
        #2. The function to apply to each character.
        
RETURN VALUE
-----------
        The string created from the successive applications of ’f’. Returns NULL if the allocation fails.

DESCRIPTION
-----------
        Applies the function ’f’ to each character of the string ’s’ to create a new string (with malloc(3)) resulting from successive applications of ’f’.


* 문자열 `s`에 속한 모든 문자를 함수 포인터 `*f()` 에 대입하여 반환된 문자들을 모은 문자열을 반환한다.
* `s`의 길이를 세어 메모리를 할당한 다음 `*f()`으로부터 반환된 문자들을 하나하나 저장하여 반환한다.

</br>
</br>
</br>
</br>
</br>
