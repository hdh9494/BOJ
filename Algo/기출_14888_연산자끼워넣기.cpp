#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int op[4];

int min_sol = 999999999;
int max_sol = -999999999;

vector <int> num;

void dfs(int total, int cnt)
{
	if (cnt == N)
	{
		min_sol = min(min_sol, total);
		max_sol = max(max_sol, total);
		return;
	}

	if (op[0] > 0)
	{
		op[0]--;
		dfs(total + num[cnt], cnt + 1);
		op[0]++;

		/* 
		
		total�� �����ؼ� ����ϰ�, �� ���� �Ķ���Ϳ� �ִ� �����
		dfs�� ������ return �Ǿ��� ��, total ���� 1�� �� ���� ����
		
		   
		op[0]--;
		total += num[cnt];
		dfs(total, cnt + 1);
		op[0]++;

		*/
	}

	if (op[1] > 0)
	{
		op[1]--;
		dfs(total - num[cnt], cnt + 1);
		op[1]++;
	}

	if (op[2] > 0)
	{
		op[2]--;
		dfs(total * num[cnt], cnt + 1);
		op[2]++;
	}

	if (op[3] > 0)
	{
		op[3]--;
		dfs(total / num[cnt], cnt + 1);
		op[3]++;
	}

}

int main(void)
{
	int val;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		num.push_back(val);
	}

	for (int i = 0; i < 4 ; i++) {
		scanf("%d", &val);
		op[i] = val;
	}


	dfs(num[0], 1);

	printf("%d\n", max_sol);
	printf("%d\n", min_sol);
	return 0;
}