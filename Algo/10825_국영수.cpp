#pragma warning(disable : 4996)

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 100001
using namespace std;

typedef struct student_ {
	string name;
	int language;
	int english;
	int math;
}STUDENT;

STUDENT s[100001];

/*

1. ���� ������ �����ϴ� ������
2 .���� ������ ������ ���� ������ �����ϴ� ������
3. ���� ������ ���� ������ ������ ���� ������ �����ϴ� ������
4. ��� ������ ������ �̸��� ���� ������ �����ϴ� ������ 
   (��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.)

*/

bool cmp(STUDENT A, STUDENT B)
{
	if (A.language == B.language)
	{
		if (A.english == B.english)
		{
			if (A.math == B.math)
				return A.name < B.name;
			else
				return A.math > B.math;
		}
		else
			return A.english < B.english;
	}
	else
		return A.language > B.language;
}


int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		cin >> s[i].name >> s[i].language >> s[i].english >> s[i].math;

	sort(s, s + N, cmp);

	for (int i = 0; i < N; i++)
		cout << s[i].name << '\n';
	return 0;
}

