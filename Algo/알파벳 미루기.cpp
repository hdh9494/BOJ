#pragma warning(disable : 4996)

#include <stdio.h>

int main(void)
{
	char str[20];
	scanf("%[^\n]s", str);

	for (int i = 0; str[i]; i++) {
		printf("%d ", str[i]);
	}
	printf("\n");

	for (int i = 0; str[i] ; i++) {
		if (str[i] + 7 >= 72 && str[i] + 7 <= 90)
			str[i] = str[i] + 7;

		else if (str[i] + 7 >= 104 && str[i] + 7 <= 122)
			str[i] = str[i] + 7;
	}

	for (int i = 0; str[i] ; i++) {
		printf("%d ", str[i]);
	}
	printf("\n");

	for (int i = 0; str[i]; i++) {
		printf("%c", str[i]);
	}

	printf("\n");

	
}