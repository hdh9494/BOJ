#pragma warning(disable : 4996)

#include <cstdio>

int N, M;

// �����佺�׳׽��� ü
// 1. 2���� �Ҽ��� ���ϰ��� �ϴ� ������ ��� ���� �����Ѵ�
// 2. �ڱ� �ڽ��� ������ 2�� ����� ��� �����.
// 3. �ڱ� �ڽ��� ������ 3�� ����� ��� �����.
// 4. �ڱ� �ڽ��� ������ 5�� ����� ��� �����.
// 5. �ڱ� �ڽ��� ������ 7�� ����� ��� �����.
// ���� ������ �ݺ��ϸ� ���ϴ� ������ ��� �Ҽ��� ���´�.
int main(void)
{
	bool num[1000001] = { false };
	scanf("%d %d", &N, &M);

	num[1] = true;

	for (int i = 2; (i*i) <= 1000000; i++) {
		if (!num[i]) {
			for (int j = i + i; j <= 1000000; j += i)
				num[j] = true;
		}
	}

	for (int i = N; i <= M; i++)
		if (!num[i])
			printf("%d\n", i);

	return 0;

}

/* �Ϲ� �Ҽ� ���ϱ�
bool isSosu(int num)
{
	if (num == 1)
		return false;

	int cnt = 0;
	for (int i = 1; i <= num; i++) {
		if (num%i == 0)
			cnt++;

		if (cnt > 2)
			return false;
	}

	if (cnt == 2)
		return true;
}


int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = N; i <= M; i++) 
		if (isSosu(i))
			printf("%d\n", i);
	
	return 0;
}
*/