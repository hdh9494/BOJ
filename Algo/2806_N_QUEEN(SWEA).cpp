#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int sol;

int row[10];


// 더 진행할 가치가 있는지 확인하는 함수

bool promising(int i)
{
	// i : 현재 i번째 행에 퀸을 놓기전에, 
	// 0 ~ i-1번행의 QUEEN의 위치와 비교하여
	// 놓을 수 있는 위치인지 아닌지를 판단.
	for (int k = 0; k < i; k++)
	{
		// 같은 열 || 대각선
		if (row[i] == row[k] || abs(row[i] - row[k]) == i - k)
			return false;
	}
	return true;
}

void N_QUEEN(int i)
{
	// N*N배열에 QUEEN을 모두 놓을 수 있는 case인 경우를 찾음 => sol++
	if (N == i)
		sol++;
	else
	{
		for (int j = 0; j < N; j++)
		{
			// (i,j)에 QUEEN을 놓음.
			// row의 idx - 행의 위치 / 데이터 값 - 열의 위치
			row[i] = j;

			// 유망하다면, 다음행의 QUEEN을 놓기위해 dfs
			if (promising(i))
				N_QUEEN(i + 1);

			// 유망하지 않다면, 다음 열의 위치에 QUEEN을 둠
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
		
		N_QUEEN(0); //재귀 돌림
		printf("#%d %d\n", tc, sol);
	}
	return 0;
}