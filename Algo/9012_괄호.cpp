#pragma warning(disable : 4996)

#include <cstdio>
#include <stack>

using namespace std;

int main(void)
{

	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++)
	{
		stack <char> st;
		char s[55];

		scanf("%s", s);

		for (int i = 0; s[i]; i++)
		{
			if (s[i] == '(' || st.empty())
				st.push(s[i]);
			else if (st.top() == '(')
				st.pop();
		}

		if (st.empty())
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}