#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

#define MAX 1000001
using namespace std;

int N;
int sol = 0;

int build_h[MAX];

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &build_h[i]);


	for (int i = 0; i < N - 1; i++) {
		for (int j = i+1; j < N; j++) {
			if (build_h[i] <= build_h[j]) {
				sol = max(sol, abs(i-j));
					
				break;
			}
		}
	}
	//
	printf("%d\n", sol);

	//printf("i:%d j:%d Àý´ë°ª:%d\n", i, j, abs(i - j));
	//printf("build[i] : %d , build[j] :%d\n", build_h[i], build_h[j]);
	return 0;
}