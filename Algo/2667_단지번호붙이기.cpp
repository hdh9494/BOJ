#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>

#define MAX 25
using namespace std;

int N;

int map[MAX][MAX];
int visit[MAX][MAX];

int total[MAX*MAX];
int idx = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int v1, int v2)
{
	int cnt = 1;
	queue <pair<int, int>> q;

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

			if (map[nx][ny] == 1 && visit[nx][ny] == 0)
			{
				if (0 <= nx && nx < N && 0 <= ny && ny < N)
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
					cnt++;
				}
			}
		}
	}

	total[idx++] = cnt;
	cnt = 1;
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0)
				bfs(i, j);
		}
	}

	printf("%d\n", idx);
	for (int i = 0; i < idx; i++)
		printf("%d\n", total[i]);

	return 0;
}