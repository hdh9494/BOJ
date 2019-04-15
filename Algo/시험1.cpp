#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

#define MAX 41
using namespace std;
typedef pair<int, int> pii;

int W, H, S;

int map[MAX][MAX];
bool visit[MAX][MAX];

vector <pii> machine;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool boundary_chk(int x, int y)
{
	if (0 <= x && x < H && 0 <= y && y < W)
		return true;
	return false;
}

int main(void)
{
	scanf("%d %d %d", &H, &W, &S);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == -1)
			{
				// 공기청정기 좌표 설정 & 방문처리
				machine.push_back(make_pair(i, j));
				visit[i][j] = -1;
			}
		}
	}

	// S번 회전하는 life 변수 선언
	int life = S;

	// S번 동안 공기청정기 가동
	while (life--)
	{
		// <<x좌표, y좌표>, 퍼지는 값>
		vector <pair<pair<int, int>, int>> v;
		queue <pii> q;

		// 먼지가 존재하는 좌표 큐에 삽입
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] != -1 && map[i][j] != 0)
					q.push(make_pair(i, j));
			}
		}

		
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			int cnt = 0;
			int divide_value = map[x][y] / 5;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];


				if (!boundary_chk(nx, ny)) continue;
				
				// 공기청정기 위치가 아니라면
				if (visit[nx][ny] != -1) {
					// 퍼지는 x,y,먼지값 벡터에 넣기
					v.push_back(make_pair(make_pair(nx, ny), divide_value));
					cnt++;
				}
			}

			map[x][y] = map[x][y] - cnt * 
			


			

		}
	}
	

}