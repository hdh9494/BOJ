#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>
#define MAX 1001
using namespace std;

int N;
char map[MAX][MAX];
int row[MAX];
int col[MAX];

void init()
{
	memset(map, 0, sizeof(map));
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		init();
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == 'B')
				{
					row[i]++;
					col[j]++;
				}
			}
		}

		int cnt = 0;
		

		// y=x 대칭축을 기준으로 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int blackstone = row[i] + col[j];
				if (map[i][j] == 'B')
					blackstone--;
				if (blackstone % 2 == 1) //홀수이면 cnt++
					cnt++;
			}
		}

		printf("#%d %d\n", tc, cnt);
	}
	return 0;
}