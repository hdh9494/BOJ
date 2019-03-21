#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <memory.h>

#define MAX 1001


using namespace std;

int ans[MAX][MAX];
int map[MAX][MAX];



int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &ans[i][j]);
			}
		}




	}
}