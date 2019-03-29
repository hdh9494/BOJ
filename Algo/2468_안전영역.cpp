#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 100
using namespace std;
typedef pair<int, int> pii;

int N;
int sol = 0;

int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool boundary_check(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < N)
		return true;
	return false;
}

void bfs(int v1, int v2, int H)
{
	queue <pii> q;
	q.push(make_pair(v1, v2));
	visit[v1][v2] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (boundary_check(nx, ny))
			{
				if (!visit[nx][ny] && map[nx][ny] >= H)
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
				}
			}
		}
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

	for (int height = 1; height <= 100; height++)
	{
		int cnt = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && map[i][j] >= height) {
					bfs(i, j, height);
					cnt++;
				}
			}
		}
		sol = max(sol, cnt);
	}
	
	printf("%d\n", sol);
	return 0;
}