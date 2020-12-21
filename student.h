//学生相关数据

#ifndef STUDENT_H
#define STUDENT_H

#include "dlist.h"

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

//获取学生学号
int getcid(stu_t);
//加载学生信息
node_t *loadstu();
//保存学生信息
int savestu(node_t *head);
//添加学生信息
int addstu(node_t *head, stu_t stu);
//查找学生函数
node_t *findstu(node_t *head, int mode, stu_t stu);
//删除学生函数
int delstu(node_t *head, int mode, stu_t stu);
//修改学生信息
int updatestu(node_t *head, int mode, stu_t olddata, stu_t newdata);
//排序学生信息
int sortstu(node_t *head, int mode);
//设置学生序号
int setstuorder(node_t *head);

//显示学生信息
void show_stu(void *data);
//比较学生学号
int cmp_stu_cid(void *data1, void *data2);
//比较学生名字
int cmp_stu_name(void *data1, void *data2);
//比较学生数学成绩
int cmp_stu_gmath(void *data1, void *data2);
//比较学生C语言成绩
int cmp_stu_glang(void *data1, void *data2);
//比较学生物理成绩
int cmp_stu_gphil(void *data1, void *data2);
//比较学生总分
int cmp_stu_sum(void *data1, void *data2);
//比较学生序号
int cmp_stu_order(void *data1, void *data2);
//比较学生班号
int cmp_stu_classid(void *data1, void *data2);

#endif
