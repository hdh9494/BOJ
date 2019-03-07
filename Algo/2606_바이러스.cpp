#pragma warning(disable : 4996)

#include <cstdio>

#define MAX_SIZE 100
using namespace std;

int N; // 컴퓨터 수
int M; // 간선의 수

int cnt = 0;

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE];

void dfs(int v)
{
	visit[v] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (map[v][i] == 1 && visit[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}
}


int main(void)
{
	int v1, v2;

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		map[v1][v2] = map[v2][v1] = 1;
	}

	dfs(1);
	printf("%d\n", cnt);
	return 0;
	
}