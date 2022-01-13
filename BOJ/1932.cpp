#include <iostream>
#include <cstring>

using namespace std;

//백준_1932_정수삼각형 

#define MAXN 501
int n;
int map[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "rt", stdin);
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++){
			cin>>map[i][j];
		}
	}
	
	memset(dp,-1,sizeof(dp));
	
	dp[0][0]=map[0][0];
	
	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0){
				dp[i][j]=dp[i-1][j]+map[i][j];
			}
			else if(j==i){
				dp[i][j]=dp[i-1][j-1]+map[i][j];
			}
			else{
				dp[i][j]=map[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
			}
		}
	}

	int ans=-1;
	for(int i=0; i<n; i++){
		ans=max(ans,dp[n-1][i]);
	}
	
	cout<<ans<<endl;

	return 0; 
}
