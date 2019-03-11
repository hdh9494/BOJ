#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

#define MAX 8

using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol;

int map[MAX][MAX];
int visit[MAX][MAX];
int temp[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector <pii> blank;
vector <pii> virus;

void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void check()
{
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0)
				cnt++;
		}
	}

	sol = max(sol, cnt);
}


void bfs_spread_virus()
{
	// ���̷����� ��Ʈ���� ����, ������ �����ߴ� virus ���ͷκ���
	// virus_pos�� ť�� ����.
	queue <pii> q;
	for (int i = 0; i < virus.size(); i++)
	{
		int vx = virus[i].first;
		int vy = virus[i].second;
		q.push(virus[i]);
		visit[vx][vy] = 1;
	}
		
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (temp[nx][ny] == 0 && visit[nx][ny] == 0)
			{
				if (0 <= nx && nx < N && 0 <= ny && ny < M)
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
					temp[nx][ny] = 2;
				}
			}
		}
	}
}

void dfs(vector <pii> vc, int pos)
{
	if (vc.size() == 3)
	{
		copy_map(temp, map);  // map �����͸� �����ϱ� ���� temp�� copy
		bfs_spread_virus();   // virus ��Ʈ��
		check();			  // �۶߸� ��, ������ ����(0)�� cnt
		return;
	}

	// ��ĭ�� ���� 3�� ���� �� ����, dfs
	for (int i = pos; i < blank.size(); i++)
	{
		int bx = blank[i].first;
		int by = blank[i].second;

		vc.push_back(blank[i]);
		map[bx][by] = 1;

		dfs(vc, i + 1);

		vc.pop_back();
		map[bx][by] = 0;
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 0)
				blank.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}

	// �� ĭ(0)�� ��ü n�� �ִµ� �� �� 3���� ���� ����� (����)
	// ��, nC3 �� ��� ����� ���� �� ����(��Ž)
	vector <pii> vc;
	dfs(vc, 0);
	printf("%d\n", sol);
	return 0;
}