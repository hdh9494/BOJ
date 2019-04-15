#pragma warning(disable : 4996)

#include <cstdio>

using namespace std;

int A_map[100][100];
int B_map[100][100];
int res_map[100][100];

int main(void)
{
	int A_row, A_col;
	scanf("%d %d", &A_row, &A_col);

	for (int i = 0; i < A_row; i++) {
		for (int j = 0; j < A_col; j++) {
			scanf("%d", &A_map[i][j]);
		}
	}

	int B_row, B_col;
	scanf("%d %d", &B_row, &B_col);

	for (int i = 0; i < B_row; i++) {
		for (int j = 0; j < B_col; j++) {
			scanf("%d", &B_map[i][j]);
		}
	}


	for (int i = 0; i < A_row; i++) {
		for (int j = 0; j < B_col; j++) {
			for (int k = 0; k < A_col; k++) {
				res_map[i][j] += (A_map[i][k] * B_map[k][j]);
			}
		}
	}

	for (int i = 0; i < A_row; i++) {
		for (int j = 0; j < B_col; j++) {
			printf("%d ", res_map[i][j]);
		}
		printf("\n");
	}

	return 0;
}