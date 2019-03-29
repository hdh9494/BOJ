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


// ��Ϲ��� ȸ�� - swap������� ����... �����ϰ� ��������
// ���� �� temp�� �޾Ƶΰ� ������..
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

	// ���ֺ����ִ� ���� �ٸ���
	if (gear[n][2] != gear[n + 1][6])
	{
		// �޾ƿ� ȸ�� ������ �ݴ�� �����ϰ�
		d = (d == 1) ? -1 : 1;
		// ���� ���� ������ �Ŀ�
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
		
		// gear��ȣ�� �޾ƿ���, �¿�� �����ֱ�
		move_left(gear_num - 1, dir);
		move_right(gear_num + 1, dir);

		rotate_gear(gear_num, dir);
	}

	sol = gear[1][0] + (2 * gear[2][0]) + (4 * gear[3][0]) + (8 * gear[4][0]);
	
	printf("%d\n", sol);
	return 0;
}

/*
[1 �ܰ�] �ԷµǴ� dir������ ���� �ð� or �ݽð���� ���� ���ϰ� �˴ϴ�.
[2 �ܰ�] ����, �������� �˻��Ͽ� ���� �ٸ� ���� �ִٸ� �ݴ�������� �����ְ�,
		 ���� ���� ���� �ִٸ� ���� �������� �ʽ��ϴ�.

���������� �翷�� ���� Ȯ���Ͽ� �� ��ϰ� �����̴��� ���θ� ���� ��������� �մϴ�!!!
*/