#pragma warning(disable : 4996)

#include <cstdio>

#define MAX 1026
using namespace std;

int N;
long long map[MAX][MAX];

void fold_left(int cnt)
{
	if (cnt == 1)
		return;

	for (int L = 1, R = cnt; L <= cnt / 2, R > cnt / 2; L++, R--)
	{
		for (int k = 1; k <= N; k++)
		{
			map[k][L] += map[k][R];
		}
	}

	fold_left(cnt / 2);
}

void fold_up(int cnt)
{
	if (cnt == 1)
		return;

	for (int U = 1, D = cnt; U <= cnt / 2, D > cnt / 2; U++, D--)
		map[U][1] += map[D][1];

	fold_up(cnt / 2);
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	fold_left(N);
	fold_up(N);

	printf("%lld\n", map[1][1]);
	return 0;
}