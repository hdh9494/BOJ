#pragma warning(disable : 4996)

#include <cstdio>
#include <deque>

using namespace std;

deque <int> deq;
deque <int>::iterator iter;

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		deq.push_back(i);

	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		int input;
		scanf("%d", &input);

		int size = deq.size();
		int index = 1;

		// 찾고자 하는 수의 index 찾기.
		for (iter = deq.begin(); iter < deq.end(); iter++){
			if (*iter == input)
				break;
			index++;
		}

		int left = index - 1;
		int right = size - index + 1;

		if (left < right)
		{
			for (int i = 1; i <= left; i++) {
				deq.push_back(deq.at(0));
				deq.pop_front();
				cnt++;
			}
			deq.pop_front();
		}

		else
		{
			for (int i = 1; i <= right; i++)
			{
				deq.push_front(deq.at(size - 1));
				deq.pop_back();
				cnt++;
			}
			deq.pop_front();
		}
	}
	printf("%d\n", cnt);
	return 0;
}