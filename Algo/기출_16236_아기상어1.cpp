#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 20
using namespace std;

struct fish {
	int y;
	int x;
	int size;
	int eat;
	int time;
};

int N;
int map[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

queue <fish> q;
vector <fish> v;

bool boundary_check(int y, int x)
{
	if (0 <= y && y < N && 0 <= x && x < N)
		return true;
	return false;
}
 

// return true �κи� ����ȴٰ� �����ϸ� ��.
bool cmp(fish a, fish b)
{
	if (a.time <= b.time) {				// ���� ª�� �ð�
		if(a.time == b.time) {			// �ð��� ���� ���
			if (a.y <= b.y) {			// y���� �� ���� ����
				if (a.y == b.y) {		// y���� ���ٸ�
					if (a.x < b.x) {	// x���� ���� ������ ����
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
	scanf("%d", &N);

	fish ex;	// ����� ���� ���¸� ����

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
			
			// �Ʊ� ��� ���� ��ġ 0
			if (map[y][x] == 9) {
				map[y][x] = 0;

				// �Ʊ� ��� �ʱ�ȭ
				// ������ 2
				ex = { y,x,2,0,0 };
			}
		}
	}

	// �ð� ����
	int ans = 0;
	while (1)
	{
		// ����⸦ �ѹ� ���������� �ٽ� �ʱ�ȭ
		v.clear();
		memset(visit, 0, sizeof(visit));

		visit[ex.y][ex.x] = 1;
		q.push(ex);

		// map�� �湮���� �� ��� �湮.
		// ũ�Ⱑ �۰ų� || 0�� ��
		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			int size = q.front().size;
			int eat = q.front().eat;
			int time = q.front().time;
			q.pop();


			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				
				if (boundary_check(ny, nx)){  // N * N �ٿ�帮 üũ
					if (!visit[ny][nx]){      // �湮 ���� üũ

						// ��(map : 0)�̰ų� || ����� ���� ���
						if (map[ny][nx] == 0 || map[ny][nx] == size)
						{
							visit[ny][nx] = true;
							// �ð� + 1
							q.push({ ny,nx,size,eat,time + 1 }); 
						}

						else if (map[ny][nx] < size)
						{
							visit[ny][nx] = true;
							// ��� ���� ����� �� + 1 , �ð� + 1
							v.push_back({ ny,nx,size,eat + 1,time + 1 }); 
						}
					}
				}
			}
		}

		// ���� ���Ͱ� ����ִٸ� ��� ���� �� �ִ� �� ����
		// break�� ���������� ����
		if (v.size() == 0)
			break;


		// vector v : ���� �� �ִ� �������� ����Ʈ
		// �̰� ������ ����(cmp)�� ���� �����Ѵ�.
		sort(v.begin(), v.end(), cmp);



		// ���� ����� ���ڰ� ���� ������� ���ٸ� ������ ����
		if (v[0].size == v[0].eat)
		{
			v[0].size++;
			v[0].eat = 0;
		}


		// ��Ƹ��� ���� map���� ����
		map[v[0].y][v[0].x] = 0;

		
		// �̵� �ð� ����
		ans += v[0].time;


		// �ð��� �ʱ�ȭ�ϰ� �ٽ� ť�� �־� ���� ���� �ݺ�
		ex = { v[0].y, v[0].x, v[0].size, v[0].eat, 0 };
	}

	printf("%d\n", ans);
	return 0;
}