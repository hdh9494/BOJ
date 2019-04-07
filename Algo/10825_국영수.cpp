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

1. 국어 점수가 감소하는 순서로
2 .국어 점수가 같으면 영어 점수가 증가하는 순서로
3. 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
4. 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 
   (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)

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

