#include <bits/stdc++.h>

using namespace std;

//백준_1256_사전 

#define MAXN 100
#define MAXK 1000000000

int DP[MAXN*2+1][MAXN+1];
int N,M,K; 

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M>>K;
	
	N+=M;
	
	DP[0][0]=1;
	//조합 표 만들기
	for(int i=1; i<=N; i++){
		DP[i][0]=1;
		for(int j=1; j<=i && j<=M; j++){
			DP[i][j]=DP[i-1][j-1]+DP[i-1][j];
			//overflow 방지 최대값 고정
			if(DP[i][j]>MAXK) DP[i][j] = (MAXK+1);
		}
	} 
	
	if(DP[N][M]<K){
		cout<<"-1";
		return 0;
	}
	
	while(N){
		if(DP[N-1][M]>=K){
			cout<<"a";
		}
		else{
			cout<<"z";
			K-=DP[N-1][M];
			M--;
		}
		N--;
	}
	
	return 0; 
}
