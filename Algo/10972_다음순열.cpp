#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[10001];

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	int tmp[10001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		tmp[i] = arr[i];
	}

	sort(tmp, tmp + N, cmp);

	// 사전순으로 가장 마지막으로 오는 순열인지 확인
	bool chk = true;
	for (int i = 0; i < N; i++) {
		if (tmp[i] != arr[i])
		{
			chk = false;
			break;
		}
	}

	if (!chk)
	{
		next_permutation(arr, arr + N);
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
	}
	else
		printf("-1");

	return 0;

}