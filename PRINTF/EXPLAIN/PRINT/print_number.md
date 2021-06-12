⭐ print_number
===============

### 1 - `set_nbr_base()` 함수로 진수의 베이스를 설정한다.

### 2 - `abs_nbr()` 함수로 음수 정수의 경우 양수로 바꾸어준다.

### 3 - `add_prec_to_nbr()` 함수로 `precision`에 따라 문자열을 자르고 해당 진법으로 변환한다.

### 4 - `add_pointer_prefix()` 함수로 포인터를 나타내는 `0x`를 붙이고 `공백`을 더한다.

### 5 -

#### (1) `0` 플래그가 없는 경우:
- `d`, `i`: `add_plus_or_minus()` 함수를 통해 부호를 붙인다.
- `x`, `X`, `o`: `add_hashtag_prefix()` 함수를 통해 `0`, `0x`, `0X`를 붙인다.
- `add_width_to_buf()` 함수를 통해 뒤에 `공백`을 채운다.


#### (2) `0` 플래그가 있는 경우:
- `add_width_to_buf()` 함수를 통해 `0`을 먼저 채운다.
- `d`, `i`: `add_plus_or_minus_with_zero()` 함수를 통해 부호를 붙인다.
- `x`, `X`, `o`: `add_hashtag_prefix_with_zero()` 함수를 통해 `0`, `0x`, `0X`를 붙인다.


### 6 - `buf` 를 출력하고 `free()` 해준다.

### 7 - 지금까지 출력한 바이트 수가 저장된 `result`를 반환한다.

</br>
</br>

⭐ add_prec_to_nbr()
====================

### 1 - `count_len_of_number()` 함수로 `nbr`의 길이를 구한다.
### 2 - `get_buf_len()` 함수를 통해 `precision`과 `nbr_len`중에 큰 것을 `buf_len`으로 정한다.
### 3 - `buf_len` - `nbr_len`의 길이만큼 `0`을 채운다.
### 4 - 해당 진법에 맞게 숫자를 변환하여 남은 `buf`의 자리에 저장한다.
### 5 - `nbr_len`을 반한한다.
