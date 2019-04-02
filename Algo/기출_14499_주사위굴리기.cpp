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

// �ֻ��� ������
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



	// 1 - ������ / 2 - ���� / 3 - ���� / 4 - �Ʒ���
	for (int i = 0; i < K; i++) {
		int dir = order[i];

		if (dir == 4)
		{
			// �ֻ��� ���� ����� continue;
			if (x + 1 == N) continue;
			x++;
			change_dice_pos(dir);

			// map �ٴ��� 0�̸�, �ֻ����� �ٴڸ��� ���� �޾ƿ�
			if (map[x][y] == 0)
				map[x][y] = dice[5];

			// map �ٴ��� 0�� �ƴϸ�, �ֻ����� �ٴڸ鿡 ���� �Ѱ��ְ�
			// map �ٴ��� 0���� �ʱ�ȭ
			else {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}

			// �ֻ��� ���� ���� ���
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