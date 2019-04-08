#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define MAX 101
using namespace std;

int N, L;
int sol;
int map[MAX][MAX];
bool visit[MAX][MAX];

void row_check(int x)
{
	memset(visit, 0, sizeof(visit));
	int cur_h = map[x][0];

	for (int y = 0; y < N; y++)
	{
		// 1. 현재 위치의 높이와 계속 같다면 진행
		if (cur_h == map[x][y]) {
			continue;
		}
			

		// 2. 현재 위치의 높이와의 차이가 2 이상인 경우 X
		else if (abs(cur_h - map[x][y]) > 1)
			return;

		// 3. 현재 위치보다 높은 곳을 만나고, 두 개의 높이 차이가 1일 경우 
		else if (cur_h < map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			
			// 길이 L의 경사로를 놓을 수 있다면
			if (0 <= y - L) {

				// 길이 L만큼 탐색을 돌면서, 일정한 높이인지 확인.
				for (int k = y - L; k < y; k++) {


					// 경사로 높이가 다르거나, 이미 놓은 경우에는
					// cnt하지 않고 return;
					if (map[x][k] != cur_h || visit[x][k] == 1)
						return;
					
					// 경사로를 놓을 수 있는 경우, 방문 체크
					visit[x][k] = 1;
				}

				cur_h = map[x][y];
			}
			// 경사로를 놓을 수 없다면, cnt하지않고 return
			else
				return;
		}

		// 4. 현재 위치보다 낮은 곳을 만나고, 두 개의 높이 차이가 1일 경우 
		else if (cur_h > map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			if (y - 1 + L < N) {

				for (int k = y; k < y + L; k++) {

					if (map[x][k] != cur_h - 1 || visit[x][k] == 1)
						return;
					visit[x][k] = 1;
				}

				cur_h = map[x][y];
			}
			else
				return;
		}
	}

	// 기저사례
	sol++;
}

void col_check(int y)
{
	memset(visit, 0, sizeof(visit));
	int cur_h = map[0][y];

	for (int x = 0; x < N; x++)
	{
		if (cur_h == map[x][y])
			continue;

		else if (abs(cur_h - map[x][y]) > 1)
			return;

		else if (cur_h < map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			if (0 <= x - L) {
				for (int k = x - L; k < x; k++) {

					if (map[k][y] != cur_h || visit[k][y] == 1)
						return;
					visit[k][y] = 1;
				}

				cur_h = map[x][y];
			}
			else
				return;
		}

		else if (cur_h > map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			if (x - 1 + L < N) {
				for (int k = x; k < x + L; k++) {
					if (map[k][y] != cur_h - 1 || visit[k][y] == 1)
						return;
					visit[k][y] = 1;
				}
				cur_h = map[x][y];
			}
			else
				return;
		}
	}

	sol++;
}

int main(void)
{
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		row_check(i);
		col_check(i);
	}

	printf("%d\n", sol);
	return 0;
}