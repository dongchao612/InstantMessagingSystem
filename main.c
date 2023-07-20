#include <stdio.h>
#include <string.h>

#include "login.h"
#include "en_decode.h"
#include "usr_mgt.h"

int main(int argc, char const *argv[])
{
    char user[NAME_LEN], passwd[PASSWD_LEN];
    printf("请输入用户名: ");
    scanf("%s", user);
    printf("\n");
    printf("请输入密码: ");
    scanf("%s", passwd);
    checkForSingle(user, passwd);

    int users;
    printf("请输入用户名: ");
    scanf("%d", &users);
    printf("\n");
    printf("请输入密码: ");
    scanf("%s", passwd);
    check_for_user(users,  passwd);
    return 0;
}
