#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_12865
//DP 

#define MAXK 100005
#define MAXN 105
int N,K;
int dp[MAXN][MAXK];

struct Item{
	int w;
	int v;
	Item(int w1, int v1){
		w=w1;
		v=v1;
	}
	bool operator<(const Item& b)const{
		return w>b.w;
	}
};

priority_queue<Item> pQ;

void Input(){
	cin>>N>>K;
	int w,v;
	for(int i=0; i<N; i++){
		cin>>w>>v;
		pQ.push(Item(w,v));
	}
}

void Solve(){
	for(int i=1; i<=N; i++){
		Item now = pQ.top();
		int nowW=now.w;
		int nowV=now.v;
		pQ.pop();
		
		for(int j=1; j<=K; j++){
			if(j<nowW){
				dp[i][j]=dp[i-1][j];
				continue;
			}
			dp[i][j]=max(dp[i-1][j],nowV+dp[i-1][j-nowW]);
		}
	}

	cout<<dp[N][K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
