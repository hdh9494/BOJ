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

	// Data 값을 count 배열의 idx로 표현
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

	printf("정렬 전\n");
	for (int i = 0; i < MAXLEN; i++)
		printf("%d ", Data[i]);
	printf("\n");

	printf("정렬 후\n");
	for (int i = 0; i < MAXLEN; i++)
		printf("%d ", ret[i]);
	printf("\n");

	return 0;

	// 장점 - 시간복잡도 : O(n) 까지 가능
	// 단점 - 데이터 값이 1,2,100000 이면, 메모리 낭비도 심각하고, 해당 값에 접근하는 시간도 오래걸림

	// 한자리 수 정렬할 때 좋음
}

