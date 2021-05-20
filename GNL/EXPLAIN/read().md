⭐read()
==================

HEADER FILE
-----------
        <unistd.h>
        
SYNTAX
------
        ssize_t read (int fd, void *buf, size_t nbytes)

PARAMETERS
----------
        #1. fd: File Descriptor
        #2. buf: The buffer to read the file
        #3. nbytes: Buffer size
        
RETURN VALUE
-----------
        The number of bytes that are already read. -1 if it fails.

DESCRIPTION
-----------
        Reads the file which was opened by open().
        
* 인자로 받은 `nbytes` 의 수만큼 `fd` 를 읽어 `buf` 에 저장하는 함수다.
* 읽어온 바이트 수를 반환하며, 실패시 `-1`을 반환한다.
* 파일을 끝까지 읽었다면, 다음 번에는 더 이상 읽을 바이트가 없기 때문에 `0`을 반환한다.

REFERENCES
-----------

http://forum.falinux.com/zbxe/index.php?document_srl=466628&mid=C_LIB
</br>
https://velog.io/@hidaehyunlee/GetNextLine-%EC%82%BD%EC%A7%88%EC%9D%98-%EA%B8%B0%EB%A1%9D
</br>
</br>
</br>
</br>
