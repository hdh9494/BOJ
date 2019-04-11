#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int sol = 99999999;

int map[31][11];

int N, M, H;

bool check_ladder()
{
	for (int col = 1; col < N; col++) {
		int now_col = col;

		for (int row = 1; row <= H; row++) {

			if (map[row][now_col - 1])
				now_col--;

			else if (map[row][now_col])
				now_col++;
		}

		if (now_col != col)
			return false;
	}
	return true;
}

void put_ladder(int x, int y, int cnt)
{
	if (cnt > 3)
		return;

	if (check_ladder())
	{
		sol = min(sol, cnt);
		return;
	}

	for (int i = x; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (!map[i][j - 1] && !map[i][j] && !map[i][j + 1])
			{
				map[i][j] = 1;
				put_ladder(i, j, cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	int v1, v2;
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		map[v1][v2] = 1;
	}

	put_ladder(1, 1, 0);

	if (sol == 99999999) {
		printf("-1\n");
		return 0;
	}


	printf("%d\n", sol);
	return 0;

}