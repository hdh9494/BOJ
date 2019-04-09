#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector <int> vc;
bool visit[10];

// visit 사용 + idx,cnt를 통해 조합
void dfs(int idx, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < vc.size(); i++)
			printf("%d ", vc[i]);
		printf("\n");
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		if (!visit[i])
		{
			vc.push_back(i);
			visit[i] = true;

			dfs(i, cnt + 1);

			visit[i] = false;
			vc.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	// 숫자는 1부터 시작이니까, dfs(1,0)
	dfs(1, 0);
	return 0;
}

// 	1. cnt 하나로만 조합을 처리 + 벡터

/*
void dfs(int pos)
{
	if (vc.size() == M)
	{
		for (int i = 0; i < vc.size(); i++)
			printf("%d ", vc[i]);
		printf("\n");
		return;
	}

	for (int i = pos; i <= N; i++)
	{
		vc.push_back(i);
		dfs(i + 1);
		vc.pop_back();
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	dfs(1);
	return 0;
}

*/