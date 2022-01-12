# SOLONG


✔️ Mandatory Part
================

| Program name | so_long  |
|--------------|----------|
| Turn in files | All your files |
| Makefile | all, clean, fclean, re, bonus |
| Arguments | a map in format *.ber |
| External functs. | • open, close, read, write, printf, malloc, free, perror, strerror, exit /br • All functions of the MinilibX |
| Libft authorized | Yes |
| Description | You must create a small 2D game where a dolphin escapes earth after eating some fish. Or any hero collects any valuables before leaving the place. |



The constraints are as follows:

• You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part.
• The management of your window must remain smooth: changing to another win- dow, minimizing, etc.
• examples are given with a dolphin theme but you can use anything you want.
• The map will be constructed with 3 components walls, collectibles, and free space.
• The player’s goal is to collect all collectibles present on the map then escape with minimal movement.
• At every move the current number of movements must be displayed in the shell.
• The player must be able to move: up, down, left, right.
• You will use a 2D view (top-down or profile).
• The game doesn’t need to be real-time.
• player cannot move into walls.
• The program displays the image in a window and respects the following rules:
◦ The W, A, S, and D keys will be used to move the main character.
◦ Pressing ESC must close the window and quit the program cleanly.
◦ Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
◦ The use of images of the minilibX is strongly recommended.
• Your program must take as a first argument a map description file with the .ber
extension.
◦ The map must be composed of only 5 possible characters: 0 for an empty space, 1 for a wall, C for a collectible, E for map exit and P for the player’s starting position.
This is a simple valid map:
◦ The map must be closed/surrounded by walls, if not the program must return an error.
◦ Map must have at least one exit, one collectible, and one starting position.
◦ You don’t need to check if there’s a valid path in the map.
◦ The map must be rectangular.
◦ You must be able to parse any kind of map, as long as it respects the rules of the map.
 
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

 ◦ Another minimal .ber map:
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111

◦ If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.

✔️ Bonus Part
============

- Handle multiple pipes :

       ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
       < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
       
- Support « and » when the first parameter is "here_doc" :

       ./pipex here_doc LIMITER cmd cmd1 file
       cmd << LIMITER | cmd1 >> file

</br>
</br>
</br>

⭐DESCRIPTIONS
==============

* The aim of this project is to mimic the UNIX mechanism.
* Key concepts: `Redirection`, `Pipes`, `Process`, `fork()`, `dup2()`
</br>
</br>



⭐MY ARTICLES
=============

리디렉션과 파이프: https://love-every-moment.tistory.com/52
</br>
리눅스 명령 탐색 경로: https://love-every-moment.tistory.com/54
</br>
프로세스 생성과 실행: https://love-every-moment.tistory.com/53
</br>
파일 디스크립터: https://love-every-moment.tistory.com/45
</br>

