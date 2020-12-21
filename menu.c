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
    while(COUNT)
    {

    }
}


