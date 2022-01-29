# PUSH SWAP

> This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

</br>

## 🎲 INSTRUCTIONS

- The game is composed of 2 stacks named a and b.
- To start with:
  - a contains a random number of either positive or negative numbers without any duplicates.
  - b is empty
- The goal is to sort in ascending order numbers into stack a.
- To do this you have the following operations at your disposal:

  **`sa`** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

  **`sb`** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

  **`ss`** : sa and sb at the same time.

  **`pa`** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

  **`pb`** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

  **`ra`** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

  **`rb`** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

  **`rr`** : ra and rb at the same time. rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

  **`rra`** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

  **`rrb`** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

  **`rrr`** : rra and rrb at the same time.
  
</br>

## 🔄 Push_swap

> ### 🚀 build
>
> ```shell
> $> make push_swap
> ```
>
> ### 🔖 Usage
>
> ```shell
> $>./push_swap 2 1 3 6 5 8
> sa
> pb
> pb
> pb
> sa
> pa
> pa
> pa
> $>./push_swap 0 one 2 3
> Error
> ```
>
> ### 🔖 Usage - with checker
>
> ```shell
> $>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
> 6
> $>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
> OK
> ```
>
> ⚠️ If your program checker displays KO, it means that your push_swap came up with a list of instructions that doesn’t sort the list.

</br>

- You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separaed by a ’\n’ and nothing else.
- The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operation tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.
- In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.
