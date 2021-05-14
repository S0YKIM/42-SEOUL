문자열 복사와 붙여넣기
=================

* The `strlcpy()` and `strlcat()` functions copy and concatenate strings.
* They are designed to be safer, more con-sistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3).
* `strlcpy()` and `strlcat()` take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NUL should be included in dstsize.
</br>
</br>
</br>

strlcpy()
===================

SYNTAX
------
        size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

DESCRIPTION
-----------
        strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.   

* `dstsize` - 1 만큼 src 에서 dst 로 복사한다.
* `dstsize` 가 0 이 아니라면 언제나 '\0' 으로 끝난다.
</br>
</br>
</br>
</br>

strlcat()
================

SYNTAX
------
    size_t strlcat(char * restrict dst, const char * restrict src, size_t size);

DESCRIPTION
-----------
        strlcat() appends string src to the end of dst. 
        It will append at most size - strlen(dst) - 1 characters.
        It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize
        (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string).

* 문자열 `src` 를 `dst` 의 끝에 추가한다.
* `dst`의 마지막 위치에 `src` 를 `size` - `strlen(dst)` - 1 만큼 복사하고 끝에 '\0'를 삽입한다.
* 최종적으로 반환되는 것은 __결합되는 문자열의 총 길이__이다.
* size < strlen(dst):  strlen(src) + size 를 반환!
* size > strlen(dst):  strlen(src) + strlen(dst)를 반환!
