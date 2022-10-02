mymat: mainmat.o mymat.o integrity_checks.o findmat.o
	gcc -g -ansi -Wall -pedantic mainmat.o mymat.o integrity_checks.o findmat.o -o mymat
mai_mat.o: mainmat.c mat.h
	gcc -c -ansi -Wall -pedantic mainmat.c -o mainmat.o
mymat.o: mymat.c mat.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o
integrity_checks.o: integrity_checks.c mat.h
	gcc -c -ansi -Wall -pedantic integrity_checks.c -o integrity_checks.o
findmat.o: findmat.c mat.h
	gcc -c -ansi -Wall -pedantic findmat.c -o findmat.o