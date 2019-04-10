#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 16
using namespace std;
typedef pair<int, int> pii;

int N, M, D;
int map[MAX][MAX];
bool visit[MAX][MAX];

vector <pii> enemy;
vector <pii> bow;
vector <pii> vc;

struct s_enemy {
	int x;
	int y;
	int dist; // �ü����� �Ÿ�
};

bool cmp(s_enemy A, s_enemy B)
{
	// �Ÿ� ��������
	if (A.dist < B.dist)
		return true;

	// �Ÿ� ������, y ��������
	else if (A.dist == B.dist)
		return A.y < B.y;
	
	else
		return false;
}

void kill_enemy()
{
	// ������ 3���� �ü� ��ǥ��
	for (int i = 0; i < vc.size(); i++)
	{
		int bow_x = vc[i].first;
		int bow_y = vc[i].second;

		vector <s_enemy> v;

		// ���� ��ġ�� ��� ���Ͽ�
		for (int j = 0; j < enemy.size(); j++)
		{
			int enemy_x = enemy[i].first;
			int enemy_y = enemy[i].second;

			int dist = abs(bow_x - enemy_x) + abs(bow_y - enemy_y);

			// �ü��� ������ �� �ִ� ���� ��ġ�� ���� v�� ����.
			if (dist <=	D)
				v.push_back({ enemy_x, enemy_y, dist });
		}
		
		sort(v.begin(), v.end(), cmp);

		
	}
}

void dfs(int idx, int cnt)
{
	if (cnt == 3)
	{
		// �ü� 3���� ���� ���¿��� ���� ��� ����
		kill_enemy();
		return;
	}

	for (int i = idx; i < bow.size(); i++)
	{
		int bx = bow[idx].first;
		int by = bow[idx].second;

		if (!visit[bx][by])
		{
			vc.push_back(bow[cnt]);
			visit[bx][by] = 1;

			dfs(i + 1, cnt + 1);

			visit[bx][by] = 0;
			vc.pop_back();
		}
	}
}

int main(void)
{
	// map ������ �־��ֱ�
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			// �� ��ǥ ���Ϳ� ����
			if (map[i][j] == 1)
				enemy.push_back(make_pair(i, j));
		}
	}

	// N��° ���� �ü� ��ǥ�� ���� MC3 (��Ž)
	for (int k = 0; k < M; k++)
		bow.push_back(make_pair(N, k));

	dfs(0, 0);
}





/*
void down_map()
{
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
}
*/