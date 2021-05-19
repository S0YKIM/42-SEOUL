⭐lstdelone()
===================

PROTOTYPE
----------
        void	ft_lstdelone(t_list *lst, void (*del)(void*))


PARAMETERS
----------
        #1. The element to free.
        #2. The address of the function used to delete the content.
        

DESCRIPTION
-----------
        Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element.
        The memory of ’next’ must not be freed.

1. `del` 함수로 `content` 변수를 `free()` 해준다.
2. 그리고나서 `lst`를 `free()` 해준다.

* 바로 free(lst)만 하면 안되는 이유?
* `free(lst)`를 하고나면 `lst->content`로 접근이 불가능하기 때문이다.
* 그래서 `del(lst->content)` 먼저 하고나서 `free(lst)` 해주어야 한다.


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
