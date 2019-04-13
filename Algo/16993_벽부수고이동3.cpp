#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define MAX 1000
using namespace std;
typedef pair<int, int> pii;

int N, M, K;

int map[MAX][MAX];
bool visit[MAX][MAX][11];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool boundary_chk(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

/*
struct point {
	int x;
	int y;
	int cnt;
	int break_cnt;
	bool night;
};
*/

void bfs(int v1, int v2)
{
	queue<pair<tuple<int, int, int>, pair<int, bool>>> q;
	q.push(make_pair(make_tuple(v1, v2, 1), make_pair(0, false)));
	visit[v1][v2][0] = true;

	while (!q.empty())
	{
		int x = get<0>(q.front().first);
		int y = get<1>(q.front().first);
		int cnt = get<2>(q.front().first);
		int break_cnt = q.front().second.first;
		bool night = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1) 
		{
			printf("%d\n", cnt);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (boundary_chk(nx, ny))
			{
				if (map[nx][ny] == 0)
				{
					if (!visit[nx][ny][break_cnt])
					{
						visit[nx][ny][break_cnt] = true;

						// 낮이면
						if (!night)
							q.push(make_pair(make_tuple(nx, ny, cnt + 1), make_pair(break_cnt, true)));
						else
							q.push(make_pair(make_tuple(nx, ny, cnt + 1), make_pair(break_cnt, false)));
					}
				}

				else if (map[nx][ny] == 1)
				{
					// 벽 부술수 있는 횟수가 남아있다면
					if (break_cnt < K)
					{
						if (!visit[nx][ny][break_cnt + 1])
						{
							// 낮이면
							if (!night)
							{
								q.push(make_pair(make_tuple(nx, ny, cnt + 1), make_pair(break_cnt + 1 , true)));
								visit[nx][ny][break_cnt + 1] = true;
							}


							// 밤이면 벽을 부술 수 없음
							else
								q.push(make_pair(make_tuple(x, y, cnt + 1), make_pair(break_cnt, false)));
						}
					}
				}
			}
		}
	}
	printf("-1\n");
	return;
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs(0, 0);

	return 0;

}