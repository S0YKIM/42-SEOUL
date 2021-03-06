⭐ init_tag
============

- 구조체 포인터 `*tag` 의 모든 요소를 초기화
- `t_tag` 는 ft_printf.h 에 정의 되어 있다.
- `tag->precision`를 `-1`로 초기화 하는 이유?
- `.` 이나 `.0` 인 경우에 `precision` 이 `0` 이 되기 때문!

</br>

⭐ init_width
=============

- `isdigit()` 을 통해 숫자인지 확인한 다음 `width`에 저장하기 전에 확인해야 하는 절차
- 만약에 이전에 `*` 플래그가 등장해서 이미 저장된 `width`가 존재했다면 다시 `0` 으로 초기화한다.
- 그리고 `*` 플래그 카운트를 다시 `0` 으로 바꿔준다.
- ex) `printf("%*3d\n", 10, 5);` ->   5 출력

</br>

❗ `printf("%3*d\n", 10, 5);` ->          5 출력
- store_star_flag() 에서 `width`에 가변인자 값인 `10`을 저장

</br>

⭐ init_precision
=================

- `isdigit()` 을 통해 숫자인지 확인한 다음 `precision`에 저장하기 전에 확인해야 하는 절차
- 만약에 이전에 `*` 플래그가 등장해서 이미 저장된 `precision`이 존재했다면 다시 `0`으로 초기화한다.
- 그리고 `*` 플래그 카운트를 다시 `0` 으로 바꿔준다.
- ex) `printf("%.*3d\n", 10, 5);` -> 0000000005 출력

</br>

❗ `printf("%.3*d\n", 10, 5);` ->        005 출력
- store_star_flag() 에서 `width`에 가변인자 값인 `10`을 저장
