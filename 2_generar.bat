set path=c:\GnuWin32\bin
flex Lexico.l
pause
bison -dyv Sintactico.y
pause
set path=c:\MinGW\bin
gcc.exe lex.yy.c y.tab.c -o primera.exe
pause
