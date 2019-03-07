#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>

#define MAX 1001

using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol = -1;

int map[MAX][MAX];
int check[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue <pii> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (map[nx][ny] == 0 && check[nx][ny] == -1)
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
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				check[i][j] = 0;
			}
			else
				check[i][j] = -1;
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (sol < check[i][j])
				sol = check[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && check[i][j] == -1)
				sol = -1;
		}
	}

	printf("%d\n", sol);
	return 0;
}