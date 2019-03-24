#pragma warning(disable : 4996)

#include <cstdio>

void strcpy_test(char *A, char *B)
{
	for (int i = 0 ; ; i++)
	{
		A[i] = B[i];
		if (A[i] == '\0')
			break;
	}
}

// 고치기
void strcpy_test2(char *A, char *B)
{
	while (*B != '\0')
		*A++ = *B;
}

int main(void)
{
	char A[100];
	char B[100];

	scanf("%s", B);
	
	strcpy_test2(A, B);
	
	printf("strcpy 후 출력\n");
	printf("%s\n", A);

	return 0;

}