#define _CRT_SECURE_NO_WARNINGS 1//（函数功能实现）
#include"contact.h"
void menu()//菜单界面函数
{
	printf("Welcome to Adress Book.\n");
	printf("1.Add          2.Delete\n");
	printf("3.Search       4.Modify\n");
	printf("5.Present      6.Sort\n");
	printf("        0.exit\n");
}

void InitContact(Contact* pc)//初始化列表函数
{
	assert(pc);
	memset(pc, 0, sizeof(pc->data));//用memset设置内存
	pc->count = 0;
}

void AddContact(Contact* pc)//添加联系人函数
{
	assert(pc);
	if (pc->count == Max)
	{
		printf("Full");
		return;//如果函数为void类型想退出函数时可以用return不返回值来实现
	} 
	printf("Name->");
	scanf("%s", pc->data[pc->count].name);//name为数组，数组名本身就表示地址
	printf("Age->");
	scanf("%d", &(pc->data[pc->count].age));//age为整型变量，本身不是地址，因此需要取地址实现
	printf("Sex->");
	scanf("%s", pc->data[pc->count].sex);
	printf("Address->");
	scanf("%s", pc->data[pc->count].add);
	pc->count++;
	printf("Success\n");
}

static int Findbyname(const Contact* pc, const char name[])//按名字对通讯录中的联系人进行查找
//如果查找到返回找到的元素下表
//如果未找到返回-1
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}//函数无需暴露给外界，因此不用进行声明,加static成为静态变量


void DelContact(Contact* pc)//删除联系人函数
{
	assert(pc);
	char name[20] = { 0 };
	printf("Choose the name you want to delete->");
	scanf("%s", name);
	if (pc->count == 0)//先判断是否有元素可以删除
	{
		printf("Error! No information.");
		return;
	}
	int pos = Findbyname(pc, name);
	int i = pos;
	if (pos == -1)//寻找是否有对应名字
	{
		printf("Error.Not found.");
		return;
	}
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("Delete Success\n");
}

void SearchContact(Contact* pc)//查找通讯录函数
{
	assert(pc);
	char name[20] = { 0 };
	printf("Search name->");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)//寻找是否有对应名字
	{
		printf("Error.Not found.");
		return;
	}
	printf("%-20s \t %-5s \t %-10s \t %-30s\n", "Name", "Age", "Sex", "Address");//加负号保证左对齐
	printf("%-20s \t %-5d \t %-10s \t %-30s\n",
		pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].add);//对找到的名字进行打印
}

void ModifyContact(Contact* pc)//修改通讯录函数
{
	assert(pc);
	char name[20] = { 0 };
	printf("Search name->");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)//寻找是否有对应名字
	{
		printf("Error.Not found.");
		return;
	}
	printf("Please modify->");
	printf("Name->");//对查找到的联系人进行修改
	scanf("%20s", pc->data[pos].name);
	printf("Age->");
	scanf("%5d", &(pc->data[pos].age));
	printf("Sex->");
	scanf("%10s", pc->data[pos].sex);
	printf("Address->");
	scanf("%40s", pc->data[pos].add);
	printf("Modify Success!");
}

int Cmpbyname(const void* e1, const void* e2)//按名字对联系人进行比较函数
{
	return strcmp(((Peoinfo*)e1)->name, ((Peoinfo*)e2)->name);
}

void SortContact(Contact* pc)//按名字对联系人进行排序函数
{
	qsort(pc->data, pc->count, sizeof(Peoinfo), Cmpbyname);
	printf("Sort Success!");
}

void PresentContact(const Contact* pc)//展示通讯录函数
{
	assert(pc);
	int i = 0;
	printf("%-20s \t %-5s \t %-10s \t %-30s\n", "Name", "Age", "Sex","Address");//加负号保证左对齐
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s \t %-5d \t %-10s \t %-30s\n",
				pc->data[i].name,pc->data[i].age,pc->data[i].sex,pc->data[i].add);
	}
}