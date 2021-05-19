write() 이용하여 출력하기
====================
`putchar_fd()`, `putstr_fd()`, `putendl_fd()`, `putnbr_fd()`
</br>
</br>
</br>
</br>

⭐putchar_fd()
===================

PROTOTYPE
----------
        void ft_putchar_fd(char c, int fd)
        
PARAMETERS
----------
        #1. The character to output.
        #2. The file descriptor on which to write.

DESCRIPTION
-----------
        Outputs the character ’c’ to the given file descriptor.

* 문자 `c`를 화면에 출력한다.
</br>
</br>
</br>
</br>
</br>

⭐putstr_fd() ⭐putendl_fd()
===========================

PROTOTYPE
----------
        void	ft_putstr_fd(char *s, int fd)
        void ft_putendl_fd(char *s, int fd)
        
PARAMETERS
----------
        #1. The string to output.
        #2. The file descriptor on which to write.

DESCRIPTION
-----------
        Outputs the string ’s’ to the given file descriptor.

* 문자열 `s`를 화면에 출력한다.
* `putendl_fd()` 는 문자열 출력 뒤에 개행 `\n`을 추가해준다.
</br>
</br>
</br>
</br>
</br>

⭐putnbr_fd()
===================

PROTOTYPE
----------
        void ft_putnbr_fd(int n, int fd)
        
PARAMETERS
----------
        #1. The integer to output.
        #2. The file descriptor on which to write.

DESCRIPTION
-----------
        Outputs the integer ’n’ to the given file descriptor.

* 정수형 `n`을 문자로 변환하여 화면에 출력한다.
</br>
</br>
</br>
</br>
</br>
