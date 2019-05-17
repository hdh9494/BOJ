#pragma warning(disable : 4996)

#include <cstdio>

int main(void)
{
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

}