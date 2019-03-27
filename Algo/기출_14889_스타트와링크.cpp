#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 21
using namespace std;

int N;

int map[MAX][MAX];
int visit[MAX];

int sol = 9999999;


// 처음에 N이 6 이상이면, 각 팀의 인원이 3명 이상 되기 때문에,
// 재귀를 사용하여 조합을 나타내야 한다고 생각해서 꼬였다.

// but, 팀이 나눠진 상태에서 팀의 총점을 구하는 것은
// 선택정렬(큰 값을 뒤로 보냄) 방법의 로직을 사용하면 된다.

void dfs(int player_num, int cnt)
{
	if (cnt == N / 2)
	{
		vector <int> start_team;
		vector <int> link_team;

		for (int i = 0; i < N; i++)
		{
			if (visit[i])
				start_team.push_back(i);
			else
				link_team.push_back(i);
		}

		int start_total = 0, link_total = 0;

		for (int i = 0; i < start_team.size(); i++) {
			for (int j = i + 1; j < start_team.size(); j++) {
				start_total += map[start_team[i]][start_team[j]] + map[start_team[j]][start_team[i]];
				link_total += map[link_team[i]][link_team[j]] + map[link_team[j]][link_team[i]];
			}
		}

		sol = min(sol, abs(start_total - link_total));
		return;
	}


	// 이 코드는 사용 X => dfs가 return되고 돌아와서 cnt가 증가하게 되면
	// if(cnt == N / 2)부분을 벗어나게 되어 꼬이게됨

	/*
	for (int i = cnt; i < N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
	*/

	
	// N의 개수가 최소 4부터 이다.
	// 0부터 N-1까지 탐색하나, 1부터 N-1까지 탐색하나 결과값은 똑같다.
	// ex) N=4일 때, A팀 - 01 02 03 12 13 23 / B팀 - 23 13 12 03 02 01
	// 즉, 6개 case중 3개만 해도 답은 같기때문
	// 따라서, 시간 줄이기 위해서는 0이 아닌 1부터 탐색해도 무방

	for (int i = player_num; i < N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(i + 1, cnt + 1);
			visit[i] = false;
		}
	}
}	

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0,0);
	printf("%d\n", sol);
	return 0;


}