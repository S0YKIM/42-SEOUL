⭐strtrim()
===================

PROTOTYPE
----------
        char *ft_strtrim(char const *s1, char const *set)
        
PARAMETERS
----------
        #1. The string to be trimmed.
        #2. The reference set of characters to trim.
        
RETURN VALUE
-----------
        The trimmed string. NULL if the allocation fails.

DESCRIPTION
-----------
        Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.

* 문자열 `s1`의 앞과 뒤로부터 문자열 `set`에 해당하는 문자를 전부 쳐내고 남은 부분 문자열을 반환한다.
* 만약 `s1`이 `NULL`이면 반환값은 빈 문자열이 된다.
* 만약 `set`이 `NULL`이면 반환값은 `s1`을 복제한 문자열이 된다.
* 만약 `s1`이 전부 `set`으로 구성되어 있다면 `start`>=`end`가 되는데 이 경우에도 빈 문자열을 반환한다.
</br>
</br>
</br>
</br>
</br>
