⭐ print_string
===============

❗ 만약 `str`이 `NULL`이면 `(NULL)`을 문자 그대로 넣어준다.
</br>

### 1 - `trim_string()` 함수를 통해 알맞은 길이의 문자열을 가져온다.

- `tag->precision`이 `-1`이 아니면서 `str`의 길이보다 작으면 `precision`에 맞게 `str`을 자른 문자열을
- `tag->precision`이 `-1`이거나 `str`의 길이보다 크면 `str` 그대로 복사한 문자열을 임시 포인터 `buf`에 저장한다.
</br>

### 2 - `add_width_to_buf()`를 통해 `width`를 `trim_string()`의 반환값인 `buf`에 더해준다.
</br>

### 3 - `buf`을 출력한 후에 `buf`를 `free()` 해준다.

</br>
</br>

⭐ trim_string
===============

- `tag->precision`과 `ft_strlen(str)` 중에서 작은 값을 길이로 가지는 문자열을 반환


</br>
</br>

⭐ add_width_to_buf
===================

- `width` - `buf`의 길이를 `len`에 저장한다.

</br>


1 - `width` <= `buf`의 길이
--------------------------
- 바로 `buf`의 길이를 반환한다.

</br>

2 - `width` > `buf`의 길이
-------------------------
- `len` 만큼의 `공백` 또는 `0`을 채운 문자열을 만든다.
- `-` 플래그가 있으면 `공백` 문자열을 오른쪽에 붙이고
- 반대의 경우에는 `공백`문자열을 왼쪽에 붙여준다.

