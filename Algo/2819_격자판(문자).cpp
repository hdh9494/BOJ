#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int res;
char arr[4][4];
bool result[10000000];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

bool boundary(int row, int col) {
	if (row < 0 || col < 0 || row >= 4 || col >= 4)
		return false;
	return true;
}

void dfs(int row, int col, string str) {
	if (!boundary(row, col))
		return;

	str += arr[row][col];
	if (str.length() == 7) {
		if (result[stoi(str)])
			return;
		result[stoi(str)] = true;
		res++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		dfs(nr, nc, str);
	}
}

int main() {
	int testNum;
	cin >> testNum;

	for (int testCase = 1; testCase <= testNum; testCase++) {
		res = 0;
		memset(result, false, sizeof(result));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cin >> arr[i][j];
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				dfs(i, j, "");
		}
		cout << "#" << testCase << " " << res << endl;
	}
	return 0;
}