#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>

void Boardgeneration(char board[ROW][COL], int row, int col);

void Displayboard(char board[ROW][COL], int row, int col);

void Play(char board[ROW][COL], int row, int col);

void Userplay(char board[ROW][COL], int row, int col);

void Dellplay(char board[ROW][COL], int row, int col);

char Judge(char board[ROW][COL], int row, int col);

int Full(char board[ROW][COL], int row, int col);