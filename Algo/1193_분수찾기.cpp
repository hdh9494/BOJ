#pragma warning(disable : 4996)

#include <cstdio>

int main(void)
{
	int n, cnt = 0;
	scanf("%d", &n);

	while (n > 0)
	{
		cnt++;
		n -= cnt;
	}

	if (cnt % 2 == 0)
		printf("%d/%d", cnt + n, 1 + (-n));
	else
		printf("%d/%d", 1 + (-n), cnt + n);

	return 0;
}