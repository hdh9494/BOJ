#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#define MAX 100
using namespace std;

int N, M;

int map[MAX][MAX];
int check[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue <pair<int, int>> q;

void bfs_maze()
{
	check[0][0] = 1;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (map[nx][ny] == 1 && check[nx][ny] == 0)
			{
				if (0 <= nx && nx < N && 0 <= ny && ny < M)
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs_maze();
	printf("%d\n", check[N - 1][M - 1]);
	return 0;
}