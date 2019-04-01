#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int sol;

int T[15];
int P[15];

void dfs(int total, int cnt)
{
	if (cnt == N)
	{
		sol = max(sol, total);
		return;
	}

	if (cnt < N)
		dfs(total, cnt + 1);

	if (T[cnt] + cnt <= N)
		dfs(total + P[cnt], T[cnt] + cnt);
	
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &T[i], &P[i]);

	dfs(0,0);
	printf("%d\n", sol);
	return 0;
}