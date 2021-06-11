⭐ print_string
===============

❗ 만약 `str`이 `NULL`이면 `(NULL)`을 문자 그대로 넣어준다.

- `tag->precision`이 `-1`이 아니면서 `str`의 길이보다 작으면 `precision`에 맞게 `str`을 자른 문자열을
- 반대의 경우에는 원래 `str`를 그대로 복사한 문자열을 임시 포인터 `buf`에 저장한다.
- `add_width_to_buf()`를 통해 `width`를 잘라진 문자열 `buf`에 더해준다.
- `buf`을 출력한 후에 `buf`를 `free()` 해준다.
