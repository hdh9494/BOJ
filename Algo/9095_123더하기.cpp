#pragma warning(disable : 4996)

#include <cstdio>

using namespace std;

int N;
int sol = 0;

void dfs(int amount)
{
	if (amount > N)
		return;

	if (amount == N) {
		sol++;
		return;
	}

	for (int i = 1; i <= 3; i++)
		dfs(amount + i);
	
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		dfs(0);
		printf("%d\n", sol);
		sol = 0;
	}
	return 0;
}

/* DPµµ °¡´É
int main(){
	int n,testCase;
	cin>>testCase;

	for(int t=0;t<testCase;t++){
		cin>>n;

		int dp[11]={0};
		dp[1]=1, dp[2]=2, dp[3]=4;

		for(int i=4;i<=n;i++)
			dp[i]=dp[i-3]+dp[i-2]+dp[i-1];

		cout<<dp[n]<<endl;
	}
	return 0;
}
*/