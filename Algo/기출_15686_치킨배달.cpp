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

// 집과 치킨집 좌표를 받기 위한 vector 생성
vector <pii> house;
vector <pii> chicken;

void dfs(vector <pii> vc, int idx, int cnt)
{
	// M개의 치킨집을 골랐다면
	if (cnt == M)
	{
		int total = 0;
		// 모든 집과 M개의 치킨집과의 최소 거리를 구함
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

	// 모든 치킨집들 중에서 M개를 선택하는 (조합) 과정
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

			// 집의 좌표 받기
			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));

			// 치킨집의 좌표 받기
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	// vector를 하나 더 생성하여, 이 백터에서 조합을 구현
	// 최대 M개의 치킨집을 고르기.
	vector <pii> vc;
	dfs(vc, 0, 0);
	printf("%d\n", sol);
	return 0;
}