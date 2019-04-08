#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, m;
bool visit[8];
int a[8];
vector<int> v;
set<vector<int>> s;

void dfs(int cnt) 
{
	if (cnt == m) 
	{
		s.insert(v);
		return;
	}

	for (int i = 0; i < n; i++) 
	{
		if (!visit[i]) 
		{
			visit[i] = true;
			v.push_back(a[i]);
			dfs(cnt + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
}

int main(void) 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);

	sort(a, a + n);
	dfs(0);

	for (auto k : s) {
		for (auto t : k) printf("%d ", t);
		printf("\n");
	}
	return 0;
}