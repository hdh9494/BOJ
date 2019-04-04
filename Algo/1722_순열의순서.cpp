#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

#define MAX 21
using namespace std;

int N;

int K;			// K번째 순열 출력
int dfs1_idx = 0;
int dfs2_idx = 0;
bool visit[MAX];

typedef unsigned long long ull;
ull fact[21] = { 1, };

vector <int> vc;
vector <int> dfs2_num;

void dfs1(int cnt)
{
	if (cnt == N) {
		dfs1_idx++;
		if (dfs1_idx == K) {
			for (int i = 0; i < vc.size(); i++)
				printf("%d ", vc[i]);
			return;
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			vc.push_back(i);
			dfs1(cnt + 1);
			vc.pop_back();
			visit[i] = false;
		}
	}
}

bool array_element_equal(int a[], int b[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void dfs2(int cnt)
{
	if (cnt == N)
	{
		dfs2_idx++;
		
		if (vc == dfs2_num) 
			printf("%d\n", dfs2_idx);
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			vc.push_back(i);
			dfs2(cnt + 1);
			vc.pop_back();
			visit[i] = false;
		}
	}
}

void setFac()
{
	for (int i = 1; i <= 20; ++i)
		fact[i] = fact[i - 1] * i;
}


int main(void)
{
	scanf("%d", &N);
	setFac();
	int type;
	scanf("%d", &type);

	if (type == 1)
	{
		scanf("%d", &K);
		dfs1(0);
	}

	else
	{
		int tmp;
		ull ans = 0;
		vector<int> v;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		for (int i = 0; i < N - 1; ++i)
		{
			int cnt = v[i] - 1;
			for (int j = 0; j <= i; ++j)
			{
				if (v[j] < v[i])
					--cnt;
			}
			if (cnt > 0)
				ans += cnt * fact[N - i - 1];
			//팩토리얼 더해
		}
		printf("%llu\n", ans + 1);
	}
	
	/*
	else if (type == 2)
	{
		int val;
		for (int i = 0; i < N; i++) {
			scanf("%d", &val);
			dfs2_num.push_back(val);
		}

		dfs2(0);
	}
	*/
	
}