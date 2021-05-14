메모리 초기화 함수
==============

</br>

⭐memset()
===================

SYNTAX
------
        void	*ft_memset(void *ptr, int value, size_t count)
</br>

DESCRIPTION
-----------
        The memset() function writes count bytes of value (converted to an unsigned char) to the string ptr.

* 어떤 메모리의 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정
* `ptr` : 채우고자 하는 메모리의 시작 포인터(시작 주소)
* `value` : 메모리에 채우고자 하는 값, int형 이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.
* `count` : 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기
* 반환값: `ptr` 의 시작 주소
</br>
</br>
</br>
</br>
</br>

⭐bzero()
================

SYNTAX
------
    void	*ft_bzero(void *ptr, size_t count)

DESCRIPTION
-----------
        The bzero() function writes count zeroed bytes to the string ptr.
        If count is zero, bzero() does nothing.

* 어떤 메모리의 시작점부터 `count` 만큼 연속된 범위를 0으로 모두 지정
* memset(ptr, 0, count) 와 동일한 기능
* 반환값: `ptr` 의 시작 주소

</br>
</br>
</br>
</br>
</br>

메모리 복사 함수
==============

</br>

⭐memcpy()
===================

SYNTAX
------
        void	*ft_memcpy(void *dest, const void *src, size_t len)
</br>

DESCRIPTION
-----------
        The memcpy() function copies len bytes from memory area src to memory area dst.
        If dst and src overlap, behavior is undefined.
        Applications in which dst and src might overlap should use memmove(3) instead.

* 문자열 `src` 를 `dest` 에 `len` 만큼 복사한다. 
* 반환값: `dest` 의 시작 주소
* `strcpy` 와의 차이: 정확히 `len` 만큼만 복사하기 때문에 '\0' 체크와 관계 없음
* strcpy(dest, src) 와 동일하게 작동하려면 memcpy(dest, src, strlen(src) + 1)
</br>
</br>
</br>
</br>
</br>

⭐memmove()
================

SYNTAX
------
    void	*ft_memmove(void *dest, const void *src, size_t len)
</br>

DESCRIPTION
-----------
        The memmove() function copies len bytes from string src to string dst.
        The two strings may overlap; the copy is always done in a non-destructive manner.

* `memcpy()` 처럼 메모리를 바이트 단위로 복사한다.
* `dest` 와 `src` 가 중첩되는 경우에는 무조건 `memmove()`를 사용해야 한다.
* 반환값: `dest` 의 시작 주소

</br>
</br>
</br>
</br>
</br>

⭐memccpy()
================

SYNTAX
------
    void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
</br>

DESCRIPTION
-----------
        copy string until character found
        The memccpy() function copies bytes from string src to string dst.
        If the character c occurs in the string src, the copy stops and a pointer to the byte after the copy of c in the string dst is returned.
        Otherwise, len bytes are copied, and a NULL pointer is returned.

* `src` 에서 (unsigned char 로 변환된)`value`가 발견될 때까지 `len`만큼 메모리를 복사
* 반환값: `value`가 발견된 `src` 의 주소 또는 `value`가 발견되지 않는 경우 널포인터

</br>
</br>
</br>
</br>
</br>

⭐memchr()
================

SYNTAX
------
    void	*ft_memchr(const void *s, int value, size_t num)
</br>

DESCRIPTION
-----------
        locate byte in byte string
        The memchr() function locates the first occurrence of value (converted to an unsigned char) in string s.

* 문자열 `s`에서 (unsigned char 로 변환된)`value` 를 검색
* 반환값: `value` 가 발견된 메모리 주소 또는 발견되지 않은 경우 널포인터
* `strchr()` 와 차이: `num` 만큼만 검색하기 떄문에 '\0' 체크와 관계 없음
* strchr(str, value) 와 동일하게 작동하려면 memchr(str, value, strlen(str) + 1)


