⭐lstmap()
===================

PROTOTYPE
----------
        t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))


PARAMETERS
----------
        #1. The adress of a pointer to an element.
        #2. The adress of the function used to iterate on the list.
        #3. The adress of the function used to delete the content of an element if needed.

RETURN VALUE
-------------
        The new list. NULL if the allocation fails.    

DESCRIPTION
-----------
        Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
        Creates a new list resulting of the successive applications of the function ’f’.
        The ’del’ function is used to delete the content of an element if needed.

* `del`: 노드 메모리 할당 실패 시 `content` 를 지워줄 함수
* `t_list *result`: 최종적으로 반환할 구조체 포인터
* `t_list *temp`: 현재 `lst->content` 를 `f` 에 적용시켜 반환된 새로운 문자열을 `content` 로 하는 새로운 구조체를 담는 임시 포인터
* 만약에 `temp` 에 메모리 할당하는 것을 실패하면 지금까지의 저장한 `result` 의 모든 노드의 `content` 를 `free()` 하고 `NULL` 을 반환한다.

* 순서
1. `result` 가 가리키는 값을 `NULL` 로 초기화한다.
2. `lstnew()` 함수를 이용하여 `f(lst->content)` 의 반환값을 `content` 로 하는 새로운 구조체를 `temp` 에 저장한다.
3. `lstadd_back()` 함수를 이용하여 `result` 에 `temp` 를 추가한다.
4. `temp` 와 `lst` 를 각각 다음 노드로 이동시킨다.
5. 최종적으로 만들어진 리스트 `result` 를 반환한다.


EXAMPLE
-----------
        void  f_del(void *content)
        {
            free(content);
        }
        int   main(void)
        {
            char *str = ft_strdup("Hello");
            t_list *lst = ft_lstnew(str);
            
            ft_lstdelone(lst, f_del);
        }
        
</br>
</br>
</br>
</br>
</br>
