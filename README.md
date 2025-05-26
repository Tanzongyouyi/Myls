# Myls
Myls is a remake "ls" for linux or other systems.It is written in C and is compiled on Android. <br>At this time, we don't know about the issues associated with porting to other platforms.<br>At this version,It's also worth mentioning that if you don't give Myls enough access to directories that require permission, Myls will think the directory is a file and label it in white.

# Usage
Usage: ./myls /directory or ./myls for local directory
![Usage](/mddata/demo.jpg "Demo")

# Want to try the fun of compiling yourself?
    gcc -o myls myls.c
This allows the executable file to be compatible with your own system.<br>
Besides gcc, you can also use any compiler you want, but I cannot guarantee that there won't be any issues.

# Advantages
1.Myls will automatically show you hidden files with no extra effort!<br>
2.Additional features are in development...
