#pragma warning(disable : 4996)


#include <cstdio>
#include <algorithm>

#define MAX 15
#define INF 9999999

using namespace std;

int N, W, H;
int sol = INF;

int map[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool check_range(int x, int y)
{
	if (0 <= x && x < H && 0 <= y && y < W)
		return true;
	return false;
}// 범위검사


void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void boom(int x, int y)
{
	if (!map[x][y]) return; // 이 부분 놓히지 말자.
	int Range = map[x][y];
	map[x][y] = 0;

	for (int k = 0; k < Range; k++)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i] * k;
			int ny = y + dy[i] * k;

			if (check_range(nx, ny) && map[nx][ny] != 0)
				boom(nx, ny);
		}
	}
}//벽돌제거

void down_block()
{
	for (int i = 0; i < W; i++)
	{
		for (int j = H - 1; j >= 1; j--)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				// map값이 0이면 j값 선정 (j는 빈칸을 의미)
				if (map[j][i] != 0)
					break;

				// map값이 0이 아니면 k값 선정 (k는 빈칸에 넣을(내려질) 칸을 의미)
				if (map[k][i] != 0) {
					map[j][i] = map[k][i]; // 빈칸에 가장 가까운 위의 칸의 값을 넣음
					map[k][i] = 0;
					break;
				}
			}
		}
	}
}//제거한 블록 공백을 내림


void check_size()
{
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] != 0)
				cnt++;
		}
	}
	sol = min(sol, cnt);
}//범위검사

void dfs(int cnt)
{
	int temp[MAX][MAX] = { 0, };
	copy_map(temp, map); //위치 중요!!

	if (cnt == N)
	{
		check_size();
		return;
	}

	for (int i = 0; i < W; i++)
	{
		int x = 0, y = i;
		while (check_range(x, y) && map[x][y] == 0)
			x++;
		boom(x, y);
		down_block();

		dfs(cnt + 1);
		copy_map(map, temp);
	}

}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		sol = INF;
		scanf("%d %d %d", &N, &W, &H);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		// 재귀로 
		dfs(0);
		printf("#%d %d\n", tc, sol);
	}
	return 0;
}