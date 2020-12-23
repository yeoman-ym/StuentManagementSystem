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

//循环链表的创建(初始化) 无数据 ****done****
LinkList LinkCreate();

//链表的插入（头插）*****done******
int LinkList_hInsert(LinkList head, const void *data, int size);

//链表的插入（尾插）*****done*****
int LinkList_tInsert(LinkList head, const void *data, int size);

//链表的删除 (头删) *****done*****
int LinkList_hdelete(LinkList);
//链表的删除（尾删）*****done*****
int LinkList_tdelete(LinkList);
//双向循环链表的删除（查找）*****done******
int LinkList_vdelete(LinkList, const void *data, func_find_t func_find);

//链表的修改 ****done*****
int LinkList_update(LinkList head, const void *olddata, const void *newdata, int size, func_find_t func_find);

//链表的查找  ****done****
LinkList LinkList_Find(LinkList head, const void *data, func_find_t func_find);

//链表的销毁 *****done***** 
int LinkList_Destory(node_t **head);

//冒泡排序
int LinkList_Bubble_sort(LinkList head, func_find_t funcmp);

//选择排序
int LinkList_Select_sort(LinkList head, func_find_t funcmp);

//显示链表 ****done*****
//底层封装，实现方式：用户提供接口
typedef void(*showfun_t)(const void *data);
int LinkList_Show(node_t *head, showfun_t showfunc);

//链表求长
int LinkList_Length(node_t *head);

#endif

