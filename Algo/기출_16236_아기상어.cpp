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

int shark_size, shark_eat; // 상어가 먹은 갯수

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


		// 상어가 먹을 수 있는 물고기를 저장하는 candi
		SHARK candi;
		// candi의 x값은 지도에서 가장 큰 값으로 초기화 해야함
		// 그래야 맨 
		candi.x = 20, candi.time = -1;

		while (!q.empty())
		{
			SHARK cur = q.front();
			q.pop();
			
			// time이 -1 => 아직 갱신되지 않았다.
			// candi.time != -1 => 갱신되었다 => 물고기를 잡았다.
			// 가장 가까운 물고기를 잡았다.
			if (candi.time == -1 && candi.time < cur.time)
				break;

			// 물고기를 먹을 수 있음 => is_update 활성화
			if (map[cur.x][cur.y] < shark_size && map[cur.x][cur.y] != 0) {
				is_update = true;

				// x가 작은 값(위쪽)을 넣어주기 위해
				// x끼리 같으면, y가 작은 값(왼쪽)을 넣어주기 위해
				// candi에 cur을 넣어줌
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
					// next가 가야하는 위치에 상어의 크기보다 작거나 같아야함
					if (visit[next.x][next.y] == false && shark_size >= map[next.x][next.y])
					{
						visit[next.x][next.y] = true;
						q.push(next);
					}

				}
			}
			
		}


		// 물고기를 먹을 수 있었다.
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