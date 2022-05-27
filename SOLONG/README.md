# SOLONG

[![sokim's 42 so_long Score](https://badge42.vercel.app/api/v2/cl1sxc9pb003009jgq7f86utb/project/2388526)](https://github.com/JaeSeoKim/badge42)

🗒️ [Developer Note](https://pouncing-elbow-0a4.notion.site/Solong-2db1e3d2978d45abb567afbac53d8b26)

# 🚀 Contents

## 🚩 Mandatory Part

| Program name | so_long |
|--------------|----------|
| Turn in files | All your files |
| Makefile | all, clean, fclean, re, bonus |
| Arguments | a map in format *.ber |
| External functs. | • open, close, read, write, printf, malloc, free, perror, strerror, exit   • All functions of the MinilibX |
| Libft authorized | Yes |
| Description | You must create a small 2D game where a dolphin escapes earth after eating some fish. Or any hero collects any valuables before leaving the place. |



## 🚩 Bonus Part

You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. Be smart!.
Bonus list:

- enemy patrols that cause the player to lose in case of contact.
- There’s some sprite animation.
- Movement count is directly displayed on the screen instead of shell output.


# 💡 Step

## (1) 데이터 초기화

- 모든 데이터를 초기화하는 init 함수 실행

## (2) 파일 읽기

- 맵 데이터 한 줄에 저장
- open() 함수 이용하여 파일 디스크립터 얻기
- read() 함수로 파일 디스크립터로부터 읽어온 데이터를 저장

## (3) 맵 파싱

- 한 줄로 되어 있는 데이터를 여러 줄로 파싱
- ft_split() 이용하여 \n 마다 파싱해주거나,
- get_next_line() 의 기능을 활용하여 (2)~(3) 과정 통합

## (4) 맵 유효성 검사

- 맵이 직사각형이 맞는지?

      맵의 모든 가로 길이가 같은지?
      맵의 모든 세로 길이가 같은지?

- 최소 5x3 또는 3x5 크기가 맞는지?

      최소 하나의 플레이어(P), 출구(E), 콜렉터블(C)가 필요
      이들을 둘러싸는 벽(1)이 필요

- 하나의 플레이어가 맞는지?
- 하나의 출구가 맞는지?
- 하나 이상의 콜렉터블이 맞는지?


## (5) 새 창 띄우기

- mlx_new_window() 를 통해 새 창 생성

## (6) 이미지 띄우기

- mlx_new_image() 를 통해 새 이미지 생성
- mlx_get_data_addr() 를 통해 생성된 이미지에 대한 정보 가져오기
- 이미지의 정보를 가지고 픽셀 찍는 함수 만들기
- mlx_put_image_to_window() 를 통해 이미지를 스크린에 출력

## (7) 이벤트 후킹

- mlx_key_hook() 로 이벤트 듣고 알맞은 함수 실행

## (8) 루프 돌리기

- mlx_loop()
