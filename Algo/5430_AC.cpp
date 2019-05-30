#pragma warning(disable : 4996)

#include <iostream>
#include <cstdio>
#include <string>
#include <deque>

using namespace std;

deque<int> dq;

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++)
	{
		bool error_ = false;
		bool reverse_ = true;

		string p, x, tmp;
		int n;

		cin >> p >> n >> x;

		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == '[')
				continue;
			else if ('0' <= x[i] && x[i] <= '9')
				tmp += x[i];
			else if (x[i] == ',' || x[i] == ']')
			{
				if (!tmp.empty())
				{
					dq.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}

		
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
				reverse_ = !reverse_;
			else
			{
				if (dq.empty())
				{
					error_ = true;
					printf("error\n");
					break;
				}
				else
				{
					if (reverse_)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (!error_)
		{
			if (reverse_)
			{
				printf("[");
				while (!dq.empty())
				{
					printf("%d", dq.front());
					dq.pop_front();
					if (!dq.empty())
						printf(",");
				}
				printf("]\n");
			}

			else
			{
				printf("[");
				while (!dq.empty())
				{
					printf("%d", dq.back());
					dq.pop_back();
					if (!dq.empty())
						printf(",");
				}
				printf("]\n");
			}
		}
	}
	return 0;
}