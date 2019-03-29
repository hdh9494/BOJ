#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector <int> vc;
	
	int N, val;
	scanf("%d", &N);

	for(int i= 0 ; i<N ; i++){
		scanf("%d", &val);
		vc.push_back(val);
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < vc.size(); i++)
		printf("%d\n", vc[i]);

	return 0;
		
}