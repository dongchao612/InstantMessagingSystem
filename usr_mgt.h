#ifndef USR_MGT_H__
#define USR_MGT_H__

#include <stdio.h>
#include <string.h>

/*系统支持的最大用户数量*/
#define MAX_UNUM 50
/*系统支持的最大用户姓名长度*/
#define MAX_UNAME_LEN 32

#define USER_OFFLINE 0
#define USER_ONLINE 1

/*表示用户的结构体*/
struct susr
{
    /*用户昵称*/
    char u_name[MAX_UNAME_LEN];
    /*用户ID*/
    int u_id;
    /*用户在线状态*/
    int u_stat;
};

/*增加好友 0表示成功 -1 表示失败*/
int user_add(int u_id, char *u_name);

/*删除好友  0表示成功 -1 表示失败*/
int user_del(int u_id, char *u_name);

/*好友排序*/
void user_sort_by_name(void);
void user_sort_by_id(void);

/*通过好友昵称或者id查找好友*/
struct susr *user_find_by_name(char *name);
struct susr *user_find_by_id(int *id);

/*通过二分法查找*/
struct susr *binary_search_by_id(int id);

/*导出好友信息*/
void user_info_dump();

void user_arry_init(int id, char *name);

#endif // !USR_MGT_H__