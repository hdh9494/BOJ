#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 50

using namespace std;
typedef pair<int, int> pii;

int N, M;
int sol = 9999999;

vector <pii> house;
vector <pii> chicken;

void dfs(vector <pii> vc, int pos)
{
	if (vc.size() == M)
	{
		int total = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int hx = house[i].first;
			int hy = house[i].second;
			//  hy = house.at(i).second;

			int minVal = 9999999;
			for (int j = 0; j < vc.size(); j++)
			{
				int cx = vc[j].first;
				int cy = vc[j].second;

				minVal = min(minVal, abs(hx - cx) + abs(hy - cy));
			}
			total += minVal;
		}

		sol = min(sol, total);
		return;
	}

	// i�� pos�� �ΰ� �ϳ��� ������Ű�� vc�� ġŲ�� pos�� �Է�.
	for (int i = pos; i < chicken.size(); i++)
	{
		vc.push_back(chicken[i]);
		dfs(vc, i + 1);
		vc.pop_back();
	}
}

int main(void)
{
	int val;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &val);

			if (val == 1)
				house.push_back(make_pair(i, j));
			else if (val == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	// �ִ� M���� ���� ����(����) ���ο� ���͸� ����
	// �� ���Ϳ� ġŲ���� nCr (n : ġŲ�� �� ���� , r : M(�ִ� M��) )
	vector <pii> vc;   
	dfs(vc, 0);
	printf("%d\n", sol);
	return 0;
}
