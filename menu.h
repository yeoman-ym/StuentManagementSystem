/***********************************
 Copyright: HQYJ
 Author: yeoman
 Date: 2020-12-20
 Description: 菜单模块头文件，相关函数声明
 **********************************/

#ifndef MENU_H
#define MENU_H

#include "dlist.h"
#include "student.h"

/* **********************
 * Summary: 登录主界面—— 学生界面，管理员界面
 * Parameters: 学生链表头结点
 * Calls: welcome_admin_menu(), welcome_stu_menu()
 * Return: 登录成功与否
 * Others: 只对学生操作，所以只需要学生数据
 * *********************/
int login_menu(node_t *stulist);

/* *******************************************************************************
 * Summary: 管理员操作界面
 * Parameters: 学生数据链表
 * Calls: addstu_menu, deletestu_menu, updatestu_menu, showstu_menu, findstu_menu,
 * Return: 对应的操作界面
 * Others: 增加，删除，更新，显示，查找，离开
 * *******************************************************************************/
int admin_menu(node_t *stulist);

/* **********************
 * Summary: 管理员登录界面
 * Parameters: 学生链表 
 * Calls: admin_menu 
 * Return: 成功返回0 失败返回非0值
 * Others: 提示管理员输入用户名和密码并验证，成功就调用管理员操作菜单
 * *********************/
int welcome_admin_menu(node_t *stulist);

#if 0
//教师操作菜单
int tch_menu(node_t *stulist, node_t *tchlist, tch_t *tchp);
//教师登录界面
int welcome_tch_menu(node_t *stulist, node_t *tchlist);
#endif

/* ************************************
 * Summary: 学生操作菜单
 * Parameters: 学生数据链表
 * Calls: show_stu, updatastu_smenu 
 * Return: 成功返回0 失败返回非0
 * Others: 显示自己的的数据，更新信息
 * ************************************/
int stu_menu(node_t *stulist, node_t *stup);

/* **********************
 * Summary: 学生登录界面
 * Parameters: 学生数据链表
 *
 * Return:
 * Others: 登录验证学生姓名和密码，成功进入学生操作界面
 * *********************/
int welcome_stu_menu(node_t *stulist);

/* **********************
 * Summary: 添加学生菜单 
 * Parameters: 学生数据链表
 * Call: addstu() 
 * Return: 成功返回0 失败返回非0
 * Others: 输入学生相应的数据插入链表
 * *********************/
int addstu_menu(node_t *stulist);

/* *********************************************
 * Summary: 删除学生菜单 
 * Parameters: 学生数据链表
 * Call: delstu()  
 * Return: 成功返回0 失败返回非0
 * Others: 找到需要删除的学生，通过学号查找到学生
 * *********************************************/
int deletestu_menu(node_t *stulist);

/* *******************************
 * Summary: 修改学生菜单 
 * Parameters: 学生数据链表
 * Call: updatestu() 
 * Return: 成功返回0 失败返回非0
 * Others: 按不同模式修改学生信息
 * *******************************/
int updatestu_menu(node_t *stulist);

/* **********************************************************
 * Summary: 修改学生菜单(学生模式) 
 * Parameters: 学生数据链表stulist, 登录时获得的学生节点stup
 * Call: LinkList_update() 
 * Return: 成功返回0 失败返回非0
 * Others: 输入相应的模式数字，进入不同修改模式，然后显示
 * **********************************************************/
int updatastu_smenu(node_t *stulist, node_t *stup);

/* **********************
 * Summary: 显示学生菜单 
 * Parameters: 学生数据链表
 * Call: addstu() 
 * Return: 成功返回0 失败返回非0
 * Others: 输入相应的模式数字，进入不同排序，然后显示
 * *********************/
int showstu_menu(node_t *stulist);

/* **********************
 * Summary: 查找学生菜单 
 * Parameters: 学生数据链表
 * Call: findstu()
 * Return: 成功返回0 失败返回非0
 * Others: 0获取全部，1，按学号获取，2，姓名获取，3，班级获取
 * *********************/
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
