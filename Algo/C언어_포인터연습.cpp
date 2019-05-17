#pragma warning(disable : 4996)

#include <stdio.h>

int main(void)
{
	printf("������ ������ ���� & ����\n\n");
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int * ptr = arr;

	// 1. *�� ���� �ش� �ּҿ� �ִ� �����Ϳ� �ٷ� ����.
	//    ��, �ּҰ��� ptr�� ��ȭ�� X
	*(ptr + 1) = 20;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 2. �ּҰ��� ptr�� +2�� �����ν� 3��° �Ķ���͸� ����Ű�� �ּҰ����� ����.
	ptr += 2;
	*ptr = 30;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 3. �ּҰ� ���� ++ �� ��, *�� ���� �����Ͽ� �� ����
	*(++ptr) = 40;
	//*++ptr = 40;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 4. *�� ���� ptr�� ���� �����ϰ� ++ptr ������ ����
	++(*ptr);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 5. *�� ���� ptr�� ���� �����Ͽ� �� ���� �� / �ּҰ� ptr++
	*ptr++ = 44;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 5-1. ptr++ Ȯ��
	*ptr++ = 50;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	
	printf("\n**�����͹迭 vs �迭������**\n\n");
	// **�����͹迭 vs �迭������**

	// 1. ������ �迭 - �������� �ּҸ� ��� �迭

	// 2. �迭 ������ - �迭�� ����Ű�� �����͸� �ǹ�.
	
	int len = 0;
	
	int a = 10;
	int b = 20;
	int c = 30;



	// 1. ������ �迭�� ����
	int *ptrArr[3] = { &a, &b, &c };

	// 2. �迭 �������� ����
	int arr1[2][3] = { 1,2,3,4,5,6 };
	int(*arrPtr)[3] = arr1;


	// ������ �迭�� Ȱ��
	printf("������ �迭�� Ȱ��\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", *ptrArr[i]);
	printf("\n\n");


	// �迭 �������� Ȱ��
	printf("�迭 �������� Ȱ��\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arrPtr[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}