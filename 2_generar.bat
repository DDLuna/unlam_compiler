flex Lexico.l
bison -dyv Sintactico.y
gcc.exe lex.yy.c y.tab.c -o segunda.exe
pause