#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 50

using namespace std;
typedef pair<int, int> pii;

int N, L, R;
int sol;

int map[MAX][MAX];
int visit[MAX][MAX];

vector <pii> vc;
queue <pii> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool check_range(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < N)
		return true;
	return false;
}

bool check_subtraction(int x, int y, int nx ,int ny)
{
	int num = abs(map[x][y] - map[nx][ny]);

	if (L <= num && num <= R)
		return true;
	return false;
}


void bfs(int v1, int v2)
{
	vc.push_back(make_pair(v1, v2));
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

			if (check_range(nx, ny) && !visit[nx][ny]) {
				if (check_subtraction(x, y, nx, ny)) {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					vc.push_back(make_pair(nx, ny));
				}
			}
		}
	}
}

void calculate()
{
	int sum = 0;
	for (int i = 0; i < vc.size(); i++)
	{
		int x = vc[i].first;
		int y = vc[i].second;

		sum += map[x][y];
	}
	
	int val = sum / vc.size();
	
	for (int i = 0; i < vc.size(); i++)
	{
		int x = vc[i].first;
		int y = vc[i].second;

		map[x][y] = val;
	}
	
}


int main(void)
{
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	while (1)
	{
		int cnt = 0;
		sol++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j])
				{
					bfs(i, j);
					calculate();
					vc.clear();
					cnt++;
				}
			}
		}
		if (cnt == N * N)
			break;
		memset(visit, 0, sizeof(visit));
	}
	printf("%d\n", sol-1);
	return 0;
}