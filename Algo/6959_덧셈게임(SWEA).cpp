#pragma warning(disable : 4996)

#include <cstdio>
#include <string.h>

using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int tc = 1 ; tc<=T ; tc++)
	{
		char num[1001];
		scanf("%s", num);

		int cnt = 0;

		// strlen�� null ���������� ���ڿ� ������ cnt�Ѵ�.
		while (strlen(num) > 1)
		{
			int temp;
			int len = strlen(num);

			// '0'�� ���� ������ char������ int������ ��ȯ(ASCII)
			temp = num[len - 1] - '0' + num[len - 2] - '0';

			if (temp > 9){
				num[len - 1] = temp % 10 + '0';
				num[len - 2] = '1';
			}
			else {
				num[len - 1] = '\0';
				num[len - 2] = temp + '0';
			}
			
			cnt++;
		}

		printf("#%d %c\n",tc, cnt%2 == 0 ? 'B' : 'A');
	}

	return 0;
}	