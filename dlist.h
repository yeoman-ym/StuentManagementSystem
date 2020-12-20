//底层链表相关函数（增删改查，排序，遍历等操作）

#ifndef DLIST_H
#define DLIST_H

#include "student.h"

//链表节点
typedef struct node
{
    struct node *prev, *next;   //前驱后继
    stu_t *data;                //学生信息 
}node_t;

#endif

