#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

#define MAX 20

using namespace std;

struct fish {
	int x;
	int y;
	int size;
	int eat;
	int time;
};

int N;
int sol;

int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue <fish> q;
vector <fish> vc;

bool cmp(fish a, fish b)
{
	if (a.time <= b.time) {
		if (a.time == b.time) {
			if (a.x <= b.x) {
				if (a.x == b.x) {
					if (a.y < b.y) {
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

bool boundary_check(int x, int y)
{
	if (0 <= x && x < N && 0 <= y && y < N)
		return true;
	return false;
}

int main(void)
{
	fish SHARK;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				SHARK.x = i, SHARK.y = j, SHARK.size = 2;
				SHARK.eat = 0, SHARK.time = 0;
			}
		}
	}

	while (1)
	{
		memset(visit, 0, sizeof(visit));

		q.push(SHARK);
		visit[SHARK.x][SHARK.y] = 1;

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


				if (boundary_check(nx, ny)) {
					if (!visit[nx][ny]) {
						if (map[nx][ny] == 0 || size == map[nx][ny])
						{
							q.push({ nx,ny,size,eat,time + 1 });
							visit[nx][ny] = 1;
						}
						else if (size > map[nx][ny])
						{
							vc.push_back({ nx,ny,size,eat + 1,time + 1 });
							visit[nx][ny] = 1;
						}
					}
				}				
			}

		}

	//	if (vc.size()) ´Â ¿¡·¯
		if (vc.size() == 0)
			break;


		sort(vc.begin(), vc.end(), cmp);

		

		if (vc[0].size == vc[0].eat)
		{
			vc[0].size += 1;
			vc[0].eat = 0;
		}

		sol += vc[0].time;

		map[vc[0].x][vc[0].y] = 0;
		SHARK = { vc[0].x, vc[0].y , vc[0].size , vc[0].eat , 0 };
	}
	printf("%d\n", sol);
	return 0;
}
