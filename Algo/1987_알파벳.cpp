#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

#define MAX 21
using namespace std;

int N, M;
int sol;

char map[MAX][MAX];
bool check[100];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool boundary_check(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < M)
		return false;
	return true;
}

void dfs(int x, int y, int cnt)
{
	sol = max(sol, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (boundary_check(nx, ny)) continue;
		if (!check[map[nx][ny]]) {
			check[map[nx][ny]] = true;
			dfs(nx, ny, cnt + 1);
			check[map[nx][ny]] = false;
		}
	}
} 

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	check[map[0][0]] = true;
	dfs(0, 0, 1);

	printf("%d\n", sol);
	return 0;

	
}