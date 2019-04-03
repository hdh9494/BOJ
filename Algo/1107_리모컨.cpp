#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int min = 1000000;
int N, M, l, length;
int val_1, val_2;

int broken[10];

int possible(int num)
{
	int length = 0;

	// num이 0일 때
	// 0번 버튼이 고장X -> 0 반환 / 0번 버튼 고장 -> 1 반환
	if (num == 0)
		return broken[0] ? 0 : 1;

	while (num)
	{
		length++;

		// num의 각 자리 숫자가 고장난 버튼에 포함되어 있으면 return;
		if (broken[num % 10]) return 0;
		num /= 10;
	}

	// 고장난 버튼이 포함되어 있지 않다면, num의 길이값 return;
	return length;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	// case1) N번에 +,- 버튼으로만 접근하는 경우
	val_1 = abs(N - 100);

	// case2) 버튼 눌러서 N번에 접근하는 경우
	for (int i = 0; i < M; i++) {
		int v;
		scanf("%d", &v);
		broken[v] = 1;
	}

	for (int i = 0; i < 1000001; i++)
	{
		length = possible(i);
		
		if (length)
		{
			int k = N - i;
			if (k < 0)
				k = k * -1;
			if (k < 9999999) {
				min = 
			}
		}
	}

	
}