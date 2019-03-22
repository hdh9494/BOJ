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
}// �����˻�


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
	if (!map[x][y]) return; // �� �κ� ������ ����.
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
}//��������

void down_block()
{
	for (int i = 0; i < W; i++)
	{
		for (int j = H - 1; j >= 1; j--)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				// map���� 0�̸� j�� ���� (j�� ��ĭ�� �ǹ�)
				if (map[j][i] != 0)
					break;

				// map���� 0�� �ƴϸ� k�� ���� (k�� ��ĭ�� ����(������) ĭ�� �ǹ�)
				if (map[k][i] != 0) {
					map[j][i] = map[k][i]; // ��ĭ�� ���� ����� ���� ĭ�� ���� ����
					map[k][i] = 0;
					break;
				}
			}
		}
	}
}//������ ��� ������ ����


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
}//�����˻�

void dfs(int cnt)
{
	int temp[MAX][MAX] = { 0, };
	copy_map(temp, map); //��ġ �߿�!!

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

		// ��ͷ� 
		dfs(0);
		printf("#%d %d\n", tc, sol);
	}
	return 0;
}