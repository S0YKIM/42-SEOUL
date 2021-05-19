구조체 활용 함수
============

typedef struct          s_list
{
        void            `*content`;
        struct s_list   `*next`;
}                       t_list;
</br>
</br>
Here is a description of the fields of the t_list struct:
• content : The data contained in the element. The void * allows to store any kind
of data.
• next : The next element’s address or NULL if it’s the last element.
</br>
</br>
</br>
</br>
