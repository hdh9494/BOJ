#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

#define MAX 100001
using namespace std;

struct Time {
	int start;
	int end;
};

int N;

Time t[MAX];


// 끝나는 시간을 기준으로 오름차순 정렬.
bool cmp(Time A, Time B)
{
	if (A.end == B.end)
		return A.start < B.start;
	else
		return A.end < B.end;
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &t[i].start, &t[i].end);

	sort(t, t + N, cmp);

	int now = 0, sol = 0;

	for (int i = 0; i < N; i++)
	{
		// 현재 시간이 다음번에 올 수 있는 시작 시간과 가장 가까운 값이면
		if (now <= t[i].start)
		{
			// 현재시간을 가장 가까운 시간의 끝나는 시간으로 바꾸고
			now = t[i].end;

			// 결과값 ++
			sol += 1;
		}
	}

	printf("%d\n", sol);
	return 0;

}