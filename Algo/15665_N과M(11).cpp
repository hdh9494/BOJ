#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a, v;

void dfs(int cnt) 
{
	if (cnt == m)
	{
		for (auto k : v) 
			printf("%d ", k);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) 
	{
		v.push_back(a[i]);
		dfs(cnt + 1);
		v.pop_back();
	}
}

int main(void) 
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) 
	{
		int t;
		scanf("%d", &t);
		if (find(a.begin(), a.end(), t) == a.end())
			a.push_back(t);
	}

	sort(a.begin(), a.end());
	n = a.size();

	dfs(0);

	return 0;
}

