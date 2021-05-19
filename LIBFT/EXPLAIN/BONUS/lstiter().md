⭐lstiter()
===================

PROTOTYPE
----------
        void	ft_lstiter(t_list *lst, void (*f)(void *))


PARAMETERS
----------
        #1. The adress of a pointer to an element.
        #2. The adress of the function used to iterate on the list.
        

DESCRIPTION
-----------
        Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
        

* 각 노드의 `content`를 함수 `f`에 적용시켜 값을 바꾼다. 
</br>
</br>


EXAMPLE
-----------
        void  f_iter(void *content)
        {
            char *cont = (char *)content;
            for (int i = 0; cont[i]; i++)
            {
                if (i % 2)
                    cont[i] = '-';
            }
            printf("%s\n", content);
        }
        
        int   main(void)
        {
            char *str = ft_strdup("Hello");
            char *str2 = ft_strdup("Replace");
            t_list *lst = ft_lstnew(str);
            ft_lstadd_back(&lst, ft_lstnew(str2));
            
            ft_lstdelone(lst, f_iter);
        }   
</br>
</br>
</br>
</br>
</br>
