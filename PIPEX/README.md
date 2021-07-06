# PIPEX()

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/sokim/pipex)](https://github.com/JaeSeoKim/badge42)
</br>

✔️ Mandatory Part
================


- The executable file must be named pipex.
- Handle the errors like the shell command < file1 cmd1 | cmd2 > file2.
- You are allowed to use the following functions:

◦ access 

◦ open

◦ unlink

◦ close

◦ read

◦ write

◦ malloc

◦ waitpid

◦ wait

◦ free

◦ pipe

◦ dup

◦ dup2

◦ execve

◦ fork

◦ perror

◦ strerror

◦ exit

</br>
</br>

- The program should be executed in this way:

       ./pipex file1 cmd1 cmd2 file2

- Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.
- The execution of the pipex program should do the same as the next shell command:

      < file1 cmd1 | cmd2 > file2

- Examples:

       ./pipex infile ``ls -l'' ``wc -l'' outfile
       < infile ls -l | wc -l > outfile
       
       ./pipex infile ``grep a1'' ``wc -w'' outfile
       < infile grep a1 | wc -w > outfile
</br>
</br>
</br>

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
