#pragma warning(disable : 4996)

#include <cstdio>

#define MAX 17
using namespace std;

int N;
int sol;

int map[MAX][MAX];
bool visit[MAX][MAX];

// 가로 세로 대각
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

int a = 0;
int b = 0;
int c = 0;

void dfs(int x, int y, int dir, int cnt)
{
	if (map[x][y] == 1 || x >= N || y >= N)
		return;

	if (dir == 2)
	{
		if (map[x][y] || map[x - 1][y] || map[x][y - 1])
			return;
	}

	if (x == N - 1 && y == N - 1)
	{
		sol++;
		return;
	}

	// dir = 0 : 가로방향 이라면
	if (dir == 0)
	{

		int nx = x + 1;
		int ny = y + 1;

		// 1. 가로 이동
		dfs(x, ny, 0, cnt + 1);

		// 2. 대각선 이동	
		dfs(nx, ny, 2, cnt + 1);
	}

	// dir = 1 : 세로방향 이라면
	else if (dir == 1)
	{
		int nx = x + 1;
		int ny = y + 1;

		// 1. 세로 이동
		dfs(nx, y, 1, cnt + 1);

		// 2. 대각선 이동
		dfs(nx, ny, 2, cnt + 1);
	}

	// dir = 2 : 대각선방향 이라면
	else if (dir == 2)
	{
		int nx = x + 1;
		int ny = y + 1;

		// 1. 가로 이동
		dfs(x, ny, 0, cnt + 1);

		// 2. 세로 이동
		dfs(nx, y, 1, cnt + 1);

		// 3. 대각선 이동
		dfs(nx, ny, 2, cnt + 1);
	}
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 1, 0, 0);

	printf("%d\n", sol);
	return 0;

}