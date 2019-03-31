#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

/*
�������� - �Ź� ���ӵ� �ΰ� �ε����� ���Ͽ�, ���� ������ ���� �ڷ� �Ѱ� ����
		   ���� ��ȿ�����̰� ���� ���Ĺ��.
*/

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void print_res(int tc, int arr[], int len)
{
	printf("%d�� ��ƾ\n", tc);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}


void Bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr,j, j + 1);
		}
		print_res(i, arr, len);
	}
}


int main(void)
{
	int arr[10] = { 5,2,9,1,7,3,8,4,0,6 };
	int len = sizeof(arr) / sizeof(int);

	printf("���� ��\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	Bubble_sort(arr, len);

	printf("\n���� ��\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}