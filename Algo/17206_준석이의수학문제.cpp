#pragma warning(disable : 4996)

#include <cstdio>

int main(void)
{
	int arr[80001] = { 0, };
	for (int i = 1; i <= 80000; i++)
	{
		if (i % 3 == 0 || i % 7 == 0)
			arr[i] = arr[i - 1] + i;
		else
			arr[i] = arr[i - 1];
	}

	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}
	return 0;
}