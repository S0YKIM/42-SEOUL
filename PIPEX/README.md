# PIPEX

[![sokim's 42 pipex Score](https://badge42.vercel.app/api/v2/cl1sxc9pb003009jgq7f86utb/project/2209830)](https://github.com/JaeSeoKim/badge42)

> The aim of this project is to mimic the UNIX mechanism.

## β­ Key concepts
`Redirection`, `Pipes`, `Process`, `fork()`, `dup2()`


## β­ Developer notes
π[λ¦¬λλ μκ³Ό νμ΄ν](https://love-every-moment.tistory.com/52)
</br>
π[λ¦¬λμ€ λͺλ Ή νμ κ²½λ‘](https://love-every-moment.tistory.com/54)
</br>
π[νλ‘μΈμ€ μμ±κ³Ό μ€ν](https://love-every-moment.tistory.com/53)
</br>
π[νμΌ λμ€ν¬λ¦½ν°](https://love-every-moment.tistory.com/45)
</br>


## π Contents

### π© Mandatory Part
- The executable file must be named pipex.
- Handle the errors like the shell command < file1 cmd1 | cmd2 > file2.
- You are allowed to use the following functions:

β¦ access 

β¦ open

β¦ unlink

β¦ close

β¦ read

β¦ write

β¦ malloc

β¦ waitpid

β¦ wait

β¦ free

β¦ pipe

β¦ dup

β¦ dup2

β¦ execve

β¦ fork

β¦ perror

β¦ strerror

β¦ exit



- The program should be executed in this way

       ./pipex file1 cmd1 cmd2 file2

- Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.
- The execution of the pipex program should do the same as the next shell command:

      < file1 cmd1 | cmd2 > file2

- Examples

       ./pipex infile ``ls -l'' ``wc -l'' outfile
       < infile ls -l | wc -l > outfile
       
       ./pipex infile ``grep a1'' ``wc -w'' outfile
       < infile grep a1 | wc -w > outfile


### π© Bonus Part

- Handle multiple pipes

       ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
       < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
       
- Support Β« and Β» when the first parameter is "here_doc"

       ./pipex here_doc LIMITER cmd cmd1 file
       cmd << LIMITER | cmd1 >> file
