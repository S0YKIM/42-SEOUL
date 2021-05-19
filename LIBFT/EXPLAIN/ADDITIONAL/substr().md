
⭐substr()
===================

PROTOTYPE
----------
        char *ft_substr(char const *s, unsigned int start, size_t len)
        
PARAMETERS
----------
        #1. The string from which to create the substring.
        #2. The start index of the substring in the string ’s’.
        #3. The maximum length of the substring.
        
RETURN VALUE
-----------
        The substring. NULL if the allocation fails.

DESCRIPTION
-----------
        Allocates (with malloc(3)) and returns a substring from the string ’s’.
        The substring begins at index ’start’ and is of maximum size ’len’.

* 문자열 `s`에서 `start` 번째 인덱스부터 `len`만큼의 부분 문자열을 반환
* malloc()을 이용하여 반환할 문자열 만큼의 메모리를 할당하여야 한다.
* 메모리 할당에 실패하면 `NULL`을 반환한다.
* 문자열 `s`의 길이가 `start`보다 작으면 `NULL` 문자열을 반환한다.
* `len`은 부분 문자열의 최대 길이로 제한하였기 때문에 부분 문자열의 길이는

1. `len` < strlen(`s`+`start`) :  len
2. `len` > strlen(`s`+`start`) :  strlen(`s`+`start`)

</br>
</br>
</br>
</br>
</br>
