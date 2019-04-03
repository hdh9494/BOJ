#pragma warning(disable : 4996)

#include <cstdio>

using namespace std;

int E, S, M;

int main(void)
{
	scanf("%d %d %d", &E, &S, &M);

	for (int val = 1; val < 10000; val++)
	{
		if (((val - 1) % 15) + 1 == 15 && ((val - 1) % 28) + 1 == 28 && ((val - 1) % 19) + 1 == 19) {
			printf("%d\n", val);
			break;
		}

	}
	return 0;
}