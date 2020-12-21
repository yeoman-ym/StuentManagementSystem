#include "student.h"
#include "common.h"

//获取学生学号
int getcid(stu_t stu)
{
    return stu.cid;
}

//加载学生信息
node_t *loadstu()
{
    LinkList head = LinkCreate();
    SYSERR(head,==,NULL,"STU load data error\n",NULL);

    FILE *fp = fopen(STUFILE, "r");
    SYSERR(fp,==,NULL,"Student file open err\n",NULL);

    int people_num;                     //存放读取出来的人数
    int max_num;                        //存放文件的最大编号
    fscanf(fp, "%d\t%d\n", &people_num, &max_num);

    //循环从文件读取每个学生数据插入到链表
    node_t *tmp = (node_t *)malloc(sizeof(node_t));                         //存放读取的学生数据  
    SYSERR(tmp,==,NULL,"malloc tmp err\n",NULL);
    tmp->data = (stu_t *)malloc(sizeof(stu_t));
    SYSERR(tmp->data,==,NULL,"data malloc err\n",NULL);

    for(int i = 1; i < people_num; i++)
    {
        fscanf(fp, "%d %s %s %d %d %d %d %d %d %d\n", &tmp->data->cid, tmp->name, tmp->pass, \
               &tmp->age, &tmp->gmath, &tmp->glang, &tmp->gphil, &tmp->gsum, &tmp->order,\
               &tmp->classid);
        LinkList_hInsert(head, tmp, sizeof(node_t));
    }
    fclose(fp);
    return head;
}
//保存学生信息
int savestu(node_t *head)
{
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(head->data,==,NULL,"data is null\n",-1);

    FILE *fp = fopen(STUFILE, "a+");
    SYSERR(fp,==,NULL,"student file open err\n",-1);
    node_t *p = head->next;
    while(p != NULL)
    {
        fprintf(fp, "%d %s %s %d %d %d %d %d %d %d\n", (int)p->data->cid, tmp->name, tmp->pass, \
               tmp->age, tmp->gmath, tmp->glang, tmp->gphil, tmp->gsum, tmp->order,\
               tmp->classid);
        p = p->next;
    }

}
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
