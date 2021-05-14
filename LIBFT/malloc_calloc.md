[FUNCTION] malloc
=================

SYNTAX
------
        void *malloc(size_t size);

DESCRIPTION
-----------
        The malloc(), calloc(), valloc(), realloc(), and reallocf() functions allocate memory.
        The malloc() function allocates size bytes of memory and returns a pointer to the allocated memory.   

* 주어진 사이즈만큼 메모리를 할당하고 할당된 메모리에 대한 포인터를 반환
* 사용한 후에는 free() 함수로 메모리를 해제해준다   




[FUNTION] calloc
================

SYNTAX
------
    void *calloc(size_t count, size_t size)

DESCRIPTION
-----------
        The calloc() function contiguously allocates enough space for count objects that are size
        bytes of memory each and returns a pointer to the allocated memory.
        The allocated memory is filled with bytes of value zero.

* count: 할당할 변수의 개수
* size: 할당할 변수의 하나의 크기
* malloc() + bzero() 함수를 합친 것과 같음
