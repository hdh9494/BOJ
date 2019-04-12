#pragma warning(disable : 4996)

#include <cstdio>

#define MAX 17
using namespace std;

int N;
int sol;

int map[MAX][MAX];
bool visit[MAX][MAX];

// ���� ���� �밢
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

	// dir = 0 : ���ι��� �̶��
	if (dir == 0)
	{

		int nx = x + 1;
		int ny = y + 1;

		// 1. ���� �̵�
		dfs(x, ny, 0, cnt + 1);

		// 2. �밢�� �̵�	
		dfs(nx, ny, 2, cnt + 1);
	}

	// dir = 1 : ���ι��� �̶��
	else if (dir == 1)
	{
		int nx = x + 1;
		int ny = y + 1;

		// 1. ���� �̵�
		dfs(nx, y, 1, cnt + 1);

		// 2. �밢�� �̵�
		dfs(nx, ny, 2, cnt + 1);
	}

	// dir = 2 : �밢������ �̶��
	else if (dir == 2)
	{
		int nx = x + 1;
		int ny = y + 1;

		// 1. ���� �̵�
		dfs(x, ny, 0, cnt + 1);

		// 2. ���� �̵�
		dfs(nx, y, 1, cnt + 1);

		// 3. �밢�� �̵�
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