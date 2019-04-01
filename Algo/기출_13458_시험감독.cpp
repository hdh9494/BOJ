#pragma warning(disable : 4996)
#include <cstdio>

using namespace std;

long N;
long map[1000001];
long B, C;

int main(void)
{
	scanf("%ld", &N);
	for (int i = 0; i < N; i++)
		scanf("%ld", &map[i]);
	scanf("%ld %ld", &B, &C);

	long val = 0;
	long total = 0;
	for (int i = 0; i < N; i++)
	{
		long cnt1 = 0;
		long cnt2 = 0;
		val = map[i];
		val -= B;

		if (val <= 0)
			cnt1++;
		else {
			if (val % C != 0)
				cnt2 = val / C + 1;
			else
				cnt2 = val / C;
			cnt2 += 1;
		}

		total += cnt1 + cnt2;
	}

	printf("%ld\n", total);
	return 0;
}