메모리 초기화 함수
==============

</br>

memset()
===================

SYNTAX
------
        void	*ft_memset(void *ptr, int value, size_t count)

DESCRIPTION
-----------
        The memset() function writes count bytes of value (converted to an unsigned char) to the string ptr.

* 어떤 메모리의 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정
* ptr : 채우고자 하는 메모리의 시작 포인터(시작 주소)
* value : 메모리에 채우고자 하는 값, int형 이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.
* count : 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기
* 반환값: ptr 의 시작 주소
</br>
</br>
</br>
</br>
</br>

bzero()
================

SYNTAX
------
    void	*ft_bzero(void *ptr, size_t count)

DESCRIPTION
-----------
        The bzero() function writes count zeroed bytes to the string ptr.
        If count is zero, bzero() does nothing.

* 어떤 메모리의 시작점부터 count 만큼 연속된 범위를 0으로 모두 지정
* memset(ptr, 0, count) 와 동일한 
