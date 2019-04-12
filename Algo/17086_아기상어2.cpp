#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 51
using namespace std;

int sol;
int N, M;

int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };

bool boundary_chk(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

int bfs(int v1, int v2)
{
	int cnt = 0;
	queue <pair<int, int>> q;
	q.push(make_pair(v1, v2));
	visit[v1][v2] = 1;

	while (!q.empty())
	{
		int curSize = q.size();
		cnt++;
		for (int i = 0; i < curSize; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 8; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (!boundary_chk(nx, ny)) continue;
				
				if (map[nx][ny] == 0 && !visit[nx][ny])
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
				}

				else if (map[nx][ny] == 1 && !visit[nx][ny])
					return cnt;
			}
		}
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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				memset(visit, 0, sizeof(visit));
				sol = max(sol, bfs(i, j));
			}
		}
	}

	printf("%d\n", sol);
	return 0;
}