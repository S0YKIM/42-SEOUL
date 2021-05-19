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

* `t_list *result`: 최종적으로 



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
