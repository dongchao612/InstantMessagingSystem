#ifndef LOGIN_H__
#define LOGIN_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 40
#define PASSWD_LEN 40

#define USER_NAME "USER1"
#define PASSWD "PASSWD1"

#define LOGIN_OK 0
#define LOGIN_ERR -1

#define USER1 10001
#define PASSWD1 "10001"
#define USER2 10002
#define PASSWD2 "10002"
#define USER3 10003
#define PASSWD3 "10003"

int checkForSingle(char *name, char *passwd);
int check_for_user(int users, char *passwd);

#endif //! LOGIN_H__