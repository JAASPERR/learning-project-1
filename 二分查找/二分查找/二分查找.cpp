#define _CRT_SECURE_NO_WARNINGS 1//输入1234打印每一位
//二分查找，找到返回下表，找不到返回-1
#include<stdio.h>
int search(int arr[], int k,int sz)//只传递了数组首元素的地址，实际arr是一个指针
{
int left = 0;
int right = sz - 1;
//int right = sizeof(arr) / sizeof(arr[0]) - 1;元素个数不能在数组内部求
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
		printf("找不到相关项");
	else printf("找到了，下标是%d\n",ret);
	return 0;
}