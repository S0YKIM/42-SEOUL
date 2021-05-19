⭐lstadd_back()
===================

PROTOTYPE
----------
        void ft_lstadd_back(t_list **lst, t_list *new)

PARAMETERS
----------
        #1. The address of a pointer to the first link of a list.
        #2. The address of a pointer to the element to be added to the list.
        
DESCRIPTION
-----------
        Adds the element ’new’ at the end of the list.

* 새로운 요소 `new`를 연결 리스트의 마지막에 추가한다.
* `lst`의 요소가 아직 존재하지 않는 경우에는 그대로 `new`를 가리키게 하면 된다.
* 아닌 경우에는 `lst`의 마지막 요소가 가리키는 다음 요소에 `new`의 주소를 저장하면 된다.   
</br>
</br>
</br>
</br>
</br>
