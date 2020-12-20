#include "student.h"
#include "menu.h"

int main()
{
    node_t *stulist;
    //加载学生数据文件student.dat到学生链表
    stulist = loadstu();
    //登录程序主菜单
    //login_menu(stulist, tchlist);
    //根据程序选择是否需要将链表数据写入文件
    savestu(stulist);
    //销毁链表
    //destroy_dlist(&stulist);
}
