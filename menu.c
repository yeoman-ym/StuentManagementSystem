/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: Provide functions to main
 **********************************/
#include "menu.h"
#include "common.h"

/* **********************
 * Summary: 
 * Parameters:
 *
 * Return:
 * Others:
 * *********************/
int login_menu(node_t *stulist, node_t *tchlist)
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
                welcome_admin_menu(stulist, tchlist);
                break;
            case '2':
                welcome_stu_menu(stulist);
                break;
        }
        if(ch[0] == '0')
        {
            printf("******** Thank You *********\n");
            break;
        }
    }
    return 0;
}

/* **********************
 * Summary: 
 * Parameters:
 *
 * Return:
 * Others:
 * *********************/
int admin_menu(node_t *stulist, node_t *tchlist)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("**************************************\n");
        printf("**** Welcome to ADMIN LOGIN MENU  ****\n");
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
                updatestu_menu(stulist, );
                break;
            case '4':
                showstu_menu(stulist);
                break;
            case '5':
                findstu_menu(stulist);
                break;
            default:
                printf("**************************************\n");
                printf("******       Input Error      ********\n");
                printf("**************************************\n");
                break;
        }
    }
    return 0;
}

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

//学生操作菜单
int stu_menu(node_t *stulist, stu_t *stup)
{
    char ch[4] = "";
    while(true)
    {
        system("clear");
        printf("**************************************\n");
        printf("******   Student Operation    ********\n");
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
                show_stu(stulist->data);
                break;
            case '2':
                updatestu_menu(stulist, stup);
                break;
            default:
                printf("******  INPUT ERROR  ******\n");
                break;
        }
    }
    return 0;
}

int welcome_stu_menu(node_t *stulist)
{
    int COUNT = LOOPCOUNT;
    char name[16] = "";
    int passwd = 0;
    while(COUNT)
    {
        system("clear");
        printf("************** Student ****************\n");
        printf("******  Input Username passwd ********\n");
        printf("**************************************\n");
        setbuf(stdin, NULL);
        scanf("%s%d", name, &passwd);
        //调用find_vdist 取出指定用户名和密码
        //和输入的值做比较
        //成功调用stu_menu()函数
        COUNT--;
    }
    return 0;
}

int addstu_menu(node_t *stulist)
{
    system("clear");
    int studentid = getcid();
}
