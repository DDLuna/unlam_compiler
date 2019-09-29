flex Lexico.l
bison -dyv Sintactico.y --graph
gcc.exe lex.yy.c y.tab.c -o primera.exe