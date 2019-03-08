#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 100

using namespace std;
typedef pair<int, int> pii;

int N;
int sol = 9999999;

int map[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int cnt)
{
	// visit 초기화
	memset(visit, 0, sizeof(visit));

	// num번째 섬의 모든 pos를 queue에 push
	queue <pii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == cnt) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
			}
		}
	}
	
	int dist = 0;
	while (!q.empty())
	{
		// num번째 섬의 바깥부분으로 1칸씩 늘려나가면서 dist++
		int curSize = q.size();
		for (int i = 0; i < curSize; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && nx < N && 0 <= ny && ny < N)
				{
					if (map[nx][ny] != cnt && map[nx][ny] != 0)
						return dist;
					else if (map[nx][ny] == 0 && visit[nx][ny] == 0)
					{
						q.push(make_pair(nx, ny));
						visit[nx][ny] = 1;
					}
				}
			}
		}
		dist++;
	}
}


void dfs(int x, int y, int num)
{
	map[x][y] = num;
	visit[x][y] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == 1 && visit[nx][ny] == 0)
			if (0 <= nx && nx < N && 0 <= ny && ny < N)
				dfs(nx, ny, num);
	}
	
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int color = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0)
				// 땅을 구분하기 위해 다른 숫자로 나눔.
				dfs(i, j, color++);
		}
	}

	for (int i = 1; i < color; i++) {
		sol = min(sol,bfs(i));
	}

	printf("%d\n", sol);
	return 0;
}