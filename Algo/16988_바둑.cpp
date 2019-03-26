#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 20
using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol;

int map[MAX][MAX];
bool visit[MAX][MAX];
int temp[MAX][MAX];

vector <pii> blank; // 0

queue <pii> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}


int bfs(int v1, int v2)
{
	int cnt = 1;
	// 상대방 돌 주변에 빈칸 있는지 확인
	bool near_blank = false;
	q.push(make_pair(v1, v2));
	visit[v1][v2] = 1;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				// bfs 돌면서 상대방돌(2) 갯수 cnt
				if (!visit[nx][ny] && temp[nx][ny] == 2)
				{
					cnt++;
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
				}
				
				// 상대방 돌 무리 근처에 0이 하나라도 있으면 잡을 수 없음
				if (temp[nx][ny] == 0)
					near_blank = true;
			}
		}
	}

	if (near_blank)
		return 0;
	else
		return cnt;
}

void dfs(vector <pii> vc, int pos)
{
	// 나의 바둑돌을 조합에 맞게 2곳에 두고 계산.
	if (vc.size() == 2)
	{
		int sum = 0;
		copy_map(temp, map);
		memset(visit, 0, sizeof(visit));

		// 상대방의 돌을 기준으로 bfs돌림
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visit[i][j] && temp[i][j] == 2)
					sum += bfs(i, j);
			}
		}
		
		sol = max(sol, sum);

		return;
	}


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
			
		}
	}

	vector <pii> vc;
	dfs(vc, 0);
	printf("%d\n", sol);
	return 0;
}