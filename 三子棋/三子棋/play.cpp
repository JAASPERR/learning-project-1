#define _CRT_SECURE_NO_WARNINGS 1
#include"play.h"

void Boardgeneration(char board[ROW][COL], int row, int col)//���̳�ʼ������
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}//���̳�ʼ����Ϊ��
	}
}

void Displayboard(char board[ROW][COL], int row, int col)//����չʾ����
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
			}//��ӡ�ָ���
			else printf("\n");
		}
		if (i < row - 1)//��ӡ�ָ���
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

void Userplay(char board[ROW][COL], int row, int col)//������ҽ�����Ϸ����
{
	int inputrow = 0;
	int inputcol = 0;
	while (1)//ѭ������
	{
		printf("Please choose where you'd like to place your chess(row,col)");
		scanf("%d%d", &inputrow, &inputcol);//��������
		if (inputrow >= 1 && inputrow <= row && inputcol >= 1 && inputcol <= col)//��֤����ĺϷ���
		{
			if (board[inputrow - 1][inputcol - 1] == ' ')
			{
				board[inputrow - 1][inputcol - 1] = '*';
				break;//�������Ϸ���break����չʾ
			}
			else printf("Illegal.Please try again\n");
		}	
		else printf("Illegal.Please try again\n");
	}
}

void Dellplay(char board[ROW][COL], int row, int col)//���Խ�����Ϸ����
{
	int inputrow = 0;
	int inputcol = 0;
	inputrow = rand() % row;
	inputcol = rand() % col;
	printf("Computer placing\n");
	while (1)//ѭ������
	{
			if (board[inputrow][inputcol] == ' ')
			{
				board[inputrow][inputcol] = '#';
				break;//�Ϸ��ͽ���չʾ������ͼ�������
			}
	}
}

int Full(char board[ROW][COL], int row, int col)//�ж������Ƿ���������������1�����򷵻�0
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

char Judge (char board[ROW][COL], int row, int col)//������Ϸ������ֱ������Ӯ������Ӯ��ƽ�ֺͼ���
{
	//ÿ�н���ж�
	int i = 0;
	int j = 0;
	for (i = 0; i <= row-1 ; i++)//ÿһ����������ͬ
	{
		if (board[i][0] == board[i][1] && board[i][1] ==  board[i][2] && board[i][0] !=' ')
		{
			return board[i][0];	 	
		}
	}
	for (j = 0; j <= col-1; j++)//ÿһ����������ͬ
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')//�ж϶Խ�����������ͬ
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (Full(board ,ROW,COL)== 1)//����full�����ж���������
	{
		return ' ';
	}
	return 'C';
}

void Play(char board[ROW][COL], int row, int col)//������Ϸ����������
{
	char ret;
	while (1)
	{
		Userplay(board,ROW,COL);
		Displayboard(board, ROW, COL);
		ret = Judge(board, ROW, COL);
		if (ret != 'C')//�����жϺ����ķ���ֵ�ж���Ϸ�Ƿ��Ѿ�����
		{
			break;
		}
		Dellplay(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Judge(board, ROW, COL);
		if (ret != 'C')//�����жϺ����ķ���ֵ�ж���Ϸ�Ƿ��Ѿ�����
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