⭐lstadd_front()
===================

PROTOTYPE
----------
        void ft_lstadd_front(t_list **lst, t_list *new)

PARAMETERS
----------
        #1. The address of a pointer to the first link of a list.
        #2. The address of a pointer to the element to be added to the list.
        
DESCRIPTION
-----------
        Adds the element ’new’ at the beginning of the list.

* 새로운 구조체 포인터 `new`를 연결리스트 `lst`의 맨앞에 추가한다.
* 먼저 `new` 의 요소 `next`가 연결리스트의 첫번째 요소를 가리키게 한다.
* 그 다음 `lst`의 시작점을 `new`가 되도록 한다.  
</br>
</br>
</br>
</br>
</br>
