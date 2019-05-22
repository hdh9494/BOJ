#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

queue <int> q;

int main(void)
{
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		char cmd[6] = { 0, };
		scanf("%s", cmd);


		// 1. push
		if (!strcmp(cmd, "push"))
		{
			int val = 0;
			scanf("%d", &val);

			q.push(val);
		}

		// 2. pop
		else if (!strcmp(cmd, "pop"))
		{
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}

			else
				printf("-1\n");
		}

		// 3. size
		else if (!strcmp(cmd, "size"))
		{
			printf("%d\n", q.size());
		}

		// 4. empty
		else if (!strcmp(cmd, "empty"))
		{
			if (!q.empty())
				printf("0\n");
			else
				printf("1\n");
		}

		// 5. front
		else if (!strcmp(cmd, "front"))
		{
			if (!q.empty()) 
				printf("%d\n", q.front());
			else
				printf("-1\n");
		}

		// 6. back
		else if (!strcmp(cmd, "back"))
		{
			if (!q.empty())
				printf("%d\n", q.back());
			else
				printf("-1\n");
		}
	}
	return 0;
}