#define _CRT_SECURE_NO_WARNINGS 1//����������ʵ�֣�
#include"contact.h"
void menu()//�˵����溯��
{
	printf("Welcome to Adress Book.\n");
	printf("1.Add          2.Delete\n");
	printf("3.Search       4.Modify\n");
	printf("5.Present      6.Sort\n");
	printf("        0.exit\n");
}

void InitContact(Contact* pc)//��ʼ���б���
{
	assert(pc);
	memset(pc, 0, sizeof(pc->data));//��memset�����ڴ�
	pc->count = 0;
}

void AddContact(Contact* pc)//�����ϵ�˺���
{
	assert(pc);
	if (pc->count == Max)
	{
		printf("Full");
		return;//�������Ϊvoid�������˳�����ʱ������return������ֵ��ʵ��
	} 
	printf("Name->");
	scanf("%s", pc->data[pc->count].name);//nameΪ���飬����������ͱ�ʾ��ַ
	printf("Age->");
	scanf("%d", &(pc->data[pc->count].age));//ageΪ���ͱ����������ǵ�ַ�������Ҫȡ��ַʵ��
	printf("Sex->");
	scanf("%s", pc->data[pc->count].sex);
	printf("Address->");
	scanf("%s", pc->data[pc->count].add);
	pc->count++;
	printf("Success\n");
}

static int Findbyname(const Contact* pc, const char name[])//�����ֶ�ͨѶ¼�е���ϵ�˽��в���
//������ҵ������ҵ���Ԫ���±�
//���δ�ҵ�����-1
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
}//�������豩¶����磬��˲��ý�������,��static��Ϊ��̬����


void DelContact(Contact* pc)//ɾ����ϵ�˺���
{
	assert(pc);
	char name[20] = { 0 };
	printf("Choose the name you want to delete->");
	scanf("%s", name);
	if (pc->count == 0)//���ж��Ƿ���Ԫ�ؿ���ɾ��
	{
		printf("Error! No information.");
		return;
	}
	int pos = Findbyname(pc, name);
	int i = pos;
	if (pos == -1)//Ѱ���Ƿ��ж�Ӧ����
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

void SearchContact(Contact* pc)//����ͨѶ¼����
{
	assert(pc);
	char name[20] = { 0 };
	printf("Search name->");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)//Ѱ���Ƿ��ж�Ӧ����
	{
		printf("Error.Not found.");
		return;
	}
	printf("%-20s \t %-5s \t %-10s \t %-30s\n", "Name", "Age", "Sex", "Address");//�Ӹ��ű�֤�����
	printf("%-20s \t %-5d \t %-10s \t %-30s\n",
		pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].add);//���ҵ������ֽ��д�ӡ
}

void ModifyContact(Contact* pc)//�޸�ͨѶ¼����
{
	assert(pc);
	char name[20] = { 0 };
	printf("Search name->");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)//Ѱ���Ƿ��ж�Ӧ����
	{
		printf("Error.Not found.");
		return;
	}
	printf("Please modify->");
	printf("Name->");//�Բ��ҵ�����ϵ�˽����޸�
	scanf("%20s", pc->data[pos].name);
	printf("Age->");
	scanf("%5d", &(pc->data[pos].age));
	printf("Sex->");
	scanf("%10s", pc->data[pos].sex);
	printf("Address->");
	scanf("%40s", pc->data[pos].add);
	printf("Modify Success!");
}

int Cmpbyname(const void* e1, const void* e2)//�����ֶ���ϵ�˽��бȽϺ���
{
	return strcmp(((Peoinfo*)e1)->name, ((Peoinfo*)e2)->name);
}

void SortContact(Contact* pc)//�����ֶ���ϵ�˽���������
{
	qsort(pc->data, pc->count, sizeof(Peoinfo), Cmpbyname);
	printf("Sort Success!");
}

void PresentContact(const Contact* pc)//չʾͨѶ¼����
{
	assert(pc);
	int i = 0;
	printf("%-20s \t %-5s \t %-10s \t %-30s\n", "Name", "Age", "Sex","Address");//�Ӹ��ű�֤�����
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s \t %-5d \t %-10s \t %-30s\n",
				pc->data[i].name,pc->data[i].age,pc->data[i].sex,pc->data[i].add);
	}
}