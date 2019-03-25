#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 20
using namespace std;

struct SHARK {
	int x, y, time;
};
SHARK shark;

int shark_size, shark_eat; // �� ���� ����

int N;

int map[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9){
				shark.x = i, shark.y = j, shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[i][j] = 0;
			}
		}
	}

	bool is_update = true;
	
	while (is_update) {
		
		is_update = false;

		bool visit[MAX][MAX] = { false, };
		queue<SHARK> q;
		visit[shark.x][shark.y] = true;
		q.push(shark);


		// �� ���� �� �ִ� ����⸦ �����ϴ� candi
		SHARK candi;
		// candi�� x���� �������� ���� ū ������ �ʱ�ȭ �ؾ���
		// �׷��� �� 
		candi.x = 20, candi.time = -1;

		while (!q.empty())
		{
			SHARK cur = q.front();
			q.pop();
			
			// time�� -1 => ���� ���ŵ��� �ʾҴ�.
			// candi.time != -1 => ���ŵǾ��� => ����⸦ ��Ҵ�.
			// ���� ����� ����⸦ ��Ҵ�.
			if (candi.time == -1 && candi.time < cur.time)
				break;

			// ����⸦ ���� �� ���� => is_update Ȱ��ȭ
			if (map[cur.x][cur.y] < shark_size && map[cur.x][cur.y] != 0) {
				is_update = true;

				// x�� ���� ��(����)�� �־��ֱ� ����
				// x���� ������, y�� ���� ��(����)�� �־��ֱ� ����
				// candi�� cur�� �־���
				if (candi.x > cur.x || (candi.x == cur.x && candi.y > cur.y))
					candi = cur;
			}

			for (int i = 0; i < 4; i++)
			{
				SHARK next;
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];
				next.time = cur.time + 1;

				if (0 <= next.x && next.x < N && 0 <= next.y && next.y < N)
				{
					// next�� �����ϴ� ��ġ�� ����� ũ�⺸�� �۰ų� ���ƾ���
					if (visit[next.x][next.y] == false && shark_size >= map[next.x][next.y])
					{
						visit[next.x][next.y] = true;
						q.push(next);
					}

				}
			}
			
		}


		// ����⸦ ���� �� �־���.
		if (is_update)
		{
			shark = candi;
			shark_eat++;
			if (shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}

			map[shark.x][shark.y] = 0;
		}
	}

	printf("%d\n", shark.time);
	return 0;

}