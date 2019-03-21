#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>

#define MAX 301

using namespace std;

typedef pair<int, int> pii;

int N;

int map[MAX][MAX];
int visit[MAX][MAX];

int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };

queue <pii> q;


bool promising(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(0<=nx && ny<N && 0<=ny && ny<N)
			if (map[nx][ny] == '*')
				return false;
	}
	return true;
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (map[nx][ny] == '.' && visit[nx][ny] == 0)
				{
					// 방문은 모두 체크해주고
					visit[nx][ny] = 1;

					// 8방면에 지뢰 없는 좌표만 큐에 삽입
					if(promising(nx,ny))
						q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int cnt = 0;
		memset(visit, 0, sizeof(visit));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &map[i][j]);
			}
		}

		// 주변에 지뢰가 1개도 없는 유망한 좌표 먼저 확인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == '.' && visit[i][j] == 0 && promising(i, j))
				{
					q.push(make_pair(i, j));
					cnt++;
					visit[i][j] = 1;
					bfs();
				}
			}
		}

		// 남은 지뢰들 visit 처리해주면서 cnt
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == '.' && visit[i][j] == 0)
					cnt++;
			}
		}
		
		printf("#%d %d\n", tc, cnt);
	}
	return 0;
}