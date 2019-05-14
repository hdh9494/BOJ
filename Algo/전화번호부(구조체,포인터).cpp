#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
	char name[20];
	char number[20];
}User;

void insert(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);


int main(void)
{
	int input;
	int person = 0; //
	User user[MAX];

	while (1)
	{
		printf("***** Menu *****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Print All\n");
		printf("5. Exit\n");
		printf("Choose the menu : ");
		scanf("%d", &input);

		if (input == 1)
		{
			printf("\n[Insert]\n");
			insert(user, &person);
		}

		else if (input == 2)
		{
			printf("\n[Delete]\n");
			deleted(user, &person);
		}

		else if (input == 3)
		{
			printf("\n[Search]\n");
			search(user, &person);
		}

		else if (input == 4)
		{
			printf("\n[Print All]\n");
			printAll(user, &person);
		}

		else if (input == 5)
		{
			printf("\n[Exit]\n");
			break;
		}

		else
			printf("\nError ! Please Retry !\n\n");
	}
	
	return 0;
}

void insert(User* ptr, int *num)
{
	if (*num < MAX)
	{
		printf("Input Name : ");
		scanf("%s", ptr[*num].name);

		printf("Input TEL Number : ");
		scanf("%s", ptr[*num].number);

		(*num)++;

		printf("Data Inesert Completed!\n");
	}

	else
		printf("Data Full !!\n");
}

int deleted(User* ptr, int *num)
{
	char name[30];

	// 데이터 갯수가 1개라도 있으면
	if (*num > 0)
	{
		printf("Input Name : ");
		scanf("%s", name);

		for (int i = 0; i < MAX; i++)
		{
			if (!strcmp(name, ptr[i].name))
			{
				(*num)--;
				printf("Data Deleted !!\n");

				// 데이터가 가득 차지 않았다면, 지우는 영역을 기준으로 한칸씩 앞으로 이동
				if (i != MAX - 1)
				{
					for (int j = i; j < MAX; j++)
					{
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
					}

					// 맨 마지막 데이터 제거
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
				}


				// 데이터가 가득 찼다면
				else
				{
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
				}

				return 0;
			}
		}

		// 해당 이름을 찾을 수 없다면
		printf("Not Found \n");
		return 0;
	}

	// 저장된 유저 정보가 없다면
	else
	{
		printf("No Data \n");
		return 0;
	}
}


int search(User * ptr, int * num)
{
	char name[30];

	if (*num > 0)
	{
		printf("Insert name : ");
		scanf("%s", name);

		for (int i = 0; i < MAX; i++)
		{
			if (!strcmp(name, ptr[i].name))
			{
				printf("Name : %s ", ptr[i].name);
				printf("Number : %s\n", ptr[i].number);
				printf("Data Found !\n");
				return 0;
			}
		}

		printf("Not Found !\n");
		return 0;
	}

	else
	{
		printf("No data ! \n");
		return 0;
	}
}

void printAll(User * ptr, int *num)
{
	if (*num > 0)
	{
		for (int i = 0; i < (*num); i++)
		{
			printf("Name : %s ", ptr[i].name);
			printf("Number : %s\n", ptr[i].number);
		}

		printf("Data Allprint !\n");
	}
	else
		printf("No Data !\n");
}