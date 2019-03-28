#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>

#define MAX 50
using namespace std;

int N, M;
int f_x, f_y, f_dir;

int map[MAX][MAX];
int visit[MAX][MAX];

void dfs(int x, int y, int dir)
{
	if (map[x][y] == 1)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (dir == 0)
		{
			dir = 3;
			int ny = y - 1;
			if (!map[x][ny]) {
				map[x][ny] = 9;
				dfs(x, ny, dir);
				return;
			}
			else
				continue;

		}

		else if (dir == 1)
		{
			dir = 0;
			int nx = x - 1;
			if (!map[nx][y]) {
				map[nx][y] = 9;
				dfs(nx, y, dir);
				return;
			}
			else
				continue;

		}

		else if (dir == 2)
		{
			dir = 1;
			int ny = y + 1;
			if (!map[x][ny]) {
				map[x][ny] = 9;
				dfs(x, ny, dir);
				return;
			}
			else
				continue;

		}

		else if (dir == 3)
		{
			dir = 2;
			int nx = x + 1;
			if (!map[nx][y]) {
				map[nx][y] = 9;
				dfs(nx, y, dir);
				return;
			}
			else
				continue;
		}
	}
	
	if (dir == 0)
	{
		int nx = x + 1;
		dfs(nx, y, dir);
	}

	else if (dir == 1)
	{
		int ny = y - 1;
		dfs(x, ny, dir);
	}

	else if (dir == 2)
	{
		int nx = x - 1;
		dfs(nx, y, dir);
	}

	else if (dir == 3)
	{
		int ny = y + 1;
		dfs(x, ny, dir);
	}
	

}

int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &f_x, &f_y, &f_dir);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	map[f_x][f_y] = 9;
	dfs(f_x, f_y, f_dir);

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