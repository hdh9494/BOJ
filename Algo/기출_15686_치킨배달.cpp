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

	// i를 pos로 두고 하나씩 증가시키며 vc에 치킨집 pos를 입력.
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

	// 최대 M개를 고르기 위해(조합) 새로운 백터를 생성
	// 이 백터에 치킨집을 nCr (n : 치킨집 총 개수 , r : M(최대 M개) )
	vector <pii> vc;   
	dfs(vc, 0);
	printf("%d\n", sol);
	return 0;
}
