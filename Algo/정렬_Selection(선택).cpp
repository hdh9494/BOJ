#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

/*
선택정렬 - 현재 위치에 들어갈 값을 찾아 정렬하는 방법.
           현재 위치에 저장될 값의 크기가 작냐,크냐에 따라
           최소 선택 정렬(오름차순) OR 최대 선택 정렬(내림차순)로 구분
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

	printf("정렬 전\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	selection_sort(arr, len);

	printf("\n정렬 후\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}