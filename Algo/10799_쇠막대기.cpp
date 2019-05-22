#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

int stack[100001] = { 0, };
int s_size = 0;
int top = -1;
int sol;

void push(int num)
{
	stack[++top] = num;
	s_size++;
}

int pop()
{
	s_size--;
	if (top == -1)
		return 0;
	else
		return stack[top--];
}

int empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int main(void)
{
	char str[100001];
	int cnt = 0;
	scanf("%s", str);

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
		{
			if (str[i + 1] == ')'){
				i++;
				if (!empty()){
					for (int k = 0; k < s_size; k++) {
						stack[k]++;
					}
				}
			}

			else {
				push(0);
			}
		}

		else if(str[i] == ')')
		{
			int res = pop();
			sol += res + 1;
		}
	}

	printf("%d\n", sol);
	return 0;
}