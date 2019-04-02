#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 10

using namespace std;

int N, M;
int arr[MAX];
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
		vc.push_back(arr[i]);
		dfs(i, cnt + 1);
		vc.pop_back();
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
