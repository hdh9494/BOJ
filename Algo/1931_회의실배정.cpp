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


// ������ �ð��� �������� �������� ����.
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
		// ���� �ð��� �������� �� �� �ִ� ���� �ð��� ���� ����� ���̸�
		if (now <= t[i].start)
		{
			// ����ð��� ���� ����� �ð��� ������ �ð����� �ٲٰ�
			now = t[i].end;

			// ����� ++
			sol += 1;
		}
	}

	printf("%d\n", sol);
	return 0;

}