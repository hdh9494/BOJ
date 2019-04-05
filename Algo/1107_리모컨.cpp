#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int remote[10] = { 1 };

int possible(int n) {      
	if (n == 0) {
		if (remote[0] != -1) return 1;   // 고장 안났다면
		else return -1;               // 고장 났다면
	}

	int len = 0;
	int cur = 0;

	// len : 고장나지 않은 버튼을 누르는 횟수
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

		// 고장난 버튼 : -1
		remote[tp] = -1;      
	}

	int cur = abs(100 - N);   // 현재에서 목표까지

	int res = 0, minVal = 1000000, press = 0;

	for (int i = 0; i < 1000000; i++) {

		// 계산값은
		// 현재 버튼에서 +,-로 이동하는 횟수(abs(N-i)) 와
		// 현재 버튼을 누르는 횟수(possible(i)) 를 더한 값
		press = possible(i);

		if (press > 0) {

			// 백준 첫번째 예시 기준으로 (N:5457 , 고장번호 : 6,7,8)
			// i가 5455 일때,

			// abs(N-i)  :  abs(5457 - 5455) = 2
			// press     :  번호를 직접 찍은 횟수(5455) = 4
			res = abs(N - i) + press;

			// 이런식으로 완탐을 돌림.
			if (res < minVal) {
				minVal = res;
			}

		}
	}

	int ret = min(minVal, cur);

	printf("%d\n", ret);

	return 0;
}


/*	다른 풀이


	1. 각 자리의 숫자는 무엇이고 총 몇자리 수인지 파악하기
	2. 재귀적으로 값을 찾고(현재의 값과 맞춰야 할 값의 차이를 보면서)가장 작은 값을 조사하기
	3. 값을 비교하기

	1.

	총 몇자리 수인지 파악합니다.
	각 자리의 숫자를 num[6] 배열에 넣어줍니다.
	코드에선 sep() 함수와 sepa() 함수가 이를 처리합니다.

	2.

	find()함수는 두가지의 인자를 받습니다 : 현재의 값인 n, 그리고 그 n의 자리수를 알려주는 cnt.
	현재의 값과 처음에 입력받은 N의 값을 비교해주면서 (둘의 차이) + (n의 자리수인 cnt)의 최솟값을 구합니다.
	여기서 이 최솟값은 N보다 하나 작은 자리수일수도 있고, 하나 큰 자리수일수도 있습니다. 각각의 경우를 다 구해야 합니다.

	3.

	나온 값과 기본값인 100에서 N의 차이를 비교해서 더 작은쪽을 출력합니다.


int remote[10];
int num[6];
int N, M;
int res = 9999999;
int len;

// N의 각 자리수를 num배열에 입력
void seperate_num(int n)
{
	int temp = N;
	for (int i = n - 1; i >= 0; i--)
	{
		num[i] = temp % 10;
		temp /= 10;
	}
}

// N이 몇자리의 수인지 확인
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