#pragma warning(disable : 4996)

#include <cstdio>

#define MAX 100

using namespace std;

int N;

int map[MAX][MAX];
long dp[MAX][MAX];


int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 || (i==N-1) && (j==N-1))
				continue;

			int right = j + map[i][j];
			int down = i + map[i][j];

			if (right < N)
				dp[i][right] += dp[i][j];
			if (down < N)
				dp[down][j] += dp[i][j];
		}
	}

	printf("%ld\n", dp[N - 1][N - 1]);
	return 0;
	
}

