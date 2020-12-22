/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: Provide functions to main
 **********************************/

#include "menu.h"
#include "common.h"

/* **********************
 * Summary: 登录主界面—— 学生界面，管理员界面
 * Parameters: 学生链表头结点
 *
 * Return: 登录成功与否
 * Others: 只对学生操作，所以只需要学生数据
 * *********************/
int login_menu(node_t *stulist)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("**************************************\n");
        printf("**** Welcome to STU_MANAGE_SYSTEM ****\n");
        printf("****    Choose 1 to admin menu    ****\n");
        printf("****    Choose 2 to stude menu    ****\n");
        printf("****    Choose 0 to quit          ****\n");
        printf("**************************************\n");
        //输入选项进入对应的界面
        setbuf(stdin, NULL);
        scanf("%s", ch);
        switch(ch[0]){
            case '1':
                welcome_admin_menu(stulist);
                break;
            case '2':
                welcome_stu_menu(stulist);
                break;
        }
        if(ch[0] == '0')
        {
            system("clear");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            printf("******** Thank You *********\n");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            break;
        }
    }
    return 0;
}

/* **********************
 * Summary: 管理员操作界面
 * Parameters: 学生数据链表
 *
 * Return: 对应的操作界面
 * Others: 增加，删除，更新，显示，查找，离开
 * *********************/
int admin_menu(node_t *stulist)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("**************************************\n");
        printf("**** Welcome to ADMIN OPERAT MENU ****\n");
        printf("****    Choose 1 to addstu menu   ****\n");
        printf("****    Choose 2 to delstu menu   ****\n");
        printf("****    Choose 3 to update menu   ****\n");
        printf("****    Choose 4 to showst menu   ****\n");
        printf("****    Choose 5 to findst menu   ****\n");
        printf("****    Choose 0 to quit   menu   ****\n");
        printf("**************************************\n");
        setbuf(stdin, NULL);
        scanf("%s", ch);
        if(ch[0] == '0')
            break;
        switch(ch[0]){
            case '1':
                addstu_menu(stulist);
                break;
            case '2':
                deletestu_menu(stulist);
                break;
            case '3':
                updatestu_menu(stulist);
                break;
            case '4':
                showstu_menu(stulist);
                break;
            case '5':
                findstu_menu(stulist);
                break;
            default:
                system("clear");
                putchar('\n');
                putchar('\n');
                printf("**************************************\n");
                printf("******       Input Error      ********\n");
                printf("**************************************\n");
                putchar('\n');
                putchar('\n');
                break;
        }
    }
    return 0;
}

/* **********************
 * Summary: 管理员登录界面
 * Parameters: 学生链表 
 *
 * Return: 成功返回0 失败返回非0值
 * Others: 提示管理员输入用户名和密码并验证，成功就调用管理员操作菜单
 * *********************/
int welcome_admin_menu(node_t *stulist)
{
    int count = LOOPCOUNT;
    char admin_name[16] = "";
    char admin_pass[16] = "";
    while(count)
    {
        count--;
        system("clear");
        printf("**************************************\n");
        printf("**** Welcome to ADMIN LOGIN MENU  ****\n");
        printf("**************************************\n");
        putchar('\n');
        putchar('\n');
        printf("****    Input Your Username       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", admin_name);
        printf("****    Input Your Password       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", admin_pass);
        //验证输入是否正确
        if(strcmp(admin_name, ADMINNAME) == 0)
        {
            if(strcmp(admin_pass, ADMINPASS) == 0)
            {
                admin_menu(stulist);
            }
            else
            {
                system("clear");
                putchar('\n');
                putchar('\n');
                putchar('\n');
                printf("****     your password error   ****\n");
                putchar('\n');
                putchar('\n');
                printf("****     enter to continue     ****\n");
                getchar();
                getchar();
            }
        }
        else{
            system("clear");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            printf("****     Your Username Error   ****\n");
            putchar('\n');
            putchar('\n');
            printf("****     Enter to continue     ****\n");
            getchar();
            getchar();
        }
    }
    return 0;
}
#if 0
/* **********************
 * Summary: 教师操作界面
 * Parameters: 
 *
 * Return:
 * Others: 管理学生数据
 * *********************/
int tch_menu(node_t *stulist, node_t *tchlist, tch_t *tchp)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("**************************************\n");
        printf("**** Welcome to TEACH LOGIN MENU  ****\n");
        printf("****    Choose 1 to showtch menu  ****\n");
        printf("****    Choose 2 to updatet menu  ****\n");
        printf("****    Choose 3 to showstu menu  ****\n");
        printf("****    Choose 4 to updates menu  ****\n");
        printf("****    Choose 0 to quit    menu  ****\n");
        printf("**************************************\n");
        setbuf(stdin, NULL);
        scanf("%s", ch);
        if(ch[0] == '0')
            break;
        switch(ch[0]){
            case '1':
               showtch_menu(tchlist);
               break;
            case '2':
               updatetch_menu(tchlist);
               break;
            case '3':
               showstu_menu(stulist);
               break;
            case '4':
               updatestu_menu(stulist, );
               break;
            default:
                printf("**************************************\n");
                printf("******      Input Error       ********\n");
                printf("**************************************\n");
                break;
        }
    }
    return 0;
}

//教师登录界面
/* **********************
 * Summary: 
 * Parameters:
 *
 * Return:
 * Others:
 * *********************/
int welcome_tch_menu(node_t *stulist, node_t *tchlist)
{
    int COUNT = LOOPCOUNT;
    char ch[4] = "";
    while(COUNT)
    {
        system("clear");
        printf("**************************************\n");
        printf("******  Input Username passwd ********\n");
        printf("**************************************\n");
        setbuf(stdin, NULL);
        scanf("%s", ch);
        //调用教师的用户名和密码
        //比较教师名和密码
        //成功则进入tch_menu()
        COUNT--;
    }
    return 0;
}
#endif

/* **********************
 * Summary: 学生操作菜单
 * Parameters: 学生数据链表
 *          学生操作权限：显示学生数据，更新数据
 * Return: 
 * Others:
 * *********************/
int stu_menu(node_t *stulist, stu_t *stup)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("**************************************\n");
        printf("****** Student Operation Menu ********\n");
        printf("******   Choose 1 to showstu  ********\n");
        printf("******   Choose 2 to updates  ********\n");
        printf("******   Choose 0 to quit     ********\n");
        printf("**************************************\n");
        setbuf(stdin, NULL);
        scanf("%s", ch);
        if(ch[0] == '0')
            break;
        switch(ch[0])
        {
            case '1':
                show_stu(stup);
                break;
            case '2':
                updatestu_menu(stulist);
                break;
            default:
                system("clear");
                putchar('\n');
                putchar('\n');
                putchar('\n');
                printf("******  INPUT ERROR  ******\n");
                putchar('\n');
                putchar('\n');
                putchar('\n');
                break;
        }
    }
    return 0;
}

/* **********************
 * Summary: 学生登录界面
 * Parameters: 学生数据链表
 *
 * Return:
 * Others: 登录验证学生姓名和密码，成功进入学生操作界面
 * *********************/
int welcome_stu_menu(node_t *stulist)
{
    int COUNT = LOOPCOUNT;
    char stu_name[32] = "";
    char stu_pass[16] = "";
    while(COUNT)
    {
        COUNT--;
        system("clear");
        printf("**************************************\n");
        printf("******  Student Login Menu    ********\n");
        printf("**************************************\n");
        putchar('\n');
        putchar('\n');
        printf("****    Input Your Username       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", stu_name);
        printf("****    Input Your Password       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", stu_pass);
        //根据用户名的唯一性，查找学生链表中的学生名字，用输入密码与之匹配
        node_t *p = LinkList_Find(stulist, stu_name, cmp_stu_name);
        //提取节点p的数据用的用户密码
        stu_t *stup = (stu_t *)p->data;
        if(p != NULL)
        {
            if(strcmp(stu_pass, stup->pass) == 0)
            {
                stu_menu(stulist,stup);
            }
            else
            {
                system("clear");
                putchar('\n');
                putchar('\n');
                putchar('\n');
                printf("****     your password error   ****\n");
                putchar('\n');
                putchar('\n');
                printf("****     enter to continue     ****\n");
                getchar();
                getchar();
            }
        }
        else{
            system("clear");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            printf("****     Your Username Error   ****\n");
            putchar('\n');
            putchar('\n');
            printf("****     Enter to continue     ****\n");
            getchar();
            getchar();
        }
    }
    return 0;
}

/* **********************
 * Summary: 添加学生菜单 
 * Parameters: 学生数据链表
 * Call: addstu() 
 * Return: 成功返回0 失败返回非0
 * Others: 输入学生相应的数据插入链表
 * *********************/
int addstu_menu(node_t *stulist)
{
    system("clear");
    printf("**************************************\n");
    printf("******  Add Student Menu      ********\n");
    printf("**************************************\n");
    putchar('\n');
    putchar('\n');
    putchar('\n');
    getchar();
    getchar();
    stu_t *newstu = (stu_t*)malloc(sizeof(stu_t));
    addstu(stulist, *newstu);
    return 0;
}

/* **********************
 * Summary: 删除学生菜单 
 * Parameters: 学生数据链表
 * Call: delstu()  
 * Return: 成功返回0 失败返回非0
 * Others: 找到需要删除的学生，通过学号查找到学生
 * *********************/
int deletestu_menu(node_t *stulist)
{
    system("clear");
    printf("**************************************\n");
    printf("******  Delete Student Menu   ********\n");
    printf("**************************************\n");
    //找到需要删除的学生，赋值给stu
    stu_t stu;
    printf("******  Input Student ID  *********\n");
    scanf("%d", &stu.cid);
    node_t *p = LinkList_Find(stulist, &stu.cid, cmp_stu_cid);
    stu_t *stup = (stu_t*)p->data;
    //调用函数删除该学生节点
    delstu(stulist, *stup);

    return 0;
}

/* **********************
 * Summary: 修改学生菜单 
 * Parameters: 学生数据链表
 * Call: updatestu() 
 * Return: 成功返回0 失败返回非0
 * Others: 按不同模式修改学生信息
 * *********************/
int updatestu_menu(node_t *stulist)
{
    int num = 0;
    //临时储存需要修改的数据和新数据
    stu_t tmp_olddata, tmp_newdata; 
    system("clear");
    printf("**************************************\n");
    printf("******  Update Student Menu   ********\n");
    printf("******  Choose 1 Update Name  ********\n");
    printf("******  Choose 2 Update Math  ********\n");
    printf("******  Choose 3 Update Lang  ********\n");
    printf("******  Choose 4 Update Phil  ********\n");
    printf("******  Choose 5 Update Clid  ********\n");
    printf("**************************************\n");
    scanf("%d", &num);
    switch(num)
    {
        case 1:
            printf("******  Input Old Name Data  ********\n");
            scanf("%s", tmp_olddata.name);
            printf("******  Input New Name Data  ********\n");
            scanf("%s", tmp_newdata.name);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 2:
            printf("******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("******  Input New Math Data  ********\n");
            scanf("%d", &tmp_newdata.gmath);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 3:
            printf("******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("******  Input New Clang Data ********\n");
            scanf("%d", &tmp_newdata.glang);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 4:
            printf("******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("******  Input New Phily Data ********\n");
            scanf("%d", &tmp_newdata.gphil);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 5:
            printf("******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("******  Input New Class Data ********\n");
            scanf("%d", &tmp_newdata.classid);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
    }
    return 0;
}

/* **********************
 * Summary: 显示学生菜单 
 * Parameters: 学生数据链表
 * Call: addstu() 
 * Return: 成功返回0 失败返回非0
 * Others: 输入相应的模式数字，进入不同排序，然后显示
 * *********************/
int showstu_menu(node_t *stulist)
{
    int mode = 0; //模式选择
    system("clear");
    printf("**************************************\n");
    printf("******  Show  Student  Menu   ********\n");
    printf("******  Choose 1 Show   Cid   ********\n");
    printf("******  Choose 2 Show   Math  ********\n");
    printf("******  Choose 3 Show   Lang  ********\n");
    printf("******  Choose 4 Show   Phil  ********\n");
    printf("******  Choose 5 Show   Clid  ********\n");
    printf("**************************************\n");
    setbuf(stdin, NULL);
    scanf("%d", &mode);
    //按模式排序
    sortstu(stulist, mode);
    //学生数据链表打印
    LinkList_Show(stulist, show_stu);
    return 0;
}

/* **********************
 * Summary: 查找学生菜单 
 * Parameters: 学生数据链表
 * Call: findstu()
 * Return: 成功返回0 失败返回非0
 * Others: 0获取全部，1，按学号获取，2，姓名获取，3，班级获取
 * *********************/
int findstu_menu(node_t *stulist)
{
    int mode = 0; //模式选择
    system("clear");
    printf("**************************************\n");
    printf("******  Find  Student  Menu   ********\n");
    printf("******  Choose 0 Find   ALL   ********\n");
    printf("******  Choose 1 Find   Cid   ********\n");
    printf("******  Choose 2 Find   Name  ********\n");
    printf("******  Choose 3 Find   Clas  ********\n");
    printf("**************************************\n");
    setbuf(stdin, NULL);
    scanf("%d", &mode);
    stu_t stu;      //存储临时值
    node_t *p;      //存储得到的链表节点
    //按模式返回对于的信息
    switch(mode)
    {
        case 0:
            p = findstu(stulist, mode, stu);
            LinkList_Show(p, show_stu);
            break;
        case 1:
            {
                printf("*****  Input Cid  *****\n");
                scanf("%d", &stu.cid);
                p = findstu(stulist, mode, stu);
                show_stu(p->data);
                break;
            }
        case 2:
            {
                printf("*****  Input Name  *****\n");
                scanf("%s", stu.name);
                p = findstu(stulist, mode, stu);
                LinkList_Show(p, show_stu);
                break;
            }
        case 3:
            {
                printf("*****  Input Class  ****\n");
                scanf("%d", &stu.classid);
                p = findstu(stulist, mode, stu);
                LinkList_Show(p, show_stu);
                break;
            }
        default:
            printf("*******  The mode error  *******\n");
            break;
    }
    return 0;
}
