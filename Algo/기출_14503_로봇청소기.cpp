#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>

#define MAX 50
using namespace std;

int N, M;
int f_x, f_y#include <cstdio>

#define MAX 51
using namespace std;

int N, M;
int r, c, d;
int sol = 1;

int map[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

// 기저사례 return 잘 설정하기

void dfs(int x, int y, int dir)
{
	// 후진해서 벽을 만났을 때, return 
	if (map[x][y] == 1)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (dir == 0)
		{
			dir = 3;
			int ny = y - 1;
			if (map[x][ny] != 0) continue;
			map[x][ny] = 9;
			dfs(x, ny, dir);

			// 이부분에 return 이 없으면
			// 뒤로 돌아가서 for문 4번을 다 돈다
			return;
		}

		else if (dir == 1)
		{
			dir = 0;
			int nx = x - 1;
			if (map[nx][y] != 0) continue;
			map[nx][y] = 9;
			dfs(nx, y, dir);
			return;
		}

		else if (dir == 2)
		{
			dir = 1;
			int ny = y + 1;
			if (map[x][ny] != 0) continue;
			map[x][ny] = 9;
			dfs(x, ny, dir);
			return;
		}

		else if (dir == 3)
		{
			dir = 2;
			int nx = x + 1;
			if (map[nx][y] != 0) continue;
			map[nx][y] = 9;
			dfs(nx, y, dir);
			return;
		}
	}


	// 4방향이 모두 청소했거나, 방인 경우
	// 방향을 유지한채로 후진.
	if (dir == 0)
	{
		int nx = x + 1;
		dfs(nx, y, dir);
	}

	else if (dir == 1)
	{
		int ny = y - 1;
		dfs(x, ny, dir);
	}

	else if (dir == 2)
	{
		int nx = x - 1;
		dfs(nx, y, dir);
	}

	else if (dir == 3)
	{
		int ny = y + 1;
		dfs(x, ny, dir);
	}

}

int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}


	map[r][c] = 9;
	dfs(r, c, d);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 9)
				cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}