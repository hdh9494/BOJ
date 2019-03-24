#pragma warning(disable : 4996)

#include <cstdio>

void strcpy_test(char *A, char *B)
{
	for (int i = 0; ; i++)
	{
		A[i] = B[i];
		if (A[i] == '\0')
			break;
	}
}

void strcpy_test2(char *A, char *B)
{
	int i = 0;
	while (B[i++] == '\0')
		*A++ = *B++;
}

int main(void)
{
	char A[100];
	char B[100];

	scanf("%s", B);
	
	strcpy_test2(A, B);
	
	printf("strcpy ÈÄ Ãâ·Â\n");
	printf("%s\n", A);

	return 0;

}