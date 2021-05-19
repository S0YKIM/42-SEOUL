⭐lstclear()
============

PROTOTYPE
----------
        void ft_lstclear(t_list **lst, void (*del)(void *))


PARAMETERS
----------
        #1. The adress of a pointer to an element.
        #2. The adress of the function used to delete the content of the element.
        

DESCRIPTION
-----------
        Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3).
        Finally, the pointer to the list must be set to NULL.

* 연결 리스트의 전체 노드 데이터를 삭제한다.
* `**lst`: 할당을 해제할 연결리스트의 시작 지점
* `*del()`: 구조체 멤버변수의 할당을 해제해주는 함수 포인터
* 임시 변수 `temp`에 `curr->next`를 저장해두고 `del`을 이용하여 현재 노드의 `content`를 지운 후에 현재 노드를 다음 노드로 옮긴다.


EXAMPLE
-----------
        void  f_del(void *content)
        {
            free(content);
        }
        
        int   main(void)
        {
            char *str = ft_strdup("Hello");
            char *str2 = ft_strdup("Hello");
            t_list *lst = ft_lstnew(str);
            ft_lstadd_back(&lst, ft_lstnew(str2))
            
            ft_lstclear(&lst, f_del);
        }
        
</br>
</br>
</br>
</br>
</br>
