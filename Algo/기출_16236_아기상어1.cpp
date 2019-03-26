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
 

// return true 부분만 적용된다고 생각하면 됨.
bool cmp(fish a, fish b)
{
	if (a.time <= b.time) {				// 가장 짧은 시간
		if(a.time == b.time) {			// 시간이 같을 경우
			if (a.y <= b.y) {			// y값이 더 작은 순서
				if (a.y == b.y) {		// y값이 같다면
					if (a.x < b.x) {	// x값이 작은 순서로 정렬
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

	fish ex;	// 상어의 이전 상태를 저장

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
			
			// 아기 상어 시작 위치 0
			if (map[y][x] == 9) {
				map[y][x] = 0;

				// 아기 상어 초기화
				// 사이즈 2
				ex = { y,x,2,0,0 };
			}
		}
	}

	// 시간 정보
	int ans = 0;
	while (1)
	{
		// 물고기를 한번 먹을때마다 다시 초기화
		v.clear();
		memset(visit, 0, sizeof(visit));

		visit[ex.y][ex.x] = 1;
		q.push(ex);

		// map의 방문가능 한 모두 방문.
		// 크기가 작거나 || 0인 곳
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

				
				if (boundary_check(ny, nx)){  // N * N 바운드리 체크
					if (!visit[ny][nx]){      // 방문 여부 체크

						// 길(map : 0)이거나 || 사이즈가 같은 고기
						if (map[ny][nx] == 0 || map[ny][nx] == size)
						{
							visit[ny][nx] = true;
							// 시간 + 1
							q.push({ ny,nx,size,eat,time + 1 }); 
						}

						else if (map[ny][nx] < size)
						{
							visit[ny][nx] = true;
							// 잡아 먹은 물고기 수 + 1 , 시간 + 1
							v.push_back({ ny,nx,size,eat + 1,time + 1 }); 
						}
					}
				}
			}
		}

		// 만약 벡터가 비어있다면 잡아 먹을 수 있는 상어가 없음
		// break로 빠져나가서 종료
		if (v.size() == 0)
			break;


		// vector v : 먹을 수 있는 물고기들의 리스트
		// 이걸 문제의 조건(cmp)에 따라 정렬한다.
		sort(v.begin(), v.end(), cmp);



		// 먹은 상어의 숫자가 현재 사이즈와 같다면 사이즈 증가
		if (v[0].size == v[0].eat)
		{
			v[0].size++;
			v[0].eat = 0;
		}


		// 잡아먹은 상어는 map에서 지움
		map[v[0].y][v[0].x] = 0;

		
		// 이동 시간 저장
		ans += v[0].time;


		// 시간을 초기화하고 다시 큐에 넣어 이전 과정 반복
		ex = { v[0].y, v[0].x, v[0].size, v[0].eat, 0 };
	}

	printf("%d\n", ans);
	return 0;
}