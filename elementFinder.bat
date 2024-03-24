@echo off
cls
gcc -o main main.c
.\main %1 %2 %3

rem AutoPulizia
del main.exe