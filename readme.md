# Compilador para la materia de Lenguajes y Compiladores

## Instrucciones
Tener en el path a GnuWin32\bin  
Tener en el path a MinGW\bin

Correr 2_generar.bat para correr el léxico + sintáctico y generar el primera.exe.  
Usar el primera.exe con archivos para generar la tabla de símbolos y el árbol sintáctico (WIP).  
Usar el 3_compilar.bat para probar todos los archivos de prueba.  
Usar 1_borrar.bat para eliminar los archivos generados.  

## Ej
primera.exe prueba.txt
---
# Git
[Descargar git](https://gitforwindows.org/)  
Clonar repo:  
```
git clone git@github.com:DDLuna/unlam_compiler.git
```
Hacer cambios:
```
git checkout -b nombre_sin_espacios
modificar|agregar|borrar cosas
git add .
git commit -m "pequeño mensaje"
git push origin master
```
Crear un PR desde github.
Merge y borrar branch
