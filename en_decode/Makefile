en_decode_test:en_decode_test.o en_decode.o
	gcc en_decode_test.o en_decode.o -o en_decode_test

en_decode_test.o:en_decode_test.c
	gcc -c en_decode_test.c -o en_decode_test.o

en_decode.o:en_decode.c
	gcc -c en_decode.c -o en_decode.o
	
.PHONY:
clear:
	rm en_decode_test en_decode_test.o en_decode.o -rf