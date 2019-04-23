#pragma warning(disable : 4996)

#include <cstdio>

int N, M;

// 에라토스테네스의 체
// 1. 2부터 소수를 구하고자 하는 구간의 모든 수를 나열한다
// 2. 자기 자신을 제외한 2의 배수를 모두 지운다.
// 3. 자기 자신을 제외한 3의 배수를 모두 지운다.
// 4. 자기 자신을 제외한 5의 배수를 모두 지운다.
// 5. 자기 자신을 제외한 7의 배수를 모두 지운다.
// 위의 과정을 반복하면 구하는 구간의 모든 소수가 남는다.
int main(void)
{
	bool num[1000001] = { false };
	scanf("%d %d", &N, &M);

	num[1] = true;

	for (int i = 2; (i*i) <= 1000000; i++) {
		if (!num[i]) {
			for (int j = i + i; j <= 1000000; j += i)
				num[j] = true;
		}
	}

	for (int i = N; i <= M; i++)
		if (!num[i])
			printf("%d\n", i);

	return 0;

}

/* 일반 소수 구하기
bool isSosu(int num)
{
	if (num == 1)
		return false;

	int cnt = 0;
	for (int i = 1; i <= num; i++) {
		if (num%i == 0)
			cnt++;

		if (cnt > 2)
			return false;
	}

	if (cnt == 2)
		return true;
}


int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = N; i <= M; i++) 
		if (isSosu(i))
			printf("%d\n", i);
	
	return 0;
}
*/