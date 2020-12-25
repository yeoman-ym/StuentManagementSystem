/*********************************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: 双向循环链表头文件，相关函数声明
 *********************************************/

#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SYSERR(X,OPTION,Y,MESSAGE,Z) if((X) OPTION (Y) )\
                                        {\
                                            printf("%s:%s:%d:%s\n", __FILE__,__func__,__LINE__,MESSAGE);\
                                           return Z;\
                                        }



//双向循环链表结构体节点定义
typedef struct node
{
    struct node *prev, *next;       //前驱后继
    void *data;                     //学生信息(可以存储任意类型的数据，使用时记得类型强转) 
}node_t, *LinkList;                 //note_t* LinkList没有区别，node_t用于节点，LinkList 用于链表头

//函数指针别名，具体比较需要自定义
typedef int (*func_find_t)(const void *, const void*);

/* ******************************************
 * Summary: 双向循环链表建立
 * Parameters: 无
 * Calls:   
 * Return: 成功返回头指针，失败返回NULL
 * Others: 
 * ******************************************/
LinkList LinkCreate();

/* ******************************************
 * Summary: 双向链表的头插
 * Parameters: 学生数据链表，万能数据，数据大小
 * Calls: 
 * Return: 成功返回0，失败返回-1
 * Others: 
 * ******************************************/
int LinkList_hInsert(LinkList head, const void *data, int size);

/* ******************************************
 * Summary: 双向链表尾插
 * Parameters: 学生数据链表，万能数据，数据大小
 * Calls:   
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_tInsert(LinkList head, const void *data, int size);

/* ******************************************
 * Summary: 链表删除
 * Parameters: 学生数据链表
 * Calls: 
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_hdelete(LinkList);

/* ******************************************
 * Summary: 双向链表的删除
 * Parameters: 学生数据链表
 * Calls:   
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_tdelete(LinkList);

/* ******************************************
 * Summary: 双向循环链表删除
 * Parameters: 学生数据链表，万能数据，查找方式
 * Calls: LinkList_Find  
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_vdelete(LinkList, const void *data, func_find_t func_find);

/* ******************************************
 * Summary: 双向链表的修改
 * Parameters: 学生数据链表，旧数据，新数据，数据大小，查找方式
 * Calls: LinkList_Find  
 * Return: 成功返回0
 * Others: 
 * ******************************************/
int LinkList_update(LinkList head, const void *olddata, const void *newdata, int size, func_find_t func_find);

/* ******************************************
 * Summary: 链表的查找
 * Parameters: 学生数据链表，万能数据，查找模式
 * Calls: func_find 
 * Return: 成功返回0 失败返回NULL
 * Others: 
 * ******************************************/
LinkList LinkList_Find(LinkList head, const void *data, func_find_t func_find);

/* ******************************************
 * Summary: 链表的销毁
 * Parameters: 学生数据链表
 * Calls: 
 * Return: 成功返回0
 * Others: 
 * ******************************************/
int LinkList_Destory(node_t **head);

/* ******************************************
 * Summary: 双向链表冒泡排序
 * Parameters: 学生数据链表，排序方式
 * Calls: funcmp    
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_Bubble_sort(LinkList head, func_find_t funcmp);

/* ******************************************
 * Summary: 双向循环链表选择排序
 * Parameters: 学生数据链表，模式
 * Calls: funcmp  
 * Return: 成功返回0 失败返回-1
 * Others: 
 * ******************************************/
int LinkList_Select_sort(LinkList head, func_find_t funcmp);

//显示函数指针取别名
typedef void(*showfun_t)(const void *data);

/* ******************************************
 * Summary: 双向链表循环打印
 * Parameters: 学生数据链表，显示方式
 * Calls:  
 * Return: 成功返回0 失败返回0
 * Others: 
 * ******************************************/
int LinkList_Show(node_t *head, showfun_t showfunc);

/* ******************************************
 * Summary: 链表求长
 * Parameters: 学生数据链表
 * Calls: 无  
 * Return: 返回链表长度
 * Others: 
 * ******************************************/
int LinkList_Length(node_t *head);

#endif

