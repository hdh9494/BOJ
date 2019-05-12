#pragma warning(disable : 4996)

#include <cstdio>

int dp[20];

/* 1. 재귀로 구현
int fibo(int num)
{
	if (num == 0)
		return 0;
	
	if (num == 1)
		return 1;

	return fibo(num - 2) + fibo(num - 1);
}

int main(void)
{
	int n, sol;
	scanf("%d", &n);

	sol = fibo(n);
	printf("%d\n", sol);
	return 0;
}
*/

// 2. dp로 구현
int main(void)
{
	dp[0] = 0;
	dp[1] = 1;
	
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	printf("%d\n", dp[n]);
	return 0;
	
}