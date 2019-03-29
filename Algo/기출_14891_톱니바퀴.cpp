#pragma warning(disable : 4996)

#include <cstdio>

using namespace std;

int sol;
int gear[5][8];

bool boundary_check(int n)
{
	if (1 <= n && n <= 4)
		return true;
	return false;
}


// 톱니바퀴 회전 - swap방식으로 진행... 무식하게 꼽지말고
// 끝에 값 temp에 받아두고 돌리자..
void rotate_gear(int gear_num, int dir)
{
	if (dir == 1)
	{
		int temp = gear[gear_num][7];
		for (int i = 6; i >= 0; i--) 
			gear[gear_num][i+1] = gear[gear_num][i];
		gear[gear_num][0] = temp;
	}

	else if (dir == -1)
	{
		int temp = gear[gear_num][0];
		for (int i = 0; i <= 6; i++)
			gear[gear_num][i] = gear[gear_num][i+1];
		gear[gear_num][7] = temp;
	}
	
}

void move_left(int n, int d)
{
	if (!boundary_check(n)) return;

	// 마주보고있는 극이 다르면
	if (gear[n][2] != gear[n + 1][6])
	{
		// 받아온 회전 방향을 반대로 설정하고
		d = (d == 1) ? -1 : 1;
		// 극을 먼저 설정한 후에
		move_left(n - 1, d);
		rotate_gear(n, d);
	}
}

void move_right(int n, int d)
{
	if (!boundary_check(n)) return;

	if (gear[n - 1][2] != gear[n][6])
	{
		d = (d == 1) ? -1 : 1;
		move_right(n + 1, d);
		rotate_gear(n, d);
	}
	
}


int main(void)
{
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}

	int K;
	scanf("%d", &K);
	
	int gear_num, dir;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &gear_num, &dir);
		
		// gear번호를 받아오고, 좌우로 돌려주기
		move_left(gear_num - 1, dir);
		move_right(gear_num + 1, dir);

		rotate_gear(gear_num, dir);
	}

	sol = gear[1][0] + (2 * gear[2][0]) + (4 * gear[3][0]) + (8 * gear[4][0]);
	
	printf("%d\n", sol);
	return 0;
}

/*
[1 단계] 입력되는 dir변수에 따라서 시계 or 반시계방향 돌지 정하게 됩니다.
[2 단계] 왼쪽, 오른쪽을 검사하여 서로 다른 값이 있다면 반대방향으로 돌려주고,
		 서로 같은 값이 있다면 돌려 움직이지 않습니다.

돌리기전에 양옆을 먼저 확인하여 옆 톱니가 움직이는지 여부를 먼저 결정해줘야 합니다!!!
*/