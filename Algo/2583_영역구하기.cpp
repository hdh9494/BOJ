#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 101
using namespace std;

int M, N, K;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int total[100];
int idx = 0;

bool boundary_chk(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

void bfs(int v1, int v2)
{
	int cnt = 1;
	queue <pair<int, int>> q;
	q.push(make_pair(v1, v2));
	visit[v1][v2] = true;

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
			if (map[nx][ny] == 0 && visit[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
				cnt++;
			}
		}
	}
	total[idx++] = cnt;
}

int main(void)
{
	
	scanf("%d %d %d", &N, &M, &K);
	
	for (int tc = 0; tc < K; tc++)
	{
		int v1, v2, v3, v4;
		scanf("%d %d %d %d", &v2, &v1, &v4, &v3);
		v3 = v3 - 1;
		v4 = v4 - 1;
		
		for (int i = v1; i <= v3; i++) {
			for (int j = v2; j <= v4; j++) {
				map[i][j] = 1;
			}
		}
	}

	int bfs_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				bfs(i, j);
				bfs_cnt++;
			}
		}
	}

	sort(total, total + bfs_cnt);

	printf("%d\n", bfs_cnt);
	for (int i = 0; i < bfs_cnt; i++)
		printf("%d ", total[i]);
	printf("\n");

	return 0;
}