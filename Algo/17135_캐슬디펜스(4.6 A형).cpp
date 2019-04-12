#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 16
using namespace std;
typedef pair<int, int> pii;

int N, M, D, Answer, Temp_Answer;
int map[MAX][MAX];
bool visit[MAX][MAX];
bool Selected[MAX];

int temp[MAX][MAX];


vector <pii> enemy;
vector <pii> vc;

vector <int> bow_pos;

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

void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void map_down()
{
	for (int i = N; i >= 1; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
}

void kill_enemy()
{
	copy_map(temp, map);

	while (1)
	{

	}

	// N�� ���� �� ����
	while (N--) 
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
				if (dist <= D)
					v.push_back({ enemy_x, enemy_y, dist });
			}

			sort(v.begin(), v.end(), cmp);


		}
	}
}

void dfs(int idx, int cnt)
{
	// �ü� 3���� ���� ���¿��� ���� ��� ����
	if (cnt == 3)
	{
		Temp_Answer = 0;
		kill_enemy();
		Answer = max(Answer, Temp_Answer);
		return;
	}

	for (int i = idx; i < M ; i++)
	{
		
		if (!Selected[i])
		{
			bow_pos.push_back(i);
			Selected[i] = true;

			dfs(i, cnt + 1);

			Selected[i] = false;
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

	/*  �޸� ���� + �ð����� =>D

	// N��° ���� �ü� ��ǥ�� ���� MC3 (��Ž)
	for (int k = 0; k < M; k++)
		bow.push_back(make_pair(N, k));

	*/

	dfs(0, 0);
}



