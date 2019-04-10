#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 501
using namespace std;

int N, M;
int sol;

int map[MAX][MAX];
bool visit[MAX][MAX];
int sum = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void spread(int x, int y, int dir, int cnt);

bool boundary_check(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

void dfs1(int x, int y, int sum, int cnt)
{
	if (cnt == 4)
	{
		sol = max(sol, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!boundary_check(nx, ny)) continue;

		if (!visit[nx][ny])
		{
			visit[nx][ny] = 1;
			dfs1(nx, ny, sum + map[nx][ny], cnt + 1);
			visit[nx][ny] = 0;
		}
	}
}


void draw(int x, int y, int dir, int cnt)
{
	// 상
	if (dir == 0)
	{
		spread(x, y, dir, 0);
		int nx = x - 1, ny = y + 1;
		if (boundary_check(nx, ny))
			sum += map[nx][ny];
		else
			sum = 0;
	}

	// 우
	else if (dir == 1)
	{
		spread(x, y, dir, 0);
		int nx = x + 1, ny = y + 1;
		if (boundary_check(nx, ny))
			sum += map[nx][ny];
		else
			sum = 0;
	}

	// 하
	else if (dir == 2)
	{
		spread(x, y, dir, 0);
		int nx = x + 1, ny = y - 1;
		if (boundary_check(nx, ny))
			sum += map[nx][ny];
		else
			sum = 0;
	}

	// 좌
	else if (dir == 3)
	{
		spread(x, y, dir, 0);
		int nx = x - 1, ny = y - 1;
		if (boundary_check(nx, ny))
			sum += map[nx][ny];
		else
			sum = 0;
	}
}

void spread(int x, int y, int dir, int cnt)
{
	if (cnt == 2) return;

	if (dir == 0)
	{	
		int nx = x - 1;
		if (nx < 0) return;
		sum += map[nx][y];
		spread(nx, y, dir, cnt + 1);
	}

	else if (dir == 1)
	{
		int ny = y + 1;
		if (ny >= M) return;
		sum += map[x][ny];
		spread(x, ny, dir, cnt + 1);
	}

	else if (dir == 2)
	{
		int nx = x + 1;
		if (nx >= N) return;
		sum += map[nx][y];
		spread(nx, y, dir, cnt + 1);
	}

	else if (dir == 3)
	{
		int ny = y - 1;
		if (ny < 0) return;
		sum += map[x][ny];
		spread(x, ny, dir, cnt + 1);
	}
}

// ㅜ 모양 설계
void dfs2(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		sum = 0;
		draw(x, y, i, 0);
		sum += map[x][y];

		sol = max(sol, sum);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// ㅜ 모양 뺴고 모두 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j])
			{
				visit[i][j] = true;
				dfs1(i, j, map[i][j], 1);
				visit[i][j] = false;

				dfs2(i, j);
				
			}
			
		}
	}

	printf("%d\n", sol);
	return 0;
}