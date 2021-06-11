⭐ print_char
=============

(1) 좌측정렬 `tag->minus == 1`
- `ft_putchar()` 로 문자 먼저 출력하고
- `print_width()`로 `width`를 출력한다.

(2) 우측정렬 `tag->minus == 0`
- `print_width()`로 `width`를 먼저 출력하고
- `ft_putchar()`로 문자를 출력한다.

</br>
</br>

⭐ print_width
==============

- `width` 즉 너비를 출력하는 함수이다.
- `c`는 `1` 바이트를 차지하므로 `width - 1` 만큼 `공백` 또는 `0`을 출력한다.
- `tag->zero`가 `1`이면 `0`을 출력하고 아니면 ` `을 출력한다.
