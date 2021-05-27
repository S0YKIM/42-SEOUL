⭐open()
=========

HEADER FILE
-----------
        #include <sys/types.h>
        #include <sys/stat.h>
        #include <fcntl.h>
        
SYNTAX
------
        int open(const char *pathname, int flags);
        int open(const char *pathname, int flags, mode_t mode)

PARAMETERS
----------
        #1. PATHNAME: The name of the file. Can be Relative Path or Absolute Path.
        #2. FLAGS: Opening options to the file
        #3. MODE: The access rights to the file
        
RETURN VALUE
-----------
        Unsigned int value of the file descriptor. -1 if it fails.

DESCRIPTION
-----------
        Opens a file. Provided by Linux.
        
* MODE 의 종류

       (1) O_RDONLY: 읽기 전용
       (2) O_WRONLY: 쓰기 전용
       (3) O_RDWR: 읽기와 쓰기 모두 가능
       (4) O_CREAT: 파일이 존재하지 않을 경우 생성
       (5) O_EXCL: O_CREAT 을 써서 파일을 오픈했는데 이미 파일이 존재하는 경우 에러 반환

REFERENCES
-----------

http://forum.falinux.com/zbxe/index.php?document_srl=408448&mid=C_LIB
</br>
https://junmung.tistory.com/8
</br>
https://www.notion.so/Get-Next-Line-c7a311e63bd2483ab5bf404791e917c6
</br>
</br>
</br>
