/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: main()函数
 **********************************/
#include "student.h"
#include "menu.h"

int main()
{
    //定义连个链表节点
    //加载学生数据文件student.dat到学生链表
    node_t *stulist = loadstu();
    //登录程序主菜单
    login_menu(stulist);
    //根据程序是否修改和用户选择，判定是否需要将链表数据写入文件
    printf("*********************************\n");
    printf("******** Save Data or Not *******\n");
    char ch[4] = "";
    scanf("%s", ch);
    if(ch[0] == 'Y' || ch[0] == 'y') // 没有判断程序是否修改？
        savestu(stulist);
    //销毁链表
    destroy_Linklist(&stulist);
}
