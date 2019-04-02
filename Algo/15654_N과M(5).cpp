#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define MAX 10

using namespace std;

int N, M;
int arr[MAX];
unordered_map <int, int> visit;
vector <int> vc;

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < vc.size(); i++)
			printf("%d ", vc[i]);
		printf("\n");
		return;
	}

	for (int i = num; i < N; i++)
	{
		if (!visit[arr[i]])
		{
			vc.push_back(arr[i]);
			visit[arr[i]] = true;
			dfs(num, cnt + 1);
			vc.pop_back();
			visit[arr[i]] = false;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);
	
	sort(arr, arr + N);

	dfs(0, 0);
	return 0;
}
