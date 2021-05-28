# 형식문자열(FORMAT)

⭐PROTOTYPE
===========


      int printf(const char* format, ...)

* `printf()` 는 표준출력(stdout)에 일련의 데이터들을 형식문자열(format)에 지정되어 있는 형태로 출력한다.
* 형식문자열 뒤에 오는 `가변인자`들의 개수는 형식 문자열 속의 형식 태그(format tag)의 개수와 같다.
</br>
</br>
</br>


# How to Create A Function Using Variable Arguments

⭐HEADER FILE
=============

      #include <stdarg.h>
      
* 이 헤더파일에 가변인수 함수를 만드는 데에 필요한 `매크로` 들이 들어있다.
* 최소 1개 이상의 고정 인수가 필요하다.
* 가변인자 `...` 는 파라미터의 마지막 순서에 있어야 한다.

</br>
</br>

⭐MACROS
========


https://velog.io/@hidaehyunlee/형식태그와-서식지정자-printf-함수의-옵션-알아보기
