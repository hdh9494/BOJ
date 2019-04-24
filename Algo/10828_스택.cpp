#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector <int> stack;
int top = -1;

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string str;
		int num;

		cin >> str;

		if (!str.compare("push")) {
			cin >> num;
			if (top > 10000)
				break;
			
			stack.push_back(num);
			top++;
		}

		else if (!str.compare("pop")) {
			if (top == -1)
				printf("-1\n");

			else {
				int val = stack[top];
				printf("%d\n", val);
				stack.pop_back();
				top--;
			}
		}

		else if (!str.compare("top")) {
			if (top == -1)
				printf("-1\n");
			else {
				int val = stack[top];
				printf("%d\n", val);
			}
		}

		else if (!str.compare("empty")) {
			if (top == -1)
				printf("1\n");
			else
				printf("0\n");
		}

		else if (!str.compare("size")) {
			int len = stack.size();
			printf("%d\n", len);
		}
	}
	return 0;
}