#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>

#define MAX 21
using namespace std;

int N, M;
int x, y;

int order[1001];
int dice[6];
int map[MAX][MAX];

// 주사위 굴리기
void change_dice_pos(int dir)
{
	if (dir == 4)
	{
		int temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
	}

	else if (dir == 3)
	{
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}

	else if (dir == 2)
	{
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}

	else if (dir == 1)
	{
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
}

	

int main(void)
{
	int K;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &x, &y, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int v;
	for (int k = 0; k < K; k++) {
		scanf("%d", &v);
		order[k] = v;
	}



	// 1 - 오른쪽 / 2 - 왼쪽 / 3 - 위로 / 4 - 아래로
	for (int i = 0; i < K; i++) {
		int dir = order[i];

		if (dir == 4)
		{
			// 주사위 범위 벗어나면 continue;
			if (x + 1 == N) continue;
			x++;
			change_dice_pos(dir);

			// map 바닥이 0이면, 주사위의 바닥면의 값을 받아옴
			if (map[x][y] == 0)
				map[x][y] = dice[5];

			// map 바닥이 0이 아니면, 주사위의 바닥면에 값을 넘겨주고
			// map 바닥은 0으로 초기화
			else {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}

			// 주사위 가장 윗면 출력
			printf("%d\n", dice[0]);
		}

		else if (dir == 3)
		{
			if (x - 1 < 0) continue;
			x--;
			change_dice_pos(dir);

			if (map[x][y] == 0)
				map[x][y] = dice[5];
			else {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}

			printf("%d\n", dice[0]);
		}

		else if (dir == 2)
		{
			if (y - 1 < 0) continue;
			y--;
			change_dice_pos(dir);


			if (map[x][y] == 0)
				map[x][y] = dice[5];
			else {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}

			printf("%d\n", dice[0]);
		}

		else if (dir == 1)
		{
			if (y + 1 == M) continue;
			y++;
			change_dice_pos(dir);


			if (map[x][y] == 0)
				map[x][y] = dice[5];
			else {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}

			printf("%d\n", dice[0]);
		}
	}

	return 0;
		
}