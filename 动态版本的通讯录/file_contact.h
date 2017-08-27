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
#define PRESENT_CAPACITY 2//��ǰ��̬���ٵĿռ�
#define ENLARGE_CAPACITY 2//ÿ�����ӵĿռ�

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
typedef struct PEO//����ÿ����Ա�Ļ�����Ϣ
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
	int size;//ͨѶ¼�ĵ�ǰ����
	int capacity;
}*pcon,CONTACT;

void init_contact(pcon con);//��ʼ��ͨѶ¼
void check_capacity(pcon con);//����Ƿ���Ҫ����
void add_infor(pcon con);
void del_infor(pcon con);
void check_infor(pcon con);
void modify_infor(pcon con);
void display_infor(pcon con);
void clear_infor(pcon con);
void sort_infor(pcon con);
void load_infor(pcon con);//ÿ�γ�������ʱ������ĳ�Ա��Ϣ���س���
void save_infor(pcon con);//ÿ�ν�����ĳ�Ա��Ϣ���浽�ļ���

#endif //__CONTACT_BOOK_H_