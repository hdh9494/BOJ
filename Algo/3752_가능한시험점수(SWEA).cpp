#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <memory.h>

using namespace std;

vector <int> vc;
bool visit[10001];

void init()
{
	memset(visit, 0, sizeof(visit));
	vc.clear();
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		init();
		int N = 0, cnt = 0;
		scanf("%d", &N);
		vc.push_back(0);
		visit[0] = 1;

		for (int i = 0; i < N; i++)
		{
			int num;
			scanf("%d", &num);

			int temp = vc.size();
			for (int j = 0; j < temp; j++)
			{
				if (!visit[vc[j] + num]) {
					vc.push_back(vc[j] + num);
					visit[vc[j] + num] = 1;
					cnt++;
				}

			}
		}

		printf("#%d %d\n", tc, cnt+1);
	}
	return 0;
}





/*
#define MAX 10001

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
*/