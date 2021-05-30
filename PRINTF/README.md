# PRINTF()

</br>

✔️ Mandatory part
================

Program name       `libftprintf.a`

Turn in ﬁles       `.c`, `/.c`, `*.h`, `/.h`, `Makefile`

Makeﬁle           `all`, `clean`, `fclean`, `re`, `bonus`

External functs.  `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`

Libft authorized  `yes`


* The prototype of ft_printf should be `int ft_printf(const char *, ...);`

* You have to recode the libc’s printf function

* It must not do the `buffer management` like the real printf

* It will manage the following conversions: `cspdiuxX%`

* It will manage any combination of the following flags: `’-0.*’` and minimum field width with all conversions

* It will be compared with the real `printf`

* You must use the command `ar` to create your librairy, using the command libtool is forbidden.

</br>
</br>

⭐DESCRIPTIONS
==============

* The aim of this project is to recode `printf` function.
* Key concepts: [`Variable Arguments`](./EXPLAIN/Variable_Argument.md) [`Format Specifier`](./EXPLAIN/Format_Specifier.md)
</br>
</br>
</br>

⭐PROTOTYPE
===========


      int printf(const char* format, ...)

* `printf()` 의 두 번째 인자인 `...` 을 `가변인자` 라고 부른다.
* 가변인자로는 아무 것도 넘겨주지 않을 수도 있고 여러 개를 넘겨줄 수도 있다.
</br>
</br>
</br>

⭐REFERENCES
============

https://norux.me/19
