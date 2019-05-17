#pragma warning(disable : 4996)

#include <cstdio>

int main(void)
{
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


	// 4. 주소값 먼저 ++ 한 후, *를 통해 접근하여 값 변경
	*ptr++ = 44;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");


	// 4. ptr++ 확인
	*ptr++ = 50;
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
}