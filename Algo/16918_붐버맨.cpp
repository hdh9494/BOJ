#pragma warning(disable : 4996)

#include <cstdio>
#include <memory.h>

#define MAX 200
using namespace std;

int R, C, N;

char map[MAX][MAX];
int check_time[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool boundary_check(int x, int y)
{
	if (0 <= x && x < R && 0 <= y && y < C)
		return true;
	return false;
}

void print_val()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void install_boom(int time)
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.') {
				map[i][j] = 'O';
				check_time[i][j] = time + 3;
			}
		}
	}
}

void delete_boom(int time)
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (check_time[i][j] == time) 
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (boundary_check)
					{
						if (map[nx][ny] == 'O')
						{
							map[nx][ny] = '.';
						}
					}
				}
				map[i][j] = '.';
				check_time[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &R, &C, &N);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'O')
				check_time[i][j] = 3;
		}
	}

	int time = 2;
	while (1)
	{	
		if (time == N + 1)
			break;

		// Â¦¼ö½Ã°£ ÆøÅº ¼³Ä¡
		if (time % 2 == 0)
			install_boom(time);
		// È¦¼ö½Ã°£ ÆøÅº Á¦°Å
		else
			delete_boom(time);

		time++;
	}
	
	print_val();
	return 0;
}