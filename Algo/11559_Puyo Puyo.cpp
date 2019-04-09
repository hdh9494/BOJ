#pragma warning(disable : 4996)

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;

int sol;

char map[12][6];
bool visit[12][6];

char color = ' ';
bool continues = false;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector <pii> block_pos;

bool boundary_check(int x, int y)
{
	if (0 <= x && x < 12 && 0 <= y && y < 6)
		return true;
	return false;
}

void block_down()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				
				// 바닥에서부터 빈칸이 아니면 계속 진행
				if (map[j][i] != '.')
					break;

				// j가 빈칸을 만났고, 그 빈칸에 넣어줄 '.'이 아닌 값을 찾음
				if (map[k][i] != '.')
				{
					// 빈칸인 j행에 '.'이 아닌 k행 값을 넣어줌
					map[j][i] = map[k][i];

					// k행의 데이터는 빈칸이 됨
					map[k][i] = '.';
					break;
				}
			}
		}
	}
}

void block_delete()
{
	for (int i = 0; i < block_pos.size(); i++)
	{
		int x = block_pos[i].first;
		int y = block_pos[i].second;

		map[x][y] = '.';
	}
}

void search(int v1, int v2)
{
	memset(visit, 0, sizeof(visit));
	int cnt = 1;
	queue <pii> q;
	q.push(make_pair(v1, v2));
	block_pos.push_back(make_pair(v1, v2));
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

			if (!boundary_check(nx, ny)) continue;

			if (map[nx][ny] == color && !visit[nx][ny])
			{
				q.push(make_pair(nx, ny));
				visit[nx][ny] = 1;
				block_pos.push_back(make_pair(nx, ny));
				cnt++;
			}
		}
	}

	// 해당 값이 4개 연속 연결되어 있다면
	if (cnt >= 4) {

		// 해당 블록들 제거
		block_delete();

		// 블록이 터지는 케이스가 존재한다면, 연쇄를 확인하기 위해 flag 변경
		continues = true;
	}

	// 블록 위치 벡터 초기화
	block_pos.clear();
}

int main(void)
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	while (1)
	{

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					color = map[i][j];
					search(i, j);
					color = ' ';
				}
			}
		}

		// 벽돌 제거 후, 빈 공간 내리기
		block_down();


		if (continues) {
			sol++;
			continues = false;
		}

		else
			break;
	}
	printf("%d\n", sol);
	return 0;
}