#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

/*
버블정렬 - 매번 연속된 두개 인덱스를 비교하여, 정한 기준의 값을 뒤로 넘겨 정렬
		   가장 비효율적이고 느린 정렬방법.
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

	printf("정렬 전\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	Bubble_sort(arr, len);

	printf("\n정렬 후\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}