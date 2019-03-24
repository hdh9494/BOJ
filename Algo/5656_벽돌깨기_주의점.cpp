#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <memory.h>

#define MAX 15
#define INF 9999999
using namespace std;

int N, W, H;
int sol = INF;

int map[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void map_copy(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void check()
{
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] != 0)
				cnt++;
		}
	}
	sol = min(sol, cnt);
}

bool check_range(int x, int y)
{
	if (0 <= x && x < H && 0 <= y && y < W)
		return true;
	return false;
}

void boom(int x, int y)
{
	int range_size = map[x][y];
	map[x][y] = 0;
	for (int range = 0; range < range_size; range++)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i] * range;
			int ny = y + dy[i] * range;

			if (check_range(nx, ny) && map[nx][ny] != 0)
				boom(nx, ny);
		}
	}
}

void reset()
{
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				if (map[j][i] != 0)
					break;

				if (map[k][i] != 0)
				{
					map[j][i] = map[k][i];
					map[k][i] = 0;
					break;
				}
			}
		}
	}
}

void dfs(int cnt)
{
	if (N == cnt)
	{
		check();
		return;
	}

	// 현재 map을 copy해서 저장해두는 temp 배열 선언
	int temp[MAX][MAX];

	for (int i = 0; i < W; i++)
	{
		// map_copy위치가 중요.
		// 1. temp에 map을 카피하는 위치
		//  => boom이나 spread와 같이 map 데이터가 변경되는 함수 이전에 복사
		//  그래야지 return해서 돌아왔을 때, boom 이전의 데이터 값을 불러와서
		//  for문을 돌며 다음 y축에 구슬을 던졌을 때를 적용할 수 있음.
		map_copy(temp, map);
		int x = 0, y = i;
		
		// map[x][y] != 0 로 작성 => while문 안에 들어가는 조건 잘 생각하기
		while (check_range(x, y) && map[x][y] == 0)
			x++;
		boom(x, y);
		reset();
		dfs(cnt + 1);
		map_copy(map, temp);
	}
}


int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		memset(map, 0, sizeof(map));
		sol = INF;


		scanf("%d %d %d", &N, &W, &H);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		dfs(0);
		printf("#%d %d\n", tc, sol);
	}
	return 0;
}