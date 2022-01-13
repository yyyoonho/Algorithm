#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//백준_1915_가장 큰 정사각형 

int n,m;
int dp[1001][1001];
char a; 

int getMin(int a, int b, int c){
	int n1=a;
	if(n1>b) n1=b;
	if(n1>c) n1=c;
	return n1;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin>>n>>m;
	
	int ans=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a;
			dp[i][j]=a-'0';
			
			if(dp[i][j]==1){
				dp[i][j]+=getMin(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
				ans=max(ans,dp[i][j]);
			}
		}
	}
	
	cout<<ans*ans;


	return 0; 
}
