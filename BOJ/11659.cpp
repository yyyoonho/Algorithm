#include <iostream>
#include <cstring>

using namespace std;

//백준_11659_구간합구하기4 

int N,M,i,j; 
int dp[100001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	
	int x;
	for(int i=1; i<=N; i++){
		cin>>x;
		dp[i]=dp[i-1]+x;
	}
	
	int a,b;
	for(int tc=0; tc<M; tc++){
		cin>>a>>b;
		cout<<dp[b]-dp[a-1]<<"\n";
	}

	return 0; 
}
