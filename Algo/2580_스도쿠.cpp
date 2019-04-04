#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;
typedef pair<int, int> pii;

int map[10][10];

vector <pii> blank;

void print_val()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

bool check_row(int x, int num)
{
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == num)
			return false;
	}
	return true;
}

bool check_col(int y, int num)
{
	for (int i = 0; i < 9; i++) {
		if (map[i][y] == num)
			return false;
	}
	return true;
}

bool check_square(int x, int y, int num)
{
	x = x / 3;
	y = y / 3;

	for (int i = 3 * x; i < (3 * x) + 3; i++) {
		for (int j = 3 * y; j < (3 * y) + 3; j++) {
			if (map[i][j] == num)
				return false;
		}
	}
	return true;
}

void dfs(int cnt)
{
	if (cnt == blank.size())
	{
		print_val();
		exit(0);
	}

	for (int num = 1; num <= 9; num++)
	{
		int x = blank[cnt].first;
		int y = blank[cnt].second;

		if (check_row(x, num) && check_col(y, num) && check_square(x, y, num))
		{
			map[x][y] = num;
			dfs(cnt + 1);
			map[x][y] = 0;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				blank.push_back(make_pair(i, j));
		}
	}
	

	for (int num = 1; num <= 9; num++) {
		int x = blank[0].first;
		int y = blank[0].second;

		if (check_row(x, num) && check_col(y, num) && check_square(x, y, num))
		{
			map[x][y] = num;
			dfs(1);
			map[x][y] = 0;
		}
	}
	return 0;
}