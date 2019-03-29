#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int sol;

int T[16];
int P[16];
int D[16];

// 1. DP
int dp(int day) {
	if (day == N + 1) return 0;
	//날짜가 N+1보다 크다면 -값을 크게 준다.
	if (day > N + 1) return -987654321;
	//메모이제이션
	if (D[day] > 0) return D[day];
	//점화식 상담을 안한다 혹은 상담을 한다. 둘 중 하나를 고른다.
	return D[day] = max(dp(day + 1), dp(day + T[day]) + P[day]);
}


// 2. 완탐(DFS)
void dfs(int total, int cnt)
{
	if (cnt == N)
	{
		sol = max(sol, total);
		return;
	}

	// 상담을 안하는 경우에는 max값 결과를 내기 위해 cnt+1해준다.
	// dfs()가 끝나고 return 된 후에, 추가적으로 상담할 수 있는 케이스를 계산
	dfs(total, cnt + 1);

	// 상담을 할 수 있는 경우는 상담을 한다.
	if (cnt + T[cnt] <= N)
		dfs(total + P[cnt], cnt + T[cnt]);
	
}
	

int main(void)
{
	int v1, v2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &v1, &v2);
		T[i] = v1, P[i] = v2;
	}

	dfs(0, 0);
	printf("%d\n", sol);
	return 0;
}