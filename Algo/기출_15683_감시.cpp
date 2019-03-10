#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 8

using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol = 99999999;

int map[MAX][MAX];

vector <int> cctv;
vector <pii> cctv_pos;

vector <pii> vc;

void map_copy(int(*a)[MAX], int(*b)[MAX])
{
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
			if (map[i][j] == 0)
				cnt++;
		}
	}

	sol = min(sol, cnt);
}

void spread(int x, int y, int dir)
{
	if (dir == 0)
	{
		int nx = x - 1;
		if (nx < 0) return;
		if (map[nx][y] == 6) return;
		map[nx][y] = 9;
		spread(nx, y, dir);
	}

	else if (dir == 1)
	{
		int ny = y + 1;
		if (ny >= M) return;
		if (map[x][ny] == 6) return;
		map[x][ny] = 9;
		spread(x, ny, dir);
	}

	else if (dir == 2)
	{
		int nx = x + 1;
		if (nx >= N) return;
		if (map[nx][y] == 6) return;
		map[nx][y] = 9;
		spread(nx, y, dir);
	}
	
	else
	{
		int ny = y - 1;
		if (ny < 0) return;
		if (map[x][ny] == 6) return;
		map[x][ny] = 9;
		spread(x, ny, dir);
	}
}

void dfs(int cnt)
{
	if (cnt == (int)cctv.size())
	{
		check();
		return;
	}

	int cctv_type = cctv[cnt];
	int x = cctv_pos[cnt].first;
	int y = cctv_pos[cnt].second;

	int temp[MAX][MAX];

	if (cctv_type == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			map_copy(temp, map);
			spread(x, y, i);
			dfs(cnt + 1);
			map_copy(map,temp);
		}
	}

	else if (cctv_type == 2)
	{
		
		for (int i = 0; i < 2; i++)
		{
			map_copy(temp, map);
			spread(x, y, i);
			spread(x, y, i + 2);
			dfs(cnt + 1);
			map_copy(map, temp);
		}
	}

	else if (cctv_type == 3)
	{
		
		for (int i = 0; i < 4; i++)
		{
			map_copy(temp, map);
			spread(x, y, i);
			spread(x, y, (i + 1) % 4);
			dfs(cnt + 1);
			map_copy(map, temp);
		}
	}

	else if (cctv_type == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			map_copy(temp, map);
			spread(x, y, i);
			spread(x, y, (i + 1) % 4);
			spread(x, y, (i + 2) % 4);
			dfs(cnt + 1);
			map_copy(map, temp);
		}
	}

	else
	{
		map_copy(temp, map);
		for (int i = 0; i < 4; i++)
			spread(x, y, i);
		dfs(cnt + 1);
		map_copy(map, temp);
	}
}


int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 6 && map[i][j] != 0)
			{
				cctv.push_back(map[i][j]);
				cctv_pos.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0);
	printf("%d\n", sol);
	return 0;
}