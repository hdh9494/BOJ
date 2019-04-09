#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 50
using namespace std;
typedef pair<int, int> pii;

int N, M;

int sol_1 = 0;
int sol_2 = 0;
int sol_3 = 0;

int map[MAX][MAX];
bool visit[MAX][MAX];

// ���ϵ���
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

bool boundary_check(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

bool cmp(int a, int b)
{
	return a > b;
}


int bfs(int v1, int v2)
{
	int cnt = 1;
	queue <pii> q;
	q.push(make_pair(v1, v2));
	visit[v1][v2] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int bit = 1;

		for (int i = 0; i < 4; i++)
		{
			if (!(map[x][y] & bit))
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!boundary_check(nx, ny)) continue;
				
				if (!visit[nx][ny])
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
					cnt++;
				}
			}

			// 1 - �� , 2 - �� , 4 - �� , 8 - ��
			bit <<= 1;
		}
	}
	return cnt;
}

int main(void)
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				sol_2 = max(sol_2, bfs(i, j));
				sol_1++;
			}
		}
	}

	printf("%d\n", sol_1);
	printf("%d\n", sol_2);

	// �ϳ��� ���� �����Ͽ� ���� �� �ִ� ���� ���� ���� ũ��

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k <= 8; k <<= 1)
			{
				// �����ִ� ���� ã��
				if (map[i][j] & k)
				{
					memset(visit, 0, sizeof(visit));

					// ���� ����, bfs ����
					map[i][j] -= k;
					sol_3 = max(sol_3, bfs(i, j));

					// ��Ž�� ������ ���� bfs ������, ������ �����ߴ� ���� �ٽ� ����
					map[i][j] += k;

				}
			}
		}
	}
	printf("%d\n", sol_3);
	return 0;
	
}