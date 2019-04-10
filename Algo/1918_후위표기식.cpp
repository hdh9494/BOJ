#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
string res;

stack <char> s;

int main(void)
{
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		// 피연산자
		if ('A' <= str[i] && str[i] <= 'Z')
			res += str[i];

		// 연산자
		else
		{
			switch (str[i])
			{
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				while (!s.empty() && (s.top() == '*' || s.top() == '/'))
				{
					res += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;
			case '+':
			case '-':

				while (!s.empty() && s.top() != '(')
				{
					res += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;

			case ')':

				while (!s.empty() && s.top() != '(')
				{
					res += s.top();
					s.pop();
				}

				s.pop();
				break;
			}
		}
	}

	while (!s.empty())
	{
		res += s.top();
		s.pop();
	}

	cout << res << '\n';
	return 0;
}

