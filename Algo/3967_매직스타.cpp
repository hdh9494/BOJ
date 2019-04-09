#pragma warning(disable : 4996)

#include <cstdio>
#include <stdlib.h>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

char map[5][9];
bool alphabet[13];
int x_cnt;

bool flag = true;

vector <pii> x_pos;

bool map_check()
{
	if ((map[1][1] - 'A') + (map[1][3] - 'A') + (map[1][5] - 'A') + (map[1][7] - 'A') != 22) return false;
	if ((map[3][1] - 'A') + (map[3][3] - 'A') + (map[3][5] - 'A') + (map[3][7] - 'A') != 22) return false;
	if ((map[0][4] - 'A') + (map[1][3] - 'A') + (map[2][2] - 'A') + (map[3][1] - 'A') != 22) return false;
	if ((map[0][4] - 'A') + (map[1][5] - 'A') + (map[2][6] - 'A') + (map[3][7] - 'A') != 22) return false;
	if ((map[4][4] - 'A') + (map[3][3] - 'A') + (map[2][2] - 'A') + (map[1][1] - 'A') != 22) return false;
	if ((map[4][4] - 'A') + (map[3][5] - 'A') + (map[2][6] - 'A') + (map[1][7] - 'A') != 22) return false;

	return true;
}

void dfs(int idx, int cnt)
{
	if (cnt == x_cnt)
	{
		if (map_check())
		{
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					printf("%c", map[i][j]);
				}
				printf("\n");
			}
			exit(1);
		}
		return;
	}

	for (int i = 0; i < 12; i++)
	{
		if (!alphabet[i])
		{
			alphabet[i] = true;
			
			// x칸에 A,B,C, .... ,L 입력
			map[x_pos[idx].first][x_pos[idx].second] = i + 'A';

			// 완탐
			dfs(idx + 1, cnt + 1);

			alphabet[i] = false;
			map[x_pos[idx].first][x_pos[idx].second] = 'x';
		}
	}
}

int main(void)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] != '.' && map[i][j] != 'x')
				// 알파벳 사용했는지 확인하는 배열
				alphabet[map[i][j] - 'A'] = 1;

			// x좌표 구하기
			else if (map[i][j] == 'x')
			{
				x_pos.push_back(make_pair(i, j));
				x_cnt++;
			}
		}
	}

	dfs(0, 0);
	return 0;
}

