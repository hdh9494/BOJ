#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <memory.h>

#define MAX 101

using namespace std;

int N;
bool visit[MAX];

vector <int> num;


void dfs(vector <int> vc, int pos, int M)
{
	if (vc.size() == M)
	{
		int sum = 0;
		for (int k = 0; k < M; k++)
			sum += vc[k];
		visit[sum] = 1;
		return;
	}

	for (int i = pos; i < num.size(); i++)
	{
		vc.push_back(num[i]);
		dfs(vc, i + 1, M);
		vc.pop_back();
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int val, N, sol = 0;
		num.clear();
		memset(visit, false, sizeof(visit));

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &val);
			num.push_back(val);
		}

		vector <int> vc;
		for (int M = 1; M <= N; M++)
			dfs(vc, 0, M);

		for (int i = 0; i < MAX; i++)
			if (visit[i])
				sol++;

		printf("#%d %d\n", tc, sol + 1);
		
	}
	return 0;
}