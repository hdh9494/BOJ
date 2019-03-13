#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>

using namespace std;

#define MAX 1001

int N, M, V;

int map[MAX][MAX];

int DFS_visit[MAX];
int BFS_visit[MAX];

void dfs(int v)
{
	printf("%d ", v);
	DFS_visit[v] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (map[v][i] && !DFS_visit[i])
			dfs(i);
	}
}

void bfs(int v)
{
	queue <int> q;
	q.push(v);
	BFS_visit[v] = 1;

	while (!q.empty())
	{
		int num = q.front();
		printf("%d ", num);
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (map[num][i] && !BFS_visit[i])
			{
				q.push(i);
				BFS_visit[i] = 1;
			}
		}
	}

}

int main(void)
{
	int v1, v2;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		map[v1][v2] = map[v2][v1] = 1;
	}

	dfs(V);
	printf("\n");
	bfs(V);
	return 0;
}