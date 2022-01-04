#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

//백준_2748_피보나치수2 

long long dp[91];
long long n; 

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>n;
	
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2; i<=n; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	
	cout<<dp[n];
	
	return 0;
}
