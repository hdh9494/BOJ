#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int sol;

int row[10];


// �� ������ ��ġ�� �ִ��� Ȯ���ϴ� �Լ�

bool promising(int i)
{
	// i : ���� i��° �࿡ ���� ��������, 
	// 0 ~ i-1������ QUEEN�� ��ġ�� ���Ͽ�
	// ���� �� �ִ� ��ġ���� �ƴ����� �Ǵ�.
	for (int k = 0; k < i; k++)
	{
		// ���� �� || �밢��
		if (row[i] == row[k] || abs(row[i] - row[k]) == i - k)
			return false;
	}
	return true;
}

void N_QUEEN(int i)
{
	// N*N�迭�� QUEEN�� ��� ���� �� �ִ� case�� ��츦 ã�� => sol++
	if (N == i)
		sol++;
	else
	{
		for (int j = 0; j < N; j++)
		{
			// (i,j)�� QUEEN�� ����.
			// row�� idx - ���� ��ġ / ������ �� - ���� ��ġ
			row[i] = j;

			// �����ϴٸ�, �������� QUEEN�� �������� dfs
			if (promising(i))
				N_QUEEN(i + 1);

			// �������� �ʴٸ�, ���� ���� ��ġ�� QUEEN�� ��
		}
		
	}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++) {
		N = 0, sol = 0;
		memset(row, 0, sizeof(row));

		scanf("%d", &N);
		
		N_QUEEN(0); //��� ����
		printf("#%d %d\n", tc, sol);
	}
	return 0;
}