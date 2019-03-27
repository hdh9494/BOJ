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


// ó���� N�� 6 �̻��̸�, �� ���� �ο��� 3�� �̻� �Ǳ� ������,
// ��͸� ����Ͽ� ������ ��Ÿ���� �Ѵٰ� �����ؼ� ������.

// but, ���� ������ ���¿��� ���� ������ ���ϴ� ����
// ��������(ū ���� �ڷ� ����) ����� ������ ����ϸ� �ȴ�.

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


	// �� �ڵ�� ��� X => dfs�� return�ǰ� ���ƿͼ� cnt�� �����ϰ� �Ǹ�
	// if(cnt == N / 2)�κ��� ����� �Ǿ� ���̰Ե�

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

	
	// N�� ������ �ּ� 4���� �̴�.
	// 0���� N-1���� Ž���ϳ�, 1���� N-1���� Ž���ϳ� ������� �Ȱ���.
	// ex) N=4�� ��, A�� - 01 02 03 12 13 23 / B�� - 23 13 12 03 02 01
	// ��, 6�� case�� 3���� �ص� ���� ���⶧��
	// ����, �ð� ���̱� ���ؼ��� 0�� �ƴ� 1���� Ž���ص� ����

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