#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <algorithm>

#define MAX 100

using namespace std;

int N, M, H;
int sol = 0;

int map[MAX][MAX][MAX];
int check[MAX][MAX][MAX];

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

// ���̷��� pos�� ������ ť
queue <pair<int, pair<int, int>>> q;

void check_size()
{
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (sol < check[k][i][j])
					sol = check[k][i][j];

			}
		}
	}
}

// virus ����(bfs)
void bfs_virus()
{
	while (!q.empty())
	{
		int x = q.front().second.first;
		int y = q.front().second.second;
		int z = q.front().first;

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (map[nz][nx][ny] == 0 && check[nz][nx][ny] == -1)
			{
				if (0 <= nx && nx < N && 0 <= ny && ny < M && 0 <= nz && nz < H)
				{
					q.push(make_pair(nz, make_pair(nx, ny)));
					check[nz][nx][ny] = check[z][x][y] + 1;
				}
			}
		}

	}
}

int main(void)
{
	scanf("%d %d %d", &M, &N, &H);
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[k][i][j]);

				// ���̷��� pos�� ť�� ����
				// ���̷����� ���� ��ƾ�� ����ϱ� ���� ���̷��� ��ġ�� check�� 0���� ǥ��
				if (map[k][i][j] == 1) {
					q.push(make_pair(k, make_pair(i, j)));
					check[k][i][j] = 0;
				}

				// ���̷��� �ƴ� ���� �湮���� ������ ǥ�� (-1)
				else
					check[k][i][j] = -1;
			}
		}
	}

	bfs_virus();
	check_size();

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[k][i][j] == 0 && check[k][i][j] == -1)
					sol = -1;

			}
		}
	}



	printf("%d\n", sol);
	return 0;
}