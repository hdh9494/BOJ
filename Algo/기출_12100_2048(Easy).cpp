#pragma warning(disable : 4996)

#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 20

using namespace std;

int N;
int sol;

int map[MAX][MAX];

void copy_map(int(*a)[MAX], int(*b)[MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void merge(int dir)
{
	queue <int> q;

	// �� - (��)
	if (dir == 0){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0)
					q.push(map[i][j]);
				map[i][j] = 0;
			}

			int idx = 0;
			int pop_data;

			while (!q.empty())
			{
				pop_data = q.front();
				q.pop();

				// �� ó�� ��������� data ����.
				// idx ���� X - ���� ���� ���ϱ� ����
				if (map[i][idx] == 0) map[i][idx] = pop_data;

				// ������ �ִ� �����Ϳ� ���� ���� ����, 2�� ����
				// idx++
				else if (map[i][idx] == pop_data) {
					map[i][idx] *= 2;
					idx++;
				}

				// ������ �ִ� �����Ϳ� �ٸ� ���� ����
				// ++idx �Ͽ� ������ ����.
				else map[i][++idx] = pop_data;			
			}
		}
	}
	
	// �� - (��)
	else if (dir == 1){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[j][i] != 0)
					q.push(map[j][i]);
				map[j][i] = 0;
			}

			int idx = 0;
			int pop_data;

			while (!q.empty())
			{
				pop_data = q.front();
				q.pop();

				if (map[idx][i] == 0) map[idx][i] = pop_data;
				else if (map[idx][i] == pop_data) {
					map[idx][i] *= 2;
					idx++;
				}
				else map[++idx][i] = pop_data;
			}			
		}
	}

	// �� - (��)
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] != 0) 
					q.push(map[i][j]);
				map[i][j] = 0;
			}
			
			int idx = N - 1;
			int pop_data;

			while (!q.empty())
			{
				pop_data = q.front();
				q.pop();

				if (map[i][idx] == 0) map[i][idx] = pop_data;
				else if (map[i][idx] == pop_data) {
					map[i][idx] *= 2;
					idx--;
				}
				else map[i][--idx] = pop_data;
			}
		}
	}


	// �� - (��)
	else if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[j][i] != 0) 
					q.push(map[j][i]);
				map[j][i] = 0;
			}

			int idx = N - 1;
			int pop_data;

			while (!q.empty())
			{
				pop_data = q.front();
				q.pop();

				if (map[idx][i] == 0) map[idx][i] = pop_data;
				else if (map[idx][i] == pop_data) {
					map[idx][i] *= 2;
					idx--;
				}
				else map[--idx][i] = pop_data;
			}
		}
	}
}

void dfs(int cnt)
{
	if (cnt == 5)
	{
		// �迭�� �ִ밪 ���ϱ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sol = max(sol, map[i][j]);
			}
		}
		return;
	}

	int temp[MAX][MAX];
	copy_map(temp, map);

	for (int i = 0; i < 4; i++)
	{
		merge(i);
		dfs(cnt + 1);
		copy_map(map, temp);
	}
	
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0);
	printf("%d\n", sol);
	return 0;
}