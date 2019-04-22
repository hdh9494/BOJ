#pragma warning(disable : 4996)

#include <cstdio>

int arr[10001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}