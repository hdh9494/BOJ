#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

using namespace std;

int N, S;
int sol;

vector <int> num;

void dfs(int amount, int cnt)
{
	if (cnt == N)
	{
		if (amount == S)
			sol++;
		return;
	}

	dfs(amount + num[cnt], cnt + 1);
	dfs(amount, cnt + 1);
}

int main(void)
{
	int val;
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		num.push_back(val);
	}
	
	dfs(0,0);

	if (S == 0)
		sol -= 1;

	printf("%d\n", sol);
	return 0;
}