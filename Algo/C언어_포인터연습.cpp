#pragma warning(disable : 4996)

#include <stdio.h>

int main(void)
{
	printf("포인터 연산자 사용법 & 문제\n\n");
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int * ptr = arr;

	// 1. *를 통해 해당 주소에 있는 데이터에 바로 접근.
	//    즉, 주소값인 ptr은 변화가 X
	*(ptr + 1) = 20;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 2. 주소값인 ptr에 +2를 함으로써 3번째 파라미터를 가르키는 주소값으로 변경.
	ptr += 2;
	*ptr = 30;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 3. 주소값 먼저 ++ 한 후, *를 통해 접근하여 값 변경
	*(++ptr) = 40;
	//*++ptr = 40;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 4. *를 통해 ptr에 먼저 접근하고 ++ptr 연산을 수행
	++(*ptr);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 5. *를 통해 ptr에 먼저 접근하여 값 변경 후 / 주소값 ptr++
	*ptr++ = 44;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 5-1. ptr++ 확인
	*ptr++ = 50;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	
	printf("\n**포인터배열 vs 배열포인터**\n\n");
	// **포인터배열 vs 배열포인터**

	// 1. 포인터 배열 - 변수들의 주소를 담는 배열

	// 2. 배열 포인터 - 배열을 가르키는 포인터를 의미.
	
	int len = 0;
	
	int a = 10;
	int b = 20;
	int c = 30;



	// 1. 포인터 배열의 선언
	int *ptrArr[3] = { &a, &b, &c };

	// 2. 배열 포인터의 선언
	int arr1[2][3] = { 1,2,3,4,5,6 };
	int(*arrPtr)[3] = arr1;


	// 포인터 배열의 활용
	printf("포인터 배열의 활용\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", *ptrArr[i]);
	printf("\n\n");


	// 배열 포인터의 활용
	printf("배열 포인터의 활용\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arrPtr[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}