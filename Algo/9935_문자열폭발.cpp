#pragma warning(disable : 4996)

#include <cstdio>

using namespace std;

char str[1000001];
char boom[40];

int chk_len(char str[])
{
	int res = 0;
	for (int i = 0; str[i]; i++)
		res++;

	return res;
}

int main(void)
{
	scanf("%s", str);
	scanf("%s", boom);

	int boom_len = chk_len(boom);
	int cnt = 0;
	bool cont_flag;

	while (1)
	{
		cont_flag = false;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == boom[0])
			{
				int start_idx = i;

				// 폭탄 문자열 같은지 여부 판단
				bool boom_same_flag = true;
				for (int j = 1; j < boom_len; j++)
				{
					if (str[++i] != boom[j]) {
						boom_same_flag = false;
						break;
					}
				}

				// 폭탄 문자열과 같다면
				// 문자열 제거 후, 그 길이만큼 앞으로 이동
				if (boom_same_flag)
				{
					int cnt = boom_len;
					while (str[start_idx])
					{
						str[start_idx] = str[start_idx + boom_len];
						start_idx++;
					}
					cont_flag = true;
					break;
				}

				i = start_idx;
			}
		}

		if (!cont_flag)
			break;
	}

	if(str[0])
		printf("%s\n", str);
	else
		printf("FRULA\n");
	return 0;
	
}