# PRINTF()

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/sokim/printf)](https://github.com/JaeSeoKim/badge42)

</br>

✔️ Mandatory Part
================

| Program name     | libftprintf.a                                                |
| ---------------- | ------------------------------------------------------------ |
| Turn in files    | *.c, */*.c, *.h, */*.h, Makefile                             |
| Makefile         | all, clean, fclean, re, bonus                                |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end       |
| Libft authorized | yes                                                          |
| Description      | Write a library that contains ft_printf, a function that will mimic the real printf |

- The prototype of ft_printf should be `int ft_printf(const char *, ...);`
- You have to recode the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: `c` `s` `p` `d` `i` `u` `x` `X`
- It will manage any combination of the following flags: ’-0.*’ and minimum field width with all conversions
- It will be compared with the real printf
- You must use the command ar to create your librairy, using the command libtool is forbidden.

> man 3 printf / man 3 stdarg

</br>

✔️ Bonus Part
============

- If the Mandatory part is not perfect don’t even think about bonuses
- You don’t need to do all the bonuses
- Manage one or more of the following conversions: nfge
- Manage one or more of the following flags: l ll h hh
- Manage all the following flags: ’# +’ (yes, one of them is a space)

</br>
</br>

⭐DESCRIPTIONS
==============

* The aim of this project is to recode `printf` function.
* Key concepts: [`Variable Arguments`](./EXPLAIN/Variable_Argument.md) [`Format Specifier`](./EXPLAIN/Format_Specifier.md)
</br>
</br>

⭐PROTOTYPE
===========

      int printf(const char* format, ...)

* `printf()` 의 두 번째 인자인 `...` 을 `가변인자` 라고 부른다.
* 가변인자로는 아무 것도 넘겨주지 않을 수도 있고 여러 개를 넘겨줄 수도 있다.
</br>
</br>

⭐ FORMAT TAG
============

    %[flags][width][.precision][extend_type]type

| flags                         | extend_type          | type             |
| ----------------------------- | -------------------- | ---------------- |
| `-`, `0`, `+`, `<SPACE>`, `#` | `h`, `hh`, `l`, `ll` | `cspdiuxXnfgeo%` |

위에서 설명한  `[flags][width][.precision][extend_type]` 은 순서가 섞여있을 때에도 작동을 해야 함.

  [참고 링크](https://dojang.io/mod/page/view.php?id=736)

  - [x] **Mandatory part**

    **Format Specifier**

      - `%c` : char - 하나의 문자
      - `%s` : *char - 문자열
      - `%p` : *void - pointer 주소
      - `%d` : int - 부호가 있는 10진수 정수
      - `%i` : int - 부호가 있는 10진수 정수
      - `%u` : unsinged int : 부호 없는 10진 정수
      - `%x` : hexadecimal(int) : 부호 없는 16진 정수 (소문자 사용)
      - `%X` : hexadecimal(int) : 부호 없는 16진 정수 (대문자 사용)

    **Flag**

    - `-` : 왼쪽 정렬
    - `0` : 공백 대신 0으로 padding처리
    - `.` : 정밀도 숫자 서식에 관여
    - `*` : 가변인자로 width, precision의 크기가 들어옴

</br>
</br>

  - [x] **Bonus part**

    **Format Specifier**

      - `%n` : int * - 인자로 들어온 포인터에 현재 까지 출력한 문자 갯수 저장
      - `%f` : double - 1.200000: 실수를 소수점으로 표기(소문자)
      - `%g` : double - 1.200000e+00: 실수 지수 표기법 사용(소문자)
      - `%e` : double - 1.2: %f와 %e 중에서 짧은 것을 사용(소문자)

    | *length* | `d i`           | `u o x X`                | `f F e E g G a A` | `c`      | `s`        | `p`     | `n`              |
    | -------- | --------------- | ------------------------ | ----------------- | -------- | ---------- | ------- | ---------------- |
    | *(none)* | `int`           | `unsigned int`           | `double`          | `int`    | `char*`    | `void*` | `int*`           |
    | `hh`     | `signed char`   | `unsigned char`          |                   |          |            |         | `signed char*`   |
    | `h`      | `short int`     | `unsigned short int`     |                   |          |            |         | `short int*`     |
    | `l`      | `long int`      | `unsigned long int`      |                   | `wint_t` | `wchar_t*` |         | `long int*`      |
    | `ll`     | `long long int` | `unsigned long long int` |                   |          |            |         | `long long int*` |

    **flag**

    - `+` : 양수 일때에는 + 음수일때에는 - 기호 출력
    - `공백` :  양수일때에는 부호를 출력 하지 않고 음수일때에만 - 기호 출력
    - `#` : 진법에 맞게 숫자 앞에 0, 0x, 0X를 출력

</br>
</br>

⭐REFERENCES
============

가변인자: https://norux.me/19
</br>
바이트패딩: https://supercoding.tistory.com/37
</br>
팔만코딩경: https://www.notion.so/ft_printf-by-suhshin-a2b3b5a4ea45403899cba0304766d77a#4add2bd892c14446b4da52d4489eea31
</br>
velog: https://velog.io/@pawer/Printf
