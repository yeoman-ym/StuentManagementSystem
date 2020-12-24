/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: 学生模块头文件，相关函数声明
 **********************************/

#ifndef STUDENT_H
#define STUDENT_H

#include "dlist.h"

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

//获取新学生学号
int getnewcid(node_t *head);
//加载学生信息
node_t *loadstu();
//保存学生信息
int savestu(node_t *head);
//添加学生信息
int addstu(node_t *head, stu_t *stup);
//查找学生函数
node_t *findstu(node_t *head, int mode, stu_t *stu);
//删除学生函数
int delstu(node_t *head, stu_t stu);
//修改学生信息(管理员模式)
int updatestu(node_t *head, int mode, stu_t olddata, stu_t newdata);
//修改学生信息(学生模式)
int updatestu_s(node_t *head, int mode, node_t *stup);
//排序学生信息
int sortstu(node_t *head, int mode);
//设置学生序号
int setstuorder(node_t *head);

//显示学生信息
void show_stu(const void *data);
//比较学生学号
int cmp_stu_cid(const void *data1, const void *data2);
//比较学生名字
int cmp_stu_name(const void *data1, const void *data2);
//比较学生数学成绩
int cmp_stu_gmath(const void *data1, const void *data2);
//比较学生C语言成绩
int cmp_stu_glang(const void *data1, const void *data2);
//比较学生物理成绩
int cmp_stu_gphil(const void *data1, const void *data2);
//比较学生总分
int cmp_stu_sum(const void *data1, const void *data2);
//比较学生序号
int cmp_stu_order(const void *data1, const void *data2);
//比较学生班号
int cmp_stu_classid(const void *data1, const void *data2);
//销毁学生链表
void destroy_Linklist(node_t **stulist);

//校验
//名字校验
int Name_check(const char *);
//年龄校验
int Age_check(int);
//成绩校验
int Score_check(int);
//班号校验
int Classid_check(int);

//统计
//平均分——各个科目的平均分+总分平均分同时展示
int stu_average(node_t *stulist);
//最高分
int stu_max_score(node_t *stulist);
//最低分
int stu_min_score(node_t *stulsit);

#endif
