#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

#define MAX 8

using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol;

int map[MAX][MAX];
int visit[MAX][MAX];
int temp[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector <pii> blank;
vector <pii> virus;

void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void check()
{
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0)
				cnt++;
		}
	}

	sol = max(sol, cnt);
}


void bfs_spread_virus()
{
	// 바이러스를 퍼트리기 위해, 기존에 저장했던 virus 벡터로부터
	// virus_pos를 큐에 삽입.
	queue <pii> q;
	for (int i = 0; i < virus.size(); i++)
	{
		int vx = virus[i].first;
		int vy = virus[i].second;
		q.push(virus[i]);
		visit[vx][vy] = 1;
	}
		
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (temp[nx][ny] == 0 && visit[nx][ny] == 0)
			{
				if (0 <= nx && nx < N && 0 <= ny && ny < M)
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
					temp[nx][ny] = 2;
				}
			}
		}
	}
}

void dfs(vector <pii> vc, int pos)
{
	if (vc.size() == 3)
	{
		copy_map(temp, map);  // map 데이터를 유지하기 위해 temp에 copy
		bfs_spread_virus();   // virus 퍼트림
		check();			  // 퍼뜨린 후, 안전한 지역(0)을 cnt
		return;
	}

	// 빈칸에 벽을 3개 세울 떄 까지, dfs
	for (int i = pos; i < blank.size(); i++)
	{
		int bx = blank[i].first;
		int by = blank[i].second;

		vc.push_back(blank[i]);
		map[bx][by] = 1;

		dfs(vc, i + 1);

		vc.pop_back();
		map[bx][by] = 0;
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 0)
				blank.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}

	// 빈 칸(0)이 전체 n개 있는데 그 중 3곳에 벽을 세운다 (조합)
	// 즉, nC3 의 모든 경우의 수를 다 수행(완탐)
	vector <pii> vc;
	dfs(vc, 0);
	printf("%d\n", sol);
	return 0;
}