⭐atoi()
===================

SYNTAX
------
        int				ft_atoi(const char *str)
 </br>

DESCRIPTION
-----------
        The atoi() function converts the initial portion of the string pointed to by str to int representation.

* ASCII 문자열을 `int` 형으로 변환하여 반환해준다
* 문자열 안에는 공백 문자가 몇개든 포함될 수 있으므로 체크해주어야 한다.
* `-` 와 `+` 부호가 등장하는 경우 최초의 부호만 부호로 인식한다.
* 공백문자(White Space)의 종류
1. `'\t'`
2. `'\r'`
3. `'\r'`
4. `'\v'`
5. `'\n'`
6. `' '`
</br>
</br>
</br>
</br>
</br>

⭐toupper() 와 tolower()
===================

SYNTAX
------
        int		ft_toupper(int c)
        int		ft_tolower(int c)
</br>

DESCRIPTION
-----------
        The toupper() function converts a lower-case letter to the corresponding upper-case letter.
        The tolower() function converts an upper-case letter to the corresponding lower-case letter.
        The argument must be representable as an unsigned char or the value of EOF.

* `toupper()` 은 소문자를 대문자로, `tolower()` 은 대문자를 소문자로 변환하여 반환
</br>
</br>
</br>
</br>
</br>
