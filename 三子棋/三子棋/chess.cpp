#define _CRT_SECURE_NO_WARNINGS 1//三子棋游戏
#include"play.h"

void menu()//菜单界面显示内容，决定是否进入游戏
{
	printf("Welcome to this game.Please choose whether you'd like to participate in.\n");
	printf("         1.continue                             0.exit\n");
}

void play()//游戏程序部分，包括棋盘生成，玩家和电脑各自下棋，判断赢家三步
{
	//利用数组开辟内存空间存放棋盘
	char board[ROW][COL] = {0};
	Boardgeneration(board,ROW,COL);
	Displayboard(board, ROW, COL);
	Play(board, ROW, COL);

}

void test()//测试函数，游戏运行的主体
{
	int input = 0;//通过数字判断进入游戏
	do
	{
		menu();
		printf("Please make your choice-->");
		scanf("%d", &input); 
		switch (input)
		{
		case 1://进入游戏
			printf("Game loading.\n");
			play();
			break;
		case 0://退出并不再显示游戏内容
			printf("Game exit\n");
			break;
		default://重新输入进入游戏
			printf("Your input content is illegal.Please try again.\n");
			break;
		}
	} while (input > 1);
}

int main()
{
	test();//利用test函数进行游戏即可
	return 0;
}