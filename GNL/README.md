GET NEXT LINE
============

[![sokim's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cl1sxc9pb003009jgq7f86utb/project/2177252)](https://github.com/JaeSeoKim/badge42)
-------------------------

> "The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor."


# 🚀 Content

## 🚩 Mandatory part

| Title            | Description                                                  |
| ---------------- | ------------------------------------------------------------ |
| Function name    | get_next_line                                                |
| Prototype        | int get_next_line(int fd, char **line);                      |
| Turn in files    | get_next_line.c, get_next_line_utils.c, get_next_line.h      |
| Parameters       | \#1. file descriptor for reading<br />#2. The value of what has been read |
| Return value     | 1 : A line has been read<br />0 : EOF has been reached<br />-1 : An error happened |
| External functs. | read, malloc, free                                           |
| Description      | Write a function which returns a line read from a file descriptor, without the newline. |

- Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.
- Make sure that your function behaves well when it reads from a file and when it reads from the standard input.
- libft is not allowed for this project. You must add a get_next_line_utils.c file which will contain the functions that are needed for your get_next_line to work.
- Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by moulinette.
- Compilation will be done this way : `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c`
- Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin.
- In the header file get_next_line.h you must have at least the prototype of the function get_next_line.
- We consider that get_next_line has an undefined behavior if, between two calls, the same file descriptor switches to a different file before EOF has been reached on the first fd.
- lseek is not an allowed function. File reading must be done only once.
- Finally we consider that get_next_line has an undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.
- Global variables are forbidden.

## 🚩 Bonus part

> The project get_next_line is straightforward and leaves very little room for bonuses, but I am sure that you have a lot of imagination. If you aced perfectly the mandatory part, then by all means complete this bonus part to go further. I repeat, no bonus will be taken into consideration if the mandatory part isn’t perfect. Turn-in all 3 initial files with _bonus for this part.

- To succeed get_next_line with a single static variable.
- To be able to manage multiple file descriptor with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.

# ⭐KEY POINT

- Key concept: `buffer` `static variables`
- 어떠한 파일을 받아와서 '\n'을 기준으로 한 줄씩 가져오는 함수를 만드는 과제
- 컴파일 과정에서 버퍼 사이즈를 입력 받는다.
- gcc -D defines a macro to be used by the preprocessor.

      gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

- main 에서 open() 함수를 이용하여 파일을 열어 파일 디스크립터를 gnl 에 넘겨준다.

      fd = open("test.txt", O_RDONLY);
      
- 여러 파일 디스크립터도 다룰 수 있기 위해서는 `static char *backup[MAX_FD]` 처럼 포인터 배열을 사용한다.
- 처음 시도에는 `char *buf[BUFFER_SIZE + 1]` 로 배열을 선언하였지만,
- BUFFER_SIZE 가 아주 커지는 경우 SEG FAULT 가 발생하는 문제로 인해 `malloc()` 을 통해 메모리를 할당하는 것으로 변경하였다.


# ⭐REFERENCE

https://github.com/hidaehyunlee/Get-Next-Line
</br>
https://code4human.tistory.com/130
</br>
https://velog.io/@yamkim/42-Seoul-Get-Next-Line2-Overview
</br>
https://epicarts.tistory.com/154
</br>
https://ohseyong.github.io/study/Get-Next-Line/
</br>
http://bit.ly/gnljs
