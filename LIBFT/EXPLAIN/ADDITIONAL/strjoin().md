⭐strjoin()
============

PROTOTYPE
----------
        char *ft_strjoin(char const *s1, char const *s2)
        
PARAMETERS
----------
        #1. The prefix string.
        #2. The suffix string.
        
RETURN VALUE
-----------
        The new string. NULL if the allocation fails.

DESCRIPTION
-----------
        Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.

* 새로운 메모리 공간을 할당하여 문자열 `s1`을 복사하고 뒤에 `s2`를 붙인 문자열을 반환한다.
* `strlcpy`를 이용하여 `s1`을 복사하고 `strlcat`을 이용하여 `s2`를 갖다붙인다.
* `s1`을 복사할 때에는 `\0`까지 복사될 수 있도록 `strlen(s1)` + `1` 만큼의 길이를 준다.
* `s2`를 갖다붙일 때에는 `strlen(s1)` + `strlen(s2)` + `1` 만큼의 길이를 준다.
</br>
</br>
</br>
</br>
</br>
