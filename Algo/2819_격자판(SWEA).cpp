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
	// 7�ڸ� ���ڰ� �ϼ��Ǹ�, �ش� ���ڸ� idx�� �����ϰ�
	// �� idx ��ġ�� �迭���� 1�� ����
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
			// ó�� ���� ���� ���������� 10^7�� ���̱� ������
		    // 10�� ���������ν�, ���� �ֱ� map���� 1�� �ڸ��� ���Բ�
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		
		init();  // �ʱ�ȭ �Լ�

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				// map �Է�
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				// ���� ��ġ ���� - 4x4 �迭 ��� ��ġ���� ����
				// x, y, map��ġ�� ��, cnt)
				dfs(i, j, map[i][j], 1);
			}
		}

		// 7�ڸ� ���ڰ� �� ����� cnt
		for (int i = 0; i < 10000000; i++)
			if (check[i])
				sol++;

		printf("#%d %d\n", tc, sol);
	}
	return 0;
}