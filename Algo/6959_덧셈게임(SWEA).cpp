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

		// strlen은 null 직전까지의 문자열 갯수를 cnt한다.
		while (strlen(num) > 1)
		{
			int temp;
			int len = strlen(num);

			// '0'를 빼는 이유는 char형에서 int형으로 변환(ASCII)
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