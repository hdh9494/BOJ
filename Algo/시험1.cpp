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
				// ����û���� ��ǥ ���� & �湮ó��
				machine.push_back(make_pair(i, j));
				visit[i][j] = -1;
			}
		}
	}

	// S�� ȸ���ϴ� life ���� ����
	int life = S;

	// S�� ���� ����û���� ����
	while (life--)
	{
		// <<x��ǥ, y��ǥ>, ������ ��>
		vector <pair<pair<int, int>, int>> v;
		queue <pii> q;

		// ������ �����ϴ� ��ǥ ť�� ����
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
				
				// ����û���� ��ġ�� �ƴ϶��
				if (visit[nx][ny] != -1) {
					// ������ x,y,������ ���Ϳ� �ֱ�
					v.push_back(make_pair(make_pair(nx, ny), divide_value));
					cnt++;
				}
			}

			map[x][y] = map[x][y] - cnt * 
			


			

		}
	}
	

}