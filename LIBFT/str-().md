        str 계열 함수들은 NULL 문자를 체크해야 한다.
        C언어에서 문자열은 기본적으로 문자열의 마지막을 '\0'으로 표시하기 때문이다.
</br>
</br>
</br>

문자열 길이 세기와 비교
=================

</br>

⭐strlen()
===================

SYNTAX
------
        size_t	ft_strlen(const char *s)

DESCRIPTION
----------- 

* 문자열 `s` 에서 '\0' 이 발견될 때가지 길이를 계산
</br>
</br>
</br>
</br>

⭐strncmp()
===================

SYNTAX
------
        int		ft_strncmp(const char *s1, const char *s2, size_t n)

DESCRIPTION
-----------
        The strncmp() function compares not more than n characters.
        Because strncmp() is designed for comparing strings rather than binary data, characters that appear after a `\0' character are not compared.
        The comparison is done using unsigned characters, so that `\200' is greater than `\0'.

* 문자열 `s1`과 문자열 `s2`을 `n`만큼 비교한다
</br>
</br>
</br>
</br>
</br>

문자열 복사와 붙여넣기
=================

* The `strlcpy()` and `strlcat()` functions copy and concatenate strings.
* They are designed to be safer, more con-sistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3).
* `strlcpy()` and `strlcat()` take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NUL should be included in dstsize.
</br>
</br>
</br>

⭐strlcpy()
===================

SYNTAX
------
        size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

DESCRIPTION
-----------
        strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.   

* `dstsize` - 1 만큼 src 에서 dst 로 복사한다.
* `dstsize` 가 0 이 아니라면 언제나 '\0' 으로 끝난다.
</br>
</br>
</br>
</br>

⭐strlcat()
================

SYNTAX
------
    size_t ft_strlcat(char * restrict dst, const char * restrict src, size_t size);

DESCRIPTION
-----------
        strlcat() appends string src to the end of dst. 
        It will append at most size - strlen(dst) - 1 characters.
        It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize
        (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string).

* 문자열 `src` 를 `dst` 의 끝에 추가한다.
* `dst`의 마지막 위치에 `src` 를 `size` - `strlen(dst)` - 1 만큼 복사하고 끝에 '\0'를 삽입한다.
* 최종적으로 반환되는 것은 __결합되는 문자열의 총 길이__이다.
* size <= strlen(dst) + 1 :  strlen(src) + size 를 반환!
* size > strlen(dst) + 1 :  strlen(src) + strlen(dst)를 반환!

</br>
</br>
</br>
</br>
</br>

문자열 검색
==============
</br>

⭐strchr()  ⭐strrchr()
=======================

SYNTAX
------
    char	*ft_strchr(const char *str, int value)

DESCRIPTION
-----------
        The strchr() function locates the first occurrence of c (converted to a char) in the string pointed to by s.
        The terminating null character is considered to be part of the string.
        Therefore if c is `\0', the functions locate the terminating `\0'.
        
* 문자열 `str` 에서 (unsigned char 로 변환된) `value` 를 검색
* `strchr()` 은 문자열의 앞에서부터 `strrchr()`은 뒤에서부터 검색한다는 점만 다르다
* 반환값: `value` 가 발견된 `str` 의 주소 또는 발견되지 않은 경우 '널포인터'

</br>
</br>
</br>
</br>
</br>

⭐strnstr
==========

SYNTAX
------
    char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

DESCRIPTION
-----------
        The strnstr() function locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched.
        Characters that appear after a `\0' character are not searched.
        
* 문자열 `haystack` 에서 문자열 `needle` 을 `len` 만큼만 검색
* 반환값
1. `needle` 이 빈 문자열: `haystack`
2. `needle` 이 `haystack` 에서 발견되지 않는 경우: '널포인터'
3. `needle`이 `haystack` 에서 발견되는 경우: `needle` 이 발견된 `haystack` 의 메모리 주소
