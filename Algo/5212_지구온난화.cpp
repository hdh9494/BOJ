#pragma warning(disable : 4996)

#include <cstdio>
#define MAX 12
using namespace std;

int R, C;
char map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void check(int v1, int v2)
{
	int cnt = 0;
	int x = v1;
	int y = v2;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visit[nx][ny] == 0)
			cnt++;

	}

	if (cnt >= 3)
		map[x][y] = '.';
}

int main(void)
{
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf(" %c", &map[i][j]);

			// ¶¥Àº visit = 1 Ã³¸®
			if (map[i][j] == 'X')
				visit[i][j] = true;

		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(map[i][j] == 'X')
				check(i, j);
		}
	}

	int start_x = 0, start_y = 0, end_x = 0, end_y = 0;

	bool flag = false;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'X') {
				start_x = i;
				flag = true;
				break;
			}	
		}
		if (flag)
			break;
	}

	bool flag1 = false;
	for (int i = R; i > 0; i--) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'X') {
				end_x = i;
				flag1 = true;
				break;
			}
		}
		if (flag1)
			break;
	}

	bool flag2 = false;
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			if (map[j][i] == 'X') {
				start_y = i;
				flag2 = true;
				break;
			}
		}
		if (flag2)
			break;
	}

	bool flag3 = false;
	for (int i = C; i > 0; i--) {
		for (int j = 1; j <= R; j++) {
			if (map[j][i] == 'X') {
				end_y = i;
				flag3 = true;
				break;
			}
		}
		if (flag3)
			break;
	}

	for (int i = start_x; i <= end_x; i++) {
		for (int j = start_y; j <= end_y; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}