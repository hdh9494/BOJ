#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <algorithm>

#define MAX 100001
using namespace std;

// N (old)- ¼öºó, K (yound) - µ¿»ý
int N, K;
int sol;
bool visit[MAX];

int bfs(int old, int young)
{
	queue <pair<int, int>> q;
	q.push(make_pair(old,0));
	visit[old] = true;

	while (!q.empty())
	{
		int old_pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (old_pos == young)
			return time;

		if (old_pos + 1 < MAX && !visit[old_pos + 1]) {
			q.push(make_pair(old_pos + 1, time + 1));
			visit[old_pos + 1] = true;
		}

		if (0 <= old_pos - 1 && !visit[old_pos - 1]) {
			q.push(make_pair(old_pos - 1, time + 1));
			visit[old_pos - 1] = true;
		}

		if (2 * old_pos < MAX && !visit[2 * old_pos]) {
			q.push(make_pair(2 * old_pos, time + 1));
			visit[2 * old_pos] = true;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &K);
	sol = bfs(N, K);
	printf("%d\n", sol);
	return 0;
}