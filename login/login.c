#include "login.h"

int checkForSingle(char *name, char *passwd)
{
#if 0
    char name[NAME_LEN];     // 用户名
    char passwd[PASSWD_LEN]; // 密码
#endif
    /*判断用户名是否合法*/
    if (strcmp(name, USER_NAME) != 0)
    {
        // printf("用户名与密码不匹配\n");
        return -1;
    }
    /*判断密码是否正确*/
    if (strcmp(passwd, PASSWD) != 0)
    {
        // printf("用户名与密码不匹配\n");
        return -1;
    }

    // printf("用户名与密码匹配!\n");

    return 0;
}

int check_for_user(int users, char *passwd)
{
#if 0
    int user;
    char passwd[PASSWD_LEN];
#endif
    int result = -1; // 0 ok  其他表示失败

    switch (users)
    {
    case USER1:
        result = strcmp(passwd, PASSWD1);
        break;
    case USER2:
        result = strcmp(passwd, PASSWD2);
        break;
    case USER3:
        result = strcmp(passwd, PASSWD3);
        break;
    default:
        result = -1;
        break;
    }
#if 0
    if (result == 0)
    {
        printf("用户名与密码匹配!\n");
    }
    else
    {
        printf("用户名与密码不匹配!\n");
    }
#endif
    return result;
}
