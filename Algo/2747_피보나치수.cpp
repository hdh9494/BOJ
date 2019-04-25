#pragma warning(disable : 4996)

#include <cstdio>
/* TLE(Time Limit Exceed)
int Fibo(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return Fibo(n - 2) + Fibo(n - 1);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	printf("%d\n", Fibo(N));
	return 0;
}
*/
int main(void)
{
	int N;
	scanf("%d", &N);

	int A[1212];

	A[0] = 0;
	A[1] = 1;

	for (int i = 2; i <= N; i++) 
		A[i] = A[i - 1] + A[i - 2];

	printf("%d", A[N]);
	return 0;
}