#define _CRT_SECURE_NO_WARNINGS 1//����1234��ӡÿһλ
//���ֲ��ң��ҵ������±��Ҳ�������-1
#include<stdio.h>
int search(int arr[], int k,int sz)//ֻ������������Ԫ�صĵ�ַ��ʵ��arr��һ��ָ��
{
int left = 0;
int right = sz - 1;
//int right = sizeof(arr) / sizeof(arr[0]) - 1;Ԫ�ظ��������������ڲ���
while (left <= right)
{
	int mid = (left + right) / 2;
	if (k == arr[mid])
	{
		return mid;
	}
	else if (k > arr[mid])
	{
		left = (mid + 1);
	}
	else
	{
		right = (mid - 1);
	}
}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	int sz = sizeof(arr) / sizeof(arr[1]);
	scanf("%d", &k);
	int ret = search(arr, k,sz);
	if (ret == -1)
		printf("�Ҳ��������");
	else printf("�ҵ��ˣ��±���%d\n",ret);
	return 0;
}