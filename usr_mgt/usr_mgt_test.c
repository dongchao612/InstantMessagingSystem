#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usr_mgt.h"

void user_add_test()
{
    user_add(10000, "tom");
    user_add(10001, "mary");
    user_add(10002, "jack");
    user_add(10003, "jeo");
    user_add(10004, "cat");
    user_add(10005, "apple");
    user_add(10006, "banana");
    user_add(10007, "orange");
    user_add(10008, "lisa");
    user_add(10009, "alice");
}

void user_del_test()
{
    user_del(10001);
    user_del(20000);
    user_del(10008);
    user_del(10010);
    user_del(999999);
}

int main(int argc, char const *argv[])
{
    struct susr *usr;

    /*初始化好友数组*/
    user_arry_init(1, "brant");

    /*好友增加测试*/
    printf("\n====================好友增加测试=======================\n");
    user_add_test();
    user_info_dump();

    printf("\n====================好友查找测试=======================\n");
    usr = user_find_by_id(10009);
    if (usr)
        printf("%d \t %s \t \n", usr->u_id, usr->u_name);
    else
        printf("10009好友未找到\n");

    usr = user_find_by_id(15000);
    if (usr)
        printf("%d \t %s \t \n", usr->u_id, usr->u_name);
    else
        printf("15000好友未找到\n");

    usr = user_find_by_name("banana");
    if (usr)
        printf("%d \t %s \t \n", usr->u_id, usr->u_name);
    else
        printf("banana 好友未找到\n");

    usr = user_find_by_name("ASDASF");
    if (usr)
        printf("%d \t %s \t \n", usr->u_id, usr->u_name);
    else
        printf("ASDASF 好友未找到\n");

    /*通过昵称排序测试*/
    printf("\n====================好友昵称排序=======================\n");
    user_sort_by_name();
    user_info_dump();

    printf("\n====================好友id排序=======================\n");
    user_sort_by_id();
    user_info_dump();

    /*删除好友测试*/
    printf("\n====================好友删除测试=======================\n");
    user_del_test();
    user_info_dump();

    return 0;
}
