#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

/*
삽입정렬 - 현재 위치에서, 그 이하의 배열들을 비교하여  
		   자신이 들어갈 위치를 찾아, 그 위치에 삽입하는 정렬
*/

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void print_res(int tc, int arr[], int len)
{
	printf("%d번 루틴\n", tc);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}


void Insertion_sort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i;
		while (arr[j-1] > arr[j])
		{
			swap(arr, j - 1, j);
			j--;
		}
		print_res(i, arr, len);
	}
}


int main(void)
{
	int arr[10] = { 5,2,9,1,7,3,8,4,0,6 };
	int len = sizeof(arr) / sizeof(int);

	printf("정렬 전\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	Insertion_sort(arr, len);

	printf("\n정렬 후\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}