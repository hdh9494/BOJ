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
	//��¥�� N+1���� ũ�ٸ� -���� ũ�� �ش�.
	if (day > N + 1) return -987654321;
	//�޸������̼�
	if (D[day] > 0) return D[day];
	//��ȭ�� ����� ���Ѵ� Ȥ�� ����� �Ѵ�. �� �� �ϳ��� ����.
	return D[day] = max(dp(day + 1), dp(day + T[day]) + P[day]);
}


// 2. ��Ž(DFS)
void dfs(int total, int cnt)
{
	if (cnt == N)
	{
		sol = max(sol, total);
		return;
	}

	// ����� ���ϴ� ��쿡�� max�� ����� ���� ���� cnt+1���ش�.
	// dfs()�� ������ return �� �Ŀ�, �߰������� ����� �� �ִ� ���̽��� ���
	dfs(total, cnt + 1);

	// ����� �� �� �ִ� ���� ����� �Ѵ�.
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