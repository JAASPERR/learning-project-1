#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//对于第n层台阶，可能是由第（n-1）层跳上来的，也可能是从（n-2）层跳上来的因此次数因此累加
int result(int m)
{
	int a = 1;
	int b = 2;
	int c = 0;
	int i = 3;
	if (m == 1)
		return 1;
	else if (m == 2)
		return 2;
	else if (m >= 3)
	{
		for (i = 3; i <= m; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}
int main()
{
	int frog = 0;
	scanf("%d", &frog);
	printf("共有%d种跳法", result(frog));
	return 0;
}