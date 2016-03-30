# Mesh Simplication

This repository holds mesh simplification, a project based on edge-collapse algorithm, which is put forward by Michael Garland and  Paul S. Heckbert in 1997.

 
## Description

-- This is one the homework of Computer Graphics, a course in spring semester, 2016.

-- You can download this project to complile by executing "make" command or test it by executing "main.exe [input.obj] [output.obj] [ratio]".

## Dragon Model (For example)
-Original model (9342 KB)
![dragon](https://raw.githubusercontent.com/lihy96/MeshSimplify/master/image/dragon.gif)

-Simplication ration = 0.3 (2221 KB)
![d03](https://raw.githubusercontent.com/lihy96/MeshSimplify/master/image/d03.gif)

-Simplication ration = 0.05 (357 KB)
![d005](https://raw.githubusercontent.com/lihy96/MeshSimplify/master/image/d005.gif)

-Simplication ration = 0.01 (80 KB)
![d001](https://raw.githubusercontent.com/lihy96/MeshSimplify/master/image/d001.gif)


##  Compiling environment

- Complier：g++ (GCC) 4.8.1

- OS：Windows 7 - 64bit

## References

- Garland M., Heckbert P S., Surface simplification using quadric error matrix, Computer Graphics, 1997, 209-216.

- Course materials provided by teacher and TA of Computer Graphics.