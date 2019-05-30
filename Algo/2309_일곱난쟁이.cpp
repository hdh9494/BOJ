#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int arr[9];
vector <int> vc;

void print_val()
{
	for (int i = 0; i < vc.size(); i++)
		printf("%d\n", vc[i]);
}

void dfs(int idx, int cnt, int sum)
{
	if (cnt == 7)
	{
		if (sum == 100) 
		{
			sort(vc.begin(), vc.end());
			print_val();
			exit(1);
		}
		return;
	}

	for (int i = idx; i < 9; i++)
	{
		vc.push_back(arr[i]);

		dfs(i + 1, cnt + 1, sum + arr[i]);

		vc.pop_back();
	}

}

int main(void)
{
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);

	dfs(0, 0, 0);
	return 0;
}