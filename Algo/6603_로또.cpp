#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

using namespace std;

int T;
int lotto[15];

vector <int> vc;

void dfs(int num, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < vc.size(); i++)
			printf("%d ", vc[i]);
		printf("\n");
		return;
	}

	for (int i = num; i < T; i++)
	{
		vc.push_back(lotto[i]);
		dfs(i + 1, cnt + 1);
		vc.pop_back();
	}
}


int main(void)
{
	while (1)
	{
		scanf("%d", &T);

		if (T == 0)
			break;
		
		for (int i = 0; i < T; i++)
			scanf("%d", &lotto[i]);

		dfs(0, 0);
		printf("\n");
	}
	return 0;
}