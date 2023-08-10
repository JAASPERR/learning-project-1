#pragma once//(通讯录相关声明文件）

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define Max 100

void menu();

typedef struct Peoinfo
{
	char name[20];
	int age;
	char sex[10];
	char add[30];
}Peoinfo;//创建通讯录的具体内容

typedef struct Contact
{
	Peoinfo data[Max];
	int count;
}Contact;//创建通讯录，包括具体内容和count来计算结构体中存储人数

void InitContact(Contact* pc);//定义初始化函数

void AddContact(Contact* pc);//添加联系人函数

void DelContact(Contact* pc);//删除联系人函数

void SearchContact(Contact* pc);//查找联系人函数

void ModifyContact(Contact* pc);//修改联系人函数

void SortContact(Contact* pc);//按名字对联系人进行排序函数

void PresentContact(const Contact* pc);//打印通讯录函数