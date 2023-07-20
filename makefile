# tool1.c tool1.h tool2.c tool2.h main.c 

TAR=main
CC:=gcc 
OBJ=main.o usr_mgt.o en_decode.o login.o
RM=rm -r
CFLAGS += -Wall -c -o

# 最终目标
$(TAR):$(OBJ) 	# 目标文件:依赖文件
	$(CC) $^ -o $@


%.o:%c	# 目标文件:依赖文件
	$(CC) $^ $(CFLAGS) $@

.PHONY:
clear:
	$(RM) $(OBJ)  -r
clearall:
	$(RM) $(OBJ) $(TAR) -r