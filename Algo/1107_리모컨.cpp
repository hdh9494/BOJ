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

	// num�� 0�� ��
	// 0�� ��ư�� ����X -> 0 ��ȯ / 0�� ��ư ���� -> 1 ��ȯ
	if (num == 0)
		return broken[0] ? 0 : 1;

	while (num)
	{
		length++;

		// num�� �� �ڸ� ���ڰ� ���峭 ��ư�� ���ԵǾ� ������ return;
		if (broken[num % 10]) return 0;
		num /= 10;
	}

	// ���峭 ��ư�� ���ԵǾ� ���� �ʴٸ�, num�� ���̰� return;
	return length;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	// case1) N���� +,- ��ư���θ� �����ϴ� ���
	val_1 = abs(N - 100);

	// case2) ��ư ������ N���� �����ϴ� ���
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