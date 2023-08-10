#define _CRT_SECURE_NO_WARNINGS 1//（对函数功能进行测试）
#include"contact.h"
//具体功能模拟：
//能够储存Max位联系人的姓名，年龄，性别，电话，地址五条信息
//能够对指定联系人进行添加和删除
//能够对指定联系人进行查找和修改
//对联系人信息进行排序后进行显示
int main()
{
	int input = 0;
	Contact con;//通讯录
	InitContact(&con);//对通讯录进行初始化
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