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

	// ���� map�� copy�ؼ� �����صδ� temp �迭 ����
	int temp[MAX][MAX];

	for (int i = 0; i < W; i++)
	{
		// map_copy��ġ�� �߿�.
		// 1. temp�� map�� ī���ϴ� ��ġ
		//  => boom�̳� spread�� ���� map �����Ͱ� ����Ǵ� �Լ� ������ ����
		//  �׷����� return�ؼ� ���ƿ��� ��, boom ������ ������ ���� �ҷ��ͼ�
		//  for���� ���� ���� y�࿡ ������ ������ ���� ������ �� ����.
		map_copy(temp, map);
		int x = 0, y = i;
		
		// map[x][y] != 0 �� �ۼ� => while�� �ȿ� ���� ���� �� �����ϱ�
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