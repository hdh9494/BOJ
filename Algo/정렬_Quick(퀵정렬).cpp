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

			if (i < j) {          // �������� ������ �� ��Ҹ� swap
				swap(i,j);
			}
			else                  // �������� �ߴ�
				break;
		}

		swap(j, left);

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

	// ���� : �ð����⵵ O(nlogn)
	// ���� : 
	
	// => pivot���� � ���� �����ϴ��� �ſ� �߿�. ��ü�� ���� �ӵ��� ������ �ִ�. (��������)
}