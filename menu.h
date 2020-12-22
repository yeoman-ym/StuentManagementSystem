//菜单模块：完成菜单的显示和调用相应功能函数

#ifndef MENU_H
#define MENU_H

#include "dlist.h"
#include "student.h"

//程序主界面
int login_menu(node_t *stulist);

//管理员操作菜单
int admin_menu(node_t *stulist);
//管理员登录界面
int welcome_admin_menu(node_t *stulist);

#if 0
//教师操作菜单
int tch_menu(node_t *stulist, node_t *tchlist, tch_t *tchp);
//教师登录界面
int welcome_tch_menu(node_t *stulist, node_t *tchlist);
#endif

//学生操作菜单
int stu_menu(stu_t *stup);
//学生登录界面
int welcome_stu_menu(node_t *stulist);

//添加学生菜单
int addstu_menu(node_t *stulist);
//删除学生菜单
int deletestu_menu(node_t *stulist);
//修改学生菜单
int updatestu_menu(node_t *stulist);
//显示学生菜单
int showstu_menu(node_t *stulist);
//查找学生菜单
int findstu_menu(node_t *stulist);

/* 教师模块暂时不写 */

//添加教师菜单
int addtch_menu(node_t *tchlist);
//删除教师菜单
int deletetch_menu(node_t *tchlist);
//修改教师菜单
int updatetch_menu(node_t *tchlist);
//显示教师菜单
int showtch_menu(node_t *tchlist);
//查找教师菜单
int findtch_menu(node_t *tchlist);

#endif
