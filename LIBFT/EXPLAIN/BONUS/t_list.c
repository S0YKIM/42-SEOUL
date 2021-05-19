// 구조체 정의


typedef struct          s_list
{
        void            *content;
        struct s_list   *next;
}                       t_list;

//Here is a description of the fields of the t_list struct:
//content : The data contained in the element. The void * allows to store any kind of data.
//next : The next element’s address or NULL if it’s the last element.

