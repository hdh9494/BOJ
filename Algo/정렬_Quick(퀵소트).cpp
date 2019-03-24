#pragma warning(disable : 4996)

#include <cstdio>
using namespace std;

int arr[10] = { 9,2,4,1,8,7,3,0,5,6 };

void swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void quick_sort(int arr[], int left, int right)
{
	int i, j;
	int temp;
	int pivot = arr[left];
	
	if (left < right)
	{
		i = left;
		j = right + 1;

		while (i <= j)
		{
			do
				i++;
			while (arr[i] < pivot);

			do
				j--;
			while (arr[j] > pivot);

			if (i < j) {          // 엇갈리지 않으면 두 요소를 swap
				swap(i,j);
			}
			else                  // 엇갈리면 중단
				break;
		}

		swap(j, left);

		quick_sort(arr, left, j - 1);
		quick_sort(arr, j + 1, right);
	}
}

int main(void)
{
	printf("정렬 전\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	quick_sort(arr, 0, 9);

	printf("\n정렬 후\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;

	// 장점 : 시간복잡도 O(nlogn)
	// 단점 : 
	
	// => pivot으로 어떤 수를 선언하는지 매우 중요. 대체로 빠른 속도를 가지고 있다. (분할정복)
}