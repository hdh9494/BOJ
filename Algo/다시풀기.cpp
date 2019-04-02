#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 10
using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol = 99999999;

int map[MAX][MAX];

vector <int> cctv;
vector <pii> cctv_pos;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

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

bool boundary_check(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < M)
		return true;
	return false;
}

void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void spread(int x, int y, int dir)
{
	// ╩С
	if (dir == 0)
	{
		int nx = x - 1;
	
		if (nx < 0) return;
		if (map[nx][y] == 6) return;
		map[nx][y] = 9;
		spread(nx, y, dir);
	}

	// ©Л
	else if (dir == 1)
	{
		int ny = y + 1;
		if (ny >= M) return;
		if (map[x][ny] == 6) return;
		map[x][ny] = 9;
		spread(x, ny, dir);
	}
	
	// го
	else if (dir == 2)
	{
		int nx = x + 1;
		if (nx >= N) return;
		if (map[nx][y] == 6) return;
		map[nx][y] = 9;
		spread(nx, y, dir);
	}

	// аб
	else if (dir == 3)
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

	int temp[MAX][MAX];
	copy_map(temp, map);

	int cctv_type = cctv[cnt];
	int x = cctv_pos[cnt].first;
	int y = cctv_pos[cnt].second;

	if (cctv_type == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			spread(x, y, i);
			dfs(cnt + 1);
			copy_map(map, temp);
		}
	}
	
	else if (cctv_type == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			spread(x, y, i);
			spread(x, y, i + 2);
			dfs(cnt + 1);
			copy_map(map, temp);
		}
	}

	else if (cctv_type == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			spread(x, y, i);
			spread(x, y, (i + 1) % 4);
			dfs(cnt + 1);
			copy_map(map, temp);
		}
	}

	else if (cctv_type == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			spread(x, y, i);
			spread(x, y, (i + 1) % 4);
			spread(x, y, (i + 2) % 4);
			dfs(cnt + 1);
			copy_map(map, temp);
		}
	}

	else if (cctv_type == 5)
	{
		for (int i = 0; i < 4; i++)
			spread(x, y, i);
		dfs(cnt + 1);
		copy_map(map, temp);
	}
	
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6)
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