#pragma warning(disable : 4996)

#include <cstdio>
#define MAXLEN 10

int main(void)
{
	// item is 1 <= N <= 10
	int Data[MAXLEN] = { 8, 1, 3, 2, 9, 9, 7, 4, 5, 2 };
	int ret[MAXLEN] = { 0, };
	int count[MAXLEN];
	int idx = 0;

	// init count index
	for (int i = 0; i < MAXLEN; i++)
		count[i] = 0;

	// Data ���� count �迭�� idx�� ǥ��
	for (int i = 0; i < MAXLEN; i++)
		count[Data[i]]++;

	idx = MAXLEN - 1;

	for (int i = idx; i > 0; i--)
	{
		while (count[i] > 0)
		{
			ret[idx--] = i;
			count[i]--;
		}
	}

	printf("���� ��\n");
	for (int i = 0; i < MAXLEN; i++)
		printf("%d ", Data[i]);
	printf("\n");

	printf("���� ��\n");
	for (int i = 0; i < MAXLEN; i++)
		printf("%d ", ret[i]);
	printf("\n");

	return 0;

	// ���� - �ð����⵵ : O(n) ���� ����
	// ���� - ������ ���� 1,2,100000 �̸�, �޸� ���� �ɰ��ϰ�, �ش� ���� �����ϴ� �ð��� �����ɸ�

	// ���ڸ� �� ������ �� ����
}

