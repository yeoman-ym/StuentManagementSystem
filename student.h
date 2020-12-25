/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: 学生模块头文件，相关函数声明
 **********************************/

#ifndef STUDENT_H
#define STUDENT_H

#include "dlist.h"

//数据显示菜单栏
#define DATASHOWF printf("\t\t\t\t\tid    name    pass age math Clan phil sum order clid\n");

typedef struct student
{
    int cid;        //学生学号
    char name[32];  //学生姓名
    char pass[16];  //学生密码
    int age;        //学生年龄
    int gmath;      //数学成绩
    int glang;      //C语言成绩
    int gphil;      //物理成绩
    int gsum;       //总分
    int order;      //排序
    int classid;    //班号
}stu_t;


/* ******************************************
 * Summary: 获取新的学号给新添加的学生
 * Parameters: 学生链表头结点
 * Calls: LinkList_Length 
 * Return: 返回新的学号数
 * Others: 从文件中获取最大的学号，链表最大人数，两种取最大值
 * ******************************************/
int getnewcid(node_t *head);

/* ******************************************
 * Summary: 获取当前链表最大的编号
 * Parameters: 学生链表头结点
 * Calls: 无 
 * Return: 返回最大编号数
 * Others: 
 * ******************************************/
int getmaxcid(node_t *head);

/* ******************************************
 * Summary: 从文件中读取数据存放到链表
 * Parameters: void
 * Calls: LinkList_hInsert  
 * Return: 存有数据的链表头结点
 * Others: 文件为空，直接返回头，有数据则循环读数据插入链表
 * ******************************************/
node_t *loadstu();

/* ******************************************
 * Summary: 将链表数据保存到文件中
 * Parameters: 学生数据链表
 * Calls: LinkList_Length  LinkList_Select_sort  
 * Return: 成功返回0 
 * Others: 
 * ******************************************/
int savestu(node_t *head);

/* ******************************************************
 * Summary: 添加学生信息
 * Parameters: 学生数据链表， 学生结构体指针
 * Calls: getnewcid LinkList_hInsert setstuorder 
 * Return: 成功返回0
 * Others: 提示学生输入姓名，密码，年龄，班级，数学成绩等
 * ******************************************************/
int addstu(node_t *head, stu_t *stup);

/* *****************************************************
 * Summary: 查找学生信息
 * Parameters: head学生链表，mode 查找方式， stu单个学生
 * Calls: LinkList_Find LinkCreate LinkList_hInsert 
 * Return: 所有学生链表，单个学生
 * Others: 0全部获取，1，按学号获取 2，姓名获取(多值查找)，3，班级获取（多值查找） 
 * *****************************************************/
node_t *findstu(node_t *head, int mode, stu_t *stu);

/* ******************************************
 * Summary: 删除学生数据
 * Parameters: 学生数据链表，需要删除的学生
 * Calls: LinkList_vdelete 
 * Return: 成功返回0
 * Others: 
 * ******************************************/
int delstu(node_t *head, stu_t stu);

/* *****************************************************************
 * Summary: 更新学生数据
 * Parameters: 学生数据链表head，模式mode，旧结构体数据，新结构体数据
 * Calls: LinkList_Find LinkList_update    
 * Return: 成功返回0
 * Others: 先找学号，再改数据
 * 1,修改名字2，修改数学成绩3，修改C成绩4，修改物理成绩，5，修改班号
 * *****************************************************************/
int updatestu(node_t *head, int mode, stu_t olddata, stu_t newdata);

/* ******************************************
 * Summary: 从修改学生信息(学生模式)
 * Parameters: 学生数据链表，模式，学生节点
 * Calls: LinkList_update 
 * Return: 成功返回0
 * Others: 1名字2年龄3数学4C语言5物理6班号
 * ******************************************/
int updatestu_s(node_t *head, int mode, node_t *stup);

/* ******************************************
 * Summary: 学生信息排序
 * Parameters: 学生数据链表，模式
 * Calls: LinkList_Bubble_sort  
 * Return: 成功返回0
 * Others: 1,学号排序2,数学成绩排序3,C语言成绩排序4,物理成绩排序5,总分排序
 * ******************************************/
int sortstu(node_t *head, int mode);

/* ******************************************
 * Summary: 设置学生序号
 * Parameters: 学生数据链表
 * Calls:  
 * Return: 成功返回0
 * Others: 在添加学生，排序时结束后，设置序号
 * ******************************************/
int setstuorder(node_t *head, func_find_t cmpfunc);

/* ******************************************
 * Summary: 显示学生信息
 * Parameters: 学生链表单个节点的数据
 * Calls:   
 * Return: 存有数据的链表头结点
 * Others: 
 * ******************************************/
void show_stu(const void *data);

/* ******************************************
 * Summary : 学号比较
 * Parameters: void*,void*
 * Calls: void   
 * Return: 数据比较
 * Others: 后面的一致
 * ******************************************/
int cmp_stu_cid(const void *data1, const void *data2);
int cmp_stu_name(const void *data1, const void *data2);
int cmp_stu_gmath(const void *data1, const void *data2);
int cmp_stu_glang(const void *data1, const void *data2);
int cmp_stu_gphil(const void *data1, const void *data2);
int cmp_stu_sum(const void *data1, const void *data2);
int cmp_stu_order(const void *data1, const void *data2);
int cmp_stu_classid(const void *data1, const void *data2);

/* ******************************************
 * Summary: 销毁链表，释放内存
 * Parameters: 学生数据链表
 * Calls: LinkList_Destory 
 * Return: 
 * Others: 
 * ******************************************/
void destroy_Linklist(node_t **stulist);

/* ******************************************
 * Summary : 学生名字校验
 * Parameters: 学生名字指针name
 * Calls: isalpha  
 * Return: 名字正确返回1，错误返回0
 * Others: 
 * ******************************************/
int Name_check(const char *);

/* ******************************************
 * Summary : 学生年龄校验
 * Parameters: 学生年龄
 * Calls: 无
 * Return: 年龄正确返回1，错误返回0
 * Others: 年龄定在1-100之间
 * ******************************************/
int Age_check(int);

/* ******************************************
 * Summary : 学生分数校验
 * Parameters: 学生分数
 * Calls: 无
 * Return: 分数正确返回1，错误返回0
 * Others: 分数定在0-100之间
 * ******************************************/
int Score_check(int);

/* ******************************************
 * Summary : 学生班号校验
 * Parameters: 学生班号
 * Calls: 无
 * Return: 班号正确返回1，错误返回0
 * Others: 班号定在1-10之间
 * ******************************************/
int Classid_check(int);

/* ******************************************
 * Summary : 平均分求取，最大值，最小值
 * Parameters: 学生数据链表
 * Calls: 无
 * Return: 班号正确返回1，错误返回0
 * Others: 
 * ******************************************/
int stu_average(node_t *stulist);
int stu_max_score(node_t *stulist);
int stu_min_score(node_t *stulsit);

#endif
