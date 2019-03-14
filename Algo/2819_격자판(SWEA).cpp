#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>

using namespace std;

int T;
int num;

int map[4][4];
int check[10000000];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int cal(int v)
{
	int multiplier = 1;
	for (int i = 1; i <= v; i++)
		multiplier *= 10;

	return multiplier;
}

void dfs(int v1, int v2, int cnt)
{
	if (cnt > 6)
	{
		check[num] = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = v1 + dx[i];
		int ny = v2 + dy[i];

		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4)
		{
			int square = cal(6 - cnt);
			num = num + (square * map[nx][ny]);

			int temp_num = num;
			dfs(nx, ny, cnt + 1);
			num = temp_num;
		}
	}


}

int main(void)
{
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int val = 0;
		memset(check, 0, sizeof(check));

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num = 1000000 * map[i][j];
				dfs(i, j, 1);
			}
		}


		for (int i = 0; i < 10000001; i++)
			if (check[i])
				val++;

		printf("#%d %d\n", tc, val);

	}
	return 0;

}