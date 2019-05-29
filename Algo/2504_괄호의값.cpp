#pragma warning(disable : 4996)

#include <cstdio>
#include <stack>

using namespace std;

int str_len(char str[])
{
	int res = 0;
	for (int i = 0; str[i]; i++)
		res++;

	return res;
}


int main(void)
{
	stack <char> st;
	char str[101];
	
	bool chk_err = false;
	int sum = 0;
	int tmp = 1;

	scanf("%s", str);

	int len = str_len(str);

	for (int s = 0; s < len ; s++)
	{
		if (str[s] == '(')
		{
			tmp *= 2;
			st.push('(');

			if (s + 1 < len && str[s + 1] == ')')
				sum += tmp;
		}

		else if (str[s] == '[')
		{
			tmp *= 3;
			st.push('[');

			if (s + 1 < len && str[s + 1] == ']')
				sum += tmp;
		}

		if (!st.empty())
		{
			if (str[s] == ')')
			{
				tmp /= 2;
				if (st.top() == '(')
					st.pop();
			}

			else if (str[s] == ']')
			{
				tmp /= 3;
				if (st.top() == '[')
					st.pop();
			}
		}

		else
			chk_err = true;
	}

	if (!st.empty() || chk_err)
		sum = 0;

	printf("%d\n", sum);
	return 0;

}

