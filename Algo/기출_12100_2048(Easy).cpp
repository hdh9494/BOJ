#pragma warning(disable : 4996)

#include <cstdio>


#define MAX 20
using namespace std;

int N;
int sol;
int map[MAX][MAX];

//          аб ╩С ©Л го
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

void check()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sol < map[i][j])
				sol = map[i][j];
		}
	}
}

void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}


void reset_left(int x, int y)
{
	for (int i = 0; i < N - 1; i++) {
		if (map[x][i] == 0) {
			map[x][i] = map[x][i + 1];
			map[x][i + 1] = 0;
		}
	}
}

void reset_right(int x, int y)
{
	for (int i = N-1; i >= 0 ; i--) {
		if (map[x][i] == 0) {
			map[x][i] = map[x][i - 1];
			map[x][i - 1] = 0;
		}
	}
}

void reset_up(int x, int y)
{
	for (int i = 0; i < N - 1; i++) {
		if (map[i][y] == 0) {
			map[i][y] = map[i + 1][y];
			map[i + 1][y] = 0;
		}
	}
}

void reset_down(int x, int y)
{
	for (int i = N - 1; i >= 0; i--) {
		if (map[i][y] == 0) {
			map[i][y] = map[i - 1][y];
			map[i - 1][y] = 0;
		}
	}
}

void dfs(int cnt)
{	
	if (cnt == 5)
	{
		check();
		return;
	}

	int temp[MAX][MAX];
	copy_map(temp, map);

	for (int dir = 0; dir < 4; dir++)
	{
		// аб
		if (dir == 0)
		{
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == map[i][j + 1]) {
						map[i][j] *= 2;
						map[i][j + 1] = 0;
					}
				}
				reset_left(i, 0);
			}
			dfs(cnt + 1);
			copy_map(map, temp);
		}

		// ╩С
		else if (dir == 1)
		{
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[j][i] == map[j + 1][i]) {
						map[j][i] *= 2;
						map[j + 1][i] = 0;
					}
				}
				reset_up(0, i);
			}
			dfs(cnt + 1);
			copy_map(map, temp);
		}

		// ©Л
		else if (dir == 2)
		{
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j > 0; j--) {
					if (map[i][j - 1] == map[i][j]) {
						map[i][j] *= 2;
						map[i][j - 1] = 0;
					}
				}
				reset_right(i, 0);
			}
			dfs(cnt + 1);
			copy_map(map, temp);
		}

		// го
		else if (dir == 3)
		{
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j >= 0; j--) {
					if (map[j][i] == map[j - 1][i]) {
						map[j][i] *= 2;
						map[j - 1][i] = 0;
					}
				}
				reset_down(0, i);
			}
			dfs(cnt + 1);
			copy_map(map, temp);
		}
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

	dfs(0);
	printf("%d\n", sol);
	return 0;
}