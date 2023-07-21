login_test:login_test.o login.o
	gcc login_test.o login.o -o login_test

login_test.o:login_test.c
	gcc -c login_test.c -o login_test.o

login.o:login.c
	gcc -c login.c -o login.o

.PHONY:
clear:
	rm login_test login_test.o login.o -rf