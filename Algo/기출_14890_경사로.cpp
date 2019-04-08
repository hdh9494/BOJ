#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define MAX 101
using namespace std;

int N, L;
int sol;
int map[MAX][MAX];
bool visit[MAX][MAX];

void row_check(int x)
{
	memset(visit, 0, sizeof(visit));
	int cur_h = map[x][0];

	for (int y = 0; y < N; y++)
	{
		// 1. ���� ��ġ�� ���̿� ��� ���ٸ� ����
		if (cur_h == map[x][y]) {
			continue;
		}
			

		// 2. ���� ��ġ�� ���̿��� ���̰� 2 �̻��� ��� X
		else if (abs(cur_h - map[x][y]) > 1)
			return;

		// 3. ���� ��ġ���� ���� ���� ������, �� ���� ���� ���̰� 1�� ��� 
		else if (cur_h < map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			
			// ���� L�� ���θ� ���� �� �ִٸ�
			if (0 <= y - L) {

				// ���� L��ŭ Ž���� ���鼭, ������ �������� Ȯ��.
				for (int k = y - L; k < y; k++) {


					// ���� ���̰� �ٸ��ų�, �̹� ���� ��쿡��
					// cnt���� �ʰ� return;
					if (map[x][k] != cur_h || visit[x][k] == 1)
						return;
					
					// ���θ� ���� �� �ִ� ���, �湮 üũ
					visit[x][k] = 1;
				}

				cur_h = map[x][y];
			}
			// ���θ� ���� �� ���ٸ�, cnt�����ʰ� return
			else
				return;
		}

		// 4. ���� ��ġ���� ���� ���� ������, �� ���� ���� ���̰� 1�� ��� 
		else if (cur_h > map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			if (y - 1 + L < N) {

				for (int k = y; k < y + L; k++) {

					if (map[x][k] != cur_h - 1 || visit[x][k] == 1)
						return;
					visit[x][k] = 1;
				}

				cur_h = map[x][y];
			}
			else
				return;
		}
	}

	// �������
	sol++;
}

void col_check(int y)
{
	memset(visit, 0, sizeof(visit));
	int cur_h = map[0][y];

	for (int x = 0; x < N; x++)
	{
		if (cur_h == map[x][y])
			continue;

		else if (abs(cur_h - map[x][y]) > 1)
			return;

		else if (cur_h < map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			if (0 <= x - L) {
				for (int k = x - L; k < x; k++) {

					if (map[k][y] != cur_h || visit[k][y] == 1)
						return;
					visit[k][y] = 1;
				}

				cur_h = map[x][y];
			}
			else
				return;
		}

		else if (cur_h > map[x][y] && abs(cur_h - map[x][y]) == 1)
		{
			if (x - 1 + L < N) {
				for (int k = x; k < x + L; k++) {
					if (map[k][y] != cur_h - 1 || visit[k][y] == 1)
						return;
					visit[k][y] = 1;
				}
				cur_h = map[x][y];
			}
			else
				return;
		}
	}

	sol++;
}

int main(void)
{
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		row_check(i);
		col_check(i);
	}

	printf("%d\n", sol);
	return 0;
}