#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

using namespace std;

int N, M;
int visit[8];

vector <int> vc;

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < vc.size(); i++)
			printf("%d ", vc[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			vc.push_back(i);
			visit[i] = 1;
			dfs(cnt + 1);
			vc.pop_back();
			visit[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	dfs(0);
	return 0;
}