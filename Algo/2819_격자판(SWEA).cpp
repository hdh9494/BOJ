#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>

using namespace std;

int sol;

int map[4][4];
bool check[10000000];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void init()
{
	sol = 0;
	memset(check, 0, sizeof(check));
}

void dfs(int v1, int v2, int val, int cnt)
{
	// 7자리 숫자가 완성되면, 해당 숫자를 idx로 생각하고
	// 그 idx 위치의 배열값을 1로 변경
	if (cnt == 7)
	{
		check[val] = true;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = v1 + dx[i];
		int ny = v2 + dy[i];

		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4)
			dfs(nx, ny, 10 * val + map[nx][ny], cnt + 1);
			// 처음 받은 값은 최종적으로 10^7의 값이기 때문에
		    // 10을 곱해줌으로써, 가장 최근 map값이 1의 자리로 오게끔
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		
		init();  // 초기화 함수

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				// map 입력
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				// 시작 위치 랜덤 - 4x4 배열 모든 위치에서 시작
				// x, y, map위치의 값, cnt)
				dfs(i, j, map[i][j], 1);
			}
		}

		// 7자리 숫자가 총 몇개인지 cnt
		for (int i = 0; i < 10000000; i++)
			if (check[i])
				sol++;

		printf("#%d %d\n", tc, sol);
	}
	return 0;
}