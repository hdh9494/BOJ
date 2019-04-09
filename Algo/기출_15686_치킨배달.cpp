#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 51
#define INF 9999999
using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol = INF;

int map[MAX][MAX];
bool visit[MAX][MAX];

bool check[MAX];

// ���� ġŲ�� ��ǥ�� �ޱ� ���� vector ����
vector <pii> house;
vector <pii> chicken;

void dfs(vector <pii> vc, int idx, int cnt)
{
	// M���� ġŲ���� ����ٸ�
	if (cnt == M)
	{
		int total = 0;
		// ��� ���� M���� ġŲ������ �ּ� �Ÿ��� ����
		for (int i = 0; i < house.size(); i++)
		{
			int hx = house[i].first;
			int hy = house[i].second;

			int minVal = INF;
			for (int j = 0; j < vc.size(); j++)
			{
				int cx = vc[j].first;
				int cy = vc[j].second;

				minVal = min(minVal, abs(hx - cx) + abs(hy - cy));
			}

			total += minVal;
		}
		sol = min(sol, total);
	}

	// ��� ġŲ���� �߿��� M���� �����ϴ� (����) ����
	for (int i = idx; i < chicken.size(); i++)
	{
		if (!check[i])
		{
			vc.push_back(chicken[i]);
			check[i] = true;

			dfs(vc, i, cnt + 1);

			check[i] = false;
			vc.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			// ���� ��ǥ �ޱ�
			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));

			// ġŲ���� ��ǥ �ޱ�
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	// vector�� �ϳ� �� �����Ͽ�, �� ���Ϳ��� ������ ����
	// �ִ� M���� ġŲ���� ����.
	vector <pii> vc;
	dfs(vc, 0, 0);
	printf("%d\n", sol);
	return 0;
}