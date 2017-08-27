#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __CONTACT_BOOK_H__
#define __CONTACT_BOOK_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


#define NAME_MAX 20
#define SEX_MAX 5
#define TEL_MAX 12
#define ADDR_MAX 25
#define PRESENT_CAPACITY 2//当前动态开辟的空间
#define ENLARGE_CAPACITY 2//每次增加的空间

enum OP
{
	EXIT,
    ADD,
	DEL,
	CHECK,
	MODIFY,
	DISPLAY,
	CLEAR,
	SORT,
};
typedef struct PEO//保存每个成员的基本信息
{
    char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX ];
}PEO;
typedef struct CONTACT
{
	PEO *peo;
	int size;//通讯录的当前人数
	int capacity;
}*pcon,CONTACT;

void init_contact(pcon con);//初始化通讯录
void check_capacity(pcon con);//检查是否需要扩容
void add_infor(pcon con);
void del_infor(pcon con);
void check_infor(pcon con);
void modify_infor(pcon con);
void display_infor(pcon con);
void clear_infor(pcon con);
void sort_infor(pcon con);
void load_infor(pcon con);//每次程序运行时将保存的成员信息加载出来
void save_infor(pcon con);//每次将输入的成员信息保存到文件中

#endif //__CONTACT_BOOK_H_