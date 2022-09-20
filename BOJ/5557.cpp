#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_5557
//DP

int N;
int arr[101];
long long dp[101][21]; 

void Input(){
	cin>>N;
	for(int i=1; i<=N;i++){
		cin>>arr[i];
	}
}

void Solve(){
	dp[1][arr[1]]++;
	for(int i=2; i<=N-1; i++){
		for(int j=0; j<=20; j++){
			if(dp[i-1][j]==0) continue;
			
			if(j+arr[i]<=20){
				dp[i][j+arr[i]]+=dp[i-1][j];
			}
			if(j-arr[i]>=0){
				dp[i][j-arr[i]]+=dp[i-1][j];
			}
		}
	}
	
	cout<<dp[N-1][arr[N]];
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
