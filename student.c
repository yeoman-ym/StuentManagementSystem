#include "student.h"
#include "common.h"

//获取学生学号
int getcid(stu_t stu)
{
    //需要修改
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
    stu_t *tmp = (stu_t *)malloc(sizeof(stu_t));
    for(int i = 1; i < people_num; i++)
    {
        fscanf(fp, "%d %s %s %d %d %d %d %d %d %d\n", &tmp->cid, tmp->name, tmp->pass, \
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
    //计算链表节点个数，找到学生的最大编号，两个数据写入文件
    int length = LinkList_Length(head);
    //按编号排序
    LinkList_Select_sort(head, cmp_stu_cid);
    //找尾，编号最大的在尾部
    node_t *tp = head->prev;
    int maxcid = ((stu_t*)tp->data)->cid;
    //找到的两个数据写入文件
    fprintf(fp, "%d\t%d\n", length, maxcid);
    //遍历链表
    node_t *p = head->next;
    while(p != head)
    {
        fprintf(fp, "%d %s %s %d %d %d %d %d %d %d\n", ((stu_t*)p->data)->cid, ((stu_t *)p->data)->name, ((stu_t*)p->data)->pass, \
               ((stu_t*)p->data)->age, ((stu_t*)p->data)->gmath, ((stu_t*)p->data)->glang, ((stu_t*)p->data)->gphil,\
               ((stu_t*)p->data)->gsum, ((stu_t*)p->data)->order,\
               ((stu_t*)p->data)->classid);
        p = p->next;
    }
    fclose(fp);
    return 0;
}

/* **********************
 * Summary: 添加学生信息
 * Parameters:
 *
 * Return:
 * Others: 提示学生输入姓名，密码，年龄，班级，数学成绩等
 * *********************/
int addstu(node_t *head, stu_t stu)
{
    //需要学生输入的数据有七个，其他自动生成
    SYSERR(head,==,NULL,"head is null\n",-1);
    system("clear");
    printf("********************************\n");
    printf("******* Input Your name ********\n");
    scanf("%s", stu.name);
    system("clear");
    printf("********************************\n");
    printf("******* Input Your passwd ******\n");
    scanf("%s", stu.pass);
    system("clear");
    printf("********************************\n");
    printf("******* Input Your age *********\n");
    scanf("%d", &stu.age);
    system("clear");
    printf("********************************\n");
    printf("******* Input Your class *******\n");
    scanf("%d", &stu.classid);
    system("clear");
    printf("********************************\n");
    printf("******* Input Your math ********\n");
    scanf("%d", &stu.gmath);
    system("clear");
    printf("********************************\n");
    printf("******* Input Your C lan *******\n");
    scanf("%d", &stu.glang);
    system("clear");
    printf("********************************\n");
    printf("******* Input Your phil ********\n");
    scanf("%d", &stu.gphil);
    //获取学号
    stu.cid = getcid(stu);
    //总分计算
    stu.gsum = stu.gmath + stu.glang + stu.gphil;
    //序号，插入之后才知道,先初始化为0
    stu.order = 0; 
    //学生数据插入链表
    LinkList_hInsert(head, &stu, sizeof(stu_t));
    setstuorder(head);
    return 0;
}

/* **********************
 * Summary: 查找学习信息
 * Parameters: head学生链表，mode 查找方式， stu单个学生
 *
 * Return: 所有学生链表，单个学生
 * Others: 0全部获取，1，按学号获取 2，姓名获取(多值查找)，3，班级获取（多值查找） 
 * *********************/
node_t *findstu(node_t *head, int mode, stu_t stu)
{
    node_t *p;
    switch(mode)
    {
    case 0:
        return head;
        break;
    case 1:
        p = LinkList_Find(head, &stu.cid, cmp_stu_cid);
        return p;
        break;
    case 2:
        p = LinkList_Find(head, &stu.name, cmp_stu_name);
        show_stu(p->data);
        break;
    case 3:
        p = LinkList_Find(head, &stu.classid, cmp_stu_classid);
        show_stu(p->data);
        break;
    }
    return p;
}

//删除学生函数
int delstu(node_t *head, stu_t stu)
{
    //head 学生链表头结点  stu 学生
    LinkList_vdelete(head, &stu.cid, cmp_stu_cid);
    return 0;
}
//修改学生信息
int updatestu(node_t *head, int mode, stu_t olddata, stu_t newdata)
{
    //1,修改名字2，修改数学成绩3，修改C成绩4，修改物理成绩，5，修改班号
    switch(mode)
    {
        case 1:
            LinkList_update(head, &olddata, &newdata, sizeof(stu_t), cmp_stu_name);
            break;
        case 2:
            LinkList_update(head, &olddata, &newdata, sizeof(stu_t), cmp_stu_gmath);
            break;
        case 3:
            LinkList_update(head, &olddata, &newdata, sizeof(stu_t), cmp_stu_glang);
            break;
        case 4:
            LinkList_update(head, &olddata, &newdata, sizeof(stu_t), cmp_stu_gphil);
            break;
        case 5:
            LinkList_update(head, &olddata, &newdata, sizeof(stu_t), cmp_stu_classid);
            break;
        default:
            printf("*****  The mode is not exist  *****\n");
            break;
    }
    return 0;
}
//排序学生信息
int sortstu(node_t *head, int mode)
{
    //1,学号排序2,数学成绩排序3,C语言成绩排序4,物理成绩排序5,总分排序
    switch(mode)
    {
        case 1:
            LinkList_Bubble_sort(head, cmp_stu_cid);
            break;
        case 2:
            LinkList_Bubble_sort(head, cmp_stu_gmath);
            break;
        case 3:
            LinkList_Bubble_sort(head, cmp_stu_glang);
            break;
        case 4:
            LinkList_Bubble_sort(head, cmp_stu_gphil);
            break;
        case 5:
            LinkList_Bubble_sort(head, cmp_stu_sum);
            break;
        default:
            printf("*****  The mode is not exist  *****\n");
            break;
    }
    return 0;
}
//设置学生序号
int setstuorder(node_t *head)
{
    int count = 0;
    //按链表顺序依次给学生序号赋值
    node_t *p = head->next;
    while(p != head)
    {
        count++;
        ((stu_t*)p->data)->order = count;
        p = p->next;
    }
    return 0;
}

//显示学生信息
void show_stu(const void *data)
{
    const stu_t *stu = (stu_t*)data;
    printf("*****  cid  is %d  *****\n", stu->cid);
    printf("*****  name is %s  *****\n", stu->name);
    printf("*****  pass is %s  *****\n", stu->pass);
    printf("*****  age  is %d  *****\n", stu->age);
    printf("*****  math is %d  *****\n", stu->gmath);
    printf("*****  lang is %d  *****\n", stu->glang);
    printf("*****  phil is %d  *****\n", stu->gphil);
    printf("*****  sum  is %d  *****\n", stu->gsum);
    printf("*****  orde is %d  *****\n", stu->order);
    printf("*****  clas is %d  *****\n", stu->classid);
}
//比较学生学号
int cmp_stu_cid(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->cid - stu2->cid;
}
//比较学生名字
int cmp_stu_name(void *data1, void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->name - stu2->name;
}
//比较学生数学成绩
int cmp_stu_gmath(void *data1, void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->gmath - stu2->gmath;
}
//比较学生C语言成绩
int cmp_stu_glang(void *data1, void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->glang - stu2->glang;
}
//比较学生物理成绩
int cmp_stu_gphil(void *data1, void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->gphil - stu2->gphil;
}
//比较学生总分
int cmp_stu_sum(void *data1, void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->gsum - stu2->gsum;
}
//比较学生序号
int cmp_stu_order(void *data1, void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->order - stu2->order;
}

//比较学生班号
int cmp_stu_classid(void *data1, void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->classid - stu2->classid;
}
