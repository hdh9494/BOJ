#pragma warning(disable : 4996)

#include <cstdio>
using namespace std;

int arr[10] = { 9,2,4,1,8,7,3,0,5,6 };

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

			if (i < j) {          // �������� ������ �� ��Ҹ� swap
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			else                  // �������� �ߴ�
				break;
		}

		temp = arr[j];
		arr[j] = arr[left];
		arr[left] = temp;

		quick_sort(arr, left, j - 1);
		quick_sort(arr, j + 1, right);
	}
}

int main(void)
{
	printf("���� ��\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	quick_sort(arr, 0, 9);

	printf("\n���� ��\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}