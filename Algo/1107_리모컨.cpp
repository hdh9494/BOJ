#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int remote[10] = { 1 };

int possible(int n) {      
	if (n == 0) {
		if (remote[0] != -1) return 1;   // ���� �ȳ��ٸ�
		else return -1;               // ���� ���ٸ�
	}

	int len = 0;
	int cur = 0;

	// len : ���峪�� ���� ��ư�� ������ Ƚ��
	while (n > 0)
	{
		if (remote[n % 10] == -1)
			return -1;
		else
		{
			n /= 10;
			len++;
		}
	}

	return len;
}

int main() {
	int N = 0;
	int M = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	int tp = 0;

	for (int i = 0; i < M; i++) {
		scanf("%d", &tp);

		// ���峭 ��ư : -1
		remote[tp] = -1;      
	}

	int cur = abs(100 - N);   // ���翡�� ��ǥ����

	int res = 0, minVal = 1000000, press = 0;

	for (int i = 0; i < 1000000; i++) {

		// ��갪��
		// ���� ��ư���� +,-�� �̵��ϴ� Ƚ��(abs(N-i)) ��
		// ���� ��ư�� ������ Ƚ��(possible(i)) �� ���� ��
		press = possible(i);

		if (press > 0) {

			// ���� ù��° ���� �������� (N:5457 , �����ȣ : 6,7,8)
			// i�� 5455 �϶�,

			// abs(N-i)  :  abs(5457 - 5455) = 2
			// press     :  ��ȣ�� ���� ���� Ƚ��(5455) = 4
			res = abs(N - i) + press;

			// �̷������� ��Ž�� ����.
			if (res < minVal) {
				minVal = res;
			}

		}
	}

	int ret = min(minVal, cur);

	printf("%d\n", ret);

	return 0;
}


/*	�ٸ� Ǯ��


	1. �� �ڸ��� ���ڴ� �����̰� �� ���ڸ� ������ �ľ��ϱ�
	2. ��������� ���� ã��(������ ���� ����� �� ���� ���̸� ���鼭)���� ���� ���� �����ϱ�
	3. ���� ���ϱ�

	1.

	�� ���ڸ� ������ �ľ��մϴ�.
	�� �ڸ��� ���ڸ� num[6] �迭�� �־��ݴϴ�.
	�ڵ忡�� sep() �Լ��� sepa() �Լ��� �̸� ó���մϴ�.

	2.

	find()�Լ��� �ΰ����� ���ڸ� �޽��ϴ� : ������ ���� n, �׸��� �� n�� �ڸ����� �˷��ִ� cnt.
	������ ���� ó���� �Է¹��� N�� ���� �����ָ鼭 (���� ����) + (n�� �ڸ����� cnt)�� �ּڰ��� ���մϴ�.
	���⼭ �� �ּڰ��� N���� �ϳ� ���� �ڸ����ϼ��� �ְ�, �ϳ� ū �ڸ����ϼ��� �ֽ��ϴ�. ������ ��츦 �� ���ؾ� �մϴ�.

	3.

	���� ���� �⺻���� 100���� N�� ���̸� ���ؼ� �� �������� ����մϴ�.


int remote[10];
int num[6];
int N, M;
int res = 9999999;
int len;

// N�� �� �ڸ����� num�迭�� �Է�
void seperate_num(int n)
{
	int temp = N;
	for (int i = n - 1; i >= 0; i--)
	{
		num[i] = temp % 10;
		temp /= 10;
	}
}

// N�� ���ڸ��� ������ Ȯ��
int cal_len(int n)
{
	int cnt = 0;
	while (n > 0) {

		if (n == 0)
			break;

		n /= 10;
		cnt++;

	}
	return cnt;
}

void find(int n, int cnt) {

	if (cnt == len) {
		if (abs(n - N) + cnt < res)
			res = abs(n - N) + cnt;
	}

	else if (cnt == len - 1) {
		if (abs(n - N) + cnt < res)
			res = abs(n - N) + cnt;
	}

	else if (cnt == len + 1) {
		if (abs(n - N) + cnt < res)
			res = abs(n - N) + cnt;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!remote[i]) continue;
		find(10 * n + i, cnt + 1);
	}
}


int main(void)
{
	memset(remote, 1, sizeof(remote));
	scanf("%d", &N);
	scanf("%d", &M);

	int temp;
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		remote[temp] = 0;
	}

	len = cal_len(N);
	seperate_num(len);

	for (int i = 0; i < 10; i++)
	{
		if (remote[i])
			find(i, 1);
	}

	if (res > abs(N - 100))
		res = abs(N - 100);

	printf("%d\n", res);
	return 0;
}
*/