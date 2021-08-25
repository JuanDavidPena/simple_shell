# Simple Shell

### Introduction
This repository is a [Holberton School](https://www.holbertonschool.com/) Project. The school project consisted in writing a shell like sh (Bourne Shell) by Stephen Bourne  , in **C**, using a limited number of standard library functions, so instead we used our own functiona that we did over the past three months [Here](https://github.com/JuanDavidPena/holbertonschool-low_level_programming.git)

The goal in this project was to make us understand how a shell works. To single out some items: what is the *environment*, the difference between *functions* and *system calls*, how to create *processes* using `execve`...  

## Usage 
In order to run this program, 

Clone This Repo

`` git clone https://github.com/JuanDavidPena/simple_shell.git ``

compile it with  

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`.  
You can then run it by invoking `./hsh` in the same directory.  

### How to use it
In order to use this shell, in a terminal, first run the program:    
`prompt$ ./hsh`  
It will then display a simple prompt and wait for commands.  
`$ `   
A command will be of the type `$ command`  
This shell can handle two types of commands: built-ins and normal programs.
##### List of built-ins
Currently the list of built-ins this shell can handle is:  
* cd [directory]  
Switch to the specified directory (path).
* env  
Displays the environment variable
* exit [exitstatus]  
Exit from the program with exitstatus value. 0 by default.
* getenv NAME  
Return the value of the NAME variable if it is in the environment
* help [command]  
Displays the syntax for the command, or all commands.  
* history  
Displays the history of user inputs .
* echo [$$] or [$?] or [$PATH]
Return pid, exit status and PATH.
##### Command
Handles the programs in `$PATH`
It supports single cmd like `ls` 

It handles path `ls /tmp`

it handles options like `ls -l`

it handles complex instructions `ls -l /var `

it handles path cmds `/bin/ls` and also options in the path `/bin/ls -l /var`

it handles Comments **#** 
## Examples Command
**Example 1**
```
Username@your-regular-prompt:~$ ./hsh
$ pwd
/home/username/
$ ^D
Username@your-regular-prompt:~$
```
**Example 2**
```
Username@your-regular-prompt:~$ ./hsh
$ ls -l /tmp 
-rw------- 1 username username    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 username username    0 Dec  5 12:09 unity_support_test.0
$ ^D
Username@your-regular-prompt:~$
```
### Examples Built-in

**case env and exit**
```
Username@your-regular-prompt:~$ ./hsh
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
Username@your-regular-prompt:~$ 

```
**Case Exit Status**
```
Username@your-regular-prompt:~$ ./hsh
$ exit 98
Username@your-regular-prompt:~$ echo $?
98
Username@your-regular-prompt:~$

```
Keep Exploring The echo Builtin and history ... Using The Help Builtin

### Also
* Handle Ctrl+C: your shell should not quit when the user inputs ^C
* If no argument is given to cd the command must be interpreted like cd $HOME
* handle the command cd -
* Handle variables replacement
* Handle the $? variable
* Handle the $$ variable
* Handle The Argument file like `./hsh test` Where test is a file filled with command and builtin to excute.
### List of functions and system calls we could use
List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    fork (man 2 fork)
    free (man 3 free)
    fstat (man 2 fstat)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    kill (man 2 kill)
    lstat (man 2 lstat)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (man 2 stat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
    _exit (man 2 _exit)
### Custom Function (Recreation of Standard Function in C)
 * _strncpy
 * _strlen
 * _putchar
 * _atoi
 * _puts
 * _strcmp
 * _isalpha
 * array_rev
 * intlen
 * _itoa
 * _strcat
 * _strcpy
 * _strchr
 * _strncmp
 * _strdup
 * _memcpy
 * _calloc
 * _realloc
 * _getenv
 * _getline
 * _strtok

For More Info About It Check The Man Page by
```
Username@your-regular-prompt:~$ man ./man_1_simple_shell
```

## Authors
* Juan David Peña [JuanDavidPena](https://github.com/JuanDavidPena)

<p align="center">
  <img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School logo">
</p>
