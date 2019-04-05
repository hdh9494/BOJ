#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

#define MAX 5
using namespace std;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

// dir 4방향
int board[4][MAX][MAX][MAX];
int map[MAX][MAX][MAX];
int visit[MAX][MAX][MAX];

bool boundary_check(int x, int y, int z)
{
	if (0 <= x && x < MAX && 0 <= y && y < MAX && 0 <= z && z < MAX)
		return true;
	return false;
}

// 미로찾기
int bfs()
{
	if (map[0][0][0] == 0 || map[4][4][4] == 0)
		return 9999;

	memset(visit, -1, sizeof(visit));

	queue <pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	visit[0][0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (boundary_check(nx, ny, nz))
			{
				if (visit[nx][ny][nz] == -1 && map[nx][ny][nz])
				{
					if (nx == 4 && ny == 4 && nz == 4)
						return visit[x][y][z] + 1;
					visit[nx][ny][nz] = visit[x][y][z] + 1;
					q.push(make_pair(nx, make_pair(ny, nz)));
				}
			}
		}
	}
	return 9999;
}


int main(void)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				scanf("%d", &board[0][i][j][k]);

		//  (x,y) 우로 회전 (4-y,x)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				board[1][i][j][k] = board[0][i][4 - k][j];

		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				board[2][i][j][k] = board[1][i][4 - k][j];

		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				board[3][i][j][k] = board[2][i][4 - k][j];
	}

	int order[5] = { 0,1,2,3,4 }; // 판을 쌓는 순서
	int ans = 9999;
	do {
		for (int tmp = 0; tmp < 1024; tmp++) {
			int brute = tmp; // 5개의 판에 대해 dir을 정해주기 위한 변수
			for (int i = 0; i < 5; i++) {
				int dir = brute % 4; 
				brute /= 4; 
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						map[i][j][k] = board[dir][order[i]][j][k];
			}
			ans = min(ans, bfs());
		}
	} while (next_permutation(order, order + 5));

	if (ans == 9999)
		ans = -1;
	printf("%d\n", ans);
}