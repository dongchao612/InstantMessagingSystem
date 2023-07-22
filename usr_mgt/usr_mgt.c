#include "usr_mgt.h"

/*所有的好友数组，最多支持MAX_UNUM 个*/
static struct susr usr_arr[MAX_UNUM];

/*实际的总的好友数目*/
static int usr_cnt = 0;

/*代表通信用户本身的结构体*/
static struct susr usr_self;

/*好友数组初始化*/
void user_arry_init(int id, char *name)
{
    memset(usr_arr, 0, sizeof(usr_arr));

    usr_cnt = 0;
    memset(&usr_self, 0, sizeof(usr_self));

    usr_self.u_id = id;
    strcpy(usr_self.u_name, name);
    usr_self.u_stat = USER_OFFLINE;
}

int user_add(int u_id, char *u_name)
{
    /*判断 好友id不能为0  好友id不能为自身id  好友数目不能达到上限MAX_UNUM*/
    /*判断 好友是否已经是自己的好友了 usr_find_by_id*/

    if (!u_id || u_id == usr_self.u_id || usr_cnt == MAX_UNUM)
    {
        return -1;
    }
    if (user_find_by_id(u_id) != NULL)
    {
        return -1;
    }

    /*将好友插入到已有的好友的末尾*/
    usr_arr[usr_cnt].u_id = u_id;
    strcpy(usr_arr[usr_cnt].u_name, u_name);
    usr_arr[usr_cnt++].u_stat = USER_OFFLINE;

    return 0;
}

int user_del(int u_id)
{
struct susr *usr, *p, *pend = usr_arr + usr_cnt;

	/*查找好友是否在好友列表中*/
	if ((usr = user_find_by_id(u_id)) == NULL)
	{
		return -1;
	}

	/*已经找到该好友的对应的结构*/
	p = usr + 1;
	/*依次对被删除好友之后的结构往前移动，直到最后一个好友结构*/
	while (p <pend)
	{
		*usr = *p++;
	}
	memset(p - 1, 0, sizeof(*p));

	/*更新好友计数*/
	usr_cnt--;

    return 0;

}

void user_sort_by_name(void)
{
   /*选择排序*/
	int i, j, index;
	struct susr temp;
	for ( i = 0; i < usr_cnt -1; i++)
	{
		index = i;
		for ( j = i+1; j < usr_cnt; j++)
		{
			if (strcmp(usr_arr[j].u_name, usr_arr[index].u_name) < 0)
			{
				index = j;
			}
		}
		if (index != i)
		{
			temp = usr_arr[index];
			usr_arr[index] = usr_arr[i];
			usr_arr[i] = temp;
		}
	}
}
void user_sort_by_id(void)
{
    /*选择排序*/
    int i, j, index;
    struct susr temp;
    for (i = 0; i < usr_cnt - 1; i++)
    {
        index = i;
        for (j = i + 1; j < usr_cnt; j++)
        {
            if (usr_arr[j].u_id < usr_arr[index].u_id)
            {
                index = j;
            }
        }
        if (index != i)
        {
            temp = usr_arr[index];
            usr_arr[index] = usr_arr[i];
            usr_arr[i] = temp;
        }
    }
}

struct susr *user_find_by_name(char *name)
{
    struct susr *p = usr_arr, *pend = p + usr_cnt;
    while (p < pend)
    {
        if (!strcmp(p->u_name, name))
        {
            break;
        }
        p++;
    }

    return (p == pend) ? NULL : p;
}

struct susr *user_find_by_id(int id)
{
    /*判断uid是否为0，或者为用户自身id，返回空*/
    if (!id || id == usr_self.u_id)
        return NULL;

    /*遍历好友列表*/
    int i = 0;
    while (i < usr_cnt)
    {
        if (usr_arr[i++].u_id == id)
        {
            break;
        }
    }

    return (i == usr_cnt) ? NULL : &usr_arr[i];
}

struct susr *binary_search_by_id(int id)
{
    return NULL;
}

/*导出好友信息*/
void user_info_dump()
{
    printf("所有好友信息如下:\nuser:%d\tname:%s\tcnt:%d\n", usr_self.u_id, usr_self.u_name, usr_cnt);
    int i = 0;
    while (i < usr_cnt)
    {
        printf("the %d th \tname:%s\tid:%d\n", i, usr_arr[i].u_name, usr_arr[i].u_id);
        i++;
    }
    printf("\n");
}
