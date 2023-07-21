#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "login.h"

int main(int argc, char const *argv[])
{
    char user[NAME_LEN], passwd[PASSWD_LEN];
    printf("请输入用户名: ");
    scanf("%s", user);
    printf("\n");
    printf("请输入密码: ");
    scanf("%s", passwd);
    int result = checkForSingle(user, passwd);

    if (result == LOGIN_ERR)
    {
        printf("用户名与密码不匹配\n");
    }
    else
    {
        printf("用户名与密码匹配!\n");
    }

    int users;
    printf("请输入用户名: ");
    scanf("%d", &users);
    printf("\n");
    printf("请输入密码: ");
    scanf("%s", passwd);

    result = check_for_user(users, passwd);

    if (result == LOGIN_ERR)
    {
        printf("用户名与密码不匹配\n");
    }
    else
    {
        printf("用户名与密码匹配!\n");
    }
    return 0;
}
