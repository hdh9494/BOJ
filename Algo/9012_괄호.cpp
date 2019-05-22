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

/*

int main(void)
{
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		int cnt1 = 0, cnt2 = 0;
		bool flag = false;
		stack <int> st;
		char str[51] = { 0, };

		scanf("%s", str);

		for (int j = 0; str[j]; j++)
		{
			if (str[j] == '(')
			{
				st.push(1);
				cnt1++;
			}

			else if (str[j] == ')')
			{
				if (st.empty()) {
					flag = true;
					break;
				}

				else {
					st.pop();
					cnt2++;
				}
			}
		}

		if (cnt1 == cnt2 && !flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

*/