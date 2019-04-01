#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>

#define MAX 50
using namespace std;

int N, M;
int r, c, d;

int map[MAX][MAX];

int dx[4] = {};
int dy[4] = { };

void dfs(int x, int y, int dir)
{
	if (map[x][y] == 1)
		return;

	map[x][y] = 9;

	for (int i = 0; i < 4; i++)
	{
		if (dir == 0)
		{
			dir = 3;
			int ny = y - 1;
			if (map[x][ny] == 0) {
				dfs(x, ny, dir);
				return;
			}

			else
				continue;
		}


		if (dir == 3)
		{
			dir = 2;
			int nx = x + 1;
			if (map[nx][y] == 0) {
				dfs(nx, y, dir);
				return;
			}
			else
				continue;
		}

		if (dir == 2)
		{
			dir = 1;
			int ny = y + 1;
			if (map[x][ny] == 0) {
				dfs(x, ny, dir);
				return;
			}
			else
				continue;
		}

		if (dir == 1)
		{
			dir = 0;
			int nx = x - 1;
			if (map[nx][y] == 0) {
				dfs(nx, y, dir);
				return;
			}
			else
				continue;
		}
	}
	// Å½»ö ¿Ï·á

	if (dir == 0)
	{
		int nx = x + 1;
		dfs(nx, y, dir);
	}

	if (dir == 3)
	{
		int ny = y + 1;
		dfs(x, ny, dir);
	}

	if (dir == 2)
	{
		int nx = x - 1;
		dfs(nx, y, dir);
	}

	if (dir == 1)
	{
		int ny = y - 1;
		dfs(x, ny, dir);
	}
	
}

int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	dfs(r, c, d);
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 9)
				cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
