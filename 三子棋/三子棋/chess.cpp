#define _CRT_SECURE_NO_WARNINGS 1//��������Ϸ
#include"play.h"

void menu()//�˵�������ʾ���ݣ������Ƿ������Ϸ
{
	printf("Welcome to this game.Please choose whether you'd like to participate in.\n");
	printf("         1.continue                             0.exit\n");
}

void play()//��Ϸ���򲿷֣������������ɣ���Һ͵��Ը������壬�ж�Ӯ������
{
	//�������鿪���ڴ�ռ�������
	char board[ROW][COL] = {0};
	Boardgeneration(board,ROW,COL);
	Displayboard(board, ROW, COL);
	Play(board, ROW, COL);

}

void test()//���Ժ�������Ϸ���е�����
{
	int input = 0;//ͨ�������жϽ�����Ϸ
	do
	{
		menu();
		printf("Please make your choice-->");
		scanf("%d", &input); 
		switch (input)
		{
		case 1://������Ϸ
			printf("Game loading.\n");
			play();
			break;
		case 0://�˳���������ʾ��Ϸ����
			printf("Game exit\n");
			break;
		default://�������������Ϸ
			printf("Your input content is illegal.Please try again.\n");
			break;
		}
	} while (input > 1);
}

int main()
{
	test();//����test����������Ϸ����
	return 0;
}