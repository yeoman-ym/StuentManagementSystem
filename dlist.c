/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: 双向循环链表相关函数定义
 **********************************/

#include "dlist.h"

/* ******************************************
 * Summary: 双向循环链表建立
 * Parameters: 无
 * Calls:   
 * Return: 成功返回头指针，失败返回NULL
 * Others: 
 * ******************************************/
LinkList LinkCreate()
{
    LinkList head = (LinkList)malloc(sizeof(node_t));
    SYSERR(head,==,NULL,"malloc err\n",NULL);

    head->data = NULL;
    head->next = head;
    head->prev = head;

    return head;
}

/* ******************************************
 * Summary: 双向链表的头插
 * Parameters: 学生数据链表，万能数据，数据大小
 * Calls: 
 * Return: 成功返回0，失败返回-1
 * Others: 
 * ******************************************/
int LinkList_hInsert(LinkList head, const void *data, int size)
{
    //安全检查
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(data,==,NULL,"data is null\n",-1);
    SYSERR(size,<,1,"size is err. must >= 1\n",-1);
    //创建新节点
    node_t *p = (node_t*)malloc(sizeof(node_t));
    SYSERR(p,==,NULL,"p malloc err\n",-1);
    p->data = (void *)malloc(size);
    if(p->data == NULL)
    {
        free(p);
        printf("malloc data err\n");
        return -1;
    }
    //数据拷贝
    memcpy(p->data,data,size);
    //先链后断
    p->next = head->next;
    p->prev = head;
    head->next = p;
    p->next->prev = p;

    return 0;
}

/* ******************************************
 * Summary: 双向链表尾插
 * Parameters: 学生数据链表，万能数据，数据大小
 * Calls:   
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_tInsert(LinkList head, const void *data, int size)
{
    //安全检查
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(data,==,NULL,"data is null\n",-1);
    SYSERR(size,<,1,"size is err. must >= 1\n",-1);
    //创建新节点
    node_t *p = (node_t*)malloc(sizeof(node_t));
    SYSERR(p,==,NULL,"p malloc err\n",-1);
    p->data = (void *)malloc(size);
    if(p->data == NULL)
    {
        free(p);
        printf("malloc data err\n");
        return -1;
    }
    //数据拷贝
    memcpy(p->data,data,size);
    //先链后断
    p->next = head;
    p->prev = head->prev;

    head->prev->next = p;
    head->prev = p;

    return 0;
}

/* ******************************************
 * Summary: 双向链表循环打印
 * Parameters: 学生数据链表，显示方式
 * Calls:  
 * Return: 成功返回0 失败返回0
 * Others: 
 * ******************************************/
int LinkList_Show(node_t *head, showfun_t showfunc)
{
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(head->next,==,NULL,"list is empty",-1);

    node_t *p = head->next;
    while(p != head)
    {
        showfunc(p->data);
        p = p->next;
    }
    return 0;
}

/* ******************************************
 * Summary: 链表删除
 * Parameters: 学生数据链表
 * Calls: 
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_hdelete(LinkList head)
{
    SYSERR(head->next,==,head,"list is empty\n",-1);
    SYSERR(head,==,NULL,"head is null",-1);

    node_t *p = head->next;
    
    head->next = head->next->next;
    head->next->next->prev = head;
    p->next = p->prev = NULL;
    free(p->data);
    free(p);
    return 0;
}

/* ******************************************
 * Summary: 双向链表的删除
 * Parameters: 学生数据链表
 * Calls:   
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_tdelete(LinkList head)
{
    SYSERR(head->next,==,head,"list is empty\n",-1);
    SYSERR(head,==,NULL,"head is null",-1);

    node_t *p = head->prev;

    head->prev->prev->next = head;
    head->prev = p->prev;

    p->next = p->prev = NULL;

    free(p->data);
    free(p);
    return 0;
}

/* ******************************************
 * Summary: 链表的查找
 * Parameters: 学生数据链表，万能数据，查找模式
 * Calls: func_find 
 * Return: 成功返回0 失败返回NULL
 * Others: 
 * ******************************************/
LinkList LinkList_Find(LinkList head, const void *data, func_find_t func_find)
{
    SYSERR(head,==,NULL,"head is null\n",NULL);
    SYSERR(head->next,==,head,"list is empty\n",NULL);
    SYSERR(data,==,NULL,"data is null\n",NULL);
    node_t *p = head->next;

    while(p != head && p->data != NULL)
    {
        if(func_find(data,p->data) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

/* ******************************************
 * Summary: 双向链表的修改
 * Parameters: 学生数据链表，旧数据，新数据，数据大小，查找方式
 * Calls: LinkList_Find  
 * Return: 成功返回0
 * Others: 
 * ******************************************/
int LinkList_update(LinkList head, const void *olddata, const void *newdata, int size, func_find_t func_find)
{
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(head->next,==,head,"list is empty\n",-1);
    SYSERR(olddata,==,NULL,"data is null\n",-1);
    SYSERR(newdata,==,NULL,"newdata is null\n",-1);

    node_t *p = LinkList_Find(head, olddata, func_find);
    SYSERR(p,==,NULL,"not found\n",-1);

    memcpy(p->data, newdata, size);

    return 0;
}

/* ******************************************
 * Summary: 双向循环链表删除
 * Parameters: 学生数据链表，万能数据，查找方式
 * Calls: LinkList_Find  
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_vdelete(LinkList head, const void *data, func_find_t func_find)
{
    node_t *p = LinkList_Find(head, data, func_find);
    SYSERR(p,==,NULL,"not found\n",-1);

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p->data);
    free(p);
    return 0;
}

/* ******************************************
 * Summary: 链表的销毁
 * Parameters: 学生数据链表
 * Calls: 
 * Return: 成功返回0
 * Others: 
 * ******************************************/
int LinkList_Destory(node_t **head)
{
    SYSERR(*head,==,NULL,"head is null\n",-1);

    node_t *p = (*head)->next, *q;
    while(p != *head)
    {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
        q = NULL;
    }
    free(*head);
    *head = NULL;

    return 0;
}

/* ******************************************
 * Summary: 双向链表冒泡排序
 * Parameters: 学生数据链表，排序方式
 * Calls: funcmp    
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_Bubble_sort(LinkList head, func_find_t funcmp)
{
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(head->next,==,NULL,"list is empty\n",-1);
    node_t *i, *j, *end;
    int flag = 0;

    for(i = head->next, end = head; i->next != head; i = i->next, end = end->prev)
    {
        flag = 0;
        for(j = head->next; j->next != end; j = j->next)
        {
            if(funcmp(j->data, j->next->data) < 0)
            {
                void *tmp = j->data;
                j->data = j->next->data;
                j->next->data = tmp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    return 0;
}

/* ******************************************
 * Summary: 双向循环链表选择排序
 * Parameters: 学生数据链表，模式
 * Calls: funcmp  
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_Select_sort(LinkList head, func_find_t funcmp)
{
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(head->next,==,NULL,"list is empty\n",-1);
    node_t *i, *j;
    void *temp;
    node_t *min;

    for(i = head->next; i->next != head; i=i->next)
    {
        min = i;
        for(j = i->next; j != head; j=j->next)
        {
            if(funcmp(min->data,j->data) > 0)
                min = j;
        }
        if(min != i)
        {
            temp = min->data;
            min->data = i->data;
            i->data = temp;
        }
    }
    return 0;
}

/* ******************************************
 * Summary: 链表求长
 * Parameters: 学生数据链表
 * Calls: 无  
 * Return: 返回链表长度
 * Others: 
 * ******************************************/
int LinkList_Length(node_t *head)
{
    int count = 0;
    node_t *p = head->next;
    while(p != head)
    {
        p = p->next;
        count++;
    }
    return count;
}

