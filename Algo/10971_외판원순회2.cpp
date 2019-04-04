#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <memory.h>

#define MAX 15
using namespace std;

int N;
int start;
int sol = 0;

int value[MAX][MAX];
bool visit[MAX];

/*
void dfs(int v, int amount, int cnt)
{
	if (cnt == N) {
		int cost = value[v][start];
		sol = min(sol, amount + cost);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!visit[i] && value[v][i] != 0)
		{
			visit[i] = true;
			dfs(i, amount + value[v][i], cnt + 1);
			visit[i] = false;
		}
	}
}
*/

int dfs(int v, int amount, int cnt)
{
	if (!visit[v])
	{
		visit[v] = true;
		cnt++;

		for (int i = 0; i < N; i++)
		{
			// (i,i) 자기 자신으로 돌아가는 case를 처리.
			if (value[v][i] != 0)
				dfs(i, amount + value[v][i], cnt);
		}
		visit[v] = false;
	}

	if (cnt == N && start == v) {
		sol = (sol == 0) ? amount : min(sol, amount);
	}

}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &value[i][j]);
		}
	}


	for (int i = 0; i < N; i++) {
		start = i;
		dfs(i, 0, 0);
		memset(visit, 0, sizeof(visit));
	}

	printf("%d\n", sol);
	return 0;
}