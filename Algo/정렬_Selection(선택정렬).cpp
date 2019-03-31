#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

/*
�������� - ���� ��ġ�� �� ���� ã�� �����ϴ� ���.
           ���� ��ġ�� ����� ���� ũ�Ⱑ �۳�,ũ�Ŀ� ����
           �ּ� ���� ����(��������) OR �ִ� ���� ����(��������)�� ����
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

void selection_sort(int arr[], int len)
{
	for (int i = 0; i < len-1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] > arr[j])
				swap(arr,i, j);
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

	selection_sort(arr, len);

	printf("\n���� ��\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}