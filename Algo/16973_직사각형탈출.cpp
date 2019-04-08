#pragma warning(disable : 4996)


#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

int N, M;
int H, W;
int Sr, Sc, Fr, Fc;

int map[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool boundary_chk(int x, int y)
{
	if (1 <= x && x <= N && 1 <= y && y <= M)
		return true;
	return false;
}

bool square_size_chk(int x, int y)
{
	if (x + H - 1 > N || y + W - 1 > M)
		return false;

	for (int i = y; i < y + W - 1; i++) {
		if (map[x + H - 1][i] || map[x][i])
			return false;
	}

	for (int j = x; j < x + H - 1; j++) {
		if (map[j][y + W - 1] || map[j][y])
			return false;
	}

	



	return true;
}

void bfs(int v1, int v2)
{
	memset(visit, -1, sizeof(visit));
	queue <pii> q;
	q.push(make_pair(v1, v2));
	visit[v1][v2] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!boundary_chk(nx, ny)) continue;
			if (map[nx][ny] == 0 && visit[nx][ny] == -1)
			{
				if (square_size_chk(nx, ny))
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = visit[x][y] + 1;
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	scanf("%d %d %d %d %d %d", &H, &W, &Sr, &Sc, &Fr, &Fc);
	bfs(Sr, Sc);
	printf("%d\n", visit[Fr][Fc]);
	return 0;

}