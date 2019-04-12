#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 21
using namespace std;

int N;
int map[MAX][MAX];
bool visit[MAX][MAX];

struct fish {
	int x;
	int y;
	int size;
	int eat;
	int time;
};

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector <fish> v;

bool boundary_chk(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < N)
		return true;
	return false;
}

bool cmp(fish a, fish b)
{
	if (a.time <= b.time) {
		if (a.time == b.time) {
			if (a.x <= b.x) {
				if (a.x == b.x) {
					if (a.y <= b.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int main(void)
{
	fish baby;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				baby = { i,j,2,0,0 };
			}
		}
	}

	int ans = 0;
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		v.clear();

		queue <fish> q;
		q.push(baby);
		visit[baby.x][baby.y] = 1;

		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int size = q.front().size;
			int eat = q.front().eat;
			int time = q.front().time;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (boundary_chk(nx, ny))
				{
					if (!visit[nx][ny])
					{
						if (map[nx][ny] == 0 || map[nx][ny] == size)
						{
							q.push({ nx,ny,size,eat,time + 1 });
							visit[nx][ny] = 1;
						}

						else if (map[nx][ny] < size)
						{
							v.push_back({ nx,ny,size,eat + 1,time + 1 });
							visit[nx][ny] = 1;
						}
					}
				}
			}
		}

		if (v.size() == 0)
			break;

		sort(v.begin(), v.end(), cmp);

		if (v[0].eat == v[0].size)
		{
			v[0].size++;
			v[0].eat = 0;
		}

		map[v[0].x][v[0].y] = 0;

		ans += v[0].time;

		baby = { v[0].x, v[0].y, v[0].size, v[0].eat, 0 };
	}
	printf("%d\n", ans);
	return 0;
}