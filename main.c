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
    //加载学生数据文件student.dat到学生链表
    node_t *stulist = loadstu();
    //登录程序主菜单
    login_menu(stulist);
    //用户选择判定是否需要将链表数据写入文件
    printf("\t\t\t\t\t***********************************\n");
    printf("\t\t\t\t\t******** Save Data or Not *********\n");
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t******** Input Y(y) to save *******\n");
    putchar('\n');

    char ch[4] = "";
    printf("\t\t\t\t\t");
    scanf("%s", ch);
    if(ch[0] == 'Y' || ch[0] == 'y')
    {
        savestu(stulist);
        system("clear");
        DATASHOWF;
        LinkList_Show(stulist, show_stu);
    }
    //销毁链表
    destroy_Linklist(&stulist);
    
    return 0;
}
