#define _CRT_SECURE_NO_WARNINGS 1//���Ժ������ܽ��в��ԣ�
#include"contact.h"
//���幦��ģ�⣺
//�ܹ�����Maxλ��ϵ�˵����������䣬�Ա𣬵绰����ַ������Ϣ
//�ܹ���ָ����ϵ�˽�����Ӻ�ɾ��
//�ܹ���ָ����ϵ�˽��в��Һ��޸�
//����ϵ����Ϣ��������������ʾ
int main()
{
	int input = 0;
	Contact con;//ͨѶ¼
	InitContact(&con);//��ͨѶ¼���г�ʼ��
	do
	{
		menu();
		printf("Choose->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:AddContact(&con);
			break;
		case 2:DelContact(&con);
			break;
		case 3:SearchContact(&con);
			break;
		case 4:ModifyContact(&con);
			break;
		case 5:PresentContact(&con);
			break;
		case 6:SortContact(&con);
			break;
		case 0:
			break;
		default:printf("Error.Please choose again.\n");
			break;
		}
	} while (input);
}