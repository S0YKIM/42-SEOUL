⭐get_index_of_newline()
=======================

PROTOTYPE
----------
        static int get_index_of_newline(char *backup);
        
PARAMETERS
----------
        #1. The pointer named backup.
        
RETURN VALUE
-----------
        The index of where the newline character locates. -1 if it doesn't exist.

DESCRIPTION
-----------
        
* 백업 문자열 안에 개행 문자가 있는지 확인한다.
* 개행 문자가 존재하면 해당 `인덱스` 를 반환하고 없으면 `-1` 을 반환한다.


</br>
</br>
</br>
</br>
</br>

⭐split_line()
=============

PROTOTYPE
----------
        static int split_line(char **backup, char **line, int newline_index);
        
PARAMETERS
----------
        #1. The pointer to the pointer named backup.
        #2. The pointer to the pointer named line.
        #3. The index of the newline character.
        
RETURN VALUE
-----------
        1 if it succeeds to split the sentence. -1 if it fails.

DESCRIPTION
-----------
        
* 백업 문자열 안에 개행 문자가 존재하는 경우 `split_line()` 함수로 들어오게 된다.
* 만약 중간에 `ft_strdup()` 에서 메모리 할당에 실패하는 경우에만 `-1` 을 반환하고 보통은 `1` 을 반환한다.
* 개행 문자를 기준으로 앞부분은 `*line` 에 보내주고 뒷부분은 `*backup` 에 저장해둔다.

</br>
</br>
</br>
</br>
</br>

⭐end_of_file()
=============

PROTOTYPE
----------
        static int end_of_file(char **backup, char **line);
        
PARAMETERS
----------
        #1. The pointer to the pointer named backup.
        #2. The pointer to the pointer named line.
        
RETURN VALUE
-----------
        0 if there is no newline charcter in *backup. split_line() if there is any newline character.

DESCRIPTION
-----------
        
* `read()` 로 더 이상 읽어올 바이트가 없을 때에 0을 반환하게 되는데 이 때에 해당 함수로 들어온다.
* 하지만 `*backup` 에는 아직 개행 문자가 남아있을 수도 있다.
* 따라서 개행 문자가 있으면 더 이상 등장하지 않을 때까지 `split_line()`, 마지막에는 `0` 을 반환한다.

</br>
</br>
</br>
</br>
