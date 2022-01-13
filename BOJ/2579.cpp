#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//백준_2579_계단오르기

int stair[301];
int dp[301]; 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>stair[i];
	}
	
	dp[0]=0;
	dp[1]=stair[1];
	dp[2]=stair[1]+stair[2];
	
	for(int i=3; i<=n; i++){
		dp[i]=max(dp[i-2],dp[i-3]+stair[i-1])+stair[i];
	}
	
	cout<<dp[n]<<endl;


	return 0; 
}
