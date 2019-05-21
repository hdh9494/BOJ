#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

int stack[100001];
int idx = -1;

int main(void)
{
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		char str[10] = { 0, };
		scanf("%s", str);

		// 1. push
		if (!strcmp(str, "push"))
		{
			int val = 0;
			scanf("%d", &val);

			stack[++idx] = val;
		}

		// 2. pop
		else if (!strcmp(str, "pop"))
		{
			if (idx == -1)
				printf("-1\n");
			else
				printf("%d\n", stack[idx--]);
		}

		// 3. top
		else if (!strcmp(str, "top"))
		{
			if (idx == -1)
				printf("-1\n");
			else
				printf("%d\n", stack[idx]);
		}

		// 4. empty
		else if (!strcmp(str, "empty"))
		{
			if (idx == -1)
				printf("1\n");
			else
				printf("0\n");
		}

		// 5. size
		else if (!strcmp(str, "size"))
		{
			if (idx == -1)
				printf("0\n");
			else
				printf("%d\n", idx + 1);
		}
	}
	return 0;
}