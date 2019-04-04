#pragma warning(disable : 4996)

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

#define MAX 10000
using namespace std;

int A, B;

int D(int num)
{
	return (num * 2) % 10000;
}

int S(int num)
{
	return (num + 9999) % 10000;
}

int L(int num)
{
	int tmp1 = num / 1000;
	int tmp2 = num - 1000 * tmp1;

	return tmp2 * 10 + tmp1;
}

int R(int num)
{
	int tmp = num % 10;

	return num / 10 + tmp * 1000;
}

void bfs(int A, int B)
{
	bool visit[MAX] = { 0, };

	queue <pair<int,string>> q;

	q.push(make_pair(A, ""));
	visit[A] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		string s = q.front().second;
		q.pop();

		if (cur == B) {
			printf("%s\n", s);
			break;
		}
		
		int next;
		next = D(cur);
		if (!visit[next])
		{
			q.push(make_pair(next, s + "D"));
			visit[next] = true;
		}

		next = S(cur);
		if (!visit[next]) {
			q.push(make_pair(next, s + "S"));
			visit[next] = true;
		}

		next = L(cur);
		if (!visit[next]) {
			q.push(make_pair(next, s + "L"));
			visit[next] = true;
		}

		next = R(cur);
		if (!visit[next])
		{
			q.push(make_pair(next, s + "R"));
			visit[next] = true;
		}
		
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &A, &B);
		bfs(A, B);
	}
	return 0;
}