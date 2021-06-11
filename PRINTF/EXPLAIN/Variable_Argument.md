# PRINTF()

⭐PROTOTYPE
===========


      int printf(const char* format, ...)

* `printf()` 의 두 번째 인자인 `...` 을 `가변인자` 라고 부른다.
* 가변인자로는 아무 것도 넘겨주지 않을 수도 있고 여러 개를 넘겨줄 수도 있다.
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

<a href="https://ibb.co/Z2KQ8hc"><img src="https://i.ibb.co/GHkZ2VC/Screen-Shot-2021-05-28-at-5-46-19-PM.png" alt="Screen-Shot-2021-05-28-at-5-46-19-PM" border="0"></a><br />

</br>

## 1. va_list

* 각 가변인자의 시작 주소를 가리키는 포인터
* 가변 인자 목록. 가변 인자의 메모리 주소를 저장하는 포인터.

</br>

## 2. va_start

</br>

<a href="https://ibb.co/qr93MLC"><img src="https://i.ibb.co/rwMRGK3/Screen-Shot-2021-06-11-at-6-16-34-PM.png" alt="Screen-Shot-2021-06-11-at-6-16-34-PM" border="0"></a>

</br>

DEFINITION
----------

      #define va_start(ap, v) ( (ap) = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) );
      
PARAMETERS
----------

      #1. va_list 인스턴스(ap)
      #2. 고정인수(v)

* `va_list` 포인터에게 가변인자 중 첫번째 선택적 인수(variable_name)의 주소를 가르쳐주는 매크로
* `va_arg()`, `va_copy()`, `va_end()` 에 대한 후속 호출에 대해 `ap` 포인터를 초기화한다.
* `v`: 인수 목록의 첫 번째 인자 바로 앞에 오는 `필수 매개 변수`의 이름. 과제에서는 `format` 이라고 불리는 부분.


</br>

## 3. va_copy

      void va_copy(va_list dest, va_list src);
      
* `va_start()` 를 `dest` 에 적용한 후 `src` 의 현재 상태에 도달하는 데에 이전에 사용된 것과 동일한 순서로 `va_arg()` 를 사용한 경우와 같이 `dest` 를 `src` 의 사본으로 초기화한다. 
* `va_copy()` 또는 `va_start()` 는 동일한 `dest` 에 대한 `va_end()` 의 중간 호출 없이 `dest` 를 다시 초기화하도록 호출해야 한다.

</br>

## 4. va_arg

</br>

<a href="https://ibb.co/RNmbNzj"><img src="https://i.ibb.co/VxZ9x2w/Screen-Shot-2021-06-11-at-6-55-40-PM.png" alt="Screen-Shot-2021-06-11-at-6-55-40-PM" border="0"></a>

</br>

DEFINITION
----------

      #define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - INTSIZEOF(T)));

* `ap` 로 지정된 위치에서 지정된 `t` 값을 검색하고 리스트에서 다음 인수를 가리키도록 `ap` 를 증가 시켜 다음 인수가 시작 되는 위치를 결정한다. 
* 즉, 특정 가변인자를 가리키고 있는 `va_list` 의 포인터를 다음 가변인자로 이동시켜 주는 매크로이다.
* `t`: `int` 나 `long`, `double` 과 같은 타입 이름이 담긴다.

❗ `t` 을 설정할 때 `char`, `short` 의 경우에는 `int` 로 대신 쓰고, `flaot` 의 경우에는 `double` 로 대신 쓴 이후 형변환을 해주어야 한다.
</br>

      ex) char ch = (char) va_arg(ap, int);

</br>

## 5. va_end

      void va_end(va_list arg_ptr);

* 가변 인자 처리가 끝났을 때 포인터를 `NULL`로 초기화한다.
* 모든 인수가 검색된 후에 포인터를 `NULL` 로 다시 설정한다. 
* 즉, 사용한 가변인자 변수를 끝낼 때에 사용한다.
</br>
</br>

⭐REFERENCES
============

velog: https://velog.io/@hidaehyunlee/%EA%B0%80%EB%B3%80%EC%9D%B8%EC%9E%90-Variadic-Arguments
</br>
코딩 도장: https://dojang.io/mod/page/view.php?id=577
<br>
티스토리: https://jhnyang.tistory.com/293
