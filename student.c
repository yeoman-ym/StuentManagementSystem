/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: 学生模块，相关函数定义
 **********************************/

#include "student.h"
#include "common.h"

int getnewcid(node_t *head)
{
    int tmp_cid = 0;
    int tmp_num = 0;
    //读取目前文件中的最大的学号
    FILE *fp = fopen(STUFILE, "a+");
    SYSERR(fp,==,NULL,"file open err\n",-1);
    //跳过一个数，取出上次文件中最大的编号
    //fseek(fp, sizeof(int), SEEK_SET);

    if(fscanf(fp, "%d\t%d\n", &tmp_num, &tmp_cid) == EOF)
    {
        fclose(fp);
        return 1;
    }
    fclose(fp);
    //取当前链表中的最大编号
    int length = getmaxcid(head);
    return tmp_cid >= length ? tmp_cid+1 : length+1;
}

int getmaxcid(node_t *head)
{
    int cid = 0;
    node_t *p = head->next;
    stu_t stup = *(stu_t*)p->data;
    while(p != head)
    {
        if(cid <= stup.cid)
            cid = stup.cid;
        p = p->next;
    }
    return cid;
}

node_t *loadstu()
{
    LinkList head = LinkCreate();
    SYSERR(head,==,NULL,"STU load data error\n",NULL);
    FILE *fp = fopen(STUFILE, "a+");
    SYSERR(fp,==,NULL,"Student file open err\n",NULL);

    int people_num;                     //存放读取出来的人数
    int max_num;                        //存放文件的最大编号
    if(fscanf(fp, "%d\t%d\n", &people_num, &max_num) == EOF)
    {
        //如果没有读到文件数据，说明为空，关闭文件，返回头结点
        fclose(fp);
        return head;
    }

    //循环从文件读取每个学生数据插入到链表
    stu_t *tmp = (stu_t *)malloc(sizeof(stu_t));
    bzero(tmp, sizeof(stu_t));
    for(int i = 1; i <= people_num; i++)
    {
        fscanf(fp, "%3d%8s%8s%4d%4d%4d%4d%4d%4d%4d\n", &tmp->cid, tmp->name, tmp->pass, \
               &tmp->age, &tmp->gmath, &tmp->glang, &tmp->gphil, &tmp->gsum, &tmp->order,\
               &tmp->classid);
        LinkList_hInsert(head, tmp, sizeof(stu_t));
        bzero(tmp, sizeof(stu_t));
    }
    fclose(fp);
    free(tmp);
    return head;
}

int savestu(node_t *head)
{
    SYSERR(head,==,NULL,"head is null\n",-1);
    SYSERR(head->next->data,==,NULL,"data is null\n",-1);
    SYSERR(head->next,==,head,"data is empty\n",-1);

    FILE *fp = fopen(STUFILE, "w+");
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
    /* stu_t *sutp = ((stu_)) */
    while(p != head)
    {
        fprintf(fp, "%3d%8s%8s%4d%4d%4d%4d%4d%4d%4d\n", ((stu_t*)p->data)->cid, ((stu_t *)p->data)->name, ((stu_t*)p->data)->pass, \
               ((stu_t*)p->data)->age, ((stu_t*)p->data)->gmath, ((stu_t*)p->data)->glang, ((stu_t*)p->data)->gphil,\
               ((stu_t*)p->data)->gsum, ((stu_t*)p->data)->order,\
               ((stu_t*)p->data)->classid);
        p = p->next;
    }
    fclose(fp);
    return 0;
}

int addstu(node_t *head, stu_t *stup)
{
    
    //需要学生输入的数据有七个，其他自动生成
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t******* Input Your name ********\n");
    do{
        printf("\t\t\t\t\t");
        setbuf(stdin,NULL);
        scanf("%s", stup->name);
    }while(!Name_check(stup->name)); //名字正确返回1
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t******* Input Your passwd ******\n");
    printf("\t\t\t\t\t");
    scanf("%s", stup->pass);
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t******* Input Your age *********\n");
    do{
        setbuf(stdin, NULL);
        printf("\t\t\t\t\t");
        scanf("%d", &stup->age);
    }while(!Age_check(stup->age));
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t******* Input Your class *******\n");
    do{
        setbuf(stdin, NULL);
        printf("\t\t\t\t\t");
        scanf("%d", &stup->classid);
    }while(!Classid_check(stup->classid));
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t******* Input Your math ********\n");
    do{
        setbuf(stdin, NULL);
        printf("\t\t\t\t\t");
        scanf("%d", &stup->gmath);
    }while(!Score_check(stup->gmath));
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t******* Input Your C lan *******\n");
    do{
        setbuf(stdin, NULL);
        printf("\t\t\t\t\t");
        scanf("%d", &stup->glang);
    }while(!Score_check(stup->glang));
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t******* Input Your phil ********\n");
    do{
        setbuf(stdin, NULL);
        printf("\t\t\t\t\t");
        scanf("%d", &stup->gphil);
    }while(!Score_check(stup->gphil));
    //获取新学号
    stup->cid = getnewcid(head);
    //总分计算
    stup->gsum = stup->gmath + stup->glang + stup->gphil;
    //序号，插入之后才知道,先初始化为0
    stup->order = 0; 
    //学生数据插入链表
    LinkList_hInsert(head, stup, sizeof(stu_t));
    setstuorder(head, cmp_stu_cid);
    DATASHOWF;
    LinkList_Show(head, show_stu);
    getchar();
    getchar();
    return 0;
}

node_t *findstu(node_t *head, int mode, stu_t *stu)
{
    node_t *p = NULL;
    switch(mode)
    {
    case 0:
        return head;
    case 1:
        if((p = LinkList_Find(head, stu, cmp_stu_cid)) == NULL)
        {
            return NULL;
            break;
        }
        else
        {
            return p;
        }
    case 2:
        {
            p = head;
            node_t *nc = LinkCreate();          //所有同名的学生插入新链表nc
            while((p = LinkList_Find(p, stu, cmp_stu_name)) != NULL)
            {
                LinkList_tInsert(nc, p->data, sizeof(stu_t));
            }
            if(NULL == nc->next->data)
            {
                return NULL;
            }
            return nc;
        }
    case 3:
        {
            p = head;
            node_t *cc = LinkCreate();          //所有同班级的插入新链表cc
            while((p = LinkList_Find(p, stu, cmp_stu_classid)) != NULL)
            {
                LinkList_tInsert(cc, p->data, sizeof(stu_t));
            }
            if(NULL == cc->next->data)
            {
                return NULL;
            }
            return cc;
        }
    }
    return head;
}

int delstu(node_t *head, stu_t stu)
{
    //head 学生链表头结点  stu 学生
    LinkList_vdelete(head, &stu.cid, cmp_stu_cid);
    return 0;
}

int updatestu(node_t *head, int mode, stu_t olddata, stu_t newdata)
{
    node_t *oldnode = LinkList_Find(head, &olddata.cid, cmp_stu_cid);                   //临时存放找到的节点
    SYSERR(oldnode,==,NULL,"malloc err\n",-1);
    node_t *p = (node_t*)malloc(sizeof(node_t));
    memcpy(p, oldnode, sizeof(node_t));
    switch(mode)
    {
        case 1:
            //修改节点赋值给新节点
            strcpy(((stu_t *)p->data)->name,newdata.name);
            //修改链表中的数据
            LinkList_update(head, oldnode->data, p->data, sizeof(stu_t), cmp_stu_cid);
            break;
        case 2:
            //通过ID 找到该学生节点
            //修改该节点的数学成绩
            ((stu_t*)p->data)->gmath = newdata.gmath;
            //更新总分
            ((stu_t*)p->data)->gsum = ((stu_t*)p->data)->gmath + ((stu_t*)p->data)->glang + ((stu_t*)p->data)->gphil;
            //更新链表
            LinkList_update(head, oldnode->data, p->data, sizeof(stu_t), cmp_stu_cid);
            break;
        case 3:
            ((stu_t*)p->data)->glang = newdata.glang;
            //更新总分
            ((stu_t*)p->data)->gsum = ((stu_t*)p->data)->gmath + ((stu_t*)p->data)->glang + ((stu_t*)p->data)->gphil;
            LinkList_update(head, oldnode->data, p->data, sizeof(stu_t), cmp_stu_cid);
            break;
        case 4:
            ((stu_t*)p->data)->gphil = newdata.gphil;
            //更新总分
            ((stu_t*)p->data)->gsum = ((stu_t*)p->data)->gmath + ((stu_t*)p->data)->glang + ((stu_t*)p->data)->gphil;
            LinkList_update(head, oldnode->data, p->data, sizeof(stu_t), cmp_stu_cid);
            break;
        case 5:
            ((stu_t*)p->data)->classid = newdata.classid;            
            LinkList_update(head, oldnode->data, p->data, sizeof(stu_t), cmp_stu_cid);
            break;
        default:
            printf("\t\t\t\t\t*****  The mode is not exist  *****\n");
            break;
    }
    return 0;
}

int sortstu(node_t *head, int mode)
{
    switch(mode)
    {
        case 0:  //统计学生数据，展示平均分，最高分，最低分
           system("clear");
           stu_average(head);
           system("clear");
           stu_max_score(head);
           system("clear");
           stu_min_score(head);
           break;
        case 1:
            LinkList_Bubble_sort(head, cmp_stu_cid);
            setstuorder(head, cmp_stu_cid);
            break;
        case 2:
            LinkList_Bubble_sort(head, cmp_stu_gmath);
            setstuorder(head, cmp_stu_gmath);
            break;
        case 3:
            LinkList_Bubble_sort(head, cmp_stu_glang);
            setstuorder(head, cmp_stu_glang);
            break;
        case 4:
            LinkList_Bubble_sort(head, cmp_stu_gphil);
            setstuorder(head, cmp_stu_gphil);
            break;
        case 5:
            LinkList_Bubble_sort(head, cmp_stu_sum);
            setstuorder(head, cmp_stu_sum);
            break;
        default:
            printf("\t\t\t\t\t*****  The mode is not exist  *****\n");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            printf("\t\t\t\t\t*********   Enter to continue  **********\n");
            getchar();
            getchar();
            break;
    }
    return 0;
}

int updatestu_s(node_t *head, int mode, node_t *stup)
{
    //申请一个新节点，保存输入的新数据
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    SYSERR(newnode,==,NULL,"malloc err\n",-1);
    //学生节点信息赋值给新节点
    memcpy(newnode, stup, sizeof(node_t));
    stu_t *stu = (stu_t*)newnode->data;

    switch(mode)
    {
        case 1:
            printf("\t\t\t\t\t***********  Input Your Name  **********\n");
            scanf("%s", stu->name);
            break;
        case 2:
            printf("\t\t\t\t\t***********  Input Your Age   **********\n");
            scanf("%d", &stu->age);
            break;
        case 3:
            printf("\t\t\t\t\t***********  Input Your Math  **********\n");
            scanf("%d", &stu->gmath);
            break;
        case 4:
            printf("\t\t\t\t\t***********  Input Your Clang  *********\n");
            scanf("%d", &stu->glang);
            break;
        case 5:
            printf("\t\t\t\t\t***********  Input Your Phily **********\n");
            scanf("%d", &stu->gphil);
            break;
        case 6:
            printf("\t\t\t\t\t***********  Input Your Clas  **********\n");
            scanf("%d", &stu->classid);
            break;
    }
    //更新总分
    stu->gsum = stu->gmath + stu->glang + stu->gphil;
    //通过cid找到要修改的学生的节点
    LinkList_update(head, stup->data, newnode->data, sizeof(stu_t), cmp_stu_cid);
    DATASHOWF;
    show_stu(newnode->data);
    getchar();
    getchar();
    return 0;
}

int setstuorder(node_t *head, func_find_t cmpfun)
{
    //按链表顺序依次给学生序号赋值
    node_t *p = head->next;
    if(1 == LinkList_Length(head))
    {
        ((stu_t*)p->data)->order = 1;
        return 0;
    }
    ((stu_t*)p->data)->order = 1;
    while(p != head && p->next != head)
    {
        if(!cmpfun(p->data, p->next->data))
        {
            ((stu_t*)p->next->data)->order = ((stu_t *)p->data)->order;
        }
        else if(cmpfun(p->data, p->next->data)>0)
        {
            ((stu_t*)p->next->data)->order = ((stu_t *)p->data)->order + 1;
        }
        p = p->next;
    }
    return 0;
}

void show_stu(const void *data)
{
    stu_t *stu = (stu_t*)data;
    printf("\t\t\t\t\t%2d%8s%8s%4d%4d%5d%5d%5d%4d%6d\n", stu->cid, stu->name, stu->pass, stu->age, stu->gmath, \
                                                        stu->glang, stu->gphil, stu->gsum, stu->order, stu->classid);
}

int cmp_stu_cid(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->cid - stu2->cid;
}

//比较学生名字
int cmp_stu_name(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return strcmp(stu1->name,stu2->name);
}

//比较学生数学成绩
int cmp_stu_gmath(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->gmath - stu2->gmath;
}

//比较学生C语言成绩
int cmp_stu_glang(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->glang - stu2->glang;
}

//比较学生物理成绩
int cmp_stu_gphil(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->gphil - stu2->gphil;
}

//比较学生总分
int cmp_stu_sum(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->gsum - stu2->gsum;
}

//比较学生序号
int cmp_stu_order(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->order - stu2->order;
}

//比较学生班号
int cmp_stu_classid(const void *data1, const void *data2)
{
    stu_t *stu1 = (stu_t*)data1;
    stu_t *stu2 = (stu_t*)data2;
    return stu1->classid - stu2->classid;
}

void destroy_Linklist(node_t **stulist)
{
    LinkList_Destory(stulist);
}

int Name_check(const char *name)
{
    SYSERR(name,==,NULL,"name is null\n",-1);
    const char *p = name;
    while(*p)
    {
        if(!isalpha(*p))
        {
            printf("\t\t\t\t\t*******  Input again  ********\n");
            return false;
        }
        p++;
    }
    return true;
}

int Age_check(int age)
{
    if(age > 0 && age <= 100)
        return true;
    else
        {
            setbuf(stdin,NULL);
            printf("\t\t\t\t\t*******  Input again  ********\n");
            return false;
        }
}

int Score_check(int score)
{
    if(score >= 0 && score <= 100)
        return true;
    else
        {
            setbuf(stdin,NULL);
            printf("\t\t\t\t\t*******  Input again  ********\n");
            return false;
        }
}

int Classid_check(int classid)
{
    if(classid >= 1 && classid <= 10)
        return true;
    else
        {
            setbuf(stdin,NULL);
            printf("\t\t\t\t\t*******  Input again  ********\n");
            return false;
        }
}

//平均分——各个科目的平均分同时展示
int stu_average(node_t *head)
{
    SYSERR(head,==,NULL,"stulist is null\n",-1);
    //获取链表人数
    int length = LinkList_Length(head);
    //获取单科总分数
    int sum_math = 0;
    int sum_glang = 0;
    int sum_gphil = 0;
    int sum_all = 0;
    node_t *p = head->next;
    while(p != head)
    {
        sum_math += ((stu_t*)p->data)->gmath;
        sum_glang += ((stu_t*)p->data)->glang;
        sum_gphil += ((stu_t*)p->data)->gphil;
        sum_all += ((stu_t*)p->data)->gsum;
        p = p->next;
    }

    system("clear");
    putchar('\n');
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t***********  Math average  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", sum_math/length);
    printf("\t\t\t\t\t***********  Clan average  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", sum_glang/length);
    printf("\t\t\t\t\t***********  Phil average  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", sum_gphil/length);
    printf("\t\t\t\t\t***********  Sum  average  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", sum_all/length);
    putchar('\n');
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t***********  Enter to continue  ************\n");
    getchar();
    getchar();
    return 0;
}

//最高分
int stu_max_score(node_t *stulist)
{
    SYSERR(stulist,==,NULL,"stulist is null\n",-1);
    int max_math = 0;
    int max_Clang = 0;
    int max_phily = 0;
    int max_sum = 0;

    node_t *p = stulist->next;
    while(p != stulist)
    {
        if(max_math <= ((stu_t *)p->data)->gmath)
            max_math = ((stu_t *)p->data)->gmath;
        if(max_Clang <= ((stu_t *)p->data)->glang)
            max_Clang = ((stu_t *)p->data)->glang;
        if(max_phily <= ((stu_t *)p->data)->gphil)
            max_phily = ((stu_t *)p->data)->gphil;
        if(max_sum <= ((stu_t *)p->data)->gsum)
            max_sum = ((stu_t *)p->data)->gsum;
        p = p->next;
    }
    system("clear");
    putchar('\n');
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t***********  Math Maxscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", max_math);
    printf("\t\t\t\t\t***********  Clan Maxscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", max_Clang);
    printf("\t\t\t\t\t***********  Phil Maxscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", max_phily);
    printf("\t\t\t\t\t***********  Sum  Maxscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", max_sum);
    putchar('\n');
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t***********  Enter to continue  ************\n");
    getchar();
    getchar();
    return 0;
}

//最低分
int stu_min_score(node_t *stulist)
{
    SYSERR(stulist,==,NULL,"stulist is null\n",-1);
    node_t *p = stulist->next;
    int min_math = ((stu_t *)p->data)->gmath;
    int min_Clang = ((stu_t *)p->data)->glang;
    int min_phily = ((stu_t *)p->data)->gphil;
    int min_sum = ((stu_t *)p->data)->gsum;
    while(p != stulist)
    {
        if(min_math >= ((stu_t *)p->data)->gmath)
            min_math = ((stu_t *)p->data)->gmath;
        if(min_Clang >= ((stu_t *)p->data)->glang)
            min_Clang = ((stu_t *)p->data)->glang;
        if(min_phily >= ((stu_t *)p->data)->gphil)
            min_phily = ((stu_t *)p->data)->gphil;
        if(min_sum >= ((stu_t *)p->data)->gsum)
            min_sum = ((stu_t *)p->data)->gsum;
        p = p->next;
    }
    system("clear");
    putchar('\n');
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t***********  Math Minscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", min_math);
    printf("\t\t\t\t\t***********  Clan Minscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", min_Clang);
    printf("\t\t\t\t\t***********  Phil Minscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", min_phily);
    printf("\t\t\t\t\t***********  Sum  Minscore  ***********\n");
    printf("\t\t\t\t\t                  %d                  \n", min_sum);
    putchar('\n');
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t***********  Enter to continue  ************\n");
    getchar();
    getchar();
    return 0;
}
