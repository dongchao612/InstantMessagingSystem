usr_mgt_test:usr_mgt_test.o usr_mgt.o
	gcc usr_mgt_test.o usr_mgt.o -o usr_mgt_test

usr_mgt_test.o:usr_mgt_test.c
	gcc -c usr_mgt_test.c -o usr_mgt_test.o

usr_mgt.o:usr_mgt.c
	gcc -c usr_mgt.c -o usr_mgt.o
	
.PHONY:
clear:
	rm usr_mgt_test usr_mgt_test.o usr_mgt.o -rf