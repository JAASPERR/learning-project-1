#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���ڵ�n��̨�ף��������ɵڣ�n-1�����������ģ�Ҳ�����Ǵӣ�n-2��������������˴�������ۼ�
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
	printf("����%d������", result(frog));
	return 0;
}