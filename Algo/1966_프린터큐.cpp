#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	int tc = 0;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++)
	{
		int n = 0, m = 0, cnt = 0;
		queue <pair<int, int>> q;
		priority_queue<int> pq;

		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			int w;
			scanf("%d", &w);
			// (인덱스, 가중치)
			q.push(make_pair(i, w));
			pq.push(w);
		}

		while (!q.empty())
		{
			int now_idx = q.front().first;
			int now_weight = q.front().second;
			q.pop();

			if (pq.top() == now_weight)
			{
				pq.pop();
				cnt++;

				if (now_idx == m)
				{
					printf("%d\n", cnt);
					break;
				}
			}
			else
				q.push(make_pair(now_idx, now_weight));
		}
	}
	return 0;
}
