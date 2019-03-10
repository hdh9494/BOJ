#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int map[4][4];
int num[10000000];
int sol;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt)
{
	if (cnt == 7)
	{
		sol++;
		return;
	}
		
	num[cnt] = map[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4)
		{
			dfs(nx, ny, cnt++);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, 0);
			}
		}

		printf("%d\n", sol);
		

	}
}

