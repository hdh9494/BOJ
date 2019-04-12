#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

#define MAX 17

using namespace std;

struct enemy {
	int x;
	int y;
	int dist;
};

int sol = 0;
int N, M, D;

int map[MAX][MAX];

bool Selected[MAX]; // 조합 구현시 필요

vector <int> bow;

void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

bool cmp(enemy A, enemy B)
{
	// 거리 오름차순 : v[0] -> 더 가까운 적
	if (A.dist <= B.dist) {

		// 거리가 같으면
		if (A.dist == B.dist) {

			// y 오름차순 : v[0] -> 더 왼쪽위치의 적
			if (A.y < B.y) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}


int kill_enemy()
{
	int temp[MAX][MAX];
	copy_map(temp, map);
	int cnt = 0;
	int loop = N;

	while (loop--)
	{
		// 궁수가 공격한 적군의 좌표 저장
		pair<int, int> Target[5];

		// 3명의 궁수를 각각 모두 고려
		for (int b = 0; b < bow.size(); b++) 
		{
			vector <enemy> v;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (temp[i][j] == 1)
					{
						// 적과 궁수의 거리 비교
						int dist = abs(N - i) + abs(bow[b] - j);

						// 거리가 D 이하이면 벡터 enemy에 저장
						if (dist <= D)
							v.push_back({ i,j,dist });
					}
				}
			}

			int Target_num = v.size();

			if (Target_num > 1)
			{
				// 궁수가 조건에 맞게 공격한 적의 정보를 sort해서 얻음 => v[0]
				sort(v.begin(), v.end(), cmp);
				Target[b].first = v[0].x;
				Target[b].second = v[0].y;
			}

			else if (Target_num == 1)
			{
				Target[b].first = v[0].x;
				Target[b].second = v[0].y;
			}
			
			// 공격할 적이 한명도 없을 때 !!!!!
			else
			{
				Target[b].first = -1;
				Target[b].second = -1;
			}

		}

		// Target된 적군을 제거하고 결과값++
		for (int k = 0; k < 3; k++)
		{
			
			int x = Target[k].first;
			int y = Target[k].second;

			if (temp[x][y] == 1)
			{
				temp[x][y] = 0;
				cnt++;
			}
		}

		// 적 위치 한칸씩 내리기
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				temp[i + 1][j] = temp[i][j];
			}
		}
		for (int i = 0; i < M; i++) temp[0][i] = 0;
	}

	return cnt;
}


void select_bow(int idx, int cnt)
{
	if (cnt == 3)
	{
		sol = max(sol, kill_enemy());
		return;
	}

	for (int i = idx; i < M; i++)
	{
		if (!Selected[i])
		{
			Selected[i] = true;
			bow.push_back(i);

			select_bow(i, cnt + 1);

			Selected[i] = false;
			bow.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	select_bow(0,0);
	printf("%d\n", sol);
	return 0;
}