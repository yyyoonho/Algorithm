#include <algorithm>
#include <iostream>

using namespace std;

//백준_11051_이항계수2

#define MAXN 1001
int N,K; 
int dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>K;
	
	dp[0][0]=1;
	for(int i=1; i<=N; i++){
		dp[i][0]=1;
		for(int j=1; j<=N; j++){
			dp[i][j]=(dp[i-1][j-1] + dp[i-1][j])%10007;
		}
	}
	
	cout<<dp[N][K];

	return 0; 
}
