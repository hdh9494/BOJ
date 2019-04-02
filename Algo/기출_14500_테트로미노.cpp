#pragma warning(disable : 4996)

#include <cstdio>

#define MAX 501
using namespace std;

int N, M;

int map[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt)
{
	if (cnt == 4)
	{
		check();
		return;
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
			dfs(i, j, 1, );
		}
	}

	
}