# SOLONG

[![sokim's 42 so_long Score](https://badge42.vercel.app/api/v2/cl1sxc9pb003009jgq7f86utb/project/2388526)](https://github.com/JaeSeoKim/badge42)

ποΈ [Developer Note](https://pouncing-elbow-0a4.notion.site/Solong-2db1e3d2978d45abb567afbac53d8b26)

# π Contents

## π© Mandatory Part

| Program name | so_long |
|--------------|----------|
| Turn in files | All your files |
| Makefile | all, clean, fclean, re, bonus |
| Arguments | a map in format *.ber |
| External functs. | β’ open, close, read, write, printf, malloc, free, perror, strerror, exit   β’ All functions of the MinilibX |
| Libft authorized | Yes |
| Description | You must create a small 2D game where a dolphin escapes earth after eating some fish. Or any hero collects any valuables before leaving the place. |



## π© Bonus Part

You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. Be smart!.
Bonus list:

- enemy patrols that cause the player to lose in case of contact.
- Thereβs some sprite animation.
- Movement count is directly displayed on the screen instead of shell output.

</br>
</br>

# π‘ Steps to make it

## (1) λ°μ΄ν° μ΄κΈ°ν

- λͺ¨λ  λ°μ΄ν°λ₯Ό μ΄κΈ°ννλ init ν¨μ μ€ν

## (2) νμΌ μ½κΈ°

- λ§΅ λ°μ΄ν° ν μ€μ μ μ₯
- open() ν¨μ μ΄μ©νμ¬ νμΌ λμ€ν¬λ¦½ν° μ»κΈ°
- read() ν¨μλ‘ νμΌ λμ€ν¬λ¦½ν°λ‘λΆν° μ½μ΄μ¨ λ°μ΄ν°λ₯Ό μ μ₯

## (3) λ§΅ νμ±

- ν μ€λ‘ λμ΄ μλ λ°μ΄ν°λ₯Ό μ¬λ¬ μ€λ‘ νμ±
- ft_split() μ΄μ©νμ¬ \n λ§λ€ νμ±ν΄μ£Όκ±°λ,
- get_next_line() μ κΈ°λ₯μ νμ©νμ¬ (2)~(3) κ³Όμ  ν΅ν©

## (4) λ§΅ μ ν¨μ± κ²μ¬

- λ§΅μ΄ μ§μ¬κ°νμ΄ λ§λμ§?

      λ§΅μ λͺ¨λ  κ°λ‘ κΈΈμ΄κ° κ°μμ§?
      λ§΅μ λͺ¨λ  μΈλ‘ κΈΈμ΄κ° κ°μμ§?

- μ΅μ 5x3 λλ 3x5 ν¬κΈ°κ° λ§λμ§?

      μ΅μ νλμ νλ μ΄μ΄(P), μΆκ΅¬(E), μ½λ ν°λΈ(C)κ° νμ
      μ΄λ€μ λλ¬μΈλ λ²½(1)μ΄ νμ

- νλμ νλ μ΄μ΄κ° λ§λμ§?
- νλμ μΆκ΅¬κ° λ§λμ§?
- νλ μ΄μμ μ½λ ν°λΈμ΄ λ§λμ§?


## (5) μ μ°½ λμ°κΈ°

- mlx_new_window() λ₯Ό ν΅ν΄ μ μ°½ μμ±

## (6) μ΄λ―Έμ§ λμ°κΈ°

- mlx_new_image() λ₯Ό ν΅ν΄ μ μ΄λ―Έμ§ μμ±
- mlx_get_data_addr() λ₯Ό ν΅ν΄ μμ±λ μ΄λ―Έμ§μ λν μ λ³΄ κ°μ Έμ€κΈ°
- μ΄λ―Έμ§μ μ λ³΄λ₯Ό κ°μ§κ³  ν½μ μ°λ ν¨μ λ§λ€κΈ°
- mlx_put_image_to_window() λ₯Ό ν΅ν΄ μ΄λ―Έμ§λ₯Ό μ€ν¬λ¦°μ μΆλ ₯

## (7) μ΄λ²€νΈ ννΉ

- mlx_key_hook() λ‘ μ΄λ²€νΈ λ£κ³  μλ§μ ν¨μ μ€ν

## (8) λ£¨ν λλ¦¬κΈ°

- mlx_loop()
