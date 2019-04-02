#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[10001];

int main(void)
{
	int tmp[10001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		tmp[i] = arr[i];
	}

	sort(tmp, tmp + N);

	// 사전순으로 가장 처음오는 순열인 경우인지 확인
	bool chk = true;
	for (int i = 0; i < N; i++) {
		if (tmp[i] != arr[i])
		{
			chk = true;
			break;
		}
	}

	if (!chk)
	{
		prev_permutation(arr, arr + N);
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
	}
	else
		printf("-1");

	return 0;

}