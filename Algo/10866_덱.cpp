#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>
#include <deque>

using namespace std;

deque <int> dq;

int main(void)
{
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		char cmd[12] = { 0, };
		scanf("%s", cmd);

		// 1. push_back
		if (!strcmp(cmd, "push_back"))
		{
			int val1 = 0;
			scanf("%d", &val1);

			dq.push_back(val1);
		}

		// 2. push_front
		else if (!strcmp(cmd, "push_front"))
		{
			int val2 = 0;
			scanf("%d", &val2);

			dq.push_front(val2);
		}

		// 3. pop_front
		else if (!strcmp(cmd, "pop_front"))
		{
			if (!dq.empty())
			{
				printf("%d\n", dq.front());
				dq.pop_front();
			}

			else
				printf("-1\n");
		}

		// 4. pop_back
		else if (!strcmp(cmd, "pop_back"))
		{
			if (!dq.empty())
			{
				printf("%d\n", dq.back());
				dq.pop_back();
			}

			else
				printf("-1\n");
		}

		// 5. size
		else if (!strcmp(cmd, "size"))
		{
			printf("%d\n", dq.size());
		}

		// 6. empty
		else if (!strcmp(cmd, "empty"))
		{
			if (!dq.empty())
				printf("0\n");
			else
				printf("1\n");
		}

		// 7. front
		else if (!strcmp(cmd, "front"))
		{
			if (!dq.empty())
				printf("%d\n", dq.front());
			
			else
				printf("-1\n");
		}

		// 8. back
		else if (!strcmp(cmd, "back"))
		{
			if (!dq.empty())
				printf("%d\n", dq.back());
			else
				printf("-1\n");
		}
	}
	return 0;
}