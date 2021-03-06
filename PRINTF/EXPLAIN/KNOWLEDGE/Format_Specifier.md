# 형식문자열(FORMAT)

      int printf(const char* format, ...)

* `형식문자열`, `서식문자열` 또는 `포맷` 이라고 부르며 `출력하고자 하는 문자열` 을 의미한다.
* `printf()` 는 표준출력(stdout)에 일련의 데이터들을 형식문자열(format)에 지정되어 있는 형태로 출력한다.
* 형식문자열 뒤에 오는 `가변인자`들의 개수는 형식 문자열 속의 형식 태그(format tag)의 개수와 같다.
</br>
</br>
</br>

⭐서식지정자(Format Specifier)
===========================
      
* `%` 문자로 시작하며 대표적으로 `%d`, `%c`, `%s`, `%p` 등이 있다.
* 컴퓨터가 어떤 정보를 어떻게 해석할 건지 지정해주는 역할을 한다.
* 예를 들어 `printf("%d\n", 10);` 이면 `10`을 부호 있는 10진수 정수로 해석하여 출력한다.
* 형식 태그 안에서 서식 지정자에 다양한 플래그, 폭, 정밀도, 길이 등의 옵션을 조합하여 사용할 수 있다.

</br>
</br>

⭐형식태그(Format Tag)
===================

## `%[flag][width][.precision]서식지정자`

</br>

* 형식태그의 첫 번째 문자는 반드시 `%` 가 온다.
* 형식태그는 출력할 값에 대하여 각각 적용된다.
* 따라서 출력할 값이 세 개라면 형식태그도 세 번 등장한다.
* `[]`로 둘러싸인 부분은 옵션이므로 생략 가능하다.
* 최소한의 형식태그는 `%` 와 `서식지정자` 로 구성된다.

</br>
</br>

⭐형식태그의 옵션
=============

## (1) 플래그(Flag)

* `-` : 필드에서 값을 왼쪽으로 정렬한다. 기본 값은 오른쪽 정렬이다.
* `0` : 오른쪽 정렬일 때에 공백을 `0`으로 메운다.
* `.` : .n (n: 10진수) 의 형태로 쓰인다. 실수일 때에 소숫점 이하의 자릿수를 결정한다.
* `*` : 서식문자로 출력할 인수 앞에 가변인수로 필드의 폭을 결정한다.
* example

      int num = 7;
      printf("%0*d", 5, num); >> 00007
      printf("[%-6d]", 123);  >> [123   ]

</br>

* `+` : 양수일 때에는 `+` 음수일 때에는 `-` 기호 출력
* `space` : 양수일 때에는 부호를 출력 하지 않고 음수일 때에만 `-` 기호 출력
* `#` : 진법에 맞게 숫자 앞에 `0`, `0x`, `0X`를 출력
</br>
</br>

## (2) 폭(Width)

* 출력할 값의 최소 너비를 지정한다.
* 출력할 값이 지정한 폭보다 작으면 자릿수를 맞추기 위해 공백 또는 0을 채워넣는다.
* 출력할 값이 지정한 폭보다 크면 `width` 옵션은 무시된다.
* `width` 에 음수가 할당되면 `-` 플래그(왼쪽 정렬) + `width` 로 간주한다.
* 폭을 지정하는 방법
      
      (1) [숫자]: printf("%3d", 123);
      (2) [*]: printf("%*d", 3, 123);
      ❗ 동시에 둘 다 사용 불가

</br>
</br>

## (3) 정밀도(Precision)

* 몇 자리까지 출력할지 `자릿수` 를 설정한다.
* 마침표 `.` 를 찍어서 사용한다.
* 정밀도에 음수가 할당되면 무시한다.

❗ 출력할 값이 정수(d, i)일 때
* 최대 자릿수를 맞추기 위해 0을 추가한다.
* 자릿수가 출력값보다 작을 경우에는 정밀도 옵션을 무시한다.

❗ 출력할 값이 실수일 때
* 소수점 이하의 최대 자릿수를 가리킨다.
* 자릿수에 따라 반올림이 되거나 소숫점 이하에 0이 추가된다.
* 실수 전체의 자릿수 설정은 width 옵션을 사용한다.

</br>
</br>

## (4) 서식지정자(Type)

* c: 문자(Character)
* d 또는 i: 부호 있는 10진법 정수(Signed Int)
* s: 문자열(String)
* p: 포인터 주소(Pointer)
* u: 부호 없는 10진법 정수(Unsigned Int)
* x: 부호 없는 16진법 정수(소문자 사용)
* X: 부호 없는 16진법 정수(대문자 사용)

      x 의 예시: 7f
      X 의 예시: 7F
</br>
</br>

⭐REFERENCES
============

https://velog.io/@hidaehyunlee/형식태그와-서식지정자-printf-함수의-옵션-알아보기
