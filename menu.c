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
 * Calls: welcome_admin_menu(), welcome_stu_menu()
 * Return: 登录成功与否
 * Others: 只对学生操作，所以只需要学生数据
 * *********************/
int login_menu(node_t *stulist)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("\t\t\t\t\t**************************************\n");
        printf("\t\t\t\t\t**** Welcome to STU_MANAGE_SYSTEM ****\n");
        printf("\t\t\t\t\t****    Choose 1 to admin menu    ****\n");
        printf("\t\t\t\t\t****    Choose 2 to stude menu    ****\n");
        printf("\t\t\t\t\t****    Choose 0 to quit          ****\n");
        printf("\t\t\t\t\t**************************************\n");
        //输入选项进入对应的界面
        setbuf(stdin, NULL);
        scanf("%s", ch);
        switch(ch[0]){
            case '1':
                welcome_admin_menu(stulist);                //进入管理员登录界面
                break;
            case '2':
                welcome_stu_menu(stulist);                  //进入学生登录界面
                break;
        }
        if(ch[0] == '0')                                    //退出学生管理系统
        {
            system("clear");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            printf("\t\t\t\t\t*********   Thank You   *********\n");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            break;
        }
    }
    return 0;
}

/* *******************************************************************************
 * Summary: 管理员操作界面
 * Parameters: 学生数据链表
 * Calls: addstu_menu, deletestu_menu, updatestu_menu, showstu_menu, findstu_menu,
 * Return: 对应的操作界面
 * Others: 增加，删除，更新，显示，查找，离开
 * *******************************************************************************/
int admin_menu(node_t *stulist)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("\t\t\t\t\t**************************************\n");
        printf("\t\t\t\t\t**** Welcome to ADMIN OPERAT MENU ****\n");
        printf("\t\t\t\t\t****    Choose 1 to addstu menu   ****\n");
        printf("\t\t\t\t\t****    Choose 2 to delstu menu   ****\n");
        printf("\t\t\t\t\t****    Choose 3 to update menu   ****\n");
        printf("\t\t\t\t\t****    Choose 4 to showst menu   ****\n");
        printf("\t\t\t\t\t****    Choose 5 to findst menu   ****\n");
        printf("\t\t\t\t\t****    Choose 0 to quit   menu   ****\n");
        printf("\t\t\t\t\t**************************************\n");

        setbuf(stdin, NULL);
        scanf("%s", ch);
        if(ch[0] == '0')                            //退出管理员操作菜单
            break;
        switch(ch[0])
        {
            case '1':
                addstu_menu(stulist);               //进入学生添加菜单
                break;
            case '2':
                deletestu_menu(stulist);            //进入学生删除菜单
                break;
            case '3':
                updatestu_menu(stulist);            //进入学生更新菜单
                break;
            case '4':
                showstu_menu(stulist);              //进入学生显示菜单
                break;
            case '5':
                findstu_menu(stulist);              //进入学生查找菜单
                break;
            default:
                system("clear");
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t**************************************\n");
                printf("\t\t\t\t\t******       Input Error      ********\n");
                printf("\t\t\t\t\t**************************************\n");
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t******    Enter to continue   ********\n");
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
 * Calls: admin_menu 
 * Return: 成功返回0 失败返回非0值
 * Others: 提示管理员输入用户名和密码并验证，成功就调用管理员操作菜单
 * *********************/
int welcome_admin_menu(node_t *stulist)
{
    int count = LOOPCOUNT;                      //密码输入次数
    char admin_name[16] = "";                   //输入的名字
    char admin_pass[16] = "";                   //输入的密码
    int flag = 1;                               //成功进入后，下次直接退出循环

    while(count && flag)
    {
        count--;
        system("clear");
        printf("\t\t\t\t\t**************************************\n");
        printf("\t\t\t\t\t**** Welcome to ADMIN LOGIN MENU  ****\n");
        printf("\t\t\t\t\t**************************************\n");
        putchar('\n');
        putchar('\n');
        printf("\t\t\t\t\t****    Input Your Username       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", admin_name);
        printf("\t\t\t\t\t****    Input Your Password       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", admin_pass);
        //验证输入是否正确
        if(strcmp(admin_name, ADMINNAME) == 0)
        {
            if(strcmp(admin_pass, ADMINPASS) == 0)
            {
                admin_menu(stulist);
                flag = 0;
            }
            else
            {
                system("clear");
                putchar('\n');
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t****     Your password error   ****\n");
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t****     Enter to continue     ****\n");
                getchar();
                getchar();
            }
        }
        else{
            system("clear");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            printf("\t\t\t\t\t****     Your Username Error   ****\n");
            putchar('\n');
            putchar('\n');
            printf("\t\t\t\t\t****     Enter to continue     ****\n");
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

/* ************************************
 * Summary: 学生操作菜单
 * Parameters: 学生数据链表
 * Calls: show_stu, updatastu_smenu 
 * Return: 成功返回0 失败返回非0
 * Others: 显示自己的的数据，更新信息
 * ************************************/
int stu_menu(node_t *stulist, node_t *stup)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("\t\t\t\t\t**************************************\n");
        printf("\t\t\t\t\t****** Student Operation Menu ********\n");
        printf("\t\t\t\t\t******   Choose 1 to showstu  ********\n");
        printf("\t\t\t\t\t******   Choose 2 to updates  ********\n");
        printf("\t\t\t\t\t******   Choose 0 to quit     ********\n");
        printf("\t\t\t\t\t**************************************\n");
        setbuf(stdin, NULL);
        scanf("%s", ch);
        if(ch[0] == '0')                            //退出学生操作菜单
            break;
        switch(ch[0])
        {
            case '1':
                putchar('\n');
                putchar('\n');
                show_stu(stup->data);               //显示单个学生数据
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t*********  Enter to continue  *********\n");
                getchar();                          //用于显示学生数据，以免被后边的菜单清屏
                getchar();
                break;
            case '2':
                updatastu_smenu(stulist, stup);     //进入学生数据更新菜单
                break;
            default:
                system("clear");
                putchar('\n');
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t*********    INPUT ERROR     *********\n");
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
    int COUNT = LOOPCOUNT;                                      //登录次数限制

    stu_t *stu_tmp = (stu_t *)malloc(sizeof(stu_t));            //定义一个临时空间存学生数据，用于添加
    SYSERR(stu_tmp,==,NULL,"malloc err\n",-1);

    bzero(stu_tmp, sizeof(stu_t));                              //初始化名字和密码
    int flag = 1;                                               // 进入学生操作菜单置0
    while(COUNT && flag)
    {
        COUNT--;
        system("clear");
        printf("\t\t\t\t\t**************************************\n");
        printf("\t\t\t\t\t******  Student Login Menu    ********\n");
        printf("\t\t\t\t\t**************************************\n");
        putchar('\n');
        putchar('\n');
        putchar('\n');
        printf("\t\t\t\t\t****    Input Your Username       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", stu_tmp->name);
        printf("\t\t\t\t\t****    Input Your Password       ****\n");
        setbuf(stdin,NULL);
        scanf("%s", stu_tmp->pass);
        //根据用户名的唯一性，查找学生链表中的学生名字，用输入密码与之匹配
        node_t *p = LinkList_Find(stulist, stu_tmp, cmp_stu_name);
        //提取节点p的数据用的用户密码
        stu_t *stup = (stu_t *)p->data;
        if(p != NULL)
        {
            if(strcmp(stu_tmp->pass, stup->pass) == 0)          //名字和密码同时正确
            {
                stu_menu(stulist,p);                            //进入学生操作界面
                flag = 0;                                       //结束后退出循环
            }
            else
            {
                system("clear");
                putchar('\n');
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t****     your password error   ****\n");
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t****     enter to continue     ****\n");
                getchar();
                getchar();
            }
        }
        else{
            system("clear");
            putchar('\n');
            putchar('\n');
            putchar('\n');
            printf("\t\t\t\t\t****     Your Username Error   ****\n");
            putchar('\n');
            putchar('\n');
            printf("\t\t\t\t\t****     Enter to continue     ****\n");
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
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t******  Add Student Menu      ********\n");
    printf("\t\t\t\t\t**************************************\n");
    putchar('\n');
    putchar('\n');

    //定义一个新的学生结构体用于存储新读取的学生数据
    stu_t *newstu = (stu_t*)malloc(sizeof(stu_t));
    //进入学生添加函数
    addstu(stulist, newstu);

    return 0;
}

/* *********************************************
 * Summary: 删除学生菜单 
 * Parameters: 学生数据链表
 * Call: delstu()  
 * Return: 成功返回0 失败返回非0
 * Others: 找到需要删除的学生，通过学号查找到学生
 * *********************************************/
int deletestu_menu(node_t *stulist)
{
    system("clear");
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t******  Delete Student Menu   ********\n");
    printf("\t\t\t\t\t**************************************\n");
    putchar('\n');
    putchar('\n');

    stu_t stu;                  //找到需要删除的学生，赋值给stu

    printf("\t\t\t\t\t******  Input Student ID  *********\n");
    scanf("%d", &stu.cid);
    putchar('\n');

    node_t *p = LinkList_Find(stulist, &stu.cid, cmp_stu_cid);
    stu_t *stup = (stu_t*)p->data;
    
    delstu(stulist, *stup);     //调用函数删除该学生节点

    return 0;
}

/* *******************************
 * Summary: 修改学生菜单 
 * Parameters: 学生数据链表
 * Call: updatestu() 
 * Return: 成功返回0 失败返回非0
 * Others: 按不同模式修改学生信息
 * *******************************/
int updatestu_menu(node_t *stulist)
{
    int num = 0;
    //临时储存需要修改的数据和新数据
    stu_t tmp_olddata, tmp_newdata; 
    system("clear");
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t******  Update Student Menu   ********\n");
    printf("\t\t\t\t\t******  Choose 1 Update Name  ********\n");
    printf("\t\t\t\t\t******  Choose 2 Update Math  ********\n");
    printf("\t\t\t\t\t******  Choose 3 Update Lang  ********\n");
    printf("\t\t\t\t\t******  Choose 4 Update Phil  ********\n");
    printf("\t\t\t\t\t******  Choose 5 Update Clid  ********\n");
    printf("\t\t\t\t\t**************************************\n");
    scanf("%d", &num);
    switch(num)
    {
        case 1:
            printf("\t\t\t\t\t******  Input Old Name Data  ********\n");
            scanf("%s", tmp_olddata.name);
            printf("\t\t\t\t\t******  Input New Name Data  ********\n");
            scanf("%s", tmp_newdata.name);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 2:
            printf("\t\t\t\t\t******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("\t\t\t\t\t******  Input New Math Data  ********\n");
            scanf("%d", &tmp_newdata.gmath);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 3:
            printf("\t\t\t\t\t******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("\t\t\t\t\t******  Input New Clang Data ********\n");
            scanf("%d", &tmp_newdata.glang);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 4:
            printf("\t\t\t\t\t******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("\t\t\t\t\t******  Input New Phily Data ********\n");
            scanf("%d", &tmp_newdata.gphil);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
        case 5:
            printf("\t\t\t\t\t******  Input Student ID     ********\n");
            scanf("%d", &tmp_olddata.cid);
            printf("\t\t\t\t\t******  Input New Class Data ********\n");
            scanf("%d", &tmp_newdata.classid);            
            //新值覆盖旧值
            updatestu(stulist, num, tmp_olddata, tmp_newdata);        
            break;
    }
    return 0;
}

/* **********************************************************
 * Summary: 修改学生菜单(学生模式) 
 * Parameters: 学生数据链表stulist, 登录时获得的学生节点stup
 * Call: LinkList_update() 
 * Return: 成功返回0 失败返回非0
 * Others: 输入相应的模式数字，进入不同修改模式，然后显示
 * **********************************************************/
int updatastu_smenu(node_t *stulist, node_t *stup)
{
    int mode = 0;                   //模式选择
    system("clear");
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t******  Update  Student  Menu ********\n");
    printf("\t\t\t\t\t******  Choose 1 Update Name  ********\n");
    printf("\t\t\t\t\t******  Choose 2 Update Age   ********\n");
    printf("\t\t\t\t\t******  Choose 3 Update Math  ********\n");
    printf("\t\t\t\t\t******  Choose 4 Update Lang  ********\n");
    printf("\t\t\t\t\t******  Choose 5 Update Phil  ********\n");
    printf("\t\t\t\t\t******  Choose 6 Update Clid  ********\n");
    printf("\t\t\t\t\t**************************************\n");
    setbuf(stdin, NULL);
    scanf("%d", &mode);
    //进入学生数据更新
    updatestu_s(stulist, mode, stup);
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
    int mode = 0;                   //模式选择
    system("clear");
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t******  Show  Student  Menu   ********\n");
    printf("\t\t\t\t\t******  Choose 1 Show   Cid   ********\n");
    printf("\t\t\t\t\t******  Choose 2 Show   Math  ********\n");
    printf("\t\t\t\t\t******  Choose 3 Show   Lang  ********\n");
    printf("\t\t\t\t\t******  Choose 4 Show   Phil  ********\n");
    printf("\t\t\t\t\t******  Choose 5 Show   Clid  ********\n");
    printf("\t\t\t\t\t**************************************\n");
    setbuf(stdin, NULL);
    scanf("%d", &mode);
    //按模式排序
    sortstu(stulist, mode);
    //重新设置名次
    setstuorder(stulist);
    //学生数据链表打印
    system("clear");
    LinkList_Show(stulist, show_stu);
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t********  Enter to continue  *********\n");
    getchar();
    getchar();
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
    int mode = 0;                   //模式选择
    system("clear");
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t******  Find  Student  Menu   ********\n");
    printf("\t\t\t\t\t******  Choose 0 Find   ALL   ********\n");
    printf("\t\t\t\t\t******  Choose 1 Find   Cid   ********\n");
    printf("\t\t\t\t\t******  Choose 2 Find   Name  ********\n");
    printf("\t\t\t\t\t******  Choose 3 Find   Clas  ********\n");
    printf("\t\t\t\t\t**************************************\n");
    setbuf(stdin, NULL);
    scanf("%d", &mode);

    stu_t *stu = (stu_t *)malloc(sizeof(stu_t));        //存储临时值
    node_t *p;                                          //存储得到的链表节点

                                                        //按模式返回对于的信息
    switch(mode)
    {
        case 0:
            system("clear");
            printf("\t\t\t\t\t***********   SHOW ALL   *************\n");
            p = findstu(stulist, mode, stu);
            LinkList_Show(p, show_stu);
            printf("\t\t\t\t\t**************************************\n");
            putchar('\n');
            putchar('\n');
            printf("\t\t\t\t\t**********  Enter to continue  *******\n");
            getchar();
            getchar();
            break;
        case 1:
            {
                printf("\t\t\t\t\t***********  Input Cid  **************\n");
                scanf("%d", &stu->cid);
                p = findstu(stulist, mode, stu);
                show_stu(p->data);
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t**********  Enter to continue  *******\n");
                getchar();
                getchar();
                break;
            }
        case 2:
            {
                printf("\t\t\t\t\t***********  Input Name  *************\n");
                scanf("%s", stu->name);
                p = findstu(stulist, mode, stu);
                LinkList_Show(p, show_stu);
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t**********  Enter to continue  *******\n");
                getchar();
                getchar();
                break;
            }
        case 3:
            {
                printf("\t\t\t\t\t**********  Input Class  *************\n");
                scanf("%d", &stu->classid);
                p = findstu(stulist, mode, stu);
                LinkList_Show(p, show_stu);
                putchar('\n');
                putchar('\n');
                printf("\t\t\t\t\t**********  Enter to continue  *******\n");
                getchar();
                getchar();
                break;
            }
        default:
            printf("\t\t\t\t\t***********  The mode error  ***********\n");
            putchar('\n');
            printf("\t\t\t\t\t**********  Enter to continue  *******\n");
            getchar();
            getchar();
            break;
    }
    return 0;
}
