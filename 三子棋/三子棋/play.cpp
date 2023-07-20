#define _CRT_SECURE_NO_WARNINGS 1
#include"play.h"

void Boardgeneration(char board[ROW][COL], int row, int col)//棋盘初始化函数
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}//棋盘初始化均为空
	}
}

void Displayboard(char board[ROW][COL], int row, int col)//棋盘展示函数
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}//打印分割列
			else printf("\n");
		}
		if (i < row - 1)//打印分割行
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
				else printf("\n");
			}
		}
	}
}

void Userplay(char board[ROW][COL], int row, int col)//棋盘玩家进行游戏函数
{
	int inputrow = 0;
	int inputcol = 0;
	while (1)//循环进行
	{
		printf("Please choose where you'd like to place your chess(row,col)");
		scanf("%d%d", &inputrow, &inputcol);//输入坐标
		if (inputrow >= 1 && inputrow <= row && inputcol >= 1 && inputcol <= col)//验证坐标的合法性
		{
			if (board[inputrow - 1][inputcol - 1] == ' ')
			{
				board[inputrow - 1][inputcol - 1] = '*';
				break;//如果坐标合法就break进行展示
			}
			else printf("Illegal.Please try again\n");
		}	
		else printf("Illegal.Please try again\n");
	}
}

void Dellplay(char board[ROW][COL], int row, int col)//电脑进行游戏函数
{
	int inputrow = 0;
	int inputcol = 0;
	inputrow = rand() % row;
	inputcol = rand() % col;
	printf("Computer placing\n");
	while (1)//循环进行
	{
			if (board[inputrow][inputcol] == ' ')
			{
				board[inputrow][inputcol] = '#';
				break;//合法就进行展示，否则就继续进行
			}
	}
}

int Full(char board[ROW][COL], int row, int col)//判断棋盘是否已满，如满返回1，否则返回0
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row-1; i++)
	{
		for (j = 0; j < col-1; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Judge (char board[ROW][COL], int row, int col)//四种游戏结果，分别是玩家赢，电脑赢，平局和继续
{
	//每行结果判断
	int i = 0;
	int j = 0;
	for (i = 0; i <= row-1 ; i++)//每一行有三个相同
	{
		if (board[i][0] == board[i][1] && board[i][1] ==  board[i][2] && board[i][0] !=' ')
		{
			return board[i][0];	 	
		}
	}
	for (j = 0; j <= col-1; j++)//每一列有三个相同
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')//判断对角线有三个相同
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (Full(board ,ROW,COL)== 1)//利用full函数判断棋盘已满
	{
		return ' ';
	}
	return 'C';
}

void Play(char board[ROW][COL], int row, int col)//进行游戏函数的主体
{
	char ret;
	while (1)
	{
		Userplay(board,ROW,COL);
		Displayboard(board, ROW, COL);
		ret = Judge(board, ROW, COL);
		if (ret != 'C')//利用判断函数的返回值判断游戏是否已经结束
		{
			break;
		}
		Dellplay(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Judge(board, ROW, COL);
		if (ret != 'C')//利用判断函数的返回值判断游戏是否已经结束
		{
			break;
		}
	}
	if (ret == '#')
	{
		printf("Comuter win");
	}
	if (ret == '*')
	{
		printf("Player win");
	}
	if (ret == ' ')
	{
		printf("Tie");
	}
}