#pragma once//(ͨѶ¼��������ļ���

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
}Peoinfo;//����ͨѶ¼�ľ�������

typedef struct Contact
{
	Peoinfo data[Max];
	int count;
}Contact;//����ͨѶ¼�������������ݺ�count������ṹ���д洢����

void InitContact(Contact* pc);//�����ʼ������

void AddContact(Contact* pc);//�����ϵ�˺���

void DelContact(Contact* pc);//ɾ����ϵ�˺���

void SearchContact(Contact* pc);//������ϵ�˺���

void ModifyContact(Contact* pc);//�޸���ϵ�˺���

void SortContact(Contact* pc);//�����ֶ���ϵ�˽���������

void PresentContact(const Contact* pc);//��ӡͨѶ¼����