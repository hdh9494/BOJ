#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector <int> vc;

void dfs()
{
	if (vc.size() == M)
	{
		for (int i = 0; i < vc.size(); i++)
			printf("%d ", vc[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		vc.push_back(i);
		dfs();
		vc.pop_back();
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	dfs();
	return 0;
}