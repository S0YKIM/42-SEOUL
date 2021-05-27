⭐open()
=========

HEADER FILE
-----------
        #include <sys/types.h>
        #include <sys/stat.h>
        #include <fcntl.h>
        
SYNTAX
------
        int open (const char *FILENAME, int FLAGS[, mode_t MODE])

PARAMETERS
----------
        #1. FILENAME:	The name of the file
        #2. FLAGS: Opening options to the file
        #3. MODE: The access rights to the file
        
RETURN VALUE
-----------
        Unsigned int value of the file descriptor. -1 if it fails.

DESCRIPTION
-----------
        Opens a file. Provided by Linux.
        
* MODE 의 종류

       (1) O_RDONLY: 읽기전용
       (2) O_WRONLY: 쓰기전용
       (3) O_RDWR:   읽기/쓰기  

REFERENCES
-----------

http://forum.falinux.com/zbxe/index.php?document_srl=408448&mid=C_LIB
</br>
https://junmung.tistory.com/8
</br>
</br>
</br>
</br>
