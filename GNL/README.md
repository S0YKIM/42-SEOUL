⭐DESCRIPTIONS
==============

* The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.
* Key concepts: `buffer` and `static variable`
</br>
</br>
</br>

⭐HOW TO SOLVE
==============

* 어떠한 파일을 받아와서 '\n'을 기준으로 한 줄씩 가져오는 함수를 만드는 과제
* 컴파일 과정에서 버퍼 사이즈를 입력 받는다.
* gcc -D defines a macro to be used by the preprocessor.

      gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

* main 에서 open() 함수를 이용하여 파일을 열어 파일 디스크립터를 gnl 에 넘겨준다.

      fd = open("test.txt", O_RDONLY);
      
* 여러 파일 디스크립터도 다룰 수 있기 위해서는 `static char *backup[MAX_FD]` 처럼 포인터 배열을 사용한다.
* 처음 시도에는 `char *buf[BUFFER_SIZE + 1]` 로 배열을 선언하였지만,
* BUFFER_SIZE 가 아주 커지는 경우 SEG FAULT 가 발생하는 문제로 인해 `malloc()` 을 통해 메모리를 할당하는 것으로 변경하였다.

</br>
</br>
</br>

⭐REFERENCES
============

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
