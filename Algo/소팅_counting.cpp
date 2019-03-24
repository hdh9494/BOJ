#pragma warning(disable : 4996)

#include <stdio.h>
#define MAXLEN 10

void main()

{
	int Data[MAXLEN] = { 8, 1, 3, 2, 9, 9, 7, 10, 5, 2 }; // item is 1 <= N <= 10
	int ret[MAXLEN] = { 0, };
	int count[MAXLEN];
	int idx = 0;

	//init count index

	for (int i = 0; i <= MAXLEN; i++)
		count[i] = 0;

	for (int i = 0; i < MAXLEN; i++)
		count[Data[i]] += 1;

	idx = MAXLEN - 1;

	for (int i = MAXLEN; i > 0; i--)
	{
		while (count[i] > 0)
		{
			ret[idx--] = i;
			count[i] -= 1;
		}
	}

	printf("{");
	for (int i = 0; i < MAXLEN; i++)
		printf("%d,", ret[i]);
	printf("}\n");

}

