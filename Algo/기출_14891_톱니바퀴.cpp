#pragma warning(disable : 4996)

#include <cstdio>

using namespace std;

int K;
int sol;

bool tow[4][8];

int tow_num[100];
bool tow_turn[100];

void check()
{

}

void turn_ns(int tow_num, int dir)
{
	for (int i = 0; i < 8; i++)
	{
		int next = (i + 1) % 8;
		
		if (dir == 1)
			tow[tow_num][next] = tow[tow_num][i];
		else
			tow[tow_num][i] = tow[tow_num][next];
	}
}

void dfs(int cnt, int tow_num, int dir)
{
	if (cnt == 4)
	{
		check();
		return;
	}


	bool same_dir = false;
	if (tow[tow_num][2] == tow[tow_num + 1][6])
		same_dir = true;

	if (!same_dir) {
		turn_ns(tow_num, dir);
		turn_ns(tow_num+1, )
	}
}


int main(void)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &tow[i][j]);
		}
	}
	scanf("%d", &K);
	
	int tow_num, dir;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &tow_num, &dir);
		dfs(1, tow_num, dir);
	}
	
	printf("%d\n", sol);
	return 0;
}