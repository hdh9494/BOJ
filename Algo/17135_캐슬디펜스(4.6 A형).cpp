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

bool Selected[MAX]; // ���� ������ �ʿ�

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
	// �Ÿ� �������� : v[0] -> �� ����� ��
	if (A.dist <= B.dist) {

		// �Ÿ��� ������
		if (A.dist == B.dist) {

			// y �������� : v[0] -> �� ������ġ�� ��
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
		// �ü��� ������ ������ ��ǥ ����
		pair<int, int> Target[5];

		// 3���� �ü��� ���� ��� ���
		for (int b = 0; b < bow.size(); b++) 
		{
			vector <enemy> v;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (temp[i][j] == 1)
					{
						// ���� �ü��� �Ÿ� ��
						int dist = abs(N - i) + abs(bow[b] - j);

						// �Ÿ��� D �����̸� ���� enemy�� ����
						if (dist <= D)
							v.push_back({ i,j,dist });
					}
				}
			}

			int Target_num = v.size();

			if (Target_num > 1)
			{
				// �ü��� ���ǿ� �°� ������ ���� ������ sort�ؼ� ���� => v[0]
				sort(v.begin(), v.end(), cmp);
				Target[b].first = v[0].x;
				Target[b].second = v[0].y;
			}

			else if (Target_num == 1)
			{
				Target[b].first = v[0].x;
				Target[b].second = v[0].y;
			}
			
			// ������ ���� �Ѹ� ���� �� !!!!!
			else
			{
				Target[b].first = -1;
				Target[b].second = -1;
			}

		}

		// Target�� ������ �����ϰ� �����++
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

		// �� ��ġ ��ĭ�� ������
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