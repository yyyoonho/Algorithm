#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
//boj_15989
//DP 

#define MAXN 10001
int T;
int n;
int dp[MAXN][4];

void Input(){
	cin>>T;
}

void Solve(){
	dp[0][1]=1;
		dp[1][1]=1;
		for(int i=2;i<MAXN;i++){
			dp[i][1]=dp[i-1][1];
			dp[i][2]=dp[i-2][1]+dp[i-2][2];
			if(i>=3){
				dp[i][3]=dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
			}
		}
		
	for(int t=0; t<T; t++){
		cin>>n;
		cout<<dp[n][1]+dp[n][2]+dp[n][3]<<'\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
