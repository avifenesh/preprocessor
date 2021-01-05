preprocessor: preprocessor.o cleanComment.o includeFiles.o 
	gcc -g -ansi -Wall -pedantic preprocessor.o cleanComment.o includeFiles.o -o preprocessor

preprocessor.o: preprocessor.c preprocessor.h
	gcc -c -ansi -Wall -pedantic preprocessor.c -o preprocessor.o

cleanComment.o: cleanComment.c
	gcc -c -ansi -Wall -pedantic cleanComment.c -o cleanComment.o

includeFile.o: includeFiles.c
	gcc -c -ansi -Wall -pedantic includeFiles.c -o includeFiles.o